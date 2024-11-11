#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("-O2")
const long long LIM = 5e5 + 5, MOD = 998244353;
long long t, n, m, k, x, y;
long long dp[3005][3005];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  string s, t;
  cin >> s >> t;
  n = s.size();
  m = t.size();
  for (long long j = 1; j <= m; j++) dp[n][j] = 0;
  dp[n][0] = 1;
  for (long long i = n - 1; i >= 1; i--) {
    for (long long j = 0; j <= m; j++) {
      if (j == 0) {
        if (i >= m)
          dp[i][j] = n - i + 1;
        else if (s[i] == t[i])
          dp[i][j] = dp[i + 1][j];
      } else if (j < m) {
        if (i + j >= m || s[i] == t[i + j]) dp[i][j] = dp[i + 1][j];
        if (s[i] == t[j - 1]) dp[i][j] = (dp[i + 1][j - 1] + dp[i][j]) % MOD;
      } else {
        dp[i][j] = 2 * dp[i + 1][j];
        if (s[i] == t[m - 1]) dp[i][j] = (dp[i][j] + dp[i + 1][j - 1]) % MOD;
      }
    }
  }
  long long ans = 0;
  for (long long i = 0; i < m; i++)
    if (t[i] == s[0]) ans = (ans + dp[1][i]) % MOD;
  ans += dp[1][m];
  ans %= MOD;
  ans = (2 * ans) % MOD;
  cout << ans << "\n";
}
