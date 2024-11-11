#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
bool _isZero(double o) { return fabs(o) < 1e-8; }
int sign(double x, double eps = 1e-8) { return (x < 0 ? -1 : x > 0); }
struct Point {
  double x, y;
  void input() {
    double a, b, c, d, l;
    scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
    x = a / b;
    y = c / d;
    l = x * x + y * y;
    x = x / l;
    y = y / l;
  }
  Point(double x = 0, double y = 0) : x(x), y(y) {}
  bool operator<(Point const& o) const {
    if (sign(o.x - x) == 0) {
      return sign(o.y - y) < 0;
    } else {
      return sign(o.x - x) < 0;
    }
  }
  bool operator==(Point const& o) const {
    return sign(x - o.x) == 0 && sign(y - o.y) == 0;
  }
  Point operator+(Point const& o) const { return Point(x + o.x, y + o.y); }
  Point operator-(Point const& o) const { return Point(x - o.x, y - o.y); }
  Point operator/(double o) const { return Point(x / o, y / o); }
  Point init() {
    double _x = x, _y = y;
    double l = sqrt(_x * _x + _y * _y);
    if (sign(_x) < 0) {
      _x = -_x;
      _y = -_y;
    } else if (sign(_x) == 0 && sign(_y) < 0) {
      _y = -_y;
    }
    return Point(_x / l, _y / l);
  }
  void output() { printf("%lf %lf\n", x, y); }
} point[1111];
struct Pair {
  Point mid;
  Point vec;
  Pair(Point mid, Point vec) : mid(mid), vec(vec) {}
  bool operator<(Pair const& o) const {
    if (o.mid == mid) {
      return o.vec < vec;
    } else {
      return o.mid < mid;
    }
  }
};
map<Pair, int> m;
map<Pair, int>::iterator mi, mj;
Pair makePair(Point& a, Point& b) { return Pair((a + b) / 2, (a - b).init()); }
int main() {
  int n, i, j;
  long long ans, sum, cnt;
  while (~scanf("%d", &n)) {
    m.clear();
    for (i = 0; i < n; i++) {
      point[i].input();
    }
    for (i = 0; i < n; i++) {
      for (j = i + 1; j < n; j++) {
        m[makePair(point[i], point[j])]++;
      }
    }
    ans = 0;
    for (mi = m.begin(); mi != m.end(); mi = mj) {
      sum = 1, cnt = 0;
      for (mj = mi; mj != m.end() && mi->first.mid == mj->first.mid; mj++) {
        sum = sum * (mj->second + 1) % mod;
        cnt = (cnt + mj->second) % mod;
      }
      ans = (ans + sum - cnt - 1) % mod;
    }
    printf("%lld\n", (ans + mod) % mod);
  }
  return 0;
}
