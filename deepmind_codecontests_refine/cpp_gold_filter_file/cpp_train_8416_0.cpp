#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	long long n, x, a[100005], ans = 0;

	cin >> n >> x >> a[0];
	for (int i = 1; i < n; ++i) {
		cin >> a[i];
		int d = a[i] + a[i - 1] - x;
		if (d > 0) {
			a[i] = max(a[i] - d, 0ll);
			ans += d;
		}
	}

	cout << ans << endl;

	return 0;
}