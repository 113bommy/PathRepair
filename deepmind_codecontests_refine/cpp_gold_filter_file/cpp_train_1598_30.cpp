#include <bits/stdc++.h>
using namespace std;
int n, l, k;
double p[210];
int a[210];
double dp[210][210][2 * 210];
int main() {
  int delta = 205;
  while (cin >> n >> l >> k) {
    int left = 0;
    for (int i = 1; i <= n; ++i) {
      scanf("%lf", p + i);
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%d", a + i);
    }
    for (int i = 0; i <= n; ++i)
      for (int j = 0; j <= n; ++j)
        for (int t = -n; t <= n; ++t) dp[i][j][t + delta] = 0.0;
    dp[0][0][min(k, n) + delta] = 1.0;
    for (int i = 0; i < n; ++i) {
      double win = p[i + 1] / 100.0;
      double lose = 1.0 - win;
      for (int j = 0; j <= i; ++j) {
        for (int t = -i; t <= n; ++t) {
          if (a[i + 1] >= 0) {
            dp[i + 1][j + 1][min(t + a[i + 1], n) + delta] +=
                dp[i][j][t + delta] * win;
            dp[i + 1][j][t + delta] += dp[i][j][t + delta] * lose;
          } else {
            dp[i + 1][j + 1][t - 1 + delta] += dp[i][j][t + delta] * win;
            dp[i + 1][j][t + delta] += dp[i][j][t + delta] * lose;
          }
        }
      }
    }
    double ans = 0.0;
    for (int i = l; i <= n; ++i)
      for (int j = 0; j <= n; ++j) {
        ans += dp[n][i][j + delta];
      }
    printf("%.7lf\n", ans);
  }
  return 0;
}
