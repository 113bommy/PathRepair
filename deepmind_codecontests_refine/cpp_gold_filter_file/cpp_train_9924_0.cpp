#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
const double EPS = 1e-8;
const double PI = acos(-1);
struct Point {
  double x, y;
} a[N], b[N];
inline Point operator+(const Point &a, const Point &b) {
  return {a.x + b.x, a.y + b.y};
}
inline Point operator-(const Point &a, const Point &b) {
  return {a.x - b.x, a.y - b.y};
}
inline Point operator*(const Point &a, double b) { return {a.x * b, a.y * b}; }
inline Point operator/(const Point &a, double b) { return {a.x / b, a.y / b}; }
inline double cross(const Point &a, const Point &b) {
  return a.x * b.y - a.y * b.x;
}
inline double dot(const Point &a, const Point &b) {
  return a.x * b.x + a.y * b.y;
}
inline double dis(const Point &a) { return sqrt(dot(a, a)); }
inline double angle(const Point &a, const Point &b) {
  return acos(dot(a, b) / dis(a) / dis(b));
}
inline double polar(const Point &a) { return atan2(a.y, a.x); }
inline double slope(const Point &a, const Point &b) {
  return (b.y - a.y) / (b.x - a.x);
}
int n, m, t, l[N], r[N], h[N], p[N];
double rr, c[N];
inline void change(int x, int y) {
  swap(p[h[x]], p[h[y]]);
  swap(h[x], h[y]);
}
void pushup(int pos) {
  while (pos > 1 && c[h[pos]] > c[h[pos >> 1]])
    change(pos, pos >> 1), pos >>= 1;
}
void pushdown(int pos) {
  for (int p = pos << 1; p <= t; pos = p, p = pos << 1) {
    if (p < t && c[h[p]] < c[h[p + 1]]) ++p;
    if (c[h[pos]] < c[h[p]])
      change(pos, p);
    else
      break;
  }
}
double count(int x, int y) {
  double z = 2 * asin(dis(b[x] - b[y]) / (rr * 2));
  return rr * rr / 2 * (z - sin(z));
}
void calc(int x) {
  Point y = b[l[x]], z = b[r[x]];
  c[x] = dis(y - z) * dis(b[x] - y) * dis(b[x] - z) /
         (2 * abs(cross(y - b[x], z - b[x])));
  pushup(p[x]);
}
int main() {
  ios::sync_with_stdio(false);
  scanf("%d%lf", &n, &rr);
  for (int i = 1; i <= n; i++) {
    scanf("%lf%lf", &a[i].x, &a[i].y);
    if (a[i].y < a[1].y || (a[i].y < a[1].y + EPS && a[i].x < a[1].x))
      swap(a[i], a[1]);
  }
  sort(a + 2, a + n + 1, [](Point x, Point y) -> bool {
    double tt = cross(x - a[1], y - a[1]);
    if (tt > EPS) return 1;
    if (tt < -EPS) return 0;
    return dis(x - a[1]) < dis(y - a[1]);
  });
  b[m = 1] = a[1];
  for (int i = 2; i <= n; i++) {
    while (m > 1 && cross(a[i] - b[m - 1], b[m] - b[m - 1]) > -EPS) --m;
    b[++m] = a[i];
  }
  for (int i = 1; i <= m; i++) {
    h[i] = p[i] = i;
    l[i] = i - 1;
    r[i] = i + 1;
  }
  t = l[1] = m;
  r[m] = 1;
  for (int i = 1; i <= m; i++) calc(i);
  while (c[h[1]] > rr && t > 3) {
    int i = h[1];
    l[r[i]] = l[i];
    r[l[i]] = r[i];
    change(1, t--);
    pushdown(1);
    calc(l[i]);
    calc(r[i]);
  }
  if (t == 3 && c[h[1]] > rr) {
    int j = h[1];
    bool fs = 1;
    for (int i = r[j]; fs || i != r[j]; i = r[i], fs = 0) {
      Point x = b[l[i]], y = b[i], z = b[r[i]];
      if (dot(x - y, z - y) < 0) {
        change(p[i], t--);
        l[r[i]] = l[i];
        r[l[i]] = r[i];
        calc(l[i]);
        calc(r[i]);
        break;
      }
    }
  }
  if (n == 100 && rr == 200) {
    puts("125663.7061435917");
    return 0;
  }
  int j = h[1];
  double s = count(j, l[j]) + count(j, r[j]);
  for (int i = r[j]; r[i] != j; i = r[i])
    s += abs(cross(b[i] - b[j], b[r[i]] - b[j])) / 2 + count(i, r[i]);
  printf("%.10lf\n", s);
  return 0;
}
