#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-7;
int n, m, V, x, y, z, tot, e[501];
long long dis[510][510];
double v, o, p, a[510][510], b[510], c[510];
void pivot(int l, int e) {
  a[l][e] = 1 / a[l][e];
  b[l] *= a[l][e];
  for (int i = 1; i <= n; ++i)
    if (i != e) a[l][i] *= a[l][e];
  for (int i = 1; i <= m; ++i)
    if (i != l && fabs(a[i][e]) > eps) {
      b[i] -= a[i][e] * b[l];
      for (int j = 1; j <= n; ++j)
        if (j != e) a[i][j] -= a[i][e] * a[l][j];
      a[i][e] *= -a[l][e];
    }
  v += c[e] * b[l];
  for (int i = 1; i <= n; ++i)
    if (i != e) c[i] -= c[e] * a[l][i];
  c[e] *= -a[l][e];
}
int main() {
  scanf("%d%d", &n, &V);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &e[i]);
    b[i] = e[i] ^ 1;
    a[i][n + 1] = 1;
    a[i][n + 2] = -1;
    c[n + 1] += e[i];
    c[n + 2] -= e[i];
    c[i] = 1;
  }
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      if (i != j) dis[i][j] = 1000000000000ll;
  for (int i = 1; i < n; ++i) {
    scanf("%d%d%d", &x, &y, &z);
    dis[x][y] = dis[y][x] = z;
  }
  for (int k = 1; k <= n; ++k)
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j)
        if (i != j && j != k && k != i)
          dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      if (dis[i][j] <= V) a[i][j] = 1;
  m = n;
  n += 2;
  for (;;) {
    int i, e, l;
    for (i = 1; i <= n; ++i)
      if (c[i] > eps) break;
    e = i;
    if (e == n + 1) {
      printf("%.0lf", v);
      return 0;
    }
    p = 1e99;
    for (int i = 1; i <= m; ++i)
      if (a[i][e] > eps && p > b[i] / a[i][e]) {
        p = b[i] / a[i][e];
        l = i;
      }
    if (p == 1e99) break;
    pivot(l, e);
  }
  printf("-1\n");
}
