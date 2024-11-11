#include <bits/stdc++.h>
using namespace std;
const long double Pi = atan2(0, -1);
const int Maxn = 105;
int n;
struct Point {
  long double x, y;
  Point() {}
  Point(long double x, long double y) : x(x), y(y) {}
  Point operator+(const Point &rhs) const {
    return Point(x + rhs.x, y + rhs.y);
  }
  void rotate(long double ang) {
    static long double tx, ty;
    tx = x;
    ty = y;
    x = tx * cos(ang) - ty * sin(ang);
    y = tx * sin(ang) + ty * cos(ang);
  }
} p[Maxn], v;
long double getx(Point a, Point b) {
  return a.x - a.y * (b.x - a.x) / (b.y - a.y);
}
int main() {
  cin >> n;
  if (n <= 4) return puts("No solution"), 0;
  p[1] = Point(0, 0);
  v = Point(100, 0);
  long double len = 100;
  v.rotate(2 * Pi / n);
  for (int i = 2; i <= n; i++) {
    p[i] = p[i - 1] + v;
    v.rotate(2 * Pi / n);
    v.x *= (len + 0.01) / len;
    v.y *= (len + 0.01) / len;
    len += 0.01;
  }
  p[n] = Point(getx(p[n - 1], p[n]), 0);
  for (int i = 1; i <= n; i++)
    printf("%.4lf %.4lf\n", double(p[i].x), double(p[i].y));
  return 0;
}
