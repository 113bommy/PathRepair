#include <bits/stdc++.h>
using namespace std;
double dp[201][201][401];
int n, l, K;
double p[201];
int s[201];
int main() {
  while (scanf("%d%d%d", &n, &l, &K) == 3) {
    int i, j, k;
    for (i = 1; i <= n; i++) scanf("%lf", &p[i]);
    for (i = 1; i <= n; i++) scanf("%d", &s[i]);
    dp[0][0][200 + K] = 1.0;
    for (i = 1; i <= n; i++)
      for (j = 0; j <= i; j++)
        for (k = 0; k <= 400; k++)
          if (dp[i - 1][j][k] > 0) {
            dp[i][j][k] += dp[i - 1][j][k] * (1.0 - p[i] / 100.0);
            dp[i][j + 1][min(k + s[i], 400)] +=
                dp[i - 1][j][k] * (p[i] / 100.0);
          }
    double ans = 0;
    for (i = l; i <= n; i++)
      for (j = 200; j <= 400; j++) ans += dp[n][i][j];
    printf("%.8f\n", ans);
  }
  return 0;
}
