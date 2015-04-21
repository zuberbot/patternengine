/*************************************************************
 *
 * http://curl.haxx.se/
 *
 *************************************************************/
#include <stdio.h>
#include <curl/curl.h>
 
int main(void) {
	// CURL easy handle to use as input to other functions
	CURL *curl = curl_easy_init();

	if (curl) {
		// Set the URL
		curl_easy_setopt(curl, CURLOPT_URL, "http://zuberbot.com/sample.txt");
 
		// Performs the entire request in a blocking manner 
		CURLcode res = curl_easy_perform(curl);

		fprintf(stdout, "\nCURLcode: %d\n", res);

		if (res != CURLE_OK) {
			const char *err = curl_easy_strerror(res);
			fprintf(stderr, "curl_easy_perform() failed: %s\n", err);
		}

		// Close all connections
		curl_easy_cleanup(curl);
	}

	return 0;
}
