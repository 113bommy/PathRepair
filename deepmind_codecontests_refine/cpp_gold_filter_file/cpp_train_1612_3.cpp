#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 5;
int n, t;
double p, dp[N][N];
signed main() {
  scanf("%d %lf %d", &n, &p, &t);
  dp[0][0] = 1;
  for (int i = 1; i <= t; ++i) {
    dp[i][0] = dp[i - 1][0] * (1 - p);
    for (int j = 1; j <= n; ++j) {
      if (j == n)
        dp[i][j] = dp[i - 1][j - 1] * p + dp[i - 1][j];
      else
        dp[i][j] = dp[i - 1][j - 1] * p + dp[i - 1][j] * (1 - p);
    }
  }
  double ans = 0;
  for (int i = 0; i <= n; ++i) ans += dp[t][i] * (double)i;
  printf("%.12lf\n", ans);
  return 0;
}
