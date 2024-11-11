#include <bits/stdc++.h>
using namespace std;
struct Point {
  long double x, y;
  Point() {}
  Point(long double _, long double __) : x(_), y(__) {}
  friend istream &operator>>(istream &_, Point &p) { return _ >> p.x >> p.y; }
  friend Point operator+(const Point &p1, const Point &p2) {
    return Point(p1.x + p2.x, p1.y + p2.y);
  }
  friend Point operator-(const Point &p1, const Point &p2) {
    return Point(p1.x - p2.x, p1.y - p2.y);
  }
  friend long double Distance(const Point &p1, const Point &p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
  }
  friend long double Arctan2(const Point &p) { return atan2(p.y, p.x); }
} A, B, C;
struct Interval {
  long double l, r;
  Interval() {}
  Interval(long double _, long double __) : l(_), r(__) {}
  bool In_Interval(long double x) const { return x >= l && x <= r; }
  friend bool Intersect(const Interval &i1, const Interval &i2) {
    return i1.In_Interval(i2.l) || i1.In_Interval(i2.r) || i2.In_Interval(i1.l);
  }
};
struct Circle {
  Point o;
  long double r;
  Circle() {}
  Circle(const Point &_, const long double &__) : o(_), r(__) {}
  friend bool Seperated(const Circle &c1, const Circle &c2) {
    return Distance(c1.o, c2.o) > c1.r + c2.r + 1e-15;
  }
  friend bool Include(const Circle &c1, const Circle &c2) {
    return Distance(c1.o, c2.o) < fabs(c1.r - c2.r);
  }
  friend Interval Get_Intersection(const Circle &c1, const Circle &c2) {
    long double alpha = Arctan2(c2.o - c1.o);
    long double a = c1.r;
    long double b = Distance(c1.o, c2.o) - 1e-15;
    long double c = c2.r;
    long double delta = acos((a * a + b * b - c * c) / (2 * a * b));
    return Interval(alpha - delta, alpha + delta);
  }
};
long double t1, t2;
bool Check(const Circle &c1, const Circle &c2, const Circle &c3) {
  Interval i1 = Get_Intersection(c1, c2);
  Interval i2 = Get_Intersection(c1, c3);
  if (Intersect(i1, i2)) return true;
  return false;
}
bool Judge(long double mid) {
  Circle c1(A, mid);
  Circle c2(B, t1 - mid);
  Circle c3(C, t2 - Distance(B, C) - mid);
  if (Seperated(c1, c2) || Seperated(c1, c3) || Seperated(c2, c3)) return false;
  if (Include(c1, c2) || Include(c1, c3) || Include(c2, c3)) return true;
  return Check(c1, c2, c3) || Check(c2, c1, c3) || Check(c3, c1, c2);
}
long double Bisection() {
  long double l = 0, r = min(t1, t2 - Distance(B, C));
  while (r - l > 1e-15) {
    long double mid = (l + r) / 2;
    if (Judge(mid))
      l = mid;
    else
      r = mid;
  }
  return (l + r) / 2;
}
int main() {
  cin >> t2 >> t1 >> A >> B >> C;
  t1 += Distance(A, B);
  t2 += Distance(A, C);
  t2 += Distance(B, C);
  if (t1 >= Distance(A, C) + Distance(B, C))
    return cout << fixed << setprecision(10) << min(t1, t2) << endl, 0;
  cout << fixed << setprecision(10) << Bisection() << endl;
  return 0;
}
