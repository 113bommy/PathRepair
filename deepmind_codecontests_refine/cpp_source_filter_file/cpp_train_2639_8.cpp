#include <bits/stdc++.h>
using namespace std;
const long double PI = 3.14159265358979323846, EPS = 1e-8;
struct Point {
  long double x, y;
  Point() : x(0), y(0) {}
  Point(long double x, long double y) : x(x), y(y) {}
};
struct Line {
  long double a, b, c;
  Line() : a(0), b(0), c(0) {}
  Line(long double a, long double b, long double c) : a(a), b(b), c(c) {}
  Line(Point p1, Point p2) {
    a = p1.y - p2.y;
    b = p2.x - p1.x;
    c = a * p1.x + b * p1.y;
  }
};
Point intersect(Line l1, Line l2) {
  return Point((l1.c * l2.b - l2.c * l1.b) / (l1.a * l2.b - l2.a * l1.b),
               (l1.c * l2.a - l2.c * l1.a) / (l1.b * l2.a - l2.b * l1.a));
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  Point a, b, c;
  cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
  Line l1(a, b), l2(b, c);
  Line m(-l1.b, l1.a, -l1.b * (a.x + b.x) / 2 + l1.a * (a.y + b.y) / 2),
      n(-l2.b, l2.a, -l2.b * (b.x + c.x) / 2 + l2.a * (b.y + c.y) / 2);
  Point o = intersect(m, n);
  long double r = hypot(o.x - a.x, o.y - a.y);
  long double ang1 = atan2(a.y - o.y, a.x - o.x),
              ang2 = atan2(b.y - o.y, b.x - o.x),
              ang3 = atan2(c.y - o.y, c.x - o.x);
  for (int i = 3; i < 101; ++i) {
    long double a1 = (ang2 - ang1) * i / (2 * PI);
    long double a2 = (ang3 - ang1) * i / (2 * PI);
    if (fabs(a1 - round(a1)) < EPS && fabs(a2 - round(a2)) < EPS)
      return cout << fixed << setprecision(10)
                  << (i * r * r * sin((long double)2 * PI / i) / 2) << "\n",
             0;
  }
  cout << "0\n";
  return 0;
}
