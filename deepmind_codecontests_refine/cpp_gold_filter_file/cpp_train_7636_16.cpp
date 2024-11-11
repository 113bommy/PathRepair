#include <bits/stdc++.h>
using namespace std;
struct Point {
  double x, y;
} p[3], re[4];
double cross(const Point& a, const Point& b, const Point& c) {
  return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}
bool isIntersect(const Point& a, const Point& b, const Point& c,
                 const Point& d) {
  if (max(a.x, b.x) < min(c.x, d.x)) return false;
  if (max(a.y, b.y) < min(c.y, d.y)) return false;
  if (max(c.x, d.x) < min(a.x, b.x)) return false;
  if (max(c.y, d.y) < min(a.y, b.y)) return false;
  if (cross(a, c, b) * cross(a, b, d) <= 0) return false;
  if (cross(c, a, d) * cross(c, d, b) <= 0) return false;
  return true;
}
Point symmetry(const Point& a, const Point& b) {
  Point t;
  t.x = a.x * 2 - b.x;
  t.y = a.y * 2 - b.y;
  return t;
}
Point circumcircle(const Point& a, const Point& b, const Point& c) {
  Point now;
  double a1 = b.x - a.x, b1 = b.y - a.y, c1 = (a1 * a1 + b1 * b1) / 2;
  double a2 = c.x - a.x, b2 = c.y - a.y, c2 = (a2 * a2 + b2 * b2) / 2;
  double d = a1 * b2 - a2 * b1;
  now.x = a.x + (c1 * b2 - c2 * b1) / d;
  now.y = a.y + (a1 * c2 - a2 * c1) / d;
  return now;
}
bool go(const Point& a, const Point& b, const Point& c) {
  if (fabs(cross(a, b, c)) < 1e-7) return false;
  Point bb = symmetry(a, b);
  re[0] = circumcircle(a, bb, c);
  re[1] = symmetry(a, re[0]);
  re[2] = symmetry(b, re[1]);
  re[3] = symmetry(c, re[0]);
  return isIntersect(re[0], re[2], re[1], re[3]);
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    for (int i = 0; i < 3; ++i) scanf("%lf%lf", &p[i].x, &p[i].y);
    if (go(p[0], p[1], p[2]) || go(p[1], p[0], p[2]) || go(p[0], p[2], p[1]) ||
        go(p[2], p[0], p[1]) || go(p[1], p[2], p[0]) || go(p[2], p[1], p[0])) {
      puts("YES");
      for (int i = 0; i < 4; ++i) printf("%.9f %.9f ", re[i].x, re[i].y);
      puts("");
    } else
      puts("NO\n");
  }
  return 0;
}
