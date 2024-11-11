#include <bits/stdc++.h>
using namespace std;
double DEG_to_RAD(double d) { return d * acos(-1.0) / 180.0; }
double RAD_to_DEG(double r) { return r * 180.0 / acos(-1.0); }
struct point_i {
  int x, y;
  point_i() { x = y = 0; }
  point_i(int _x, int _y) : x(_x), y(_y) {}
};
struct point {
  double x, y;
  point() { x = y = 0.0; }
  point(double _x, double _y) : x(_x), y(_y) {}
  bool operator<(point other) const {
    if (fabs(x - other.x) > 1e-9) return x < other.x;
    return y < other.y;
  }
  bool operator==(point other) const {
    return (fabs(x - other.x) < 1e-9 && (fabs(y - other.y) < 1e-9));
  }
};
double dist(point p1, point p2) { return hypot(p1.x - p2.x, p1.y - p2.y); }
point rotate(point p, double theta) {
  double rad = DEG_to_RAD(theta);
  return point(p.x * cos(rad) - p.y * sin(rad),
               p.x * sin(rad) + p.y * cos(rad));
}
struct line {
  double a, b, c;
};
void pointsToLine(point p1, point p2, line &l) {
  if (fabs(p1.x - p2.x) < 1e-9) {
    l.a = 1.0;
    l.b = 0.0;
    l.c = -p1.x;
  } else {
    l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
    l.b = 1.0;
    l.c = -(double)(l.a * p1.x) - p1.y;
  }
}
struct line2 {
  double m, c;
};
int pointsToLine2(point p1, point p2, line2 &l) {
  if (abs(p1.x - p2.x) < 1e-9) {
    l.m = 1e9;
    l.c = p1.x;
    return 0;
  } else {
    l.m = (double)(p1.y - p2.y) / (p1.x - p2.x);
    l.c = p1.y - l.m * p1.x;
    return 1;
  }
}
bool areParallel(line l1, line l2) {
  return (fabs(l1.a - l2.a) < 1e-9) && (fabs(l1.b - l2.b) < 1e-9);
}
bool areSame(line l1, line l2) {
  return areParallel(l1, l2) && (fabs(l1.c - l2.c) < 1e-9);
}
bool areIntersect(line l1, line l2, point &p) {
  if (areParallel(l1, l2)) return false;
  p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
  if (fabs(l1.b) > 1e-9)
    p.y = -(l1.a * p.x + l1.c);
  else
    p.y = -(l2.a * p.x + l2.c);
  return true;
}
struct vec {
  double x, y;
  vec(double _x, double _y) : x(_x), y(_y) {}
};
vec toVec(point a, point b) { return vec(b.x - a.x, b.y - a.y); }
vec scale(vec v, double s) { return vec(v.x * s, v.y * s); }
point translate(point p, vec v) { return point(p.x + v.x, p.y + v.y); }
void pointSlopeToLine(point p, double m, line &l) {
  l.a = -m;
  l.b = 1;
  l.c = -((l.a * p.x) + (l.b * p.y));
}
void closestPoint(line l, point p, point &ans) {
  line perpendicular;
  if (fabs(l.b) < 1e-9) {
    ans.x = -(l.c);
    ans.y = p.y;
    return;
  }
  if (fabs(l.a) < 1e-9) {
    ans.x = p.x;
    ans.y = -(l.c);
    return;
  }
  pointSlopeToLine(p, 1 / l.a, perpendicular);
  areIntersect(l, perpendicular, ans);
}
void reflectionPoint(line l, point p, point &ans) {
  point b;
  closestPoint(l, p, b);
  vec v = toVec(p, b);
  ans = translate(translate(p, v), v);
}
double dot(vec a, vec b) { return (a.x * b.x + a.y * b.y); }
double norm_sq(vec v) { return v.x * v.x + v.y * v.y; }
double distToLine(point p, point a, point b, point &c) {
  vec ap = toVec(a, p), ab = toVec(a, b);
  double u = dot(ap, ab) / norm_sq(ab);
  c = translate(a, scale(ab, u));
  return dist(p, c);
}
double distToLineSegment(point p, point a, point b, point &c) {
  vec ap = toVec(a, p), ab = toVec(a, b);
  double u = dot(ap, ab) / norm_sq(ab);
  if (u < 0.0) {
    c = point(a.x, a.y);
    return dist(p, a);
  }
  if (u > 1.0) {
    c = point(b.x, b.y);
    return dist(p, b);
  }
  return distToLine(p, a, b, c);
}
double angle(point a, point o, point b) {
  vec oa = toVec(o, a), ob = toVec(o, b);
  return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob)));
}
double cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }
bool ccw(point p, point q, point r) {
  return cross(toVec(p, q), toVec(p, r)) > 0;
}
bool collinear(point p, point q, point r) {
  return fabs(cross(toVec(p, q), toVec(p, r))) < 1e-9;
}
void Line2Point(line l, point &a, point &b) {
  if (l.a == 0) {
    double c = -l.c / l.b;
    a = point(-1, c);
    b = point(1, c);
  } else if (l.b == 0) {
    double c = -l.c / l.a;
    a = point(c, -1);
    b = point(c, 1);
  } else {
    double c0 = -(l.c + l.a) / l.b;
    a = point(1, c0);
    double c1 = -(l.c + (1 + c0) * l.b) / l.a;
    b = point(c1, (1 + c0));
  }
}
int main() {
  int n;
  point h, s;
  cin >> h.x >> h.y >> s.x >> s.y;
  cin >> n;
  int ans = 0;
  while (n--) {
    line l;
    cin >> l.a >> l.b >> l.c;
    point a, b;
    Line2Point(l, a, b);
    if (ccw(a, b, h) != ccw(a, b, s)) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
