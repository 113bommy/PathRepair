#include <bits/stdc++.h>
const int N = 55, P = 998244353;
int w[N], n, r, o, dp[N][2][2][2], ans;
void inc(int& x, long long y) { x = (x + y) % P; }
int main() {
  scanf("%d%d", &n, &r);
  w[0] = 1;
  for (int i = 1; i <= n; i++) w[i] = (w[i - 1] + w[i - 1]) % P;
  scanf("%d", &o);
  if (o != 1) dp[1][1][0][1] = 1;
  if (o != 0) dp[1][0][1][1] = 1;
  for (int i = 2; i <= n; i++) {
    int o;
    scanf("%d", &o);
    if (o != 1) {
      for (int j = 0; j < 2; ++j)
        for (int k = 0; k < 2; ++k) {
          inc(dp[i][j | 1][1][!k], (long long)dp[i - 1][j][1][k] * w[i - 2]);
          inc(dp[i][j][1][k], (long long)dp[i - 1][j][1][k] * w[i - 2]);
        }
      inc(dp[i][1][0][0], (long long)dp[i - 1][1][0][1] * w[i - 1]);
      inc(dp[i][1][0][1], (long long)dp[i - 1][1][0][0] * w[i - 1]);
    }
    if (o != 0) {
      for (int j = 0; j < 2; ++j)
        for (int k = 0; k < 2; ++k) {
          inc(dp[i][1][j | 1][!k], (long long)dp[i - 1][1][j][k] * w[i - 2]);
          inc(dp[i][1][j][k], (long long)dp[i - 1][1][j][k] * w[i - 2]);
        }
      inc(dp[i][0][1][0], (long long)dp[i - 1][0][1][1] * w[i - 1]);
      inc(dp[i][0][1][1], (long long)dp[i - 1][0][1][0] * w[i - 1]);
    }
  }
  for (int j = 0; j < 2; ++j)
    for (int k = 0; k < 2; ++k) inc(ans, dp[n][j][k][r]);
  printf("%d", ans);
  return 0;
}
