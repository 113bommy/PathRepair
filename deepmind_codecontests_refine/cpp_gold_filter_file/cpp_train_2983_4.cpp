#include <bits/stdc++.h>
using namespace std;
inline double sq(double x) { return x * x; };
const double eps = 1e-5;
struct Point {
  double x, y;
  Point(double x = 0, double y = 0) : x(x), y(y) {}
  Point &operator=(Point oth) {
    x = oth.x, y = oth.y;
    return *this;
  }
  bool operator==(Point oth) const {
    return abs(x - oth.x) < eps and abs(y - oth.y) < eps;
  }
  Point operator+(Point oth) { return Point(x + oth.x, y + oth.y); }
  Point operator-(Point oth) { return Point(x - oth.x, y - oth.y); }
  Point operator*(double k) { return Point(x * k, y * k); }
  Point operator/(double k) { return Point(x / k, y / k); }
  Point rotate(double theta) {
    return Point(x * cos(theta) - y * sin(theta),
                 x * sin(theta) + y * cos(theta));
  }
  bool operator<(Point oth) const {
    return abs(x - oth.x) < eps ? y < oth.y : x < oth.x;
  }
  double disSquare() { return sq(x) + sq(y); }
};
struct Circle {
  double r;
  Point cent;
  Circle(Point a, double r) : cent(a), r(r) {}
  vector<Point> intersection(Circle oth) {
    if (oth.cent == cent) return assert(oth.r != r), vector<Point>{};
    double d = sqrt((cent - oth.cent).disSquare());
    if (abs(oth.r - r) - d > eps) return {};
    if (d - r - oth.r > eps) return {};
    auto V = oth.cent - cent;
    V = V / sqrt(V.disSquare()) * r;
    if (d - r - oth.r > -eps) return {cent + V};
    double theta = acos((sq(r) + sq(d) - sq(oth.r)) / 2 / r / d);
    if (abs(theta) < eps) return {cent + V};
    return {cent + V.rotate(theta), cent + V.rotate(-theta)};
  }
};
class Solution {
  vector<Circle> Hand;

 public:
  void run(istream &in, ostream &out) {
    int n;
    in >> n;
    for (int i = 0; i < n; ++i) {
      int x, y, r;
      in >> x >> y >> r;
      Hand.emplace_back(Point(x, y), r);
    }
    int V = 0, E = 0, nonInter = 0;
    vector<Point> intersectionPool;
    for (int i = 0; i < n; ++i) {
      vector<Point> twoCirXs;
      for (int j = 0; j < n; ++j)
        if (i != j) {
          for (auto xs : Hand[i].intersection(Hand[j])) {
            twoCirXs.push_back(xs);
          }
        }
      if (twoCirXs.size() == 0) {
        ++nonInter;
        continue;
      }
      sort(twoCirXs.begin(), twoCirXs.end());
      twoCirXs.resize(unique(twoCirXs.begin(), twoCirXs.end()) -
                      twoCirXs.begin());
      E += (int)twoCirXs.size();
      intersectionPool.insert(intersectionPool.end(), twoCirXs.begin(),
                              twoCirXs.end());
    }
    sort(intersectionPool.begin(), intersectionPool.end());
    intersectionPool.resize(
        unique(intersectionPool.begin(), intersectionPool.end()) -
        intersectionPool.begin());
    V = intersectionPool.size();
    if (V == 0)
      out << 1 + nonInter << '\n';
    else
      out << E + 2 - V + nonInter << '\n';
  }
};
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  Solution().run(cin, cout);
};
