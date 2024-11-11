#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= mod;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
struct vector2 {
  double x, y;
  explicit vector2(double x_ = 0, double y_ = 0) : x(x_), y(y_) {}
  bool operator==(const vector2& rhs) const { return x == rhs.x && y == rhs.y; }
  bool operator<(const vector2& rhs) const {
    return x != rhs.x ? x < rhs.x : y > rhs.y;
  }
  vector2 operator+(const vector2& rhs) const {
    return vector2(x + rhs.x, y + rhs.y);
  }
  vector2 operator-(const vector2& rhs) const {
    return vector2(x - rhs.x, y - rhs.y);
  }
  vector2 operator*(double rhs) const { return vector2(x * rhs, y * rhs); }
  double norm() const { return hypot(x, y); }
  vector2 normalize() const { return vector2(x / norm(), y / norm()); }
  double polar() const {
    return fmod(atan2(y, x) + 2 * 3.141592653589793, 2 * 3.141592653589793);
  }
  double dot(const vector2& rhs) const { return x * rhs.x + y * rhs.y; }
  double cross(const vector2& rhs) const { return x * rhs.y - rhs.x * y; }
  vector2 project(const vector2& rhs) const {
    vector2 r = rhs.normalize();
    return r * r.dot(*this);
  }
};
double howMuchCloser(vector2 p, vector2 a, vector2 b) {
  return (b - p).norm() - (a - p).norm();
}
double ccw(vector2 a, vector2 b) { return a.cross(b); }
double ccw(vector2 p, vector2 a, vector2 b) { return ccw(a - p, b - p); }
bool lineIntersection(vector2 a, vector2 b, vector2 c, vector2 d, vector2& x) {
  double det = (b - a).cross(d - c);
  if (fabs(det) < FLT_EPSILON) return false;
  x = a + (b - a) * ((c - a).cross(d - c) / det);
  return true;
}
bool parallelSegments(vector2 a, vector2 b, vector2 c, vector2 d, vector2& p) {
  if (b < a) swap(a, b);
  if (d < c) swap(c, d);
  if (ccw(a, b, c) != 0 || b < c || d < a) return false;
  if (a < c)
    p = c;
  else
    p = a;
  return true;
}
bool isBoundingRectangle(vector2 p, vector2 a, vector2 b) {
  if (b < a) swap(a, b);
  return p == a || p == b || (a < p && p < b);
}
bool segmentIntersection(vector2 a, vector2 b, vector2 c, vector2 d,
                         vector2& p) {
  if (!lineIntersection(a, b, c, d, p)) return parallelSegments(a, b, c, d, p);
  return isBoundingRectangle(p, a, b) && isBoundingRectangle(p, c, d);
}
bool fastSegmentIntersection(vector2 a, vector2 b, vector2 c, vector2 d) {
  double ab = ccw(a, b, c) * ccw(a, b, d);
  double cd = ccw(c, d, a) * ccw(c, d, b);
  if (ab == 0 && cd == 0) {
    if (b < a) swap(a, b);
    if (d < c) swap(c, d);
    return !(b < c || d < a);
  }
  return ab <= 0 && cd <= 0;
}
vector2 perpendicularFoot(vector2 p, vector2 a, vector2 b) {
  return a + (p - a).project(b - a);
}
double pointToLine(vector2 p, vector2 a, vector2 b) {
  return (p - perpendicularFoot(p, a, b)).norm();
}
double area(const vector<vector2>& p) {
  double ret = 0;
  for (int i = 0; i < (int)p.size(); i++) {
    int j = (i + 1) % p.size();
    ret += p[i].cross(p[j]);
  }
  return fabs(ret) / 2.;
}
bool isInside(vector2 q, const vector<vector2>& p) {
  int crosses = 0;
  for (int i = 0; i < (int)p.size(); i++) {
    int j = (i + 1) % p.size();
    if ((p[i].y > q.y) != (p[j].y > q.y)) {
      double atX =
          p[i].x + (p[j].x - p[i].x) * (q.y - p[i].y) / (p[j].y - p[i].y);
      if (atX > q.x) crosses++;
    }
  }
  return crosses % 2 > 0;
}
vector<vector2> cutPolygonByLine(vector<vector2>& poly, vector2 a, vector2 b) {
  int n = poly.size();
  vector<bool> inside(n, 0);
  for (int i = 0; i < (int)n; i++) {
    inside[i] = ccw(a, b, poly[i]) >= 0;
  }
  vector<vector2> ret;
  for (int i = 0; i < (int)n; i++) {
    if (inside[i]) ret.push_back(poly[i]);
    int j = (i + 1) % n;
    vector2 cross;
    if (inside[i] != inside[j]) {
      if (!lineIntersection(a, b, poly[i], poly[j], cross)) continue;
      ret.push_back(cross);
    }
  }
  return ret;
}
vector<vector2> giftWrap(const vector<vector2>& points) {
  int n = points.size();
  vector<vector2> hull;
  vector2 pivot = *min_element(points.begin(), points.end());
  hull.push_back(pivot);
  while (1) {
    vector2 ph = hull.back(), next = points[0];
    for (int i = 1; i < (int)n; i++) {
      double cross = ccw(ph, next, points[i]);
      double dist = (next - ph).norm() - (points[i] - ph).norm();
      if (cross > 0 || (cross == 0 && dist < 0)) next = points[i];
    }
    if (next == pivot) break;
    hull.push_back(next);
  }
  return hull;
}
vector<vector2> giftWrap1(const vector<vector2>& points) {
  int n = points.size();
  vector<vector2> hull;
  hull.push_back(points[0]);
  hull.push_back(points[1]);
  for (int i = 2; i < (int)n; i++) {
    int sz = hull.size();
    while (hull.size() > 1) {
      if (ccw(hull[hull.size() - 2], hull[hull.size() - 1], points[i]) >= 0)
        hull.pop_back();
      else
        break;
    }
    hull.push_back(points[i]);
  }
  return hull;
}
int n, p, q, c, d, maxC, maxD;
vector<vector2> points;
int main() {
  maxC = maxD = 0;
  scanf("%d%d%d", &n, &p, &q);
  for (int i = 0; i < (int)n; i++) {
    scanf("%d%d", &c, &d);
    points.push_back(vector2(c, d));
    maxC = max(maxC, c);
    maxD = max(maxD, d);
  }
  points.push_back(vector2(maxC, 0));
  points.push_back(vector2(0, maxD));
  sort(points.begin(), points.end());
  vector<vector2> hull = giftWrap1(points);
  double ans = 10000000;
  double tmpP = double(p) * 1000000, tmpQ = double(q) * 1000000;
  for (int i = 0; i < (int)hull.size(); i++) {
    vector2 p1(-1, -1);
    if (segmentIntersection(hull[i], hull[(i + 1) % hull.size()], vector2(0, 0),
                            vector2(double(tmpP), double(tmpQ)), p1)) {
      if (p1.x != -1) {
        ans = min(ans, p / p1.x);
      }
    }
  }
  printf("%.12lf\n", ans);
  return 0;
}
