#include <bits/stdc++.h>
using namespace std;
const long double EPS = 1e-14;
inline int sign(long double x) { return (abs(x) < EPS ? 0 : (x > 0 ? 1 : -1)); }
inline long double ldabs(long double x) { return (x >= 0 ? x : -x); }
inline long double ldmax(long double a, long double b) {
  return (a > b ? a : b);
}
inline long double ldmin(long double a, long double b) {
  return (a < b ? a : b);
}
class Point {
 public:
  long double x, y;
  Point(long double i, long double j) : x(i), y(j) {}
  Point() {}
  friend inline long double get_distance2(const Point &A, const Point &B) {
    return ((A - B) * (A - B));
  }
  friend inline long double get_distance(const Point &A, const Point &B) {
    return sqrt(get_distance2(A, B));
  }
  friend Point operator-(const Point &A, const Point &B) {
    return Point(A.x - B.x, A.y - B.y);
  }
  friend long double operator*(const Point &A, const Point &B) {
    return (A.x * B.x + A.y * B.y);
  }
  friend long double operator^(const Point &A, const Point &B) {
    return (A.x * B.y - B.x * A.y);
  }
  friend bool operator==(const Point &A, const Point &B) {
    return (sign(A.x - B.x) == 0 && sign(A.y - B.y) == 0);
  }
};
class Circle {
 public:
  Point center;
  long double radius;
  Circle(const Point &P, long double r) : center(P), radius(r) {}
  Circle() {}
};
long double solve();
bool check();
bool have_intersection(const Circle &A, const Circle &B, const Circle &C);
bool is_on_circle(const Point &P, const Circle &C);
bool is_in_circle(const Point &P, const Circle &C);
bool is_separated(const Circle &C1, const Circle &C2);
bool is_included(const Circle &C1, const Circle &C2);
int get_intersection(const Circle &C1, const Circle &C2, vector<Point> &inters);
long double t1, t2;
Point cinema, house, shop;
Circle circles[3];
int main() {
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  while (cin >> t1 >> t2 >> cinema.x >> cinema.y >> house.x >> house.y >>
         shop.x >> shop.y) {
    long double res = solve();
    cout << res << endl;
  }
  return 0;
}
long double solve() {
  Point &A = cinema, &B = house, &C = shop;
  long double ac = get_distance(A, C);
  long double cb = get_distance(C, B);
  long double ab = get_distance(A, B);
  long double d1 = ac + cb;
  long double d2 = ab;
  if (d2 + t2 >= d1) {
    return ldmin(d1 + t1, d2 + t2);
  }
  long double left = 0, right = ldmin(d1 + t1 - cb, d2 + t2);
  for (int i = 1; i <= 100; i++) {
    long double mid = (left + right) / 2;
    circles[0] = Circle(A, mid);
    circles[2] = Circle(B, d2 + t2 - mid);
    circles[1] = Circle(C, d1 - cb + t1 - mid);
    if (check())
      left = mid;
    else
      right = mid;
  }
  return left;
}
bool check() {
  for (int i = 0; i < 3; i++) {
    int j = (i + 1) % 3;
    if (is_separated(circles[i], circles[j])) return false;
  }
  for (int i = 0; i < 3; i++) {
    int j = (i + 1) % 3;
    if (is_included(circles[i], circles[j])) return true;
  }
  for (int i = 0; i < 3; i++) {
    int j = (i + 1) % 3;
    int k = (i + 2) % 3;
    if (have_intersection(circles[i], circles[j], circles[k])) return true;
  }
  return false;
}
bool have_intersection(const Circle &A, const Circle &B, const Circle &C) {
  vector<Point> inters;
  int cnt = get_intersection(A, B, inters);
  if (cnt == 1) {
    Point &P = inters[0];
    if (is_in_circle(P, A) && is_in_circle(P, B) && is_in_circle(P, C))
      return true;
    return false;
  }
  Point &P1 = inters[0], &P2 = inters[1];
  if (is_in_circle(P1, A) && is_in_circle(P1, B) && is_in_circle(P1, C))
    return true;
  if (is_in_circle(P2, A) && is_in_circle(P2, B) && is_in_circle(P2, C))
    return true;
  return false;
}
inline bool is_on_circle(const Point &P, const Circle &C) {
  return (sign(get_distance2(P, C.center) - C.radius * C.radius) == 0);
}
inline bool is_in_circle(const Point &P, const Circle &C) {
  return (sign(get_distance2(P, C.center) - C.radius * C.radius) <= 0);
}
inline bool is_separated(const Circle &C1, const Circle &C2) {
  long double d = get_distance(C1.center, C2.center);
  return (sign((C1.radius + C2.radius) - d) < 0);
}
inline bool is_included(const Circle &C1, const Circle &C2) {
  long double d = get_distance(C1.center, C2.center);
  return (sign(ldabs(C1.radius - C2.radius) - d) > 0);
}
int get_intersection(const Circle &C1, const Circle &C2,
                     vector<Point> &inters) {
  if (is_separated(C1, C2)) return 0;
  if (is_included(C1, C2)) return -1;
  inters.clear();
  long double r1 = C1.radius, r2 = C2.radius;
  long double x1 = C1.center.x, y1 = C1.center.y;
  long double x2 = C2.center.x, y2 = C2.center.y;
  long double d = get_distance(C1.center, C2.center);
  long double sqr_d = (C1.center - C2.center) * (C1.center - C2.center);
  long double a = 2 * r1 * (x1 - x2), b = 2 * r1 * (y1 - y2),
              c = r2 * r2 - r1 * r1 - sqr_d;
  long double A = a * a + b * b, B = -2 * a * c, C = c * c - b * b;
  if (sign((r1 + r2) - d) == 0 || sign(abs(r1 - r2) - d) == 0) {
    long double sumx = -B / A;
    long double cosa = sumx / 2, sina = sqrt(1 - cosa * cosa);
    Point P(x1 + r1 * cosa, y1 + r1 * sina);
    if (!is_on_circle(P, C2)) P.y = y1 - r1 * sina;
    inters.push_back(P);
    return 1;
  }
  long double delta = sqrt(B * B - 4 * A * C);
  long double cosa = (-B + delta) / A / 2, cosb = (-B - delta) / A / 2;
  long double sina = sqrt(1 - cosa * cosa), sinb = sqrt(1 - cosb * cosb);
  Point P1(x1 + r1 * cosa, y1 + r1 * sina);
  if (!is_on_circle(P1, C2)) P1.y = y1 - r1 * sina;
  Point P2(x1 + r1 * cosb, y1 + r1 * sinb);
  if (!is_on_circle(P2, C2) || P1 == P2) P2.y = y1 - r1 * sinb;
  inters.push_back(P1);
  inters.push_back(P2);
  return 2;
}
