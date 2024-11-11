#include <bits/stdc++.h>
using namespace std;
const int N = 2000 + 10;
const double inf = 1e8 + 10;
double dp[N][N][2][2];
int limit[N][2];
double p;
int n;
double aa[N], h;
double fun(int l, int r, int f1, int f2) {
  double le, re;
  double ret = 0;
  if (dp[l][r][f1][f2] >= 0) return dp[l][r][f1][f2];
  if (l > r) return 0;
  if (f1)
    le = aa[l - 1] + h;
  else
    le = aa[l - 1];
  if (f2)
    re = aa[r + 1];
  else
    re = aa[r + 1] - h;
  ret += 0.5 * p * (min(h, aa[l] - le) + fun(l + 1, r, 0, f2));
  ret += 0.5 * (1 - p) * (min(h, re - aa[r]) + fun(l, r - 1, f1, 1));
  int i = limit[l][1];
  i = min(i, r);
  ret += 0.5 * (1 - p) *
         (min(aa[i] + h - aa[l], re - aa[l]) + fun(i + 1, r, 1, f2));
  i = limit[r][0];
  i = max(i, l);
  ret += 0.5 * p * (min(aa[r] - le, aa[r] - aa[i] + h) + fun(l, i - 1, f1, 0));
  return dp[l][r][f1][f2] = ret;
}
int main() {
  while (scanf("%d%lf%lf", &n, &h, &p) != EOF) {
    for (int i = 1; i <= n; i++) {
      scanf("%lf", &aa[i]);
    }
    aa[0] = -inf * 2, aa[n + 1] = inf * 2;
    sort(aa, aa + n + 2);
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        for (int k = 0; k < 2; k++) {
          for (int l = 0; l < 2; l++) {
            dp[i][j][k][l] = -1;
          }
        }
      }
    }
    limit[n][1] = n;
    for (int i = n - 1; i >= 1; i--) {
      if (aa[i + 1] - aa[i] >= h)
        limit[i][1] = i;
      else
        limit[i][1] = limit[i + 1][1];
    }
    limit[1][0] = 1;
    for (int i = 2; i <= n; i++) {
      if (aa[i] - aa[i - 1] >= h)
        limit[i][0] = i;
      else
        limit[i][0] = limit[i - 1][0];
    }
    printf("%lf\n", fun(1, n, 0, 1));
  }
  return 0;
}
