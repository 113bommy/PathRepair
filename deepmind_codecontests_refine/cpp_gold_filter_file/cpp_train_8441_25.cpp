#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
struct Point {
  long long x, y;
  double angle;
  Point() {}
  Point(long long x, long long y) : x(x), y(y) {}
  Point operator-(const Point &p) const { return Point(x - p.x, y - p.y); }
  Point operator+(const Point &p) const { return Point(x + p.x, y + p.y); }
  long long operator|(const Point &p) const { return x * p.x + y * p.y; }
  long long operator^(const Point &p) const { return x * p.y - y * p.x; }
  Point operator*(const double &k) const { return Point(x * k, y * k); }
  Point operator/(const double &k) const { return Point(x / k, y / k); }
  int belong() {
    if (x == 0 && y == 0) return 0;
    if (x >= 0 && y > 0) return 1;
    if (x < 0 && y >= 0) return 2;
    if (x <= 0 && y < 0) return 3;
    return 4;
  }
  bool operator==(const Point &p) const { return x == p.x && y == p.y; }
  bool right(Point s, Point e) {
    return (x - s.x) * (e.y - s.y) - (y - s.y) * (e.x - s.x) > 0;
  }
  bool left(Point s, Point e) {
    return (x - s.x) * (e.y - s.y) - (y - s.y) * (e.x - s.x) < 0;
  }
  double dis(const Point &p) const {
    return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
  }
  double ang() { return atan2(y, x); }
  void input() { scanf("%lld%lld", &x, &y); }
  void output() { printf("%lld %lld\n", x, y); }
} p[100015], pp, q[100015];
bool cmpa(Point p1, Point p2) {
  return p1.angle < p2.angle;
  p1 = p1 - pp, p2 = p2 - pp;
  int b1 = p1.belong(), b2 = p2.belong();
  return b1 == b2 ? (p1 ^ p2) > 0 : b1 < b2;
}
bool cmpx(const Point &p1, const Point &p2) {
  return p1.x == p2.x ? p1.y < p2.y : p1.x < p2.x;
}
bool cmpy(const Point &p1, const Point &p2) {
  return p1.y == p2.y ? p1.x < p2.x : p1.y < p2.y;
}
int n;
long long cal(long long x) { return x * (x - 1) >> 1; }
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    q[i].input();
  }
  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    pp = q[i];
    for (int j = 1; j <= n; ++j) {
      p[j] = q[j];
      if (j == i) {
        p[j].angle = -4;
      } else {
        p[j].angle = (p[j] - pp).ang();
      }
    }
    sort(p + 1, p + n + 1, cmpa);
    for (int j = 2; j <= n; ++j) {
      int s = 2, e = j - 1, mi, res1 = 0;
      while (s <= e) {
        mi = s + e >> 1;
        if (p[mi].left(p[1], p[j])) {
          s = (res1 = mi - 1) + 2;
        } else {
          e = mi - 1;
        }
      }
      int res2 = 0;
      s = j + 1, e = n;
      while (s <= e) {
        mi = s + e >> 1;
        if (p[mi].left(p[1], p[j])) {
          s = (res2 = mi - j) + j + 1;
        } else {
          e = mi - 1;
        }
      }
      int res = res1 + res2;
      ans += cal(res) * cal(n - 2 - res);
    }
  }
  printf("%lld\n", ans >> 1);
  return 0;
}
