#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
long long sum[2005][2005], dp[2005][2005], mod = 1e9 + 7;
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n, m;
  cin >> n >> m;
  if (m == 1) {
    cout << 0;
    return 0;
  }
  for (long long i = 2; i <= m; i++) dp[1][i] = 1;
  for (long long i = 2; i <= n; i++) {
    for (long long j = 2; j <= m; j++)
      dp[i][j] = (dp[i - 1][j] + 2 * dp[i][j - 1] - dp[i][j - 2] + mod) % mod;
  }
  long long ans = 0;
  for (long long i = 1; i <= n; i++) {
    for (long long j = 2; j <= m; j++) {
      sum[i][j] = (sum[i - 1][j] + dp[i][j]) % mod;
    }
    for (long long j = 2; j <= m; j++) {
      ans = (ans + sum[i][j] * dp[n - i + 1][j] % mod * (m - j + 1)) % mod;
    }
  }
  cout << ans;
  return 0;
}
