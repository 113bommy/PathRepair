#include <bits/stdc++.h>
using namespace std;
int n, a[705];
long long ans, t[705], dp[705][705][2];
int main() {
  char c = getchar();
  while (c > 47) a[++n] = c - 48, c = getchar();
  t[1] = 1;
  for (int i = 2; i <= n; ++i) t[i] = t[i - 1] * 10ll % 1000000007;
  for (int i = 2; i <= n; ++i) (t[i] += t[i - 1]) %= 1000000007;
  for (int _ = 1; _ <= 9; ++_) {
    memset(dp, 0, sizeof(dp));
    dp[0][0][1] = 1;
    for (int i = 1; i <= n; ++i) {
      int __ = min(_, a[i]);
      for (int j = 0; j < i; ++j) {
        dp[i][j + 1][0] += dp[i - 1][j][0] * (10 - _);
        dp[i][j][0] += dp[i - 1][j][0] * _;
        dp[i][j][0] += dp[i - 1][j][1] * __;
        dp[i][j + 1][0] += dp[i - 1][j][1] * (a[i] - __);
        dp[i][j + (_ == __)][1] += dp[i - 1][j][1];
      }
      for (int j = 0; j < i; ++j)
        dp[i][j][0] %= 1000000007, dp[i][j][1] %= 1000000007;
    }
    for (int i = 1; i <= n; ++i)
      (ans += (dp[n][i][0] + dp[n][i][1]) * t[i]) %= 1000000007;
  }
  printf("%I64d\n", (ans % 1000000007 + 1000000007) % 1000000007);
  return 0;
}
