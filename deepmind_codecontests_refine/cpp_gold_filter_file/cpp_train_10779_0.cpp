#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8, inf = 1e5;
inline int read() {
  int ans = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') f = ch == '-' ? -1 : f, ch = getchar();
  while (ch >= '0' && ch <= '9')
    ans = (ans << 1) + (ans << 3) + ch - '0', ch = getchar();
  return ans * f;
}
inline int sgn(double x) {
  if (fabs(x) < eps) return 0;
  if (x > eps) return 1;
  return -1;
}
struct pot {
  double x, y;
  pot() {}
  pot(double _x, double _y) : x(_x), y(_y) {}
  inline friend pot operator+(const pot &a, const pot &b) {
    return (pot){a.x + b.x, a.y + b.y};
  }
  inline friend pot operator-(const pot &a, const pot &b) {
    return (pot){a.x - b.x, a.y - b.y};
  }
  inline friend double operator*(const pot &a, const pot &b) {
    return a.x * b.y - a.y * b.x;
  }
  inline friend bool operator==(const pot &a, const pot &b) {
    return !sgn(a.x - b.x) && !sgn(a.y - b.y);
  }
  inline friend double operator&(const pot &a, const pot &b) {
    return a.x * b.x + a.y * b.y;
  }
  inline friend pot operator/(const pot &a, double t) {
    return (pot){a.x / t, a.y / t};
  }
  inline friend pot operator*(const pot &a, double t) {
    return (pot){a.x * t, a.y * t};
  }
  inline double norm() { return sqrt(x * x + y * y); }
};
struct vec {
  pot a, b;
};
pot p[310];
vec t[610];
vec h[310];
int n, m, k, m1, k1;
int cnt, last;
int q[610], id[610];
pot g[610], ans[2];
inline bool onsegment(const pot &a, const pot &b, const pot &c) {
  if (sgn((b - a) * (c - a))) return 0;
  if (sgn(a.x - b.x) * sgn(a.x - c.x) > 0 ||
      sgn(a.y - b.y) * sgn(a.y - c.y) > 0)
    return 0;
  return 1;
}
inline pot cross(const vec &a, const vec &b) {
  pot da = a.b - a.a, db = b.b - b.a, dc = b.a - a.a;
  if (!sgn(da * db)) {
    if (sgn(da.x) == sgn(db.x))
      return (pot){inf, 1};
    else
      return (pot){inf, -1};
  }
  double t = (db * dc) / (db * da);
  return a.a + (da * t);
}
inline bool cmp(int x, int y) {
  double t1 = atan2((t[x].b - t[x].a).y, (t[x].b - t[x].a).x),
         t2 = atan2((t[y].b - t[y].a).y, (t[y].b - t[y].a).x);
  if (fabs(t1 - t2) > eps) return t1 < t2;
  return (t[x].b - t[x].a) * (t[y].a - t[x].a) < -eps;
}
inline double planemeet(int cas) {
  for (int i = 0; i < cnt; i++) id[i] = i;
  m = 0, k = 0;
  q[++m] = id[0];
  m1 = 1, k1 = 1;
  for (int i = 1; i < cnt; i++) {
    int v = id[i];
    while (k1 <= k && (t[v].b - t[v].a) * (g[k] - t[v].a) <= 0) m--, k--;
    while (k1 <= k && (t[v].b - t[v].a) * (g[k1] - t[v].a) <= 0) m1++, k1++;
    g[++k] = cross(t[q[m]], t[v]);
    if (fabs(g[k].x - inf) < eps) {
      if (g[k].y == -1) return 0;
      k--;
      continue;
    }
    q[++m] = v;
  }
  while (k1 < k && (t[q[m1]].b - t[q[m1]].a) * (g[k] - t[q[m1]].a) <= 0)
    m--, k--;
  if (k1 == k) return 0;
  ans[cas] = g[k];
  return 1;
}
bool check(int dl, int dr, int cas) {
  if (dl == dr) {
    ans[cas] = p[dr];
    return 1;
  }
  if ((p[dl + 1] - p[dl]) * (p[dr + 1] - p[dr]) <= 0) return 0;
  if (dl > dr) dr += n;
  cnt = 0;
  for (int i = dl; i <= dr; i++) t[cnt++] = h[i % n];
  for (int i = dl; i <= dr; i++) t[cnt++] = (vec){p[i % n], p[(i + 1) % n]};
  return planemeet(cas);
}
bool check(double x) {
  last = 2;
  ans[0] = p[2];
  for (int i = 0; i <= n; i++) {
    pot da = p[i + 1] - p[i], fa = (pot){-da.y, da.x};
    fa = fa / fa.norm() * x;
    h[i] = (vec){p[i + 1] + fa, p[i] + fa};
  }
  for (int i = 1; i <= n; i++) {
    while (i != last + 1 && check(i, last + 1, 0)) last = (last + 1) % n;
    if (check(last + 1, i - 1, 1)) return 1;
  }
  return 0;
}
int main() {
  n = read();
  for (int i = 1; i <= n; i++) p[i].x = read(), p[i].y = read();
  p[0] = p[n];
  p[n + 1] = p[1];
  double l = 0, r = inf;
  while (sgn(r - l)) {
    double mid = (l + r) / 2;
    if (check(mid))
      r = mid;
    else
      l = mid;
  }
  printf("%.10f\n", r);
  check(r);
  printf("%.10f %.10f\n", ans[0].x, ans[0].y);
  printf("%.10f %.10f\n", ans[1].x, ans[1].y);
}
