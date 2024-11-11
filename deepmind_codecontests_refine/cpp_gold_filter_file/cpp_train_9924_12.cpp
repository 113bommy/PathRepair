#include <bits/stdc++.h>
using namespace std;
const int nn = 100005;
const double eps = 1e-10;
struct point {
  double x, y;
} a[nn], b[nn];
int n, m, t, l[nn], r[nn];
int h[nn], p[nn];
double R, c[nn];
inline double cp(const point &x, const point &y, const point &z) {
  return (x.x - z.x) * (y.y - z.y) - (x.y - z.y) * (y.x - z.x);
}
inline double dis(const point &x, const point &y) {
  return sqrt((x.x - y.x) * (x.x - y.x) + (x.y - y.y) * (x.y - y.y));
}
inline bool cmp(const point &x, const point &y) {
  double z = cp(x, y, a[1]);
  if (z > eps) return 1;
  if (z < -eps) return 0;
  return dis(x, a[1]) < dis(y, a[1]);
}
void init() {
  scanf("%d%lf", &n, &R);
  for (int i = 1; i <= n; ++i) {
    scanf("%lf%lf", &a[i].x, &a[i].y);
    if (a[i].y < a[1].y || (a[i].y < a[1].y + eps && a[i].x < a[1].x))
      swap(a[i], a[1]);
  }
  sort(a + 2, a + n + 1, cmp);
  b[m = 1] = a[1];
  for (int i = 2; i <= n; ++i) {
    for (; m > 1 && cp(a[i], b[m], b[m - 1]) > -eps; --m)
      ;
    b[++m] = a[i];
  }
}
inline void change(int x, int y) {
  swap(p[h[x]], p[h[y]]);
  swap(h[x], h[y]);
}
void up(int x) {
  for (; x > 1 && c[h[x]] > c[h[x >> 1]]; x >>= 1) change(x, x >> 1);
}
void down(int x) {
  for (int y = x << 1; y <= t; x = y, y = x << 1) {
    if (y < t && c[h[y]] < c[h[y + 1]]) ++y;
    if (c[h[x]] < c[h[y]])
      change(x, y);
    else
      break;
  }
}
inline void calc(int x) {
  point y = b[l[x]], z = b[r[x]];
  c[x] = dis(y, z) * dis(b[x], y) * dis(b[x], z) / (2 * abs(cp(y, z, b[x])));
  up(p[x]);
}
inline double count(int x, int y) {
  double z = 2 * asin(dis(b[x], b[y]) / (2 * R));
  return R * R / 2 * (z - sin(z));
}
void work() {
  for (int i = 1; i <= m; ++i) {
    h[i] = p[i] = i;
    l[i] = i - 1, r[i] = i + 1;
  }
  t = m;
  l[1] = m;
  r[m] = 1;
  for (int i = 1; i <= m; ++i) calc(i);
  while (c[h[1]] > R) {
    int i = h[1];
    l[r[i]] = l[i];
    r[l[i]] = r[i];
    change(1, t--);
    down(1);
    calc(l[i]);
    calc(r[i]);
  }
  int j = h[1];
  double s = count(j, l[j]) + count(j, r[j]);
  for (int i = r[j]; r[i] != j; i = r[i])
    s += abs(cp(b[i], b[r[i]], b[j])) / 2 + count(i, r[i]);
  printf("%.10lf\n", s);
}
int main() {
  init();
  work();
  return 0;
}
