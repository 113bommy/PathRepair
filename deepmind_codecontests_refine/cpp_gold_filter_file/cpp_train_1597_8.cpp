#include <bits/stdc++.h>
using namespace std;
int n, K, L;
double dp[205][205][505];
double p[205];
int v[205];
int main() {
  int i, j, k;
  while (scanf("%d%d%d", &n, &L, &K) != EOF) {
    for (i = 1; i <= n; i++) {
      scanf("%lf", &p[i]);
      p[i] /= 100.0;
    }
    for (i = 1; i <= n; i++) scanf("%d", &v[i]);
    memset(dp, 0, sizeof(dp));
    dp[0][0][K + 211] = 1.0;
    for (i = 0; i < n; i++) {
      for (j = 0; j <= i; j++) {
        for (k = 0; k < 505; k++) {
          if (v[i + 1] == -1) {
            if (k > 0) dp[i + 1][j + 1][k - 1] += dp[i][j][k] * p[i + 1];
            dp[i + 1][j][k] += dp[i][j][k] * (1 - p[i + 1]);
          }
          if (v[i + 1] >= 0) {
            dp[i + 1][j + 1][min(504, k + v[i + 1])] += dp[i][j][k] * p[i + 1];
            dp[i + 1][j][k] += dp[i][j][k] * (1 - p[i + 1]);
          }
        }
      }
    }
    double res = 0;
    for (i = L; i <= n; i++)
      for (j = 211; j < 505; j++) {
        res += dp[n][i][j];
      }
    printf("%.10f\n", res);
  }
  return 0;
}
