#include <cstdlib>
#include <iostream>
int main(void) {
	int n;
	while (std::cin >> n) {
		const int mod = 1000000007;
		int stack = 0, *arr;
		long long ans = 1;
		arr = new int[n];
		for (int i = 0; i < n; ++i) {
			std::cin >> arr[i];
		}
		for (int i = 0; i < n; ++i) {
			if (arr[i] < 2 * ++stack - 1) {
				ans *= stack--;
				ans %= mod;
	   		}
		}
		for (int i = 0; i < stack; ++i) {
			ans *= i + 1;
			ans %= mod;
		}
		std::cout << ans << std::endl;
		delete[] arr;
	}
	return EXIT_SUCCESS;
}