#include <bits/stdc++.h>
using namespace std;
int n, m, a[55];
double C[55][55];
double f[55][55][55];
void init() {
  int i, j, k;
  for (i = 0; i <= 50; i++)
    for (j = 0; j <= 50; j++) C[i][j] = 0.0;
  for (i = 0; i <= 50; i++)
    for (j = 0; j <= 50; j++)
      for (k = 0; k <= 50; k++) f[i][j][k] = 0.0;
  C[0][0] = 1.0;
  C[1][0] = 1.0;
  C[1][1] = 1.0 / m;
  for (i = 2; i <= 50; i++) {
    C[i][0] = 1.0;
    for (j = 1; j <= i; j++) C[i][j] = C[i - 1][j] + C[i - 1][j - 1] / m;
  }
}
int main() {
  int i, j, k, l;
  scanf("%d%d", &n, &m);
  init();
  for (i = 1; i <= m; i++) scanf("%d", &a[i]);
  f[0][0][0] = 1.0;
  for (i = 1; i <= m; i++)
    for (j = 0; j <= n; j++)
      for (l = 0; l <= j; l++) {
        int last = j - l;
        int len = 0;
        if (l % a[i] == 0 || l == 0)
          len = l / a[i];
        else
          len = (l / a[i]) + 1;
        double cnt = 0.0;
        for (k = 0; k <= len; k++) cnt += f[i - 1][last][k];
        f[i][j][len] += cnt * C[n - last][l];
        for (k = len + 1; k <= n; k++)
          f[i][j][k] += f[i - 1][last][k] * C[n - last][l];
      }
  double ans = 0.0;
  for (i = 0; i <= n; i++) ans += i * f[m][n][i];
  printf("%.10lf\n", ans);
  return 0;
}
