#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-10;
const double inf = 1e20;
const double pi = acos(-1.0);
const int maxp = 50200;
int sgn(double x) {
  if (fabs(x) < eps) return 0;
  if (x < 0)
    return -1;
  else
    return 1;
}
inline double sqr(double x) { return x * x; }
struct Point {
  double x, y, ang;
  Point() {}
  Point(double _x, double _y) {
    x = _x;
    y = _y;
  }
  void input() { scanf("%lf%lf", &x, &y); }
  void output() { printf("%.2f %.2f\n", x, y); }
  bool operator==(Point b) const {
    return sgn(x - b.x) == 0 && sgn(y - b.y) == 0;
  }
  bool operator<(Point b) const {
    if (sgn(this->ang - b.ang) == 0) return this->x < b.x;
    return this->ang < b.ang;
  }
  Point operator-(const Point &b) const { return Point(x - b.x, y - b.y); }
  double operator^(const Point &b) const { return x * b.y - y * b.x; }
  double operator*(const Point &b) const { return x * b.x + y * b.y; }
  double len() { return hypot(x, y); }
  double len2() { return x * x + y * y; }
  double distance(Point p) { return hypot(x - p.x, y - p.y); }
  Point operator+(const Point &b) const { return Point(x + b.x, y + b.y); }
  Point operator*(const double &k) const { return Point(x * k, y * k); }
  Point operator/(const double &k) const { return Point(x / k, y / k); }
  double rad(Point a, Point b) {
    Point p = *this;
    return fabs(atan2(fabs((a - p) ^ (b - p)), (a - p) * (b - p)));
  }
  Point trunc(double r) {
    double l = len();
    if (!sgn(l)) return *this;
    r /= l;
    return Point(x * r, y * r);
  }
  Point rotleft() { return Point(-y, x); }
  Point rotright() { return Point(y, -x); }
  Point rotate(Point p, double angle) {
    Point v = (*this) - p;
    double c = cos(angle), s = sin(angle);
    return Point(p.x + v.x * c - v.y * s, p.y + v.x * s + v.y * c);
  }
};
struct Line {
  Point s, e;
  Line() {}
  Line(Point _s, Point _e) {
    s = _s;
    e = _e;
  }
  bool operator==(Line v) { return (s == v.s) && (e == v.e); }
  Line(Point p, double angle) {
    s = p;
    if (sgn(angle - pi / 2) == 0) {
      e = (s + Point(0, 1));
    } else {
      e = (s + Point(1, tan(angle)));
    }
  }
  Line(double a, double b, double c) {
    if (sgn(a) == 0) {
      s = Point(0, -c / b);
      e = Point(1, -c / b);
    } else if (sgn(b) == 0) {
      s = Point(-c / a, 0);
      e = Point(-c / a, 1);
    } else {
      s = Point(0, -c / b);
      e = Point(1, -(c + a) / b);
    }
  }
  void input() {
    s.input();
    e.input();
  }
  void adjust() {
    if (e < s) swap(s, e);
  }
  double length() { return s.distance(e); }
  double angle() {
    double k = atan2(e.y - s.y, e.x - s.x);
    if (sgn(k) < 0) k += pi;
    if (sgn(k - pi) == 0) k -= pi;
    return k;
  }
  int relation(Point p) {
    int c = sgn((p - s) ^ (e - s));
    if (c < 0)
      return 1;
    else if (c > 0)
      return 2;
    else
      return 3;
  }
  bool pointonseg(Point p) {
    return sgn((p - s) ^ (e - s)) == 0 && sgn((p - s) * (p - e)) <= 0;
  }
  bool parallel(Line v) { return sgn((e - s) ^ (v.e - v.s)) == 0; }
  int segcrossseg(Line v) {
    int d1 = sgn((e - s) ^ (v.s - s));
    int d2 = sgn((e - s) ^ (v.e - s));
    int d3 = sgn((v.e - v.s) ^ (s - v.s));
    int d4 = sgn((v.e - v.s) ^ (e - v.s));
    if ((d1 ^ d2) == -2 && (d3 ^ d4) == -2) return 2;
    return (d1 == 0 && sgn((v.s - s) * (v.s - e)) <= 0) ||
           (d2 == 0 && sgn((v.e - s) * (v.e - e)) <= 0) ||
           (d3 == 0 && sgn((s - v.s) * (s - v.e)) <= 0) ||
           (d4 == 0 && sgn((e - v.s) * (e - v.e)) <= 0);
  }
  int linecrossseg(Line v) {
    int d1 = sgn((e - s) ^ (v.s - s));
    int d2 = sgn((e - s) ^ (v.e - s));
    if ((d1 ^ d2) == -2) return 2;
    return (d1 == 0 || d2 == 0);
  }
  int linecrossline(Line v) {
    if ((*this).parallel(v)) return v.relation(s) == 3;
    return 2;
  }
  Point crosspoint(Line v) {
    double a1 = (v.e - v.s) ^ (s - v.s);
    double a2 = (v.e - v.s) ^ (e - v.s);
    return Point((s.x * a2 - e.x * a1) / (a2 - a1),
                 (s.y * a2 - e.y * a1) / (a2 - a1));
  }
  double dispointtoline(Point p) { return fabs((p - s) ^ (e - s)) / length(); }
  double dispointtoray(Point p) {
    if (sgn((p - s) * (e - s)) < 0) return p.distance(s);
    return dispointtoline(p);
  }
  double dispointtoseg(Point p) {
    if (sgn((p - s) * (e - s)) < 0 || sgn((p - e) * (s - e)) < 0)
      return min(p.distance(s), p.distance(e));
    return dispointtoline(p);
  }
  double dissegtoseg(Line v) {
    return min(min(dispointtoseg(v.s), dispointtoseg(v.e)),
               min(v.dispointtoseg(s), v.dispointtoseg(e)));
  }
  Point lineprog(Point p) {
    return s + (((e - s) * ((e - s) * (p - s))) / ((e - s).len2()));
  }
  Point symmetrypoint(Point p) {
    Point q = lineprog(p);
    return Point(2 * q.x - p.x, 2 * q.y - p.y);
  }
} ll1, ll2, ll3, ll4;
struct circle {
  Point p;
  double r;
  circle() {}
  circle(Point _p, double _r) {
    p = _p;
    r = _r;
  }
  circle(double x, double y, double _r) {
    p = Point(x, y);
    r = _r;
  }
  circle(Point a, Point b, Point c) {
    Line u = Line((a + b) / 2, ((a + b) / 2) + ((b - a).rotleft()));
    Line v = Line((b + c) / 2, ((b + c) / 2) + ((c - b).rotleft()));
    p = u.crosspoint(v);
    r = p.distance(a);
  }
  circle(Point a, Point b, Point c, bool t) {
    Line u, v;
    double m = atan2(b.y - a.y, b.x - a.x), n = atan2(c.y - a.y, c.x - a.x);
    u.s = a;
    u.e = u.s + Point(cos((n + m) / 2), sin((n + m) / 2));
    v.s = b;
    m = atan2(a.y - b.y, a.x - b.x), n = atan2(c.y - b.y, c.x - b.x);
    v.e = v.s + Point(cos((n + m) / 2), sin((n + m) / 2));
    p = u.crosspoint(v);
    r = Line(a, b).dispointtoseg(p);
  }
  void input() {
    p.input();
    scanf("%lf", &r);
  }
  void output() { printf("%.2lf %.2lf %.2lf\n", p.x, p.y, r); }
  bool operator==(circle v) { return (p == v.p) && sgn(r - v.r) == 0; }
  bool operator<(circle v) const {
    return ((p < v.p) || ((p == v.p) && sgn(r - v.r) < 0));
  }
  double area() { return pi * r * r; }
  double circumference() { return 2 * pi * r; }
  int relation(Point b) {
    double dst = b.distance(p);
    if (sgn(dst - r) < 0)
      return 2;
    else if (sgn(dst - r) == 0)
      return 1;
    return 0;
  }
  int relationseg(Line v) {
    double dst = v.dispointtoseg(p);
    if (sgn(dst - r) < 0)
      return 2;
    else if (sgn(dst - r) == 0)
      return 1;
    return 0;
  }
  int relationline(Line v) {
    double dst = v.dispointtoline(p);
    if (sgn(dst - r) < 0)
      return 2;
    else if (sgn(dst - r) == 0)
      return 1;
    return 0;
  }
  int relationcircle(circle v) {
    double d = p.distance(v.p);
    if (sgn(d - r - v.r) > 0) return 5;
    if (sgn(d - r - v.r) == 0) return 4;
    double l = fabs(r - v.r);
    if (sgn(d - r - v.r) < 0 && sgn(d - l) > 0) return 3;
    if (sgn(d - l) == 0) return 2;
    if (sgn(d - l) < 0) return 1;
  }
  int pointcrosscircle(circle v, Point &p1, Point &p2) {
    int rel = relationcircle(v);
    if (rel == 1 || rel == 5) return 0;
    double d = p.distance(v.p);
    double l = (d * d + r * r - v.r * v.r) / (2 * d);
    double h = sqrt(r * r - l * l);
    Point tmp = p + (v.p - p).trunc(l);
    p1 = tmp + ((v.p - p).rotleft().trunc(h));
    p2 = tmp + ((v.p - p).rotright().trunc(h));
    if (rel == 2 || rel == 4) return 1;
    return 2;
  }
  int pointcrossline(Line v, Point &p1, Point &p2) {
    if (!(*this).relationline(v)) return 0;
    Point a = v.lineprog(p);
    double d = v.dispointtoline(p);
    d = sqrt(r * r - d * d);
    if (sgn(d) == 0) {
      p1 = a;
      p2 = a;
      return 1;
    }
    p1 = a + (v.e - v.s).trunc(d);
    p2 = a - (v.e - v.s).trunc(d);
    return 2;
  }
  int gercircle(Point a, Point b, double r1, circle &c1, circle &c2) {
    circle x(a, r1), y(b, r1);
    int t = x.pointcrosscircle(y, c1.p, c2.p);
    if (!t) return 0;
    c1.r = c2.r = r;
    return t;
  }
  int getcircle(Line u, Point q, double r1, circle &c1, circle &c2) {
    double dis = u.dispointtoline(q);
    if (sgn(dis - r1 * 2) > 0) return 0;
    if (sgn(dis) == 0) {
      c1.p = q + ((u.e - u.s).rotleft().trunc(r1));
      c2.p = q + ((u.e - u.s).rotright().trunc(r1));
      c1.r = c2.r = r1;
      return 2;
    }
    Line u1 = Line((u.s + (u.e - u.s).rotleft().trunc(r1)),
                   (u.e + (u.e - u.s).rotleft().trunc(r1)));
    Line u2 = Line((u.s + (u.e - u.s).rotright().trunc(r1)),
                   (u.e + (u.e - u.s).rotright().trunc(r1)));
    circle cc = circle(q, r1);
    Point p1, p2;
    if (!cc.pointcrossline(u1, p1, p2)) cc.pointcrossline(u2, p1, p2);
    c1 = circle(p1, r1);
    if (p1 == p2) {
      c2 = c1;
      return 1;
    }
    c2 = circle(p2, r1);
    return 2;
  }
  int getcircle(Line u, Line v, double r1, circle &c1, circle &c2, circle &c3,
                circle &c4) {
    if (u.parallel(v)) return 0;
    Line u1 = Line(u.s + (u.e - u.s).rotleft().trunc(r1),
                   u.e + (u.e - u.s).rotleft().trunc(r1));
    Line u2 = Line(u.s + (u.e - u.s).rotright().trunc(r1),
                   u.e + (u.e - u.s).rotright().trunc(r1));
    Line v1 = Line(v.s + (v.e - v.s).rotleft().trunc(r1),
                   v.e + (v.e - v.s).rotleft().trunc(r1));
    Line v2 = Line(v.s + (v.e - v.s).rotright().trunc(r1),
                   v.e + (v.e - v.s).rotright().trunc(r1));
    c1.r = c2.r = c3.r = c4.r = r1;
    c1.p = u1.crosspoint(v1);
    c2.p = u1.crosspoint(v2);
    c3.p = u2.crosspoint(v1);
    c4.p = u2.crosspoint(v2);
    return 4;
  }
  int getcircle(circle cx, circle cy, double r1, circle &c1, circle &c2) {
    circle x(cx.p, r1 + cx.r), y(cy.p, r1 + cy.r);
    int t = x.pointcrosscircle(y, c1.p, c2.p);
    if (!t) return 0;
    c1.r = c2.r = r1;
    return t;
  }
  int tangentline(Point q, Line &u, Line &v) {
    int x = relation(q);
    if (x == 2) return 0;
    if (x == 1) {
      u = Line(q, q + (q - p).rotleft());
      v = u;
      return 1;
    }
    double d = p.distance(q);
    double l = r * r / d;
    double h = sqrt(r * r - l * l);
    u = Line(q, p + ((q - p).trunc(l) + (q - p).rotleft().trunc(h)));
    v = Line(q, p + ((q - p).trunc(l) + (q - p).rotright().trunc(h)));
    return 2;
  }
  double areacircle(circle v) {
    int rel = relationcircle(v);
    if (rel >= 4) return 0.0;
    if (rel <= 2) return min(area(), v.area());
    double d = p.distance(v.p);
    double hf = (r + v.r + d) / 2.0;
    double ss = 2 * sqrt(hf * (hf - r) * (hf - v.r) * (hf - d));
    double a1 = acos((r * r + d * d - v.r * v.r) / (2.0 * r * d));
    a1 = a1 * r * r;
    double a2 = acos((v.r * v.r + d * d - r * r) / (2.0 * v.r * d));
    a2 = a2 * v.r * v.r;
    return a1 + a2 - ss;
  }
  double areatriangle(Point a, Point b) {
    if (sgn((p - a) ^ (p - b)) == 0) return 0.0;
    Point q[5];
    int len = 0;
    q[len++] = a;
    Line l(a, b);
    Point p1, p2;
    if (pointcrossline(l, q[1], q[2]) == 2) {
      if (sgn((a - q[1]) * (b - q[1])) < 0) q[len++] = q[1];
      if (sgn((a - q[2]) * (b - q[2])) < 0) q[len++] = q[2];
    }
    q[len++] = b;
    if (len == 4 && sgn((q[0] - q[1]) * (q[2] - q[1])) > 0) swap(q[1], q[2]);
    double res = 0;
    for (int i = 0; i < len - 1; i++) {
      if (relation(q[i]) == 0 || relation(q[i + 1]) == 0) {
        double arg = p.rad(q[i], q[i + 1]);
        res += r * r * arg / 2.0;
      } else {
        res += fabs((q[i] - p) ^ (q[i + 1] - p)) / 2.0;
      }
    }
    return res;
  }
  double dis(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
  }
  Point o;
  double ri;
  void tt(Point p1, Point p2, Point p3) {
    double a, b, c, d, e, f;
    a = p2.y - p1.y;
    b = p3.y - p1.y;
    c = p2.x - p1.x;
    d = p3.x - p1.x;
    f = p3.x * p3.x + p3.y * p3.y - p1.x * p1.x - p1.y * p1.y;
    e = p2.x * p2.x + p2.y * p2.y - p1.x * p1.x - p1.y * p1.y;
    o.x = (a * f - b * e) / (2 * a * d - 2 * b * c);
    o.y = (d * e - c * f) / (2 * a * d - 2 * b * c);
    ri = dis(o, p1);
  }
  void getmincircover(Point p[], int n, circle &c) {
    random_shuffle(p, p + n);
    o = p[0];
    ri = 0;
    for (int i = 1; i < n; i++) {
      if (dis(p[i], o) > ri + eps) {
        o = p[i];
        ri = 0;
        for (int j = 0; j <= i - 1; j++) {
          if (dis(o, p[j]) > ri + eps) {
            o.x = (p[i].x + p[j].x) / 2;
            o.y = (p[i].y + p[j].y) / 2;
            ri = dis(o, p[j]);
            for (int k = 0; k <= j - 1; k++) {
              if (dis(o, p[k]) > ri + eps) {
                tt(p[i], p[j], p[k]);
              }
            }
          }
        }
      }
    }
    c.p = o;
    c.r = ri;
  }
} cc, ccc;
const int maxn = 1010;
struct circles {
  circle c[maxn];
  double ans[maxn];
  double pre[maxn];
  int n;
  circles() {}
  void add(circle cc) { c[n++] = cc; }
  bool inner(circle x, circle y) {
    if (x.relationcircle(y) != 1) return 0;
    return sgn(x.r - y.r) <= 0 ? 1 : 0;
  }
  void init_or() {
    bool mark[maxn] = {0};
    int i, j, k = 0;
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++)
        if (i != j && !mark[j]) {
          if ((c[i] == c[j]) || inner(c[i], c[j])) break;
        }
      if (j < n) mark[i] = 1;
    }
    for (i = 0; i < n; i++)
      if (!mark[i]) c[k++] = c[i];
    n = k;
  }
  void init_add() {
    int i, j, k;
    bool mark[maxn] = {0};
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++)
        if (i != j && !mark[j]) {
          if ((c[i] == c[j]) || inner(c[j], c[i])) break;
        }
      if (j < n) mark[i] = 1;
    }
    for (i = 0; i < n; i++)
      if (!mark[i]) c[k++] = c[i];
    n = k;
  }
  double areaarc(double th, double r) { return 0.5 * r * r * (th - sin(th)); }
  void getarea() {
    memset(ans, 0, sizeof(ans));
    vector<pair<double, int> > v;
    for (int i = 0; i < n; i++) {
      v.clear();
      v.push_back(make_pair(-pi, 1));
      v.push_back(make_pair(pi, -1));
      for (int j = 0; j < n; j++)
        if (i != j) {
          Point q = (c[j].p - c[i].p);
          double ab = q.len(), ac = c[i].r, bc = c[j].r;
          if (sgn(ab + ac - bc) <= 0) {
            v.push_back(make_pair(-pi, 1));
            v.push_back(make_pair(pi, -1));
            continue;
          }
          if (sgn(ab + bc - ac) <= 0) continue;
          if (sgn(ab - ac - bc) > 0) continue;
          double th = atan2(q.y, q.x),
                 fai = acos((ac * ac + ab * ab - bc * bc) / (2.0 * ac * ab));
          double a0 = th - fai;
          if (sgn(a0 + pi) < 0) a0 += 2 * pi;
          double a1 = th + fai;
          if (sgn(a1 - pi) > 0) a1 -= 2 * pi;
          if (sgn(a0 - a1) > 0) {
            v.push_back(make_pair(a0, 1));
            v.push_back(make_pair(pi, -1));
            v.push_back(make_pair(-pi, 1));
            v.push_back(make_pair(a1, -1));
          } else {
            v.push_back(make_pair(a0, 1));
            v.push_back(make_pair(a1, -1));
          }
        }
      sort(v.begin(), v.end());
      int cur = 0;
      for (int j = 0; j < v.size(); j++) {
        if (cur && sgn(v[j].first - pre[cur])) {
          ans[cur] += areaarc(v[j].first - pre[cur], c[i].r);
          ans[cur] += 0.5 * (Point(c[i].p.x + c[i].r * cos(pre[cur]),
                                   c[i].p.y + c[i].r * sin(pre[cur])) ^
                             Point(c[i].p.x + c[i].r * cos(v[j].first),
                                   c[i].p.y + c[i].r * sin(v[j].first)));
        }
        cur += v[j].second;
        pre[cur] = v[j].first;
      }
    }
  }
} C;
struct polygon {
  int n;
  Point p[maxp];
  Line l[maxp];
  void input(int _n) {
    n = _n;
    for (int i = 0; i < n; i++) p[i].input();
  }
  void add(Point q) { p[n++] = q; }
  void getline() {
    for (int i = 0; i < n; i++) {
      l[i] = Line(p[i], p[(i + 1) % n]);
    }
  }
  struct cmp {
    Point p;
    cmp(const Point &p0) { p = p0; }
    bool operator()(const Point &aa, const Point &bb) {
      Point a = aa, b = bb;
      int d = sgn((a - p) ^ (b - p));
      if (d == 0) {
        return sgn(a.distance(p) - b.distance(p)) < 0;
      }
      return d > 0;
    }
  };
  void norm() {
    Point mi = p[0];
    for (int i = 1; i < n; i++) mi = min(mi, p[i]);
    sort(p, p + n, cmp(mi));
  }
  void getconvex(polygon &convex) {
    sort(p, p + n);
    convex.n = n;
    for (int i = 0; i < min(n, 2); i++) {
      convex.p[i] = p[i];
    }
    if (convex.n == 2 && (convex.p[0] == convex.p[1])) convex.n--;
    if (n <= 2) return;
    int &top = convex.n;
    top = 1;
    for (int i = 2; i < n; i++) {
      while (top &&
             sgn((convex.p[top] - p[i]) ^ (convex.p[top - 1] - p[i])) <= 0)
        top--;
      convex.p[++top] = p[i];
    }
    int temp = top;
    convex.p[++top] = p[n - 2];
    for (int i = n - 3; i >= 0; i--) {
      while (top != temp &&
             sgn((convex.p[top] - p[i]) ^ (convex.p[top - 1] - p[i])) <= 0)
        top--;
      convex.p[++top] = p[i];
    }
    if (convex.n == 2 && (convex.p[0] == convex.p[1])) convex.n--;
    convex.norm();
  }
  void Graham(polygon &convex) {
    norm();
    int &top = convex.n;
    top = 0;
    if (n == 1) {
      top = 1;
      convex.p[0] = p[0];
      return;
    }
    if (n == 2) {
      top = 2;
      convex.p[0] = p[0];
      convex.p[1] = p[1];
      if (convex.p[0] == convex.p[1]) top--;
      return;
    }
    convex.p[0] = p[0];
    convex.p[1] = p[1];
    top = 2;
    for (int i = 2; i < n; i++) {
      while (top > 1 && sgn((convex.p[top - 1] - convex.p[top - 2]) ^
                            (p[i] - convex.p[top - 2])) <= 0)
        top--;
      convex.p[top++] = p[i];
    }
    if (convex.n == 2 && (convex.p[0] == convex.p[1])) convex.n--;
  }
  double dis(Point a, Point b, Point c) {
    return fabs((a - c) ^ (b - c) / (a - b).len());
  }
  double getD(polygon &convex, int &pos1, int &pos2) {
    double ans = 0.0;
    int pos = 1;
    convex.p[convex.n + 1] = convex.p[1];
    convex.p[convex.n] = convex.p[0];
    if (convex.n == 0 || convex.n == 1) return 0;
    if (convex.n == 2) return (convex.p[1] - convex.p[0]).len();
    for (int i = 1; i <= convex.n; i++) {
      while (dis(convex.p[i], convex.p[i + 1], convex.p[pos]) <=
             dis(convex.p[i], convex.p[i + 1], convex.p[pos + 1]))
        pos = pos % convex.n + 1;
      double tmp1 = (convex.p[i] - convex.p[pos]).len(),
             tmp2 = (convex.p[i + 1] - convex.p[pos]).len();
      if (tmp1 > ans) {
        ans = tmp1;
        pos1 = i % n;
        pos2 = pos % n;
      }
      if (tmp2 > ans) {
        ans = tmp2;
        pos1 = (i + 1) % n;
        pos2 = pos % n;
      }
    }
    convex.p[convex.n + 1] = Point(0, 0);
    convex.p[convex.n] = Point(0, 0);
    return ans;
  }
  bool isconvex() {
    bool s[2];
    memset(s, false, sizeof(s));
    for (int i = 0; i < n; i++) {
      int j = (i + 1) % n;
      int k = (j + 1) % n;
      s[sgn((p[j] - p[i]) ^ (p[k] - p[i])) + 1] = true;
      if (s[0] && s[2]) return false;
    }
    return true;
  }
  int relationpoint(Point q) {
    for (int i = 0; i < n; i++) {
      if (p[i] == q) return 3;
    }
    getline();
    for (int i = 0; i < n; i++) {
      if (l[i].pointonseg(q)) return 2;
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      int j = (i + 1) % n;
      int k = sgn((q - p[j]) ^ (p[i] - p[j]));
      int u = sgn(p[i].y - q.y);
      int v = sgn(p[j].y - q.y);
      if (k > 0 && u < 0 && v >= 0) cnt++;
      if (k < 0 && v < 0 && u >= 0) cnt--;
    }
    return cnt != 0;
  }
  void convexcut(Line u, polygon &po) {
    int &top = po.n;
    top = 0;
    for (int i = 0; i < n; i++) {
      int d1 = sgn((u.e - u.s) ^ (p[i] - u.s));
      int d2 = sgn((u.e - u.s) ^ (p[(i + 1) % n] - u.s));
      if (d1 >= 0) po.p[top++] = p[i];
      if (d1 * d2 < 0) po.p[top++] = u.crosspoint(Line(p[i], p[(i + 1) % n]));
    }
  }
  double getcircumference() {
    double sum = 0;
    for (int i = 0; i < n; i++) {
      sum += p[i].distance(p[(i + 1) % n]);
    }
    return sum;
  }
  double getarea() {
    double sum = 0;
    for (int i = 0; i < n; i++) {
      sum += (p[i] ^ p[(i + 1) % n]);
    }
    return fabs(sum) / 2;
  }
  bool getdir() {
    double sum = 0;
    for (int i = 0; i < n; i++) sum += (p[i] ^ p[(i + 1) % n]);
    if (sgn(sum) > 0) return 1;
    return 0;
  }
  Point getbarycentre() {
    Point ret(0, 0);
    double area = 0;
    for (int i = 1; i < n - 1; i++) {
      double tmp = (p[i] - p[0]) ^ (p[i + 1] - p[0]);
      if (sgn(tmp) == 0) continue;
      area += tmp;
      ret.x += (p[0].x + p[i].x + p[i + 1].x) / 3 * tmp;
      ret.y += (p[0].y + p[i].y + p[i + 1].y) / 3 * tmp;
    }
    if (sgn(area)) ret = ret / area;
    return ret;
  }
  double cross(Point A, Point B, Point C) { return (B - A) ^ (C - A); }
  double dot(Point A, Point B, Point C) { return (B - A) * (C - A); }
  double minRectangleCover() {
    if (n < 3) return 0.0;
    p[n] = p[0];
    double ans = -1;
    int r = 1, pp = 1, q;
    for (int i = 0; i < n; i++) {
      while (sgn(cross(p[i], p[i + 1], p[r + 1]) -
                 cross(p[i], p[i + 1], p[r])) >= 0)
        r = (r + 1) % n;
      while (sgn(dot(p[i], p[i + 1], p[pp + 1]) - dot(p[i], p[i + 1], p[pp])) >=
             0)
        pp = (pp + 1) % n;
      if (i == 0) q = pp;
      while (sgn(dot(p[i], p[i + 1], p[q + 1]) - dot(p[i], p[i + 1], p[q])) <=
             0)
        q = (q + 1) % n;
      double d = (p[i] - p[i + 1]).len2();
      double tmp = cross(p[i], p[i + 1], p[r]) *
                   (dot(p[i], p[i + 1], p[pp]) - dot(p[i], p[i + 1], p[q])) / d;
      if (ans < 0 || ans > tmp) {
        ans = tmp;
        ll1.s = p[i];
        ll1.e = p[i + 1];
        double an1 = ll1.angle();
        double an2 = an1 + pi / 2;
        if (an2 >= pi) an2 -= pi;
        ll2 = Line(p[pp], an2);
        ll3 = Line(p[q], an2);
        ll4 = Line(p[r], an1);
      }
    }
    return ans;
  }
  vector<Point> convexCut(const vector<Point> &ps, Point q1, Point q2) {
    vector<Point> qs;
    int n = ps.size();
    for (int i = 0; i < n; i++) {
      Point p1 = ps[i], p2 = ps[(i + 1) % n];
      int d1 = sgn((q2 - q1) ^ (p1 - q1)), d2 = sgn((q2 - q1) ^ (p2 - q1));
      if (d1 >= 0) qs.push_back(p1);
      if (d1 * d2 < 0) qs.push_back(Line(p1, p2).crosspoint(Line(q1, q2)));
    }
    return qs;
  }
} PO, po;
Point s1[maxp], s2[maxp];
void getMinkowski(polygon thi, polygon convex, polygon &po) {
  for (int i = 0; i < thi.n - 1; i++) s1[i] = thi.p[i + 1] - thi.p[i];
  s1[thi.n - 1] = thi.p[0] - thi.p[thi.n - 1];
  for (int i = 0; i < convex.n - 1; i++) s2[i] = convex.p[i + 1] - convex.p[i];
  s2[convex.n - 1] = convex.p[0] - convex.p[convex.n - 1];
  int tot;
  po.p[tot = 0] = thi.p[0] + convex.p[0];
  int pos1 = 0, pos2 = 0;
  while (pos1 < thi.n && pos2 < convex.n) {
    ++tot;
    po.p[tot] =
        po.p[tot - 1] + ((s1[pos1] ^ s2[pos2]) >= 0 ? s1[pos1++] : s2[pos2++]);
  }
  while (pos1 < thi.n) {
    ++tot;
    po.p[tot] = po.p[tot - 1] + s1[pos1++];
  }
  while (pos2 < convex.n) {
    ++tot;
    po.p[tot] = po.p[tot - 1] + s2[pos2++];
  }
  po.n = tot + 1;
  po.p[po.n] = po.p[0];
}
struct halfplane : public Line {
  double angle;
  halfplane() {}
  halfplane(Point _s, Point _e) {
    s = _s;
    e = _e;
  }
  halfplane(Line v) {
    s = v.s;
    e = v.e;
  }
  void calcangle() { angle = atan2(e.y - s.y, e.x - s.x); }
  bool operator<(const halfplane &b) const { return angle < b.angle; }
};
struct halfplanes {
  int n;
  halfplane hp[maxp];
  Point p[maxp];
  int que[maxp];
  int st, ed;
  void push(halfplane tmp) { hp[n++] = tmp; }
  void unique() {
    int m = 1;
    for (int i = 1; i < n; i++) {
      if (sgn(hp[i].angle - hp[i - 1].angle) != 0)
        hp[m++] = hp[i];
      else if (sgn((hp[m - 1].e - hp[m - 1].s) ^ (hp[i].s - hp[m - 1].s)) > 0) {
        hp[m - 1] = hp[i];
      }
    }
    n = m;
  }
  bool halfplaneinsert() {
    for (int i = 0; i < n; i++) hp[i].calcangle();
    sort(hp, hp + n);
    unique();
    que[st = 0] = 0;
    que[ed = 1] = 1;
    p[1] = hp[0].crosspoint(hp[1]);
    for (int i = 2; i < n; i++) {
      while (st < ed && sgn((hp[i].e - hp[i].s) ^ (p[ed] - hp[i].s)) < 0) ed--;
      while (st < ed && sgn((hp[i].e - hp[i].s) ^ (p[st + 1] - hp[i].s)) < 0)
        st++;
      que[++ed] = i;
      if (hp[i].parallel(hp[que[ed - 1]])) return false;
      p[ed] = hp[i].crosspoint(hp[que[ed - 1]]);
    }
    while (st < ed &&
           sgn((hp[que[st]].e - hp[que[st]].s) ^ (p[ed] - hp[que[st]].s)) < 0)
      ed--;
    while (st < ed && sgn((hp[que[ed]].e - hp[que[ed]].s) ^
                          (p[st + 1] - hp[que[ed]].s)) < 0)
      st++;
    if (st + 1 >= ed) return false;
    return true;
  }
  void getconvex(polygon &con) {
    p[st] = hp[que[st]].crosspoint(hp[que[ed]]);
    con.n = ed - st + 1;
    for (int j = st, i = 0; j <= ed; i++, j++) con.p[i] = p[j];
  }
} HP;
set<Point> sp;
set<Point>::iterator pre, suc;
set<Point>::iterator PRE(set<Point>::iterator x) {
  if (x == sp.begin()) return --sp.end();
  return --x;
}
set<Point>::iterator SUC(set<Point>::iterator x) {
  if ((++x) == sp.end()) return sp.begin();
  return x;
}
Point pp[202];
int main() {
  int t;
  scanf("%d", &t);
  Point pt = Point(0, 0);
  int num;
  scanf("%d", &num);
  pp[0].input();
  pt = pt + pp[0];
  scanf("%d", &num);
  pp[1].input();
  pt = pt + pp[1];
  scanf("%d", &num);
  pp[2].input();
  pt = pt + pp[2];
  pt = pt / 3.0;
  pp[0] = pp[0] - pt;
  pp[1] = pp[1] - pt;
  pp[2] = pp[2] - pt;
  pp[0].ang = atan2(pp[0].y, pp[0].x);
  pp[1].ang = atan2(pp[1].y, pp[1].x);
  pp[2].ang = atan2(pp[2].y, pp[2].x);
  sp.insert(pp[0]);
  sp.insert(pp[1]);
  sp.insert(pp[2]);
  t -= 3;
  int op;
  Point ppt;
  while (t--) {
    scanf("%d", &op);
    ppt.input();
    ppt = ppt - pt;
    ppt.ang = atan2(ppt.y, ppt.x);
    if ((suc = sp.lower_bound(ppt)) == sp.end()) suc = sp.begin();
    pre = PRE(suc);
    if (op == 1) {
      double dt = (*pre - ppt) ^ (*suc - ppt);
      if (dt >= 0) continue;
      sp.insert(ppt);
      set<Point>::iterator it = sp.find(ppt);
      set<Point>::iterator itq = PRE(it);
      set<Point>::iterator itqq = PRE(itq);
      while (((*itqq - *itq) ^ (*it - *itq)) >= 0) {
        sp.erase(itq);
        itq = itqq;
        itqq = PRE(itq);
      }
      itq = SUC(it);
      itqq = SUC(itq);
      while (((*it - *itq) ^ (*itqq - *itq)) >= 0) {
        sp.erase(itq);
        itq = itqq;
        itqq = SUC(itq);
      }
    } else {
      double dt = (*pre - ppt) ^ (*suc - ppt);
      if (sgn(dt) >= 0)
        puts("YES");
      else
        puts("NO");
    }
  }
  return 0;
}
