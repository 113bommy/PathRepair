#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-10;
struct Point {
  double x, y;
  Point() {}
  Point(double x, double y) : x(x), y(y) {}
  void Input() { scanf("%lf%lf", &x, &y); }
} p[105];
bool operator!=(const Point &x, const Point &y) {
  return fabs(x.x - y.x) > eps || fabs(x.y - y.y) > eps;
}
Point operator+(const Point &x, const Point &y) {
  return Point(x.x + y.x, x.y + y.y);
}
Point operator-(const Point &x, const Point &y) {
  return Point(x.x - y.x, x.y - y.y);
}
Point operator*(const Point &x, const double &y) {
  return Point(x.x * y, x.y * y);
}
Point operator/(const Point &x, const double &y) {
  return Point(x.x / y, x.y / y);
}
double Cross(Point a, Point b) { return a.x * b.y - a.y * b.x; }
double Dot(Point a, Point b) { return a.x * b.x + a.y * b.y; }
double Len(Point a) { return sqrt(Dot(a, a)); }
Point GetCross(Point x, Point vx, Point y, Point vy) {
  Point v = x - y;
  double t = Cross(vy, v) / Cross(vx, vy);
  return x + vx * t;
}
int n;
bool Check(Point a, double r) {
  for (int i = 1; i <= n; ++i)
    if (Len(a - p[i]) < r) return 0;
  return 1;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) p[i].Input();
  double ans = -1;
  for (int a = 1; a <= n; ++a)
    for (int b = a + 1; b <= n; ++b)
      for (int c = 1; c <= n; ++c)
        if (c != a && c != b)
          for (int d = c + 1; d <= n; ++d)
            if (d != a && d != b) {
              Point x = (p[a] + p[b]) / 2, y = (p[c] + p[d]) / 2;
              if (x != y || fabs(Cross(p[a] - p[b], p[a] - p[c])) < eps)
                continue;
              if (Check(x, Len(x - p[a]))) ans = max(ans, Len(x - p[a]));
            }
  for (int a = 1; a <= n; ++a)
    for (int b = a + 1; b <= n; ++b)
      for (int c = b + 1; c <= n; ++c)
        if (Dot(p[b] - p[a], p[c] - p[a]) > eps &&
            Dot(p[a] - p[b], p[c] - p[b]) > eps &&
            Dot(p[a] - p[c], p[b] - p[c]) > eps) {
          Point x = (p[a] + p[b]) / 2, vx = x - p[a];
          Point y = (p[b] + p[c]) / 2, vy = y - p[b];
          vx = Point(vx.y, -vx.x), vy = Point(vy.y, -vy.x);
          Point o = GetCross(x, vx, y, vy);
          if (Check(o, Len(o - p[a]))) ans = max(ans, Len(o - p[a]));
        }
  if (ans < 0)
    puts("-1");
  else
    printf("%.20f\n", ans);
  return 0;
}
