#include <bits/stdc++.h>
template <typename T>
inline bool MIN(T &a, const T &b) {
  return a > b ? a = b, 1 : 0;
}
template <typename T>
inline bool MAX(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}
using namespace std;
int n, l0;
struct Point {
  long double x, y;
  Point() {}
  Point(long double x, long double y) : x(x), y(y) {}
} A[100010];
Point operator+(Point a, Point b) { return Point(a.x + b.x, a.y + b.y); }
Point operator-(Point a, Point b) { return Point(a.x - b.x, a.y - b.y); }
Point operator*(Point a, long double b) { return Point(a.x * b, a.y * b); }
Point operator/(Point a, long double b) { return Point(a.x / b, a.y / b); }
long double length(Point a) { return sqrt(a.x * a.x + a.y * a.y); }
pair<long double, int> q[100010 << 1];
int vis[100010], S[100010];
int run(Point a, Point b, long double r1, long double r2, Point &c1,
        Point &c2) {
  if (r1 > r2) swap(a, b), swap(r1, r2);
  long double d = length(a - b);
  if (r1 + r2 < d + (1e-8) || d + r1 < r2 + (1e-8)) return 0;
  long double t = (r1 * r1 - r2 * r2 + d * d) / 2 / d;
  Point c = a + (b - a) / length(b - a) * t;
  t = sqrt(r1 * r1 - t * t);
  Point v = a - b;
  swap(v.x, v.y);
  v.x = -v.x;
  v = v / length(v);
  c1 = c + v * t, c2 = c - v * t;
  return 1;
}
int ok(long double mid) {
  int cnt_q = 0, cnt_S = 0;
  memset(vis, 0, sizeof(vis));
  for (int i = 1; i <= n; ++i) {
    Point a = A[i], b = Point(l0, 0);
    long double r1 = length(a - Point(-l0, 0)), r2 = mid;
    Point c1, c2;
    if (!run(a, b, r1, r2, c1, c2)) continue;
    q[++cnt_q] = make_pair(atan2(c1.y, c1.x - l0), i);
    q[++cnt_q] = make_pair(atan2(c2.y, c2.x - l0), i);
  }
  sort(q + 1, q + cnt_q + 1);
  for (int i = 1; i <= cnt_q; ++i) {
    if (!vis[q[i].second])
      vis[q[i].second] = 1, S[++cnt_S] = q[i].second;
    else {
      if (q[i].second != S[cnt_S]) return 1;
      --cnt_S;
    }
  }
  return 0;
}
int main() {
  scanf("%d%d", &n, &l0);
  for (int i = 1; i <= n; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    A[i] = Point(a, b);
  }
  long double l = 0, r = l0 * 2;
  for (int i = 0; i < 100; ++i) {
    long double mid = (l + r) / 2;
    if (ok(mid))
      r = mid;
    else
      l = mid;
  }
  printf("%.12lf\n", (double)l);
  return 0;
}
