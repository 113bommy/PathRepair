#include "bits/stdc++.h"
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
template<typename T>bool maxup(T& a, const T& b) { if (a < b) { a = b; return true; }; }

int dp[2005][2005][2];
int main() {
	int m, n; cin >> m >> n;
	vector<int> s(m + 1);
	s[m] = 0;
	rep(i, m) {
		char c; cin >> c;
		s[i] = c == 'I';
	}
	vector<int> t(n + 1);
	rep(i, n) {
		char c; cin >> c;
		t[i] = c == 'I';
	}
	t[n] = 0;

	int ans = 0;
	rep(i, m + 1) rep(j, n + 1) {
		maxup(dp[i + 1][j][0], (dp[i][j][1] + 1) * !!dp[i][j][1] * !s[i]);
		maxup(dp[i][j + 1][0], (dp[i][j][1] + 1) * !!dp[i][j][1] * !t[j]);

		maxup(dp[i + 1][j][1], (dp[i][j][0] + 1) * s[i]);
		maxup(dp[i][j + 1][1], (dp[i][j][0] + 1) * t[j]);

		maxup(ans, dp[i + 1][j][1]);
		maxup(ans, dp[i][j + 1][1]);
	}
	cout << ans << endl;
}