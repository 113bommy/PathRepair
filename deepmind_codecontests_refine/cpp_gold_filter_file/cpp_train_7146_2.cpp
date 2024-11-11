#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e6 + 10;
const long long INF = 1e18;
const long double EPS = 1e-12;
struct Point {
  long double x, y;
  Point() {}
  Point(long double x, long double y) : x(x), y(y) {}
  Point(const Point &p) : x(p.x), y(p.y) {}
  Point operator+(const Point &p) const { return Point(x + p.x, y + p.y); }
  Point operator-(const Point &p) const { return Point(x - p.x, y - p.y); }
  Point operator*(long double c) const { return Point(x * c, y * c); }
  Point operator/(long double c) const { return Point(x / c, y / c); }
};
long double dot(Point p, Point q) { return p.x * q.x + p.y * q.y; }
long double dist2(Point p, Point q) { return dot(p - q, p - q); }
long double cross(Point p, Point q) { return p.x * q.y - p.y * q.x; }
ostream &operator<<(ostream &os, const Point &p) {
  os << "(" << p.x << "," << p.y << ")";
}
bool operator<(const Point &a, const Point &b) {
  return make_pair(a.x, a.y) < make_pair(b.x, b.y);
}
bool operator==(const Point &a, const Point &b) {
  return abs(a.x - b.x) < EPS && abs(a.y - b.y) < EPS;
}
Point RotateCCW90(Point p) { return Point(-p.y, p.x); }
Point RotateCW90(Point p) { return Point(p.y, -p.x); }
Point RotateCCW(Point p, long double t) {
  return Point(p.x * cos(t) - p.y * sin(t), p.x * sin(t) + p.y * cos(t));
}
Point ProjectPointLine(Point a, Point b, Point c) {
  return a + (b - a) * dot(c - a, b - a) / dot(b - a, b - a);
}
Point ProjectPointSegment(Point a, Point b, Point c) {
  long double r = dot(b - a, b - a);
  if (fabs(r) < EPS) return a;
  r = dot(c - a, b - a) / r;
  if (r < 0) return a;
  if (r > 1) return b;
  return a + (b - a) * r;
}
pair<Point, Point> Perpendicularline(Point a, Point b, Point c) {
  c = ProjectPointLine(a, b, c);
  if (a == c) a = b;
  return make_pair(c, c + RotateCW90(a - c));
}
long double DistancePointSegment(Point a, Point b, Point c) {
  return sqrt(dist2(c, ProjectPointSegment(a, b, c)));
}
long double DistancePointPlane(long double x, long double y, long double z,
                               long double a, long double b, long double c,
                               long double d) {
  return fabs(a * x + b * y + c * z - d) / sqrt(a * a + b * b + c * c);
}
bool LinesParallel(Point a, Point b, Point c, Point d) {
  return fabs(cross(b - a, c - d)) < EPS;
}
bool LinesCollinear(Point a, Point b, Point c, Point d) {
  return LinesParallel(a, b, c, d) && fabs(cross(a - b, a - c)) < EPS &&
         fabs(cross(c - d, c - a)) < EPS;
}
bool SegmentsIntersect(Point a, Point b, Point c, Point d) {
  if (LinesCollinear(a, b, c, d)) {
    if (dist2(a, c) < EPS || dist2(a, d) < EPS || dist2(b, c) < EPS ||
        dist2(b, d) < EPS)
      return true;
    if (dot(c - a, c - b) > 0 && dot(d - a, d - b) > 0 && dot(c - b, d - b) > 0)
      return false;
    return true;
  }
  if (cross(d - a, b - a) * cross(c - a, b - a) > 0) return false;
  if (cross(a - c, d - c) * cross(b - c, d - c) > 0) return false;
  return true;
}
Point ComputeLineIntersection(Point a, Point b, Point c, Point d) {
  b = b - a;
  d = c - d;
  c = c - a;
  assert(dot(b, b) > EPS && dot(d, d) > EPS);
  return a + b * cross(c, d) / cross(b, d);
}
Point ComputeCircleCenter(Point a, Point b, Point c) {
  b = (a + b) / 2;
  c = (a + c) / 2;
  return ComputeLineIntersection(b, b + RotateCW90(a - b), c,
                                 c + RotateCW90(a - c));
}
bool PointInPolygon(const vector<Point> &p, Point q) {
  bool c = 0;
  for (int i = 0; i < p.size(); i++) {
    int j = (i + 1) % p.size();
    if ((p[i].y <= q.y && q.y < p[j].y || p[j].y <= q.y && q.y < p[i].y) &&
        q.x < p[i].x + (p[j].x - p[i].x) * (q.y - p[i].y) / (p[j].y - p[i].y))
      c = !c;
  }
  return c;
}
bool PointOnPolygon(const vector<Point> &p, Point q) {
  for (int i = 0; i < p.size(); i++)
    if (dist2(ProjectPointSegment(p[i], p[(i + 1) % p.size()], q), q) < EPS)
      return true;
  return false;
}
vector<Point> CircleLineIntersection(Point a, Point b, Point c, long double r) {
  vector<Point> ret;
  b = b - a;
  a = a - c;
  long double A = dot(b, b);
  long double B = dot(a, b);
  long double C = dot(a, a) - r * r;
  long double D = B * B - A * C;
  if (D < -EPS) return ret;
  ret.push_back(c + a + b * (-B + sqrt(D + EPS)) / A);
  if (D > EPS) ret.push_back(c + a + b * (-B - sqrt(D)) / A);
  return ret;
}
vector<Point> CircleCircleIntersection(Point a, Point b, long double r,
                                       long double R) {
  vector<Point> ret;
  long double d = sqrt(dist2(a, b));
  if (d > r + R || d + min(r, R) < max(r, R)) return ret;
  long double x = (d * d - R * R + r * r) / (2 * d);
  long double y = sqrt(r * r - x * x);
  Point v = (b - a) / d;
  ret.push_back(a + v * x + RotateCCW90(v) * y);
  if (y > 0) ret.push_back(a + v * x - RotateCCW90(v) * y);
  return ret;
}
long double ComputeSignedArea(const vector<Point> &p) {
  long double area = 0;
  for (int i = 0; i < p.size(); i++) {
    int j = (i + 1) % p.size();
    area += p[i].x * p[j].y - p[j].x * p[i].y;
  }
  return area / 2.0;
}
long double ComputeArea(const vector<Point> &p) {
  return fabs(ComputeSignedArea(p));
}
Point ComputeCentroid(const vector<Point> &p) {
  Point c(0, 0);
  long double scale = 6.0 * ComputeSignedArea(p);
  for (int i = 0; i < p.size(); i++) {
    int j = (i + 1) % p.size();
    c = c + (p[i] + p[j]) * (p[i].x * p[j].y - p[j].x * p[i].y);
  }
  return c / scale;
}
bool IsSimple(const vector<Point> &p) {
  for (int i = 0; i < p.size(); i++) {
    for (int k = i + 1; k < p.size(); k++) {
      int j = (i + 1) % p.size();
      int l = (k + 1) % p.size();
      if (i == l || j == k) continue;
      if (SegmentsIntersect(p[i], p[j], p[k], p[l])) return false;
    }
  }
  return true;
}
long double area2(Point a, Point b, Point c) { return cross(b - a, c - a); }
void ConvexHull(vector<Point> &pts) {
  sort(pts.begin(), pts.end());
  pts.erase(unique(pts.begin(), pts.end()), pts.end());
  vector<Point> up, dn;
  for (int i = 0; i < pts.size(); i++) {
    while (up.size() > 1 && area2(up[up.size() - 2], up.back(), pts[i]) >= 0)
      up.pop_back();
    while (dn.size() > 1 && area2(dn[dn.size() - 2], dn.back(), pts[i]) <= 0)
      dn.pop_back();
    up.push_back(pts[i]);
    dn.push_back(pts[i]);
  }
  pts = dn;
  for (int i = (int)up.size() - 2; i >= 1; i--) pts.push_back(up[i]);
}
bool in_convex(vector<Point> &l, Point p) {
  int a = 1, b = l.size() - 1, c;
  if (((l[a].x - l[0].x) * (l[b].y - l[0].y) -
       (l[a].y - l[0].y) * (l[b].x - l[0].x)) > 0)
    swap(a, b);
  if (((l[a].x - l[0].x) * (p.y - l[0].y) -
       (l[a].y - l[0].y) * (p.x - l[0].x)) >= 0 ||
      ((l[b].x - l[0].x) * (p.y - l[0].y) -
       (l[b].y - l[0].y) * (p.x - l[0].x)) <= 0)
    return false;
  while (abs(a - b) > 1) {
    c = (a + b) / 2;
    if (((l[c].x - l[0].x) * (p.y - l[0].y) -
         (l[c].y - l[0].y) * (p.x - l[0].x)) > 0)
      b = c;
    else
      a = c;
  }
  return ((l[b].x - l[a].x) * (p.y - l[a].y) -
          (l[b].y - l[a].y) * (p.x - l[a].x)) <= 0;
}
vector<pair<Point, Point> > find_tangent(Point a, Point b, long double r1,
                                         long double r2) {
  vector<pair<Point, Point> > Q;
  if (dist2(a, b) <= (r1 - r2) * (r1 - r2)) return Q;
  int f = 0;
  if (r2 > r1) swap(a, b), swap(r1, r2), f = 1;
  if (abs(r2 - r1) <= EPS) {
    pair<Point, Point> m = Perpendicularline(a, b, a),
                       n = Perpendicularline(a, b, b);
    vector<Point> l1 = CircleLineIntersection(m.first, m.second, a, r1),
                  l2 = CircleLineIntersection(n.first, n.second, b, r2);
    assert(l1.size() == 2 && l2.size() == 2);
    if (cross(b - a, l1[0] - b) * cross(b - a, l2[0] - b) < 0)
      swap(l2[0], l2[1]);
    Q.push_back(make_pair(l1[0], l2[0]));
    Q.push_back(make_pair(l1[1], l2[1]));
  } else {
    Point out = (b * r1 - a * r2) / (r1 - r2);
    assert(dist2(out, a) >= r1 && dist2(out, b) >= r2);
    vector<Point> l1 = CircleCircleIntersection(
                      a, out, r1, sqrt(dist2(out, a) - (r1) * (r1))),
                  l2 = CircleCircleIntersection(
                      b, out, r2, sqrt(dist2(out, b) - (r2) * (r2)));
    assert(l1.size() == 2 && l2.size() == 2);
    if (cross(b - a, l1[0] - b) * cross(b - a, l2[0] - b) < 0)
      swap(l2[0], l2[1]);
    Q.push_back(make_pair(l1[0], l2[0]));
    Q.push_back(make_pair(l1[1], l2[1]));
  }
  if (dist2(a, b) > (r1 + r2) * (r1 + r2) + EPS) {
    Point out = (b * r1 + a * r2) / (r1 + r2);
    assert(dist2(out, a) >= r1 && dist2(out, b) >= r2);
    vector<Point> l1 = CircleCircleIntersection(
                      a, out, r1, sqrt(dist2(out, a) - (r1) * (r1))),
                  l2 = CircleCircleIntersection(
                      b, out, r2, sqrt(dist2(out, b) - (r2) * (r2)));
    assert(l1.size() == 2 && l2.size() == 2);
    if (cross(b - a, l1[0] - b) * cross(b - a, l2[0] - b) > 0)
      swap(l2[0], l2[1]);
    Q.push_back(make_pair(l1[0], l2[0]));
    Q.push_back(make_pair(l1[1], l2[1]));
  } else if (abs((r1 + r2) * (r1 + r2) - dist2(a, b)) < EPS) {
    Point out = (b * r1 + a * r2) / (r1 + r2);
    Q.push_back(Perpendicularline(a, b, out));
  }
  if (f == 1) {
    for (int i = 0; i < Q.size(); ++i) swap(Q[i].first, Q[i].second);
  }
  return Q;
}
long double error = 1e-8;
Point rect;
vector<pair<Point, long double> > circ;
bool inpoly(vector<Point> &a, Point b) {
  int n = a.size();
  for (int i = 0; i < a.size(); ++i) {
    if (DistancePointSegment(a[i], a[(i + 1) % n], b) < error) return 1;
  }
  return in_convex(a, b);
}
bool outcircle(Point cen, long double rad, Point a) {
  if (dist2(cen, a) > rad * rad - error) return 1;
  return 0;
}
Point bottom;
bool cmp(Point a, Point b) {
  long double val = cross(a - bottom, b - a);
  if (fabs(val) < EPS) {
    return dist2(bottom, b) > dist2(bottom, a);
  }
  return val > EPS;
}
int myconvexhull(vector<Point> &pts) {
  sort(pts.begin(), pts.end());
  pts.resize(unique(pts.begin(), pts.end()) - pts.begin());
  bottom = pts[0];
  sort(pts.begin() + 1, pts.end(), cmp);
  vector<Point> hull;
  hull.clear();
  for (int i = 0; i < pts.size(); ++i) {
    while (hull.size() >= 2 &&
           cross(hull[hull.size() - 2] - hull[hull.size() - 1],
                 pts[i] - hull[hull.size() - 1]) >= -1 * EPS) {
      hull.pop_back();
    }
    hull.push_back(pts[i]);
  }
  pts.clear();
  for (int i = 0; i < hull.size(); ++i) {
    pts.push_back(hull[i]);
  }
  return 0;
}
int main() {
  std::ios::sync_with_stdio(false);
  long double r, x1, y1, x2, y2, val, rad;
  vector<Point> vec;
  cin >> r >> x1 >> y1 >> x2 >> y2;
  val = sqrt(dist2(Point(x1, y1), Point(x2, y2)));
  if (val - r >= -1 * EPS) {
    cout << setprecision(30) << x1 << " " << y1 << " " << r - EPS << endl;
  } else {
    rad = (val + r) / 2.0;
    if (x2 != x1 || y2 != y1) {
      vec = CircleLineIntersection(Point(x1, y1), Point(x2, y2), Point(x1, y1),
                                   r);
      if (dist2(vec[0], Point(x2, y2)) > dist2(vec[1], Point(x2, y2))) {
        cout << setprecision(30) << (vec[0].x + x2) / 2.0 << " "
             << (vec[0].y + y2) / 2.0 << " " << rad << endl;
      } else {
        cout << setprecision(30) << (vec[1].x + x2) / 2.0 << " "
             << (vec[1].y + y2) / 2.0 << " " << rad << endl;
      }
    } else {
      vec = CircleLineIntersection(Point(x1, y1), Point(x2 + 1, y2 + 1),
                                   Point(x1, y1), r);
      if (dist2(vec[0], Point(x2, y2)) > dist2(vec[1], Point(x2, y2))) {
        cout << setprecision(30) << (vec[0].x + x2) / 2.0 << " "
             << (vec[0].y + y2) / 2.0 << " " << rad << endl;
      } else {
        cout << setprecision(30) << (vec[1].x + x2) / 2.0 << " "
             << (vec[1].y + y2) / 2.0 << " " << rad << endl;
      }
    }
  }
}
