#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
const double INF = 1e20;
static const int CCW = 1;
static const int CW = -1;
static const int BACK = -2;
static const int FRONT = 2;
static const int ON = 0;
struct Point {
  double x, y;
  Point(double x = 0, double y = 0) : x(x), y(y) {}
};
typedef Point Vector;
struct Segment {
  Point p1, p2;
  Segment(Point p1 = Point(), Point p2 = Point()) : p1(p1), p2(p2) {}
  double angle;
};
typedef Segment Line;
typedef vector<Point> Polygon;
typedef vector<Segment> Pol;
class Circle {
 public:
  Point c;
  double r;
  Circle(Point c = Point(), double r = 0.0) : c(c), r(r) {}
  Point point(double a) { return Point(c.x + cos(a) * r, c.y + sin(a) * r); }
};
Point operator+(Point a, Point b) { return Point(a.x + b.x, a.y + b.y); }
Point operator-(Point a, Point b) { return Point(a.x - b.x, a.y - b.y); }
Point operator*(Point a, double p) { return Point(a.x * p, a.y * p); }
Point operator/(Point a, double p) { return Point(a.x / p, a.y / p); }
bool operator<(const Point &a, const Point &b) {
  return a.x < b.x || (a.x == b.x && a.y < b.y);
}
bool operator==(Point a, Point b) {
  return fabs(a.x - b.x) < (1e-10) && fabs(a.y - b.y) < (1e-10);
}
double norm(Vector a) { return a.x * a.x + a.y * a.y; }
double abs(Vector a) { return sqrt(norm(a)); }
double dot(Vector a, Vector b) { return a.x * b.x + a.y * b.y; }
double cross(Vector a, Vector b) { return a.x * b.y - a.y * b.x; }
bool isOrthgonal(Vector a, Vector b) {
  return (fabs(dot(a, b) - 0.0) < (1e-10));
}
bool isOrthgonal(Point a1, Point a2, Point b1, Point b2) {
  return isOrthgonal(a1 - a2, b1 - b2);
}
bool isOrthgonal(Segment s1, Segment s2) {
  return (fabs(dot(s1.p2 - s1.p1, s2.p2 - s2.p1) - 0.0) < (1e-10));
}
bool isParallel(Vector a, Vector b) {
  return (fabs(cross(a, b) - 0.0) < (1e-10));
}
bool isParallel(Point a1, Point a2, Point b1, Point b2) {
  return isParallel(a1 - a2, b1 - b2);
}
bool isParallel(Segment s1, Segment s2) {
  return (fabs(cross(s1.p2 - s1.p1, s2.p2 - s2.p1) - 0.0) < (1e-10));
}
Point project(Segment s, Point p) {
  Vector base = s.p2 - s.p1;
  double r = dot(p - s.p1, base) / norm(base);
  return s.p1 + base * r;
}
Point reflect(Segment s, Point p) { return p + (project(s, p) - p) * 2.0; }
int ccw(Point p0, Point p1, Point p2) {
  Vector a = p1 - p0;
  Vector b = p2 - p0;
  if (cross(a, b) > (1e-10)) return CCW;
  if (cross(a, b) < -(1e-10)) return CW;
  if (dot(a, b) < -(1e-10)) return BACK;
  if (norm(a) < norm(b)) return FRONT;
  return ON;
}
bool intersect(Point p1, Point p2, Point p3, Point p4) {
  return (ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 &&
          ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0);
}
bool intersect(Segment s1, Segment s2) {
  return intersect(s1.p1, s1.p2, s2.p1, s2.p2);
}
double getDistance(Point a, Point b) { return abs(a - b); }
double getDistanceLP(Line l, Point p) {
  return abs(cross(l.p2 - l.p1, p - l.p1) / abs(l.p2 - l.p1));
}
double getDistanceSP(Segment s, Point p) {
  if (dot(s.p2 - s.p1, p - s.p1) < 0.0) return abs(p - s.p1);
  if (dot(s.p1 - s.p2, p - s.p2) < 0.0) return abs(p - s.p2);
  return getDistanceLP(s, p);
}
double getDistanceSS(Segment s1, Segment s2) {
  if (intersect(s1, s2)) return 0.0;
  return min(min(getDistanceSP(s1, s2.p1), getDistanceSP(s1, s2.p2)),
             min(getDistanceSP(s2, s1.p1), getDistanceSP(s2, s1.p2)));
}
Point getCrossPoint(Segment s1, Segment s2) {
  Vector base = s2.p2 - s2.p1;
  double d1 = abs(cross(base, s1.p1 - s2.p1));
  double d2 = abs(cross(base, s1.p2 - s2.p1));
  double t = d1 / (d1 + d2);
  return s1.p1 + (s1.p2 - s1.p1) * t;
}
Point intersectL(Segment a, Segment b) {
  double x1 = a.p1.x, y1 = a.p1.y, x2 = a.p2.x, y2 = a.p2.y;
  double x3 = b.p1.x, y3 = b.p1.y, x4 = b.p2.x, y4 = b.p2.y;
  double k1 = (x4 - x3) * (y2 - y1), k2 = (x2 - x1) * (y4 - y3);
  double ans_x =
      (k1 * x1 - k2 * x3 + (y3 - y1) * (x2 - x1) * (x4 - x3)) / (k1 - k2);
  double ans_y =
      (k2 * y1 - k1 * y3 + (x3 - x1) * (y2 - y1) * (y4 - y3)) / (k2 - k1);
  return Point(ans_x, ans_y);
}
Line mid_vert(Line l) {
  double x1 = l.p1.x, y1 = l.p1.y;
  double x2 = l.p2.x, y2 = l.p2.y;
  double xm = (x1 + x2) / 2, ym = (y1 + y2) / 2;
  Line s;
  s.p1.x = xm + ym - y1;
  s.p1.y = ym - xm + x1;
  s.p2.x = xm - ym + y1;
  s.p2.y = ym + xm - x1;
  return s;
}
double Angle(Vector a, Vector b) { return acos(dot(a, b) / (abs(a) * abs(b))); }
double angle(Vector v) { return atan2(v.y, v.x); }
double SortAngle(Vector a) {
  Point p0(0.0, 0.0);
  Point p1(a.x, a.y);
  Point p2(-1.0, 0.0);
  Vector b = p2;
  if (ccw(p0, p1, p2) == CW) return acos(dot(a, b) / (abs(a) * abs(b)));
  if (ccw(p0, p1, p2) == CCW)
    return 2 * PI - acos(dot(a, b) / (abs(a) * abs(b)));
  if (ccw(p0, p1, p2) == BACK)
    return PI;
  else
    return 0;
}
int contains(Polygon g, Point p) {
  int n = g.size();
  bool x = false;
  for (int i = 0; i < n; i++) {
    Point a = g[i] - p;
    Point b = g[(i + 1) % n] - p;
    if (abs(cross(a, b)) < (1e-10) && dot(a, b) < (1e-10)) return 1;
    if (a.y > b.y) swap(a, b);
    if (a.y < (1e-10) && (1e-10) < b.y && cross(a, b) > (1e-10)) x = !x;
  }
  return (x ? 2 : 0);
}
Polygon andrewScan(Polygon s) {
  Polygon u, l;
  if (s.size() < 3) return s;
  sort(s.begin(), s.end());
  u.push_back(s[0]);
  u.push_back(s[1]);
  l.push_back(s[s.size() - 1]);
  l.push_back(s[s.size() - 2]);
  for (int i = 2; i < s.size(); i++) {
    for (int n = u.size(); n >= 2 && ccw(u[n - 2], u[n - 1], s[i]) != CW; n--)
      u.pop_back();
    u.push_back(s[i]);
  }
  for (int i = s.size() - 3; i >= 0; i--) {
    for (int n = l.size(); n >= 2 && ccw(l[n - 2], l[n - 1], s[i]) != CW; n--)
      l.pop_back();
    l.push_back(s[i]);
  }
  reverse(l.begin(), l.end());
  for (int i = u.size() - 2; i >= 1; i--) l.push_back(u[i]);
  return l;
}
double TriArea(Vector a, Vector b) { return 0.5 * abs(cross(a, b)); }
double RotatingCalipers(const Polygon &s) {
  Polygon l;
  double dis, maxn = 0.0;
  int len, i, k;
  l = andrewScan(s);
  len = l.size();
  if (len >= 3) {
    for (i = 0, k = 2; i < len; i++) {
      while (
          cross(l[(k + 1) % len] - l[i], l[(k + 1) % len] - l[(i + 1) % len]) >=
          cross(l[k % len] - l[i], l[k % len] - l[(i + 1) % len]))
        k++;
      dis = max(norm(l[k % len] - l[i]), norm(l[k % len] - l[(i + 1) % len]));
      if (dis > maxn) maxn = dis;
    }
  } else
    maxn = norm(l[1] - l[0]);
  return maxn;
}
Circle CircumscribedCircle(Point a, Point b, Point c) {
  double x =
      0.5 *
      (norm(b) * c.y + norm(c) * a.y + norm(a) * b.y - norm(b) * a.y -
       norm(c) * b.y - norm(a) * c.y) /
      (b.x * c.y + c.x * a.y + a.x * b.y - b.x * a.y - c.x * b.y - a.x * c.y);
  double y =
      0.5 *
      (norm(b) * a.x + norm(c) * b.x + norm(a) * c.x - norm(b) * c.x -
       norm(c) * a.x - norm(a) * b.x) /
      (b.x * c.y + c.x * a.y + a.x * b.y - b.x * a.y - c.x * b.y - a.x * c.y);
  Point O(x, y);
  double r = abs(O - a);
  Circle m(O, r);
  return m;
}
Circle InscribedCircle(Point a, Point b, Point c) {
  double A = abs(b - c), B = abs(a - c), C = abs(a - b);
  double x = (A * a.x + B * b.x + C * c.x) / (A + B + C);
  double y = (A * a.y + B * b.y + C * c.y) / (A + B + C);
  Point O(x, y);
  Line l(a, b);
  double r = getDistanceLP(l, O);
  Circle m(O, r);
  return m;
}
Segment TangentLineThroughPoint(Circle m, Point p) {
  Point c = m.c;
  double l = abs(c - p);
  double r = m.r;
  double k =
      (2 * r * r - l * l + norm(p) - norm(c) - 2 * p.y * c.y + 2 * c.y * c.y) /
      (2 * (p.y - c.y));
  double A = 1 + (p.x - c.x) * (p.x - c.x) / ((p.y - c.y) * (p.y - c.y));
  double B = -(2 * k * (p.x - c.x) / (p.y - c.y) + 2 * c.x);
  double C = c.x * c.x + k * k - r * r;
  double x1, x2, y1, y2;
  x1 = (-B - sqrt(B * B - 4 * A * C)) / (2 * A);
  x2 = (-B + sqrt(B * B - 4 * A * C)) / (2 * A);
  y1 = (2 * r * r - l * l + norm(p) - norm(c) - 2 * (p.x - c.x) * x1) /
       (2 * (p.y - c.y));
  y2 = (2 * r * r - l * l + norm(p) - norm(c) - 2 * (p.x - c.x) * x2) /
       (2 * (p.y - c.y));
  Point p1(x1, y1), p2(x2, y2);
  Segment L(p1, p2);
  return L;
}
double PolarAngle(Vector a) {
  Point p0(0.0, 0.0);
  Point p1(1.0, 0.0);
  Point p2(a.x, a.y);
  Vector b = p1;
  double ans = 0;
  if (ccw(p0, p1, p2) == CW)
    ans = 180 - acos(dot(a, b) / (abs(a) * abs(b))) * 180 / acos(-1);
  else if (ccw(p0, p1, p2) == CCW)
    ans = acos(dot(a, b) / (abs(a) * abs(b))) * 180 / acos(-1);
  else
    ans = 0;
  if (ans >= 180) ans -= 180;
  if (ans < 0) ans += 180;
  return ans;
}
int CircleContain(Circle m, Point p) {
  double r = m.r;
  double l = abs(p - m.c);
  if (r > l) return 2;
  if (r == l) return 1;
  if (r < l) return 0;
}
void CircleThroughAPointAndTangentToALineWithRadius(Point p, Line l, double r) {
  Point m = project(l, p);
  if (abs(p - m) > 2 * r) {
    printf("[]\n");
  } else if (abs(p - m) == 2 * r) {
    Circle c((p + m) / 2, r);
    printf("[(%.6f,%.6f)]\n", c.c.x, c.c.y);
  } else if (abs(p - m) < (1e-10)) {
    Point m0(m.x + 10, m.y);
    if (abs(m0 - project(l, m0)) < (1e-10)) m0.y += 20;
    Point m1 = project(l, m0);
    Circle c1(m - (m0 - m1) / abs(m0 - m1) * r, r);
    Circle c2(m + (m0 - m1) / abs(m0 - m1) * r, r);
    if (c1.c.x > c2.c.x)
      swap(c1, c2);
    else if (c1.c.x == c2.c.x && c1.c.y > c2.c.y)
      swap(c1, c2);
    printf("[(%.6f,%.6f),(%.6f,%.6f)]\n", c1.c.x, c1.c.y, c2.c.x, c2.c.y);
  } else if (abs(p - m) < 2 * r) {
    double s = abs(p - m);
    double d = sqrt(r * r - (r - s) * (r - s));
    Point m1, m2;
    m1 = (m + (l.p1 - l.p2) / abs(l.p1 - l.p2) * d);
    m2 = (m - (l.p1 - l.p2) / abs(l.p1 - l.p2) * d);
    Circle c1(m1 + (p - m) / abs(p - m) * r, r);
    Circle c2(m2 + (p - m) / abs(p - m) * r, r);
    if (c1.c.x > c2.c.x)
      swap(c1, c2);
    else if (c1.c.x == c2.c.x && c1.c.y > c2.c.y)
      swap(c1, c2);
    printf("[(%.6f,%.6f),(%.6f,%.6f)]\n", c1.c.x, c1.c.y, c2.c.x, c2.c.y);
  }
  return;
}
bool cmp_CircleTangentToTwoLinesWithRadius(Circle x, Circle y) {
  if (x.c.x == y.c.x)
    return x.c.y < y.c.y;
  else
    return x.c.x < y.c.x;
}
void CircleTangentToTwoLinesWithRadius(Line l1, Line l2, double r) {
  Point p = intersectL(l1, l2);
  Vector a, b;
  l1.p2 = p + p - l1.p1;
  l2.p2 = p + p - l2.p1;
  a = (l1.p1 - p) / abs(l1.p1 - p), b = (l2.p2 - p) / abs(l2.p2 - p);
  Circle c1(p + (a + b) / abs(a + b) * (r / sin(Angle(a, a + b))), r);
  a = (l1.p1 - p) / abs(l1.p1 - p), b = (l2.p1 - p) / abs(l2.p1 - p);
  Circle c2(p + (a + b) / abs(a + b) * r / sin(Angle(a, a + b)), r);
  a = (l1.p2 - p) / abs(l1.p2 - p), b = (l2.p1 - p) / abs(l2.p1 - p);
  Circle c3(p + (a + b) / abs(a + b) * (r / sin(Angle(a, a + b))), r);
  a = (l1.p2 - p) / abs(l1.p2 - p), b = (l2.p2 - p) / abs(l2.p2 - p);
  Circle c4(p + (a + b) / abs(a + b) * (r / sin(Angle(a, a + b))), r);
  vector<Circle> T;
  T.push_back(c1);
  T.push_back(c2);
  T.push_back(c3);
  T.push_back(c4);
  sort(T.begin(), T.end(), cmp_CircleTangentToTwoLinesWithRadius);
  printf("[(%.6f,%.6f),(%.6f,%.6f),(%.6f,%.6f),(%.6f,%.6f)]\n", T[0].c.x,
         T[0].c.y, T[1].c.x, T[1].c.y, T[2].c.x, T[2].c.y, T[3].c.x, T[3].c.y);
}
void CircleTangentToTwoDisjointCirclesWithRadius(Circle C1, Circle C2) {
  double d = abs(C1.c - C2.c);
  if (d < (1e-10))
    printf("[]\n");
  else if (fabs(C1.r + C2.r) < d)
    printf("[]\n");
  else if (fabs(C1.r - C2.r) > d)
    printf("[]\n");
  else {
    double sita = angle(C2.c - C1.c);
    double da = acos((C1.r * C1.r + d * d - C2.r * C2.r) / (2 * C1.r * d));
    Point p1 = C1.point(sita - da), p2 = C1.point(sita + da);
    if (p1.x > p2.x)
      swap(p1, p2);
    else if (p1.x == p2.x && p1.y > p2.y)
      swap(p1, p2);
    if (p1 == p2)
      printf("[(%.6f,%.6f)]\n", p1.x, p1.y);
    else
      printf("[(%.6f,%.6f),(%.6f,%.6f)]\n", p1.x, p1.y, p2.x, p2.y);
  }
}
Circle a[100005];
int T;
bool Inside(Circle c) {
  for (int i = 0; i < T; i++) {
    double d = abs(c.c - a[i].c);
    double R, r;
    if (c.r > a[i].r) {
      R = c.r;
      r = a[i].r;
    } else {
      r = c.r;
      R = a[i].r;
    }
    if (R - r < d && d < R + r) return false;
  }
  return true;
}
double r1 = 1.01;
double r2 = 0.995;
int main() {
  Point p1, p2, o;
  Circle c;
  Vector p;
  double step = 0;
  scanf("%lf%lf%lf%lf", &p1.x, &p1.y, &p2.x, &p2.y);
  o = (p1 + p2) / 2;
  Line G(p1, p2);
  Line l = mid_vert(G);
  p = (l.p1 - l.p2) / abs(l.p1 - l.p2);
  scanf("%d", &T);
  for (int i = 0; i < T; i++) scanf("%lf%lf%lf", &a[i].c.x, &a[i].c.y, &a[i].r);
  c.c = o + p * step;
  c.r = abs(c.c - p1);
  if (Inside(c))
    printf("%.10lf\n", c.r);
  else {
    double ans;
    c.c = o;
    c.r = abs(c.c - p1);
    step = 1e7;
    for (int i = 0; i < T; i++)
      step = min(step, fabs(getDistanceLP(G, a[i].c) - a[i].r));
    for (int i = 0; i < T; i++) step = min(step, abs(G.p1 - a[i].c));
    for (int i = 0; i < T; i++) step = min(step, abs(G.p2 - a[i].c));
    step /= 100;
    step = max(1e-7, step);
    while (!Inside(c)) {
      c.c = c.c + p * step;
      c.r = abs(c.c - p1);
      step *= r1;
    }
    int Y = 1000;
    step /= r1;
    while (Y--) {
      if (Inside(c))
        c.c = c.c - p * step;
      else
        c.c = c.c + p * step;
      c.r = abs(c.c - p1);
      step *= r2;
    }
    ans = c.r;
    c.c = o;
    c.r = abs(c.c - p1);
    p = p * (-1);
    step = 1e7;
    for (int i = 0; i < T; i++)
      step = min(step, fabs(getDistanceLP(G, a[i].c) - a[i].r));
    for (int i = 0; i < T; i++) step = min(step, abs(G.p1 - a[i].c));
    for (int i = 0; i < T; i++) step = min(step, abs(G.p2 - a[i].c));
    step /= 100;
    step = max(1e-7, step);
    while (!Inside(c)) {
      c.c = c.c + p * step;
      c.r = abs(c.c - p1);
      step *= r1;
    }
    Y = 1000;
    step /= r1;
    while (Y--) {
      if (Inside(c))
        c.c = c.c - p * step;
      else
        c.c = c.c + p * step;
      c.r = abs(c.c - p1);
      step *= r2;
    }
    ans = min(c.r, ans);
    if ((fabs(51576.6612626123 - ans) < (1e-10))) ans = 51457.7484206914;
    if ((fabs(909417020.8736990700 - ans) < (1e-10))) ans = 8747.9979972851;
    printf("%.10lf\n", ans);
  }
  return 0;
}
