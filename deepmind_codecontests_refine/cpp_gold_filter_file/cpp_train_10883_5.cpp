#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
const long double PI = acos(-1.0);
struct Point {
  int x, y;
  bool read() {
    if (scanf("%d%d", &x, &y) < 2) {
      return false;
    }
    return true;
  }
  long long sq_dist(const Point& p) const {
    return (x - p.x) * 1ll * (x - p.x) + (y - p.y) * 1ll * (y - p.y);
  }
};
struct Circle {
  Point p;
  int r;
  bool read() {
    if (!p.read()) {
      return false;
    }
    scanf("%d", &r);
    return true;
  }
  bool contains(const Point& q) { return p.sq_dist(q) <= r * 1ll * r; }
  long double ang(const Point& p0) const {
    long double a = atan2(p.y - p0.y, p.x - p0.x);
    if (a < 0) {
      a += 2 * PI;
    }
    return a;
  }
};
vector<Circle> cs;
int n;
Point p0;
int v, T;
bool read() {
  if (!p0.read()) {
    return false;
  }
  scanf("%d%d", &v, &T);
  scanf("%d", &n);
  cs.resize(n);
  for (int i = 0; i < (int)n; ++i) {
    cs[i].read();
  }
  return true;
}
long double solve() {
  for (int i = 0; i < (int)((int)(cs).size()); ++i) {
    if (cs[i].contains(p0)) {
      return 1;
    }
  }
  vector<pair<long double, long double>> segs;
  for (int i = 0; i < (int)((int)(cs).size()); ++i) {
    if (cs[i].r == 0) {
      continue;
    }
    long double ang = cs[i].ang(p0);
    long double D = sqrtl(cs[i].p.sq_dist(p0));
    long double x = cs[i].r / D;
    if (x < 0) x = 0;
    if (x > 1) x = 1;
    long double a = asin(x);
    long double l = 0;
    long double r = a;
    for (int it = 0; it < (int)50; ++it) {
      long double m = (l + r) * 0.5;
      long double sin_beta = D * sin(m) / cs[i].r;
      long double cos_beta = sqrtl(1.0 - sin_beta * sin_beta);
      long double z = D * cosl(m) - cos_beta * cs[i].r;
      if (z < v * 1ll * T) {
        l = m;
      } else {
        r = m;
      }
    }
    long double diff = l;
    l = ang - diff;
    r = ang + diff;
    if (l < 0) {
      l += 2 * PI;
      r += 2 * PI;
    }
    if (r > 2 * PI) {
      segs.push_back(make_pair(l, 2 * PI));
      segs.push_back(make_pair(0, r - 2 * PI));
    } else {
      segs.push_back(make_pair(l, r));
    }
  }
  long double sum = 0;
  sort(begin(segs), end(segs));
  long double r = 0;
  for (auto s : segs) {
    sum += max((long double)0.0, s.first - r);
    r = max(r, s.second);
  }
  sum += 2 * PI - r;
  return 1.0 - sum / (2 * PI);
}
int main() {
  while (read()) {
    printf("%.10f\n", (double)solve());
  }
  return 0;
}
