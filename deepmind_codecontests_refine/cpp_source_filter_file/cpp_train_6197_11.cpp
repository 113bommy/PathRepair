#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-6;
inline bool lt(double lhs, double rhs) { return rhs - lhs >= eps; }
inline bool le(double lhs, double rhs) { return rhs - lhs > -eps; }
inline bool gt(double lhs, double rhs) { return lhs - rhs >= eps; }
inline bool ge(double lhs, double rhs) { return lhs - rhs > -eps; }
inline bool eq(double lhs, double rhs) { return fabs(rhs - lhs) < eps; }
inline bool ne(double lhs, double rhs) { return fabs(rhs - lhs) >= eps; }
inline bool zr(double lhs) { return fabs(lhs) < eps; }
inline bool nz(double lhs) { return fabs(lhs) >= eps; }
inline bool ps(double lhs) { return lhs >= eps; }
inline bool nn(double lhs) { return lhs > -eps; }
inline bool ng(double lhs) { return lhs <= -eps; }
inline bool np(double lhs) { return lhs < eps; }
struct Point {
  double x, y;
  Point(double x = 0, double y = 0) : x(x), y(y) {}
  void get() { scanf("%lf%lf", &x, &y); }
  void put() const { printf("(%lf, %lf)", x, y); }
};
struct Segment {
  Point a, b;
  Segment() : a(), b() {}
  Segment(Point a, Point b) : a(a), b(b) {}
};
struct Line {
  double A, B, C;
  Line() : A(0), B(0), C(0) {}
  Line(double A, double B, double C) : A(A), B(B), C(C) {}
  Line(const Point& lhs, const Point& rhs)
      : A(rhs.y - lhs.y), B(lhs.x - rhs.x), C(-(lhs.x * A + lhs.y * B)) {}
  Line(double slope, const Point& p)
      : A(slope), B(-1.0), C(p.y - slope * p.x) {}
  Line(const Point& p, double slope)
      : A(slope), B(-1.0), C(p.y - slope * p.x) {}
  Line(const Segment& s) { *this = Line(s.a, s.b); }
  double eval(const Point& p) const { return A * p.x + B * p.y + C; }
  void put() { printf("%lf %lf %lf\n", A, B, C); }
};
double operator^(const Point& lhs, const Point& rhs) {
  return lhs.x * rhs.y - lhs.y * rhs.x;
}
double operator*(const Point& lhs, const Point& rhs) {
  return lhs.x * rhs.x + lhs.y * rhs.y;
}
const Point operator-(const Point& lhs, const Point& rhs) {
  return Point(lhs.x - rhs.x, lhs.y - rhs.y);
}
bool onSegment(const Point& p, const Segment& s) {
  return zr((p - s.a) ^ (p - s.b)) && np((p - s.a) * (p - s.b));
}
bool cross(const Segment& v, const Segment& w) {
  if (onSegment(v.a, w) || onSegment(v.b, w) || onSegment(w.a, v) ||
      onSegment(w.b, v))
    return true;
  return (ps((v.a - w.a) ^ (w.b - w.a)) ^ ps((v.b - w.a) ^ (w.b - w.a))) &&
         (ps((w.a - v.a) ^ (v.b - v.a)) ^ ps((w.b - v.a) ^ (v.b - v.a)));
}
const Point intersect(const Line& a, const Line& b) {
  return Point((a.B * b.C - b.B * a.C) / (b.B * a.A - a.B * b.A),
               (a.A * b.C - b.A * a.C) / (b.A * a.B - a.A * b.B));
}
Point x;
double dist(const Point& a, const Point& b) {
  return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
bool Less(const Point& a, const Point& b) {
  Point hor(1, 0), va = a - x, vb = b - x;
  if ((va ^ vb) == 0 && va.x * vb.x > 0) {
    if (dist(va, x) < dist(vb, x))
      return 1;
    else
      return 0;
  }
  if ((va ^ hor) == 0) {
    if (va.x > 0 && !((vb ^ hor) == 0 && vb.x > 0)) return 1;
    if (va.x < 0 && (vb ^ hor) > 0) return 1;
    return 0;
  } else if ((va ^ hor) < 0) {
    if ((vb ^ hor) == 0 && vb.x < 0) return 1;
    if ((vb ^ hor) < 0 && (vb ^ va) < 0) return 1;
    if ((vb ^ hor) > 0) return 1;
    return 0;
  } else {
    if ((vb ^ va) < 0 && (vb ^ hor) > 0) return 1;
    return 0;
  }
}
void sortPolarCoor(vector<Point>& ps) { sort(ps.begin(), ps.end(), Less); }
bool inPolygon(vector<Point>& ps, Point p) {
  for (int i = 0; i <= (int)ps.size() - 1; i++) {
    int a = i, b = i == (int)ps.size() - 1 ? 0 : i + 1;
    Segment edge(ps[a], ps[b]);
    if (onSegment(p, edge)) return true;
  }
  double leftm = DBL_MAX;
  for (int i = 0; i <= (int)ps.size() - 1; i++) {
    if (ps[i].x < leftm) leftm = ps[i].x;
  }
  Segment ray(Point(min(leftm, p.x) - 100, p.y), p);
  int count = 0;
  for (int i = 0; i <= (int)ps.size() - 1; i++) {
    int a = i, b = i == (int)ps.size() - 1 ? 0 : i + 1;
    bool upa, upb;
    if (eq(ps[a].y, p.y) || gt(ps[a].y, p.y))
      upa = 1;
    else
      upa = 0;
    if (eq(ps[b].y, p.y) || gt(ps[b].y, p.y))
      upb = 1;
    else
      upb = 0;
    if (upa ^ upb) {
      Segment edge(ps[a], ps[b]);
      Point inter = intersect(Line(edge), Line(ray));
      if (onSegment(inter, edge) && onSegment(inter, ray)) count++;
    }
  }
  return count % 2 == 1;
}
bool inTriangle(const Point& a, const Point& b, const Point& c,
                const Point& x) {
  if (onSegment(x, Segment(a, b)) || onSegment(x, Segment(b, c)) ||
      onSegment(x, Segment(c, a)))
    return 1;
  Point v1 = b - a, v2 = c - b, v3 = a - c;
  Point xa = x - a, xb = x - b, xc = x - c;
  double d1 = xa ^ v1, d2 = xb ^ v2, d3 = xc ^ v3;
  return (ng(d1) && ng(d2) && ng(d3)) || (ps(d1) && ps(d2) && ps(d3));
}
const int MAX = 120;
int n;
Point tri[MAX][3];
vector<Segment> s1, s2;
class cmp {
 public:
  cmp() {}
  bool operator()(const Point& a, const Point& b) {
    if (eq(a.x, b.x))
      return lt(a.y, b.y);
    else
      return lt(a.x, b.x);
  }
};
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%lf %lf %lf %lf %lf %lf", &tri[i][0].x, &tri[i][0].y, &tri[i][1].x,
          &tri[i][1].y, &tri[i][2].x, &tri[i][2].y);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      int k = j == 2 ? 0 : j + 1;
      s1.push_back({tri[i][j], tri[i][k]});
    }
  }
  for (int i = 0; i < s1.size(); i++) {
    set<Point, cmp> ts;
    ts.insert(s1[i].a), ts.insert(s1[i].b);
    for (int j = 0; j < s1.size(); j++) {
      if (j != i) {
        if (cross(s1[i], s1[j])) {
          Point inter = intersect(Line(s1[i]), Line(s1[j]));
          ts.insert(inter);
        }
      }
    }
    for (auto ite = ts.begin(); ite != ts.end(); ite++) {
      auto ite1 = ite;
      ++ite1;
      if (ite1 != ts.end()) {
        s2.push_back(Segment(*ite, *ite1));
      }
    }
  }
  double ans = 0;
  for (int i = 0; i < s2.size(); i++) {
    bool in = 0;
    Point mid = Point((s2[i].a.x + s2[i].b.x) / 2, (s2[i].a.y + s2[i].b.y) / 2);
    for (int j = 0; j < n; j++) {
      if (inTriangle(tri[j][0], tri[j][1], tri[j][2], s2[i].a) &&
          inTriangle(tri[j][0], tri[j][1], tri[j][2], s2[i].b) &&
          !onSegment(mid, Segment(tri[j][0], tri[j][1])) &&
          !onSegment(mid, Segment(tri[j][1], tri[j][2])) &&
          !onSegment(mid, Segment(tri[j][2], tri[j][0]))) {
        in = 1;
        break;
      }
    }
    if (in == 0)
      ans += sqrt(dist(s2[i].a, s2[i].b));
    else {
    }
  }
  printf("%.10lf\n", ans);
  return 0;
}
