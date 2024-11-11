#include <bits/stdc++.h>
using namespace std;
int Sig(double a) {
  if (a < -1e-5)
    return -1;
  else if (a > 1e-5)
    return 1;
  else
    return 0;
}
struct Point {
  double x, y;
  Point() {}
  Point(double x0, double y0) : x(x0), y(y0) {}
  void in() { scanf("%lf%lf", &x, &y); }
  Point operator*(double t) { return Point(t * x, t * y); }
  double operator*(Point pt) { return x * pt.y - y * pt.x; }
  double operator^(Point pt) { return pt.x * x + pt.y * y; }
  Point operator+(Point pt) { return Point(x + pt.x, y + pt.y); }
  Point operator-(Point pt) { return Point(x - pt.x, y - pt.y); }
  bool operator==(Point pt) {
    if (fabs(x - pt.x) < 1e-5 && fabs(y - pt.y) < 1e-5)
      return true;
    else
      return false;
  }
};
struct Triangle {
  Point p[4];
  void in() {
    for (int i = 0; i < 3; i++) p[i].in();
    if ((p[1] - p[0]) * (p[2] - p[0]) < 0) swap(p[0], p[1]);
    p[3] = p[0];
  }
} T[110];
double dis(Point a, Point b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
struct Line {
  Point p, q;
  Line() {}
  Line(Point p0, Point q0) : p(p0), q(q0) {}
};
Point Intersect(Line u, Line v) {
  Point ret = u.p;
  double t =
      ((u.p.x - v.p.x) * (v.p.y - v.q.y) - (u.p.y - v.p.y) * (v.p.x - v.q.x)) /
      ((u.p.x - u.q.x) * (v.p.y - v.q.y) - (u.p.y - u.q.y) * (v.p.x - v.q.x));
  ret.x += (u.q.x - u.p.x) * t;
  ret.y += (u.q.y - u.p.y) * t;
  return ret;
}
bool Is_InLine(Point o, Line l) {
  double x1 = min(l.p.x, l.q.x);
  double x2 = max(l.p.x, l.q.x);
  double y1 = min(l.p.y, l.q.y);
  double y2 = max(l.p.y, l.q.y);
  if (Sig(o.x - x1) >= 0 && Sig(x2 - o.x) >= 0 && Sig(o.y - y1) >= 0 &&
      Sig(y2 - o.y) >= 0)
    return true;
  else
    return false;
}
bool Is_Parallel(Line u, Line v) {
  Point p = u.p - u.q;
  Point q = v.p - v.q;
  return fabs(p.x * q.y - q.x * p.y) < 1e-5;
}
bool Is_Same(Line u, Line v) {
  Point p = u.p - u.q;
  Point q = v.p - u.q;
  return Is_Parallel(u, v) && fabs(p * q) < 1e-5;
}
Point pp[1000010];
int qq;
bool cmp(Point a, Point b) {
  if (Sig(a.x - b.x) == 0) return a.y < b.y;
  return a.x < b.x;
}
int n;
bool InAny(Point o) {
  for (int i = 0; i < n; i++) {
    bool flag = true;
    for (int a = 0; a < 3; a++) {
      if (Sig((T[i].p[a + 1] - T[i].p[a]) * (o - T[i].p[a])) <= 0) flag = false;
    }
    if (flag) return true;
  }
  return false;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) T[i].in();
  double ans = 0;
  for (int i = 0; i < n; i++)
    for (int a = 0; a < 3; a++) {
      Line l = Line(T[i].p[a], T[i].p[a + 1]);
      qq = 0;
      pp[qq++] = l.p;
      pp[qq++] = l.q;
      for (int j = 0; j < n; j++) {
        if (i == j) continue;
        for (int b = 0; b < 3; b++) {
          Line g = Line(T[j].p[b], T[j].p[b + 1]);
          if (Is_Parallel(l, g)) {
            if (Is_Same(l, g)) {
              if (l.p == g.p || l.p == g.q) pp[qq++] = l.p;
              if (l.q == g.p || l.q == g.q) pp[qq++] = l.q;
            }
          } else {
            Point o = Intersect(l, g);
            if (Is_InLine(o, l) && Is_InLine(o, g)) pp[qq++] = o;
          }
        }
      }
      sort(pp, pp + qq, cmp);
      for (int i = 1; i < qq; i++) {
        Point o = (pp[i - 1] + pp[i]) * 0.5;
        if (!InAny(o)) ans += dis(pp[i - 1], pp[i]);
      }
    }
  printf("%.10f\n", ans);
  return 0;
}
