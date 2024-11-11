#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-10;
inline int sgn(const double &x) { return (x > eps) - (x < -eps); }
struct Point {
  double x, y;
  Point(double x = 0.0, double y = 0.0) : x(x), y(y) {}
  Point operator+(const Point &t) const { return Point(x + t.x, y + t.y); }
  Point operator-(const Point &t) const { return Point(x - t.x, y - t.y); }
  bool operator<(const Point &t) const {
    return sgn(x - t.x) == 0 ? sgn(y - t.y) < 0 : x < t.x;
  }
  bool operator>(const Point &t) const { return t < *this; }
  bool operator==(const Point &t) const { return !(t < *this) && !(*this < t); }
};
double angle(Point A) { return atan2(A.y, A.x); }
double Length(Point A) { return sqrt(A.x * A.x + A.y * A.y); }
struct Circle {
  Point c;
  double r;
  Circle(Point c, double r) : c(c), r(r) {}
  Circle() {}
  Point point(double rad) {
    return Point(c.x + cos(rad) * r, c.y + sin(rad) * r);
  }
};
int GetCircleCircleIntersection(Circle C1, Circle C2, vector<Point> &sol) {
  double d = Length(C1.c - C2.c);
  if (sgn(d) == 0) {
    if (sgn(C1.r - C2.r) == 0) return -1;
    return 0;
  }
  if (sgn(C1.r + C2.r - d) < 0) return 0;
  if (sgn(fabs(C1.r - C2.r) - d) > 0) return 0;
  double a = angle(C2.c - C1.c);
  double da = acos((C1.r * C1.r + d * d - C2.r * C2.r) / (2 * C1.r * d));
  Point p1 = C1.point(a - da), p2 = C1.point(a + da);
  sol.push_back(p1);
  if (p1 == p2) return 1;
  sol.push_back(p2);
  return 2;
}
set<Point> cp[4];
set<Point> ps;
int n, f[5];
Circle c[4];
int sf(int x) { return x == f[x] ? x : sf(f[x]); }
int main() {
  cin >> n;
  for (int i = 0, x, y, r; i < n; i++) {
    f[i] = i;
    cin >> x >> y >> r;
    c[i] = Circle(Point(x, y), r);
  }
  for (int i = 0; i < n; i++) {
    vector<Point> s;
    for (int j = i + 1; j < n; j++) {
      s.clear();
      GetCircleCircleIntersection(c[i], c[j], s);
      for (int k = 0; k < s.size(); k++) {
        f[i] = sf(j);
        ps.insert(s[k]);
        cp[i].insert(s[k]);
        cp[j].insert(s[k]);
      }
    }
  }
  int P = 0, F;
  for (int i = 0; i < n; i++)
    if (i == sf(i)) P++;
  int E = 0, V = 0;
  for (int i = 0; i < n; i++) {
    E += cp[i].size();
  }
  V = ps.size();
  cout << (F = E - V + P + 1) << endl;
  return 0;
}
