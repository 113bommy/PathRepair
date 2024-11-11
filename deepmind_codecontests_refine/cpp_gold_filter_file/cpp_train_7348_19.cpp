#include <bits/stdc++.h>
using namespace std;
const long double pi = acosl(-1);
const int maxn = 20010;
const long long mod = 1e9 + 7;
const long long inf = 1e9;
const long double eps = 1e-8;
struct point {
  double x, y;
  point() { x = y = 0.0; }
  point(double _x, double _y) : x(_x), y(_y) {}
  bool operator==(point other) const {
    return (fabs(x - other.x) < eps && (fabs(y - other.y) < eps));
  }
  point operator-(const point& r) const { return point(x - r.x, y - r.y); }
} a[maxn];
point toVec(point a, point b) { return point(b.x - a.x, b.y - a.y); }
double dist(point p1, point p2) { return hypot(p1.x - p2.x, p1.y - p2.y); }
double dot(point a, point b) { return (a.x * b.x + a.y * b.y); }
double norm_sq(point v) { return v.x * v.x + v.y * v.y; }
double angle(point a, point o, point b) {
  point oa = toVec(o, a), ob = toVec(o, b);
  return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob)));
}
double cross(point a, point b) { return a.x * b.y - a.y * b.x; }
pair<int, int> check(const point& pt, double ang, point a[], int n) {
  int rev = 0;
  if (cross(a[0] - pt, point(cos(ang), sin(ang))) < 0) {
    rev = 1, ang -= pi;
  }
  point unit(cos(ang), sin(ang));
  int l = 0, r = n - 1, s1, s2;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (-cross(unit, a[mid] - pt) < 0)
      r = mid - 1;
    else {
      if (-cross(a[mid] - pt, a[0] - pt) >= 0)
        l = mid + 1, s1 = mid;
      else
        r = mid - 1;
    }
  }
  r = n - 1;
  unit.x = -unit.x, unit.y = -unit.y;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (cross(unit, a[mid] - pt) < 0)
      l = mid + 1, s2 = mid;
    else
      r = mid - 1;
  }
  if (rev) swap(s1, s2);
  return {s1, s2};
}
point lineIntersectSeg(point p, point q, point A, point B) {
  double a = B.y - A.y;
  double b = A.x - B.x;
  double c = B.x * A.y - A.x * B.y;
  double u = fabs(a * p.x + b * p.y + c);
  double v = fabs(a * q.x + b * q.y + c);
  return point((p.x * v + q.x * u) / (u + v), (p.y * v + q.y * u) / (u + v));
}
int n, q, x, y;
double pre[maxn];
void init() {
  for (int i = 1; i < n; i++) {
    pre[i] = pre[i - 1] + cross(a[i - 1], a[i]);
  }
  pre[n] = pre[n - 1] + cross(a[n - 1], a[0]);
}
double sol(const point& pt, double ang) {
  double tot = pre[n];
  auto pa = check(pt, ang, a, n);
  point A = pt, B = point(pt.x + cos(ang), pt.y + sin(ang));
  point s1 = lineIntersectSeg(a[pa.first], a[(pa.first + 1) % n], A, B);
  point s2 = lineIntersectSeg(a[pa.second], a[(pa.second + 1) % n], A, B);
  pa.first = (pa.first + 1) % n;
  double area =
      cross(s1, a[pa.first]) + cross(a[pa.second], s2) + cross(s2, s1);
  if (pa.first <= pa.second)
    area += pre[pa.second] - pre[pa.first];
  else
    area += tot - pre[pa.first] + pre[pa.second];
  return area - (tot - area);
}
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &x, &y);
    a[i] = point(x, y);
  }
  reverse(a, a + n);
  init();
  point pt;
  for (int i = 0; i < q; i++) {
    scanf("%d%d", &x, &y);
    pt.x = x;
    pt.y = y;
    double l = 0, r = pi, mid = -1;
    double al = sol(pt, l);
    for (int it = 0; it < 50; it++) {
      mid = (l + r) / 2;
      double tmp = sol(pt, mid);
      if (tmp * al <= 0)
        r = mid;
      else
        l = mid, al = tmp;
    }
    printf("%.10lf\n", mid);
  }
}
