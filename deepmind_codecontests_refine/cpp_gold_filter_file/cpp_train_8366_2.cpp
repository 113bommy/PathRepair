#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const double EPS = 1E-8;
bool zero(double x) { return -EPS < x && x < EPS; }
int sgn(double x) { return x > EPS ? 1 : (x < -EPS ? -1 : 0); }
class Point {
 public:
  double x, y;
  Point() {}
  Point(double x, double y) : x(x), y(y) {}
  void init() { scanf("%lf%lf", &x, &y); }
  void print() const { printf("Point(%lf %lf)\n", x, y); }
  bool operator<(const Point &rhs) const {
    return x < rhs.x - EPS || (zero(x - rhs.x) && y < rhs.y - EPS);
  }
  bool operator==(const Point &rhs) const {
    return zero(x - rhs.x) && zero(y - rhs.y);
  }
  Point operator-(const Point &rhs) const {
    return Point(x - rhs.x, y - rhs.y);
  }
  Point operator+(const Point &rhs) const {
    return Point(x + rhs.x, y + rhs.y);
  }
  Point operator*(const double scale) const {
    return Point(x * scale, y * scale);
  }
  Point operator/(const double scale) const {
    return Point(x / scale, y / scale);
  }
  double operator*(const Point &rhs) const { return x * rhs.y - rhs.x * y; }
  double operator^(const Point &rhs) const { return x * rhs.x + y * rhs.y; }
  Point rotate(double angle) const {
    Point p(sin(angle), cos(angle));
    return Point((*this) * p, (*this) ^ p);
  }
  double length2() const { return x * x + y * y; }
  double length() const { return sqrt(this->length2()); }
  Point trunc(const double scale) const {
    return (*this) / this->length() * scale;
  }
  double angle() const { return atan2(y, x); }
  Point perpendicular() const { return Point(-y, x); }
};
class Line {
 public:
  Point l1, l2;
  Line() {}
  Line(Point l1, Point l2) : l1(l1), l2(l2) {}
  void init() {
    l1.init();
    l2.init();
  }
  void print() const {
    printf("Line[(%lf %lf)--(%lf %lf)]\n", l1.x, l1.y, l2.x, l2.y);
  }
  bool cross(const Point &p) const { return zero((p - l2) * (l1 - l2)); }
  bool cross(const Line &rhs) const { return !this->parallel(rhs); }
  bool parallel(const Line &rhs) const {
    return zero((l1 - l2) * (rhs.l1 - rhs.l2));
  }
  Point intersection(const Line &rhs) const {
    return l1 + (l2 - l1) * (((l1 - rhs.l1) * (rhs.l1 - rhs.l2)) /
                             ((l1 - l2) * (rhs.l1 - rhs.l2)));
  }
  Point projection(const Point &p) const {
    return this->intersection(Line(p, p + (l1 - l2).perpendicular()));
  }
  double distance(const Point &p) const {
    return fabs((p - l1) * (l2 - l1)) / (l1 - l2).length();
  }
};
const int MAXN = 100;
int n;
Point point[MAXN];
vector<int> idx;
vector<double> angle;
Line getLine(const Point &u, const Point &v) {
  Point l1 = (u + v) / 2;
  return Line(l1, l1 + (u - v).perpendicular());
}
bool isValid(const Point &p) {
  angle = vector<double>(idx.size());
  for (int i = (0); i < ((int)angle.size()); i++) {
    angle[i] = (point[idx[i]] - p).angle();
  }
  sort(angle.begin(), angle.end());
  angle.push_back(angle.front() + PI * 2);
  for (int i = (1); i < ((int)angle.size()); i++) {
    if (angle[i] - angle[i - 1] > PI - EPS) {
      return false;
    }
  }
  return true;
}
int main() {
  scanf("%d", &n);
  for (int i = (0); i < (n); i++) {
    point[i].init();
  }
  double res = -1;
  for (int i = (0); i < (n); i++) {
    for (int j = (0); j < (n); j++) {
      if (i == j) continue;
      Line l1 = getLine(point[i], point[j]);
      for (int k = (j + 1); k < (n); k++) {
        if (i == k) continue;
        Line l2 = getLine(point[i], point[k]);
        if (!l1.cross(l2)) continue;
        Point p = l1.intersection(l2);
        double dist = 1E100;
        for (int l = (0); l < (n); l++) {
          double tmpdist = (p - point[l]).length2();
          if (dist > tmpdist + EPS) {
            dist = tmpdist;
            idx = vector<int>(1, l);
          } else if (tmpdist - EPS < dist) {
            idx.push_back(l);
          }
        }
        if (res < dist && isValid(p)) {
          res = dist;
        }
      }
    }
  }
  if (res < 0) {
    puts("-1");
  } else {
    printf("%.13lf\n", sqrt(res));
  }
  return 0;
}
