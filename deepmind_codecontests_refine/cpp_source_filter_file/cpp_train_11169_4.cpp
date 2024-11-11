#include <bits/stdc++.h>
using namespace std;
void testCase() {
  long long n, m;
  cin >> n >> m;
  string s, t;
  cin >> s >> t;
  vector<vector<long long>> dp(n + 1, vector<long long>(m, 0));
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= m; j++) {
      dp[i][j] = max(dp[i][j], dp[i - 1][j] - 1);
      dp[i][j] = max(dp[i][j], dp[i][j - 1] - 1);
      if (s[i - 1] == t[j - 1]) {
        dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 2);
      }
    }
  }
  long long ans = 0;
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= m; j++) {
      ans = max(ans, dp[i][j]);
    }
  }
  cout << ans << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  for (long long tc = 1; tc <= t; tc++) {
    testCase();
  }
  return 0;
}
