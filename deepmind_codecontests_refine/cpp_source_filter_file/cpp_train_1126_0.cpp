#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100005;

long long x[N], c[N], cc[N], cmx[N], ccmx[N], v[N];

int main() {
	int n; long long C;
	cin >> n >> C;
	for (int i = 1; i <= n; i++)cin >> x[i] >> y[i];
	for (int i = 1; i <= n; i++) {
		c[i] = c[i - 1] + v[i] - (x[i] - x[i - 1]);
		cmx[i] = max(cmx[i - 1], c[i]);
	}
	x[n + 1] = C;
	for (int i = n; i >= 1; i--) {
		cc[n - i + 1] = cc[n - i] + v[i] - (x[i + 1] - x[i]);
		ccmx[n - i + 1] = max(ccmx[n - i + 1], cc[n - i + 1]);
	}
	long long ans = 0;
	for (int i = 0; i <= n; i++) {
		ans = max(ans, c[i] - x[i] + ccmx[n - i]);
		ans = max(ans, cc[i] - (C - x[n - i + 1]) + cmx[n - i]);
	}
	cout << ans << endl;
	return 0;
}