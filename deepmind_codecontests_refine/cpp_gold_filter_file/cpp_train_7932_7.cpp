#include <bits/stdc++.h>
using namespace std;
int c1[150];
long double dp[150][100050], c[150][150];
int main() {
  int n, x;
  scanf("%d%d", &n, &x);
  for (int i(1); i <= n; ++i) scanf("%d", &c1[i]);
  for (int i(dp[0][0] = 1), j, k; i <= n; ++i)
    for (j = i; j; --j)
      for (k = 10000; k >= c1[i]; --k) dp[j][k] += dp[j - 1][k - c1[i]];
  for (int i(0), j; i < 150; ++i)
    for (c[i][0] = j = 1; j <= i; ++j) c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
  long double ans(0);
  for (int i(1), j; i <= n; ++i)
    for (j = 0; j <= 10000; ++j)
      ans +=
          min(x * (n + i) * 1.0l / (i << 1), j * 1.0l / i) * dp[i][j] / c[n][i];
  return printf("%.20Lf", ans), 0;
}
