#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || '9' < ch) f = (ch ^ '-') ? f : -1, ch = getchar();
  while ('0' <= ch && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  return x * f;
}
int const N = 30;
double const EPS = 1e-8;
bool equal0(double x) { return -EPS < x && x < EPS; }
int n, m, T;
double a[N][N];
int b[N], id[N << 1];
void pivot(int x, int y) {
  swap(id[n + x], id[y]);
  double t = a[x][y];
  a[x][y] = 1;
  for (int i = 0; i <= n; i++) a[x][i] /= t;
  for (int i = 0; i <= m; i++) {
    if (i == x || equal0(a[i][y])) continue;
    t = a[i][y], a[i][y] = 0;
    for (int j = 0; j <= n; j++) a[i][j] -= a[x][j] * t;
  }
}
bool simplex() {
  while (true) {
    int x = 0, y = 0;
    for (int j = 1; !y && j <= n; j++)
      if (a[0][j] > EPS) y = j;
    if (!y) return true;
    double minX = 1e18;
    for (int i = 1; i <= m; i++)
      if (a[i][y] > EPS && minX > a[i][0] / a[i][y])
        minX = a[i][0] / a[i][y], x = i;
    if (!x) {
      puts("Unbounded");
      return false;
    }
    pivot(x, y);
  }
}
bool solve() {
  for (int i = 1; i <= n; i++) id[i] = i;
  while (true) {
    int x = 0, y = 0;
    for (int i = 1; i <= m; i++)
      if (a[i][0] < -EPS && (!x || rand() & 1)) x = i;
    if (!x) return simplex();
    for (int j = 1; j <= n; j++)
      if (a[x][j] < -EPS && (!y || rand() & 1)) y = j;
    if (!y) {
      puts("Infeasible");
      return false;
    }
    pivot(x, y);
  }
}
double ans[N];
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
    a[i][_a] = -1;
    a[i][_b] = 1;
  }
  T = 1;
  if (solve()) {
    if (!T) return 0;
    for (int i = 1; i <= m; i++) ans[id[n + i]] = a[i][0];
    for (int i = 1; i <= n; i++) printf("%d ", (int)ans[i]);
  }
  return 0;
}
