#include <bits/stdc++.h>
const int N = 18;
int n;
long double p[N][N], dp[1 << N][N];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) {
      double v;
      scanf("%lf", &v);
      p[i][j] = v;
    }
  dp[0][0] = 1;
  long double ans = 0;
  for (int i = 1; i < 1 << n; ++i)
    for (int j = 0; j < n; ++j)
      if (!(i >> j & 1)) {
        for (int k = 0; k < n; ++k)
          if (i >> k & 1)
            dp[i][j] = std::max(dp[i][j], dp[i & ~(1 << k)][j] * p[j][k] +
                                              dp[i & ~(1 << k)][k] * p[k][j]);
        if ((i | 1 << j) == (1 << n) - 1) ans = std::max(ans, dp[i][j]);
      }
  printf("%.10lf\n", (double)ans);
  return 0;
}
