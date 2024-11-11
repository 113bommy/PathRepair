#include <bits/stdc++.h>
using namespace std;
const double EPS = 1E-9;
const double PI = acos(-1);
struct pt {
  double x, y;
  bool operator<(const pt& p) const {
    return x < p.x - EPS || abs(x - p.x) < EPS && y < p.y - EPS;
  }
};
struct line {
  double a, b, c;
  line() {}
  line(pt p, pt q) {
    a = p.y - q.y;
    b = q.x - p.x;
    c = -a * p.x - b * p.y;
    norm();
  }
  void norm() {
    double z = sqrt(a * a + b * b);
    if (abs(z) > EPS) a /= z, b /= z, c /= z;
  }
  double dist(pt p) const { return a * p.x + b * p.y + c; }
};
inline bool betw(double l, double r, double x) {
  return min(l, r) <= x + EPS && x <= max(l, r) + EPS;
}
inline bool intersect_1d(double a, double b, double c, double d) {
  if (a > b) swap(a, b);
  if (c > d) swap(c, d);
  return max(a, c) <= min(b, d) + EPS;
}
bool intersect(pt a, pt b, pt c, pt d, pt& left, pt& right) {
  if (!intersect_1d(a.x, b.x, c.x, d.x) || !intersect_1d(a.y, b.y, c.y, d.y))
    return false;
  line m(a, b);
  line n(c, d);
  double zn = (m.a * n.b - m.b * n.a);
  if (abs(zn) < EPS) {
    if (abs(m.dist(c)) > EPS || abs(n.dist(a)) > EPS) return false;
    if (b < a) swap(a, b);
    if (d < c) swap(c, d);
    left = max(a, c);
    right = min(b, d);
    return true;
  } else {
    left.x = right.x = -(m.c * n.b - m.b * n.c) / zn;
    left.y = right.y = -(m.a * n.c - m.c * n.a) / zn;
    return betw(a.x, b.x, left.x) && betw(a.y, b.y, left.y) &&
           betw(c.x, d.x, left.x) && betw(c.y, d.y, left.y);
  }
}
bool cmp(pt a, pt b) { return a.x < b.x || a.x == b.x && a.y < b.y; }
bool cw(pt a, pt b, pt c) {
  return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) < 0;
}
bool ccw(pt a, pt b, pt c) {
  return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) > 0;
}
void convex_hull(vector<pt>& a) {
  if (a.size() == 1) return;
  sort(a.begin(), a.end(), &cmp);
  pt p1 = a[0], p2 = a.back();
  vector<pt> up, down;
  up.push_back(p1);
  down.push_back(p1);
  for (size_t i = 1; i < a.size(); ++i) {
    if (i == a.size() - 1 || cw(p1, a[i], p2)) {
      while (up.size() >= 2 && !cw(up[up.size() - 2], up[up.size() - 1], a[i]))
        up.pop_back();
      up.push_back(a[i]);
    }
    if (i == a.size() - 1 || ccw(p1, a[i], p2)) {
      while (down.size() >= 2 &&
             !ccw(down[down.size() - 2], down[down.size() - 1], a[i]))
        down.pop_back();
      down.push_back(a[i]);
    }
  }
  a.clear();
  for (size_t i = 0; i < up.size(); ++i) a.push_back(up[i]);
  for (size_t i = down.size() - 2; i > 0; --i) a.push_back(down[i]);
}
double sq(const vector<pt>& fig) {
  double res = 0;
  for (unsigned i = 0; i < fig.size(); i++) {
    pt p1 = i ? fig[i - 1] : fig.back(), p2 = fig[i];
    res += (p1.x - p2.x) * (p1.y + p2.y);
  }
  return fabs(res) / 2;
}
int main() {
  double w, h, a;
  cin >> w >> h >> a;
  if (a > 90) a -= 90;
  pt p[10];
  p[1].x = -w / 2.0;
  p[1].y = h / 2.0;
  p[2].x = w / 2.0;
  p[2].y = h / 2.0;
  p[3].x = w / 2.0;
  p[3].y = -h / 2.0;
  p[4].x = -w / 2.0;
  p[4].y = -h / 2.0;
  for (int i = 1; i <= 4; ++i) {
    double a0 = abs(atan(p[i].y / p[i].x));
    if (i == 1) a0 = PI - a0;
    if (i == 3) a0 = 2 * PI - a0;
    if (i == 4) a0 += PI;
    double r = sqrt(p[i].y * p[i].y + p[i].x * p[i].x);
    a0 += a / 180.0 * PI;
    p[i + 4].x = r * cos(a0);
    p[i + 4].y = r * sin(a0);
  }
  vector<pt> v;
  for (int i = 1; i <= 4; ++i)
    for (int j = 5; j <= 8; ++j) {
      pt left, right;
      if (intersect(p[i], p[i % 4 + 1], p[j], p[(j - 4) % 4 + 5], left, right))
        v.push_back(left);
    }
  convex_hull(v);
  printf("%.6lf", sq(v));
  return 0;
}
