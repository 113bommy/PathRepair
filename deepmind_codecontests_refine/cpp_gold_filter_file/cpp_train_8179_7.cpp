#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
int sgn(double x) {
  if (fabs(x) < eps) return 0;
  return (x < 0) ? (-1) : (1);
}
typedef class Point {
 public:
  double x, y;
  Point(double x = 0.0, double y = 0.0) : x(x), y(y) {}
} Point;
Point operator+(Point a, Point b) { return Point(a.x + b.x, a.y + b.y); }
Point operator-(Point a, Point b) { return Point(a.x - b.x, a.y - b.y); }
Point operator*(Point a, double k) { return Point(a.x * k, a.y * k); }
Point operator/(Point a, double k) { return Point(a.x / k, a.y / k); }
bool operator==(Point a, Point b) { return !sgn(a.x - b.x) && !sgn(a.y - b.y); }
double dot(Point a, Point b) { return a.x * b.x + a.y * b.y; }
double length(Point a) { return sqrt(dot(a, a)); }
Point normal(Point a) {
  double d = length(a);
  if (d == 0) {
    int a = 0 / 0;
  }
  return a / d;
}
Point getPerpend(Point A, Point B, Point v) {
  double k = dot(A - B, v) / dot(v, v);
  return B + v * k;
}
typedef class Segment {
 public:
  Point a, b;
  double s, t;
  Segment(Point a, Point b, double s, double t) : a(a), b(b), s(s), t(t) {}
  double get_t(Point p) {
    if (sgn(a.x - b.x)) {
      double dx = (b.x - a.x) / (t - s);
      return (p.x - a.x) / dx + s;
    }
    double dy = (b.y - a.y) / (t - s);
    return (p.y - a.y) / dy + s;
  }
} Segment;
typedef class Event {
 public:
  double p;
  int sgn;
  Event(double p, int sgn) : p(p), sgn(sgn) {}
  bool operator<(Event e) const {
    if (::sgn(p - e.p) != 0) return p < e.p;
    return sgn < e.sgn;
  }
} Event;
typedef class Position {
 public:
  int id;
  double d;
  Position() {}
  Position(int id, double d) : id(id), d(d) {}
  Point toPoint();
  Position fix();
} Position;
ostream &operator<<(ostream &os, Point p) {
  os << "(" << p.x << ", " << p.y << ")";
  return os;
}
int n, m;
Point *P;
Point *v;
double *len, C, Cm;
vector<Segment> *D;
inline void init() {
  scanf("%d%d", &n, &m);
  P = new Point[n + 1];
  v = new Point[n + 1];
  len = new double[(n + 1)];
  D = new vector<Segment>[(m + 1)];
  for (int i = 0; i < n; i++) {
    scanf("%lf%lf", &P[i].x, &P[i].y);
  }
  for (int i = 0; i < n; i++) {
    v[i] = P[(i + 1) % n] - P[i];
    len[i] = length(v[i]);
    C += len[i];
  }
  Cm = C / m;
}
Point getIntersecting(Segment seg, double mid) {
  if (seg.a == seg.b) {
    double d = dot(seg.a, seg.a);
    return (d <= mid * mid) ? (Point(seg.s, seg.t)) : (Point(1e9, -1e9));
  }
  Point v = normal(seg.b - seg.a);
  Point P = getPerpend(Point(0, 0), seg.a, v);
  double d = mid * mid - dot(P, P);
  if (d < 0) return Point(1e9, -1e9);
  d = sqrt(d);
  Point L = P - v * d;
  Point R = P + v * d;
  return Point(max(seg.get_t(L), seg.s), min(seg.get_t(R), seg.t));
}
vector<Event> E;
bool check(double mid) {
  E.clear();
  for (int i = 0; i < m; i++) {
    for (auto seg : D[i]) {
      Point rt = getIntersecting(seg, mid);
      if (rt.x <= rt.y) {
        E.push_back(Event(rt.x, 1));
        E.push_back(Event(rt.y, -1));
      }
    }
  }
  sort(E.begin(), E.end());
  int sum = 0;
  for (auto e : E) {
    sum += e.sgn;
    if (sum >= m) {
      return true;
    }
  }
  return false;
}
Position operator+(Position a, double dist) {
  a.d += dist;
  return a.fix();
}
Point Position ::toPoint() { return P[id] + v[id] * (d / len[id]); }
Position Position ::fix() {
  while (sgn(d - len[id]) >= 0) d -= len[id], id = (id + 1) % n;
  return *this;
}
inline void solve() {
  Position cur(0, 0);
  for (int i = 0; i < m; i++) {
    double s = 0;
    Position nxt = cur + Cm;
    while (s < Cm) {
      double d = min(len[cur.id] - cur.d, len[nxt.id] - nxt.d);
      d = min(Cm - s, d);
      Point a = nxt.toPoint() - cur.toPoint();
      cur = cur + d;
      nxt = nxt + d;
      Point b = nxt.toPoint() - cur.toPoint();
      D[i].push_back(Segment(a, b, s, s + d));
      s += d;
    }
  }
  double l = 0, r = 1e6;
  for (int t = 1; t <= 128 && l + eps < r; t++) {
    double mid = (l + r) / 2;
    if (check(mid)) {
      r = mid;
    } else {
      l = mid;
    }
  }
  printf("%.9lf\n", r);
}
int main() {
  init();
  solve();
  return 0;
}
