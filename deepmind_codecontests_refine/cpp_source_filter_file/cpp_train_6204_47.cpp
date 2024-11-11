#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.);
const double EPS = 1E-9;
int Zero(double O) { return fabs(O) <= EPS; }
struct Point {
  double x, y;
  void read() { scanf("%lf%lf", &x, &y); }
  void Print() { printf("%lf %lf\n", x, y); }
  void init(double _x, double _y) {
    x = _x;
    y = _y;
  }
  double operator*(const Point &b) const { return x * b.y - y * b.x; }
  double operator^(const Point &b) const { return x * b.x + y * b.y; }
  Point operator-(const Point &b) const { return (Point){x - b.x, y - b.y}; }
  Point operator+(const Point &b) const { return (Point){x + b.x, y + b.y}; }
  int operator<(const Point &b) const { return x < b.x || x == b.x && y < b.y; }
  int operator==(const Point &b) const {
    return Zero(x - b.x) && Zero(y - b.y);
  }
  void Rotate(double alpha) {
    double _x = x * cos(alpha) - y * sin(alpha);
    double _y = y * cos(alpha) + x * sin(alpha);
    x = _x;
    y = _y;
  }
} a[1005], b[1005], ERRORPOINT = (Point){1e99, 1e99};
struct Line {
  Point p, q;
} A[1005], B[1005];
Point Intersection(Line A, Line B) {
  Point ret = A.p;
  double u = (A.p - B.p) * (B.p - B.q);
  double v =
      (A.p.x - A.q.x) * (B.p.y - B.q.y) - (A.p.y - A.q.y) * (B.p.x - B.q.x);
  if (Zero(v)) return (Point){1e99, 1e99};
  u /= v;
  ret.x += (A.q.x - A.p.x) * u;
  ret.y += (A.q.y - A.p.y) * u;
  return ret;
}
int Inline(Line A, Point O) {
  return ((A.q - A.p) ^ (O - A.p)) >= -EPS && ((A.p - A.q) ^ (O - A.q)) >= -EPS;
}
double Calc(Point now, Point dir, Point goal) {
  goal = goal - now;
  return (goal.x + goal.y) / (dir.x + dir.y);
}
int main() {
  int n, x1, y1, x2, y2;
  scanf("%d", &n);
  scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
  static Point a[4];
  a[0].init(x1, y1);
  a[1].init(x2, y1);
  a[2].init(x2, y2);
  a[3].init(x1, y2);
  double L = 0, R = 1e100;
  for (int i = 1; i <= n; i++) {
    Point now, dir;
    Line t;
    now.read();
    dir.read();
    if (Zero(dir.x) && Zero(dir.y)) {
      if (now.x >= x1 - EPS && now.x <= x2 + EPS && now.y >= y1 - EPS &&
          now.y <= y2 + EPS)
        continue;
      return puts("-1"), 0;
    }
    if (dir.y == 0 && (now.y == y1 || now.y == y2)) return puts("-1"), 0;
    if (dir.x == 0 && (now.x == x1 || now.x == x2)) return puts("-1"), 0;
    t.p = now;
    t.q = now + dir;
    vector<Point> cur;
    cur.clear();
    for (int k = 0; k < 4; k++) {
      Line l;
      l.p = a[k];
      l.q = a[(k + 1) % 4];
      Point g = Intersection(l, t);
      if (g == ERRORPOINT || !Inline(l, g)) continue;
      cur.push_back(g);
      for (int v = 0; v + 1 < cur.size(); v++)
        if (g == cur[v]) {
          cur.pop_back();
          break;
        }
    }
    if (cur.size() <= 1) return puts("-1"), 0;
    assert(cur.size() == 2);
    double Time1 = Calc(now, dir, cur[0]);
    double Time2 = Calc(now, dir, cur[1]);
    Time1 = max(Time1, 0.);
    Time2 = max(Time2, 0.);
    if (Time1 > Time2) swap(Time1, Time2);
    L = max(L, Time1);
    R = min(R, Time2);
  }
  if (L + 1e-11 >= R || L > R) return puts("-1"), 0;
  printf("%.10f\n", L);
}
