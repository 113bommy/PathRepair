#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const double eps = 1e-8;
const int nm = 1005;
int n, k, m, t;
double res;
long long sl[20];
long long l[nm], r[nm];
double dp[nm][nm];
double p[nm];
int main() {
  int i, j, x, y, z, w;
  sl[1] = 1;
  for (i = 2; i <= 19; i++) sl[i] = sl[i - 1] * 10;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) scanf("%I64d%I64d", &l[i], &r[i]);
  scanf("%d", &k);
  for (i = 1; i <= n; i++) {
    int scsl = 0;
    long long x = l[i];
    while (x) {
      x /= 10;
      scsl++;
    }
    long long sth = 0;
    sth -= min((l[i] - sl[scsl]), sl[scsl]);
    x = r[i];
    long long scsr = 0;
    while (x) {
      x /= 10;
      scsr++;
    }
    sth += min((r[i] - sl[scsr] + 1), sl[scsr]);
    for (j = scsl; j < scsr; j++) sth += sl[j];
    p[i] = (double)sth / (r[i] - l[i] + 1);
  }
  dp[0][0] = 1;
  for (i = 1; i <= n; i++)
    for (j = 0; j <= i; j++) {
      if (j == 0) dp[i][j] = dp[i - 1][j] * (1 - p[i]);
      dp[i][j] = dp[i - 1][j] * (1 - p[i]) + dp[i - 1][j - 1] * p[i];
    }
  int Min = ceil(1. * n * k / 100 - eps);
  for (i = Min; i <= n; i++) res += dp[n][i];
  printf("%.12lf ", res);
  ;
  return 0;
}
