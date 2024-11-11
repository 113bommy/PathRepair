#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-10;
double dp[205][250][256];
int main() {
  int x, k, Q;
  scanf("%d%d%d", &x, &k, &Q);
  double p = Q / 100.0, q = (100 - Q) / 100.0;
  int t1 = 0, t2 = 0, t3 = x & 255;
  x >>= 8;
  if (t3) {
    while (x & 1) {
      x >>= 1;
      t2++;
    }
  } else {
    while (x && (x & 1) == 0) {
      x >>= 1;
      t2++;
    }
  }
  int tmp, j2, k2;
  dp[t1][t2][t3] = 1;
  for (int t = 0; t < k; ++t) {
    int lim = t2;
    for (int i = 0; i <= lim; ++i) {
      if (fabs(dp[t][i][0]) > eps) {
        dp[t + 1][i + 1][0] += dp[t][i][0] * p;
        dp[t + 1][0][1] += dp[t][i][0] * q;
        if (i + 1 > t2) t2 = i + 1;
      }
      for (int j = 1; j < 256; ++j) {
        if (fabs(dp[t][i][j]) < eps) continue;
        double p1 = dp[t][i][j] * p, q1 = dp[t][i][j] * q;
        tmp = j << 1;
        j2 = tmp & 255;
        k2 = tmp >> 8;
        if (!j2)
          dp[t + 1][0][0] += p1;
        else if (k2) {
          dp[t + 1][i + 1][j2] += p1;
          if (i + 1 > t2) t2 = i + 1;
        } else
          dp[t + 1][0][j2] += p1;
        tmp = j + 1;
        j2 = tmp & 255;
        k2 = tmp >> 8;
        dp[t + 1][i][j2] += q1;
      }
    }
  }
  double ans = 0;
  for (int j = 0; j < 256; ++j) {
    tmp = 0;
    j2 = j;
    while (j2 && (j2 & 1) == 0) {
      tmp++;
      j2 >>= 1;
    }
    for (int i = 0; i <= t2; ++i) {
      if (fabs(dp[k][i][j]) < eps) continue;
      if (j == 0)
        ans += dp[k][i][j] * (8 + i);
      else
        ans += dp[k][i][j] * (tmp);
    }
  }
  printf("%.13lf\n", ans);
  return 0;
}
