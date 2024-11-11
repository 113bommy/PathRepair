#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const int inf = 1012345678;
const int maxn = 100;
int n, m;
int rd() {
  int x;
  scanf("%d", &x);
  return x;
}
double a[maxn];
double p[maxn], dp[maxn][maxn][maxn], r[maxn];
int c[maxn][maxn];
int main() {
  int i, j, k, t;
  for (i = 0; i <= 51; i++) c[i][0] = 1;
  for (i = 1; i <= 51; i++)
    for (j = 1; j <= i; j++) c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
  while (scanf("%d%d", &n, &m) != EOF) {
    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1;
    p[0] = 1;
    for (i = 1; i <= m; i++) p[i] = p[i - 1] * (1.0 / m);
    for (i = 1; i <= m; i++) scanf("%lf", &a[i]);
    int ni, nj, nk;
    for (i = 1; i <= m; i++) {
      for (j = 0; j <= n; j++) {
        for (k = 0; k <= j; k++) {
          for (ni = 0; ni + j <= n; ni++) {
            nj = n - j;
            nk = (ni + a[i] - 1) / a[i];
            nk = max(nk, k);
            dp[i][ni + j][nk] += (dp[i - 1][j][k] * c[nj][ni]);
          }
        }
      }
    }
    double res = 0;
    double sum = 1;
    for (i = 1; i <= n; i++) {
      sum *= m;
      res += dp[m][n][i] * i;
    }
    res /= sum;
    printf("%.19f\n", res);
  }
}
