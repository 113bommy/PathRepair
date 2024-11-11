#include <bits/stdc++.h>
using namespace std;
const int nmax = 50, mmax = nmax * 2, dmax = 10, mo = (int)(1e9 + 7);
int n, c, x, y, a[nmax + 18], p;
double f[nmax + 18][nmax + 18][nmax + 18][nmax + 18];
double g[nmax + 18];
double ans;
int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a < b ? a : b; }
int fpm(long long a, int b) {
  long long rnt = 1;
  for (; b; b >>= 1, a = a * a % mo)
    if (b & 1) rnt = rnt * a % mo;
  return rnt % mo;
}
double calcc(int k) {
  if (g[k] == 0) return 0;
  if (k == n) return 1;
  double rnt = k;
  for (int i = 1; i <= k; ++i) rnt = rnt * i;
  for (int i = (n == k) ? 1 : n - k; i <= n; ++i) rnt = rnt / i;
  return rnt;
}
double calc(int k) {
  double rnt = k;
  if (k > n / 2) k = n - k;
  for (int i = 1; i <= k; ++i) rnt = rnt * i;
  for (int i = n - k + 1; i <= n; ++i) rnt = rnt / i;
  return rnt;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", a + i);
  scanf("%d", &p);
  for (int l = 1; l <= n; ++l) {
    f[l][0][0][0] = 1;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j <= i; ++j)
        for (int k = 0; k <= p; ++k) {
          f[l][i + 1][j][k] += f[l][i][j][k];
          if (i + 1 == l) continue;
          if (k + a[i + 1] <= p)
            f[l][i + 1][j + 1][k + a[i + 1]] += f[l][i][j][k];
        }
    for (int i = 0; i < n; ++i)
      for (int j = 0; j <= p; ++j)
        if (j + a[l] > p)
          g[i] += f[l][n][i][j];
        else if (i == n - 1)
          g[n] += f[l][n][i][j];
  }
  for (int i = 1; i <= n; ++i) ans += calcc(i) * g[i];
  printf("%.9f", ans);
  return 0;
}
