#include <bits/stdc++.h>
namespace TNT {
const int MAXN = 5e3 + 10;
const int INF = 1e8;
inline int read() {
  int x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') ch = getchar();
  while (ch >= '0' && ch <= '9') {
    x = (x << 3) + (x << 1) + (ch ^ 48);
    ch = getchar();
  }
  return x;
}
inline void write(int x) {
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
int dp[MAXN][MAXN >> 1][3], a[MAXN];
inline void main() {
  using std::max;
  using std::min;
  int n = read(), sum;
  sum = (n + 1) / 2;
  for (register int i = 1; i <= n; i++) a[i] = read();
  a[0] = INF;
  for (register int i = 1; i <= n; i++)
    for (register int j = 1; j <= sum; j++)
      for (register int k = 0; k <= 1; k++) dp[i][j][k] = INF;
  dp[0][0][0] = dp[1][0][0] = dp[1][1][1] = 0;
  for (register int i = 2; i <= n; i++) {
    dp[i][0][0] = dp[i - 1][0][0];
    for (register int j = 1; j <= (i + 1) / 2; j++) {
      dp[i][j][1] =
          min(dp[i - 2][j - 1][0] + max(0, a[i - 1] - a[i] + 1),
              dp[i - 2][j - 1][1] + max(max(0, a[i - 1] - a[i] + 1),
                                        max(0, a[i - 1] - a[i - 2] + 1)));
      dp[i][j][0] =
          min(dp[i - 1][j][0], dp[i - 1][j][1] + max(0, a[i] - a[i - 1] + 1));
    }
  }
  for (register int i = 1; i <= sum; i++)
    write(min(dp[n][i][0], dp[n][i][1])), putchar(' ');
  return;
}
}  // namespace TNT
int main() {
  TNT::main();
  return 0;
}
