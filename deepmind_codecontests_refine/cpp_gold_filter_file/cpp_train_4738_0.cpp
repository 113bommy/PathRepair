#include <bits/stdc++.h>
const long double eps = 1e-6;
inline int dcmp(long double x) { return x < -eps ? -1 : x > eps; }
struct Point {
  long double x, y;
  Point() {}
  Point(long double _x, long double _y) : x(_x), y(_y) {}
  Point operator+(const Point &rhs) const {
    return Point(x + rhs.x, y + rhs.y);
  }
  Point operator-(const Point &rhs) const {
    return Point(x - rhs.x, y - rhs.y);
  }
  long double len() const { return hypot(x, y); }
  void read() { std::cin >> x >> y; }
};
long double det(const Point &a, const Point &b) {
  return a.x * b.y - a.y * b.x;
}
long double dot(const Point &a, const Point &b) {
  return a.x * b.x + a.y * b.y;
}
using Vec = Point;
using Poly = std::vector<Point>;
int n, m;
long double get_pos(Point a, Vec b, Point c, Vec d) {
  return det(d, a - c) / det(b, d);
}
long double solve(const Poly &poly, Point a, Vec b) {
  long double ret = 0.;
  std::vector<std::pair<long double, int>> vec;
  for (int i = 0; i < n; ++i) {
    int j = (i + 1) % n;
    Point c = poly[i];
    Vec d = poly[j] - poly[i];
    int f1 = dcmp(det(b, c - a));
    int f2 = dcmp(det(b, c + d - a));
    if (!f1 && !f2) continue;
    if (f1 > f2) {
      vec.emplace_back(get_pos(a, b, c, d), !f1 || !f2 ? +1 : +2);
    } else if (f1 < f2) {
      vec.emplace_back(get_pos(a, b, c, d), !f1 || !f2 ? -1 : -2);
    }
  }
  std::sort(vec.begin(), vec.end());
  int now = 0;
  for (int i = 0; i + 1 < vec.size(); ++i) {
    now += vec[i].second;
    if (now) {
      ret += vec[i + 1].first - vec[i].first;
    }
  }
  ret *= b.len();
  return ret;
}
int main() {
  std::cin >> n >> m;
  Poly poly(n);
  for (int i = 0; i < n; ++i) {
    poly[i].read();
  }
  for (int i = 0; i < m; ++i) {
    Point a, b;
    a.read();
    b.read();
    std::cout << std::setprecision(13) << solve(poly, a, b - a) << std::endl;
  }
}
