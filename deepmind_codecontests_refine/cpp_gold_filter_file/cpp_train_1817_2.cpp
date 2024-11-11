#include <bits/stdc++.h>
using namespace std;
int i, j, k, n, m, K, t, nn;
int a[610], id[610], du[610];
double c[610][610], b[110][110], d[110];
inline void gaosi() {
  for (i = 1; i <= n; i++) {
    for (j = i; j <= n; j++)
      if (c[j][i]) {
        for (k = i; k <= t; k++) swap(c[i][k], c[j][k]);
        break;
      }
    for (j = t; j >= i; j--) c[i][j] /= c[i][i];
    for (j = i + 1; j <= n; j++)
      if (c[j][i])
        for (k = t; k >= i; k--) c[j][k] -= c[j][i] * c[i][k];
  }
  for (i = n; i; i--)
    for (j = 1; j <= i - 1; j++)
      for (k = n + 1; k <= t; k++) c[j][k] -= c[j][i] * c[i][k];
  for (i = 1; i <= nn; i++) d[i] = c[1][n + i];
  for (i = 1; i <= n; i++)
    if (a[i])
      for (j = 1; j <= nn; j++) b[id[i] - n][j] = c[i][j + n];
}
inline void mul() {
  int i, j;
  double a[110] = {};
  for (i = 1; i <= nn; i++)
    for (j = 1; j <= nn; j++) a[j] += d[i] * b[i][j];
  for (i = 1; i <= nn; i++) d[i] = a[i];
}
inline void multi() {
  int i, j, k;
  double a[110][110] = {};
  for (i = 1; i <= nn; i++)
    for (j = 1; j <= nn; j++)
      for (k = 1; k <= nn; k++) a[i][k] += b[i][j] * b[j][k];
  for (i = 1; i <= nn; i++)
    for (j = 1; j <= nn; j++) b[i][j] = a[i][j];
}
inline void work() {
  K -= 2;
  for (; K; K /= 2) {
    if (K & 1) mul();
    multi();
  }
  printf("%.12lf\n", fabs(d[nn]));
}
int main() {
  scanf("%d%d%d", &n, &m, &K);
  t = n;
  for (i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    if (a[i]) id[i] = ++t;
  }
  nn = t - n;
  for (i = 1; i <= m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    du[x]++, du[y]++;
    if (a[y])
      c[x][id[y]]++;
    else
      c[x][y]++;
    if (a[x])
      c[y][id[x]]++;
    else
      c[y][x]++;
  }
  for (i = 1; i <= n; i++) c[i][i] -= du[i];
  gaosi();
  work();
  return 0;
}
