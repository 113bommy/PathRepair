#include <bits/stdc++.h>
double dp[55][5005];
int f[64], s[64], p[64];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d%d%d", &f[i], &s[i], &p[i]);
  }
  double l = 0, r = 10000000000LL;
  while (r * 0.9999999999 > l) {
    double mid = (l + r) / 2;
    for (int i = 0; i <= m; i++) {
      dp[n][i] = 0;
    }
    for (int i = n - 1; i >= 0; i--) {
      for (int j = 0; j <= m; j++) {
        if (j + f[i] > m) {
          dp[i][j] = mid;
          continue;
        }
        if (j + s[i] > m) {
          dp[i][j] = (mid + s[i]) * (100 - p[i]) / 100 +
                     (dp[i + 1][j + f[i]] + f[i]) * p[i] / 100;
        } else {
          dp[i][j] = (dp[i + 1][j + s[i]] + s[i]) * (100 - p[i]) / 100 +
                     (dp[i + 1][j + f[i]] + f[i]) * p[i] / 100;
        }
        if (dp[i][j] > mid) {
          dp[i][j] = mid;
        }
      }
    }
    if (dp[0][0] < mid) {
      r = mid;
    } else {
      l = mid;
    }
  }
  printf("%.10f\n", l);
  return 0;
}
