#include <bits/stdc++.h>
using namespace std;
int n, m, K, all, tot, w[613], deg[613], cn = 0, X[613 * 613], Y[613 * 613],
                                         rev[613];
double a[613][613];
struct Mat {
  double f[107][107];
  inline Mat() {
    for (int i = 1; i <= all; i++)
      for (int j = 1; j <= all; j++) f[i][j] = 0.0;
  }
  inline Mat operator*(const Mat &b) const {
    Mat p;
    int i, j, k;
    for (i = 1; i <= all; i++)
      for (k = 1; k <= all; k++)
        for (j = 1; j <= all; j++) p.f[i][k] += f[i][j] * b.f[j][k];
    return p;
  }
} tr, ans;
int main() {
  scanf("%d%d%d", &n, &m, &K);
  tot = n;
  int i, j, k, p, x, y;
  double v, iv;
  for (i = 1; i <= n; i++) {
    scanf("%d", &x);
    if (x) rev[w[i] = ++tot] = i;
  }
  for (i = 1; i <= m; i++) {
    scanf("%d%d", &x, &y);
    ++deg[x];
    ++deg[y];
    a[x][w[y] ? w[y] : y] -= 1;
    a[y][w[x] ? w[x] : x] -= 1;
  }
  for (i = 1; i <= n; i++) a[i][i] = deg[i];
  for (i = 1; i <= n; i++)
    for (j = n + 1; j <= tot; j++) a[i][j] = -a[i][j];
  for (i = 1; i <= n; i++) {
    p = i;
    for (j = i + 1; j <= n; j++)
      if (fabs(a[j][i]) > fabs(a[p][i])) p = j;
    if (p != i)
      for (k = i; k <= tot; k++) swap(a[i][k], a[p][k]);
    iv = 1.0 / a[i][i];
    for (j = i; j <= tot; j++) a[i][j] *= iv;
    for (j = i + 1; j <= n; j++)
      if (fabs(v = a[j][i]) > 0)
        for (k = i; k <= tot; k++) a[j][k] -= a[i][k] * v;
  }
  for (i = n; i >= 1 + 1; i--)
    for (j = i - 1; j >= 1; j--)
      if (fabs(v = a[j][i]) > 0) {
        a[j][i] = 0;
        for (k = n + 1; k <= tot; k++) a[j][k] -= a[i][k] * v;
      }
  for (i = n + 1; i <= tot; i++)
    for (j = n + 1; j <= tot; j++) tr.f[i - n][j - n] = a[rev[i]][j];
  all = tot - n + 1;
  for (i = n + 1; i <= tot; i++) tr.f[all][i - n] = a[1][i];
  --K;
  for (i = 1; i <= all; i++) ans.f[i][i] = 1.0;
  while (K) {
    if (K & 1) ans = ans * tr;
    K >>= 1;
    if (K) tr = tr * tr;
  }
  printf("%.8lf", ans.f[all][tot - n]);
  return 0;
}
