#include <bits/stdc++.h>
const double EPS = 1e-8;
const int MAXN = 20 + 5, MAXM = MAXN * MAXN;
template <typename _T>
_T ABS(const _T x) {
  return x > 0 ? x : -x;
}
template <typename _T>
void swapp(_T &x, _T &y) {
  _T w = x;
  x = y;
  y = w;
}
struct GraphSet {
  int to, nx;
  GraphSet(int T = 0, int N = 0) { to = T, nx = N; }
} as[MAXM];
int n, m, s, t, cnt, upper, d[MAXN], begin[MAXN];
double mat[MAXN][MAXN], p[MAXN];
int has(const int x, const int y) { return (x - 1) * n + y; }
void makeEdge(const int u, const int v) {
  as[++cnt] = GraphSet(v, begin[u]), begin[u] = cnt;
}
void Eradicate() {
  for (int i = 1; i <= upper; ++i) {
    int p = i;
    for (int j = i + 1; j <= upper; ++j) {
      if (ABS(mat[p][i]) < ABS(mat[j][i])) p = i;
    }
    for (int j = i + 1; j <= upper + 1; ++j) swapp(mat[p][j], mat[i][j]);
    if (ABS(mat[i][i]) < EPS) continue;
    for (int j = 1; j <= upper; ++j) {
      if (i == j) continue;
      double d = mat[j][i] / mat[i][i];
      for (int k = 1; k <= upper + 1; ++k) mat[j][k] -= mat[i][k] * d;
    }
  }
  for (int i = 1; i <= upper; ++i) mat[i][upper + 1] /= mat[i][i];
}
int main() {
  scanf("%d%d%d%d", &n, &m, &s, &t), upper = n * n;
  for (int i = 1, u, v; i <= m; ++i) {
    scanf("%d%d", &u, &v);
    makeEdge(u, v), makeEdge(v, u);
    d[u]++, d[v]++;
  }
  for (int i = 1; i <= n; ++i) scanf("%lf", &p[i]);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (i == j)
        mat[has(i, j)][has(i, j)] = 1;
      else
        mat[has(i, j)][has(i, j)] = 1 - p[i] * p[j];
      for (int ii = begin[i]; ii; ii = as[ii].nx) {
        int u = as[ii].to;
        for (int iii = begin[j]; iii; iii = as[iii].nx) {
          int v = as[iii].to;
          if (u == v) continue;
          mat[has(i, j)][has(u, v)] = -(1 - p[u]) / d[u] * (1 - p[v]) / d[v];
        }
      }
      for (int ii = begin[i]; ii; ii = as[ii].nx) {
        int u = as[ii].to;
        if (u == j) continue;
        mat[has(i, j)][has(u, j)] = -p[j] * (1 - p[u]) / d[u];
      }
      for (int ii = begin[j]; ii; ii = as[ii].nx) {
        int v = as[ii].to;
        if (i == v) continue;
        mat[has(i, j)][has(i, v)] = -p[i] * (1 - p[v]) / d[v];
      }
    }
  }
  mat[has(s, t)][upper + 1] = 1;
  Eradicate();
  for (int i = 1; i <= n; ++i) printf("%.9lf ", mat[has(i, i)][upper + 1]);
  return 0;
}
