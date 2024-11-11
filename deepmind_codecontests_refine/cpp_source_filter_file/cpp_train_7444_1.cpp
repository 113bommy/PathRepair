#include <bits/stdc++.h>
using namespace std;
bool debug = 0;
int n, m, k;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
long long ln, lk, lm;
struct Point {
  long long x, y;
  Point() {}
  Point(long long x, long long y) : x(x), y(y) {}
  long double abs() const { return hypot(x, y); }
  long double arg() const { return atan2(y, x); }
  Point operator*(long long o) const { return Point(x * o, y * o); }
  Point operator+(const Point& o) const { return Point(x + o.x, y + o.y); }
  Point operator-(const Point& o) const { return Point(x - o.x, y - o.y); }
  bool operator<(const Point& o) const {
    return x < o.x - 1e-9 || (x < o.x + 1e-9 && y < o.y - 1e-9);
  }
  Point scale(long long o) const { return *this * (o / abs()); }
  Point rotY() const { return Point(-y, x); }
  Point rotX() const { return Point(y, -x); }
  long long cross(Point b) const { return x * b.y - b.x * y; }
  long long dot(Point b) const { return x * b.x + y * b.y; }
  long double disToSeg(Point& a, Point& b) {
    return fabs(((*this) - a).cross(b - a) / (b - a).abs());
  }
  void readin() { scanf("%lld%lld", &x, &y); }
} pt[100005];
int p, q;
long double ans = (1LL << 60);
void setAns(long double x, long double y) {
  long double t = max(p / x, q / y);
  ans = min(ans, t);
}
void fmain() {
  scanf("%d%d%d", &n, &p, &q);
  for (int(i) = 0; (i) < (int)(n); (i)++) pt[i].readin();
  sort(pt, pt + n);
  vector<Point> vp;
  for (int(i) = 0; (i) < (int)(n); (i)++) {
    while (vp.size() > 2) {
      Point a = vp.back(), o = vp[vp.size() - 2];
      if ((pt[i] - o).cross(a - o) >= 0)
        vp.pop_back();
      else
        break;
    }
    vp.push_back(pt[i]);
  }
  Point pq = Point(p, q), O = Point(0, 0);
  for (int(i) = 0; (i) < (int)(vp.size()); (i)++) {
    int j = (i + 1) % vp.size();
    setAns(vp[i].x, vp[i].y);
    long long tmp1 = vp[i].cross(pq), tmp2 = vp[j].cross(pq);
    if ((tmp1 < 0 && tmp2 > 0) || (tmp1 > 0 && tmp2 < 0)) {
      long double t1 = vp[i].disToSeg(O, pq), t2 = vp[j].disToSeg(O, pq);
      long double tmp = t1 / (t1 + t2);
      Point gg = (vp[j] - vp[i]);
      setAns(vp[i].x + gg.x * tmp, vp[i].y + gg.y * tmp);
    }
  }
  printf("%.10Lf\n", ans);
}
int main() {
  fmain();
  return 0;
}
