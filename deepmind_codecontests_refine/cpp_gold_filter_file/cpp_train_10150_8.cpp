#include <bits/stdc++.h>
int n, m;
long long ans = 0, dp[2][505][505], mod = 1e9 + 7;
char s[505][505];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
  int T = 0;
  if (s[1][1] == s[n][m]) dp[T][1][n] = 1;
  for (int k = 1; k <= (n + m) / 2 - 1; k++) {
    T = !T;
    memset(dp[T], 0, sizeof(dp[T]));
    for (int i = 1; i <= n; i++) {
      int y1 = k - i + 2;
      if (y1 < 1 || y1 > m) continue;
      for (int j = n; j >= i; j--) {
        int y2 = m - (k - (n - j));
        if (y2 < 1 || y2 > m || y2 < y1) continue;
        if (s[i][y1] != s[j][y2]) continue;
        dp[T][i][j] += dp[!T][i][j] + dp[!T][i][j + 1] + dp[!T][i - 1][j] +
                       dp[!T][i - 1][j + 1];
        dp[T][i][j] %= mod;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    ans = (ans + dp[T][i][i]) % mod;
    if ((n + m) & 1) ans = (ans + dp[T][i][i + 1]) % mod;
  }
  return !printf("%lld\n", ans);
}
