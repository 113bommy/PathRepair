#include <bits/stdc++.h>
const int maxn = 35, mod = 1e9 + 7;
inline int max(int a, int b) { return a > b ? a : b; }
int n, dp[maxn][maxn][2], ans;
void plus(int &x, int v) { x += v, (x >= mod ? x -= mod : 0); }
int main() {
  scanf("%d", &n), dp[30][0][1] = 1;
  for (int i = 30; i; --i) {
    for (int j = 0; j <= 30; ++j) {
      plus(dp[i - 1][j + 1][0], dp[i][j][0]),
          plus(dp[i - 1][j][0], 1ll * dp[i][j][0] * (1 << j) % mod);
      int p1 = (j ? (1 << j - 1) : 1), p2 = (j ? (1 << j - 1) : 0);
      if (!(n & (1 << i - 1)))
        plus(dp[i - 1][j][1], 1ll * p1 * dp[i][j][1] % mod);
      else
        plus(dp[i - 1][j + 1][1], dp[i][j][1]),
            plus(dp[i - 1][j][0], 1ll * dp[i][j][1] * p1 % mod),
            plus(dp[i - 1][j][1], 1ll * dp[i][j][1] * p2 % mod);
    }
  }
  for (int i = 0; i <= 30; ++i) plus(ans, dp[0][i][0]), plus(ans, dp[0][i][1]);
  return printf("%d\n", ans), 0;
}
