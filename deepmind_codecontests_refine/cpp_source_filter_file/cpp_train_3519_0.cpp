#include <iostream>
#include <algorithm>
#include <vector>
#define int long long
using namespace std;
int n, k, a[100], ans;
signed main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++)cin >> a[i];
	for (int i = 0; i < min(n, k); i++) {
		for (int j = 0; i + j < min(n, k); j++) {
			vector<int>v; int sum = 0;
			for (int p = 0; p < i; p++) {
				v.push_back(a[p]); sum += a[p];
			}
			for (int p = 0; p < j; p++) {
				v.push_back(a[n - p - 1]); sum += a[n - p - 1];
			}
			sort(v.begin(), v.end());
			for (int p = 0; p < min(k - i - j, i + j); p++)sum -= min(v[p], 0);
			ans = max(ans, sum);
		}
	}
	cout << ans << endl;
}