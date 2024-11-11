#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long a[1505][1505];
long long dp[1505][1505];
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (long long i = 1; i <= n; i++)
    for (long long j = 1; j <= m; j++) cin >> a[i][j];
  for (long long i = 1; i <= m; i++) dp[1][i] = dp[1][i - 1] + a[1][i];
  for (long long i = 2; i <= n; i++) {
    if (i & 1) {
      long long mx = dp[i - 1][1];
      long long cur = a[i][1];
      for (long long j = 2; j <= m; j++) {
        cur += a[i][j];
        dp[i][j] = cur + mx;
        mx = max(mx, dp[i - 1][j]);
      }
    } else {
      long long mx = dp[i - 1][m];
      long long cur = 0;
      for (long long j = 1; j <= m; j++) cur += a[i][j];
      for (long long j = m - 1; j >= 1; j--) {
        cur -= a[i][j + 1];
        dp[i][j] = cur + mx;
        mx = max(mx, dp[i - 1][j]);
      }
    }
  }
  long long ans = -1e18;
  if (n & 1) {
    for (long long i = 2; i <= m; i++) ans = max(ans, dp[n][i]);
  } else {
    for (long long i = 1; i < m; i++) ans = max(ans, dp[n][i]);
  }
  cout << ans << '\n';
}
