#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8, inf = 1e9;
int n, m, type, id[310], tp[310];
double a[310][310];
void pivot(int r, int c) {
  swap(id[r + n], id[c]);
  double t = -a[r][c];
  a[r][c] = -1;
  for (int i = 0; i <= n; ++i) a[r][i] /= t;
  for (int i = 0; i <= m; ++i)
    if (a[i][c] && r != i) {
      t = a[i][c];
      a[i][c] = 0;
      for (int j = 0; j <= n; ++j) a[i][j] += t * a[r][j];
    }
}
void solve() {
  double t;
  for (int i = 1; i <= n; ++i) id[i] = i;
  while (true) {
    int i = 0, j = 0;
    double _w = -eps;
    for (int k = 1; k <= m; ++k)
      if (a[k][0] < _w) _w = a[i = k][0];
    if (!i) break;
    for (int k = 1; k <= n; ++k)
      if (a[i][k] > eps) {
        j = k;
        break;
      }
    if (!j) {
      printf("Infeasible");
      return;
    }
    pivot(i, j);
  }
  while (true) {
    int i = 0, j = 0;
    double _w = eps;
    for (int k = 1; k <= n; ++k)
      if (a[0][k] > _w) _w = a[0][j = k];
    if (!j) break;
    _w = inf;
    for (int k = 1; k <= m; ++k)
      if (a[k][j] < -eps && (t = -a[k][0] / a[k][j]) < _w) _w = t, i = k;
    if (!i) {
      printf("Unbounded");
      return;
    }
    pivot(i, j);
  }
  for (int i = n + 1; i <= n + m; ++i) tp[id[i]] = i - n;
  if (type)
    for (int i = 1; i <= n; ++i) printf("%d ", (int)(tp[i] ? a[tp[i]][0] : 0));
}
int main() {
  scanf("%d%d", &n, &m);
  int _a, _b, _d;
  memset(a, 0, sizeof a);
  for (int i = 1; i <= m; i++) {
    a[i][0] = -1;
  }
  for (int i = 1; i <= m; i++) {
    scanf("%d%d%d", &_a, &_b, &_d);
    a[0][_a] -= _d;
    a[0][_b] += _d;
    a[i][_a] = 1;
    a[i][_b] = -1;
  }
  type = 1;
  solve();
  return 0;
}
