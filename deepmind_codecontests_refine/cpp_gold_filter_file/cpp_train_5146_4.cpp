#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:256000000")
using namespace std;
const int M = 100500;
const long double EPS = 1e-7;
int n;
long double A, B, C;
int m, u, d;
int px[M], py[M];
int upper[M], lower[M];
int ux[M], lx[M];
inline long double f(const long double x, const long double y) {
  return n * x * x + n * y * y + A * x + B * y + C;
}
void read_points() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    A += -2.0 * x;
    B += -2.0 * y;
    C += 1.0 * x * x + 1.0 * y * y;
  }
}
void read_polygon() {
  scanf("%d", &m);
  int left = 0, right = 0;
  for (int i = 0; i < m; ++i) {
    scanf("%d %d", px + i, py + i);
    if (px[left] > px[i]) left = i;
    if (px[right] < px[i]) right = i;
  }
  for (int i = right;; i = (i == m - 1 ? 0 : i + 1)) {
    lower[d] = i;
    lx[d] = px[i];
    ++d;
    if (i == left) break;
  }
  for (int i = left;; i = (i == m - 1 ? 0 : i + 1)) {
    upper[u] = i;
    ux[u] = px[i];
    ++u;
    if (i == right) break;
  }
  reverse(lower, lower + d);
  reverse(lx, lx + d);
}
inline void set_bounds(const long double x, long double& ly, long double& ry) {
  const int ri = upper_bound(lx, lx + d, x) - 1 - lx;
  const int i = lower[ri];
  const int ni = lower[ri + 1];
  const int rj = upper_bound(ux, ux + u, x) - 1 - ux;
  const int j = upper[rj];
  const int nj = upper[rj + 1];
  ly = py[i] + (x - px[i]) / (px[ni] - px[i]) * (py[ni] - py[i]);
  ry = py[j] + (x - px[j]) / (px[nj] - px[j]) * (py[nj] - py[j]);
}
inline long double ternary(const long double x) {
  long double l, r;
  set_bounds(x, l, r);
  while (r - l > EPS) {
    const long double m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
    if (m1 == l || m2 == r || m1 == m2) break;
    if (f(x, m1) < f(x, m2))
      r = m2;
    else
      l = m1;
  }
  return f(x, r);
}
long double ternary() {
  long double l = px[lower[0]], r = px[lower[d - 1]];
  while (r - l > EPS) {
    const long double m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
    if (m1 == l || m2 == r || m1 == m2) break;
    if (ternary(m1) < ternary(m2))
      r = m2;
    else
      l = m1;
  }
  return ternary(r);
}
int main() {
  read_points();
  read_polygon();
  printf("%.5lf\n", (double)ternary());
  return 0;
}
