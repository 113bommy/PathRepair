#include <bits/stdc++.h>
using namespace std;

signed main () {
	string s;
	cin >> s;
	int n = s.size();
	vector < vector < int > > dp(n + 1, vector < int > (2, 0));
	dp[n][1] = 1;
	for (int i = n - 1; i >= 0; --i) {
		dp[i][0] = min(dp[i + 1][1] + 1 + int(s[i] - '0'), dp[i + 1][0] + int(s[i] - '0'));
		dp[i][1] = min(dp[i + 1][1] + 10 - int(s[i] - '0') - 1, dp[i + 1][0] + 10 - int(s[i] - '0'));
	}
	cout << min(dp[0][0], dp[0][1] + 1) << '\n';
}
