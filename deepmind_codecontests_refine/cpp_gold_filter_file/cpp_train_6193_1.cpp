#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const double EPS = 1e-16;
struct CPoint {
  double x, y;
  int i;
  CPoint(double xx, double yy) : x(xx), y(yy) {}
  CPoint() {}
  void Read() { scanf("%lf%lf", &x, &y); }
};
struct CLine {
  CPoint a, b;
  CLine(CPoint aa, CPoint bb) : a(aa), b(bb) {}
  CLine() {}
  void Read() { scanf("%lf%lf%lf%lf", &a.x, &a.y, &b.x, &b.y); }
};
CPoint operator+(CPoint a, CPoint b) { return CPoint(a.x + b.x, a.y + b.y); }
CPoint operator-(CPoint a, CPoint b) { return CPoint(a.x - b.x, a.y - b.y); }
CPoint operator*(CPoint a, double k) { return CPoint(k * a.x, k * a.y); }
CPoint operator*(double k, CPoint a) { return CPoint(k * a.x, k * a.y); }
double operator*(CPoint a, CPoint b) { return a.x * b.x + a.y * b.y; }
CPoint operator/(CPoint a, double k) { return CPoint(a.x / k, a.y / k); }
double operator^(CPoint a, CPoint b) { return a.x * b.y - a.y * b.x; }
double cross(CPoint a, CPoint b) { return a.x * b.y - a.y * b.x; }
double Length(CPoint p) { return sqrt(p * p); }
CPoint unit(CPoint p) { return 1.0 / Length(p) * p; }
double project(CPoint p, CPoint n) { return p * (unit(n)); }
double area(CPoint a, CPoint b) { return a ^ b * 0.5; }
bool isZero(double x) { return -EPS < x && x < EPS; }
int Cmp(double x) {
  if (isZero(x)) {
    return 0;
  }
  if (x > 0) {
    return 1;
  }
  return -1;
}
double dist(CPoint p, CPoint q) { return Length(p - q); }
double dist(CPoint p, CLine l) {
  return fabs((p - l.a) ^ (p - l.b)) / Length(l.a - l.b);
}
CPoint Rotate(CPoint a, CPoint b, double alpha) {
  CPoint p = b - a;
  return CPoint(a.x + (p.x * cos(alpha) - p.y * sin(alpha)),
                a.y + (p.x * sin(alpha) + p.y * cos(alpha)));
}
int sideOfLine(CPoint p, CLine l) {
  double res = (p - l.a) ^ (p - l.b);
  if (isZero(res)) {
    return 0;
  } else {
    return res > 0 ? 1 : -1;
  }
}
CLine Vertical(CPoint p, CLine l) {
  return CLine(p, p + (Rotate(l.b, l.a, PI / 2) - l.a));
}
CPoint root(CPoint p, CLine l) {
  return l.a + project(p - l.a, l.b - l.a) * unit(l.b - l.a);
}
double angle(CLine l, CLine m) {
  return acos(fabs(project(l.b - l.a, m.b - m.a) / Length(l.b - l.a)));
}
bool PointOnSegment(CPoint p, CPoint a, CPoint b) {
  return Cmp(cross(p - a, b - a)) == 0 && Cmp((p - a) * (p - b)) <= 0;
}
CPoint GetIntersect(CLine l, CLine m, string &s) {
  if (isZero(cross(l.b - l.a, m.b - m.a))) {
    if (!sideOfLine(l.a, m)) {
      s = "LINE";
    } else {
      s = "NONE";
    }
    return CPoint(0, 0);
  }
  s = "POINT";
  double t = cross(m.b - m.a, l.a - m.a) / cross(l.b - l.a, m.b - m.a);
  return l.a + (l.b - l.a) * t;
}
CPoint GetIntersect(CLine l, CLine m) {
  double t = cross(m.b - m.a, l.a - m.a) / cross(l.b - l.a, m.b - m.a);
  return l.a + (l.b - l.a) * t;
}
bool IsCross(CLine l, CLine m) {
  return sideOfLine(l.a, m) * sideOfLine(l.b, m) <= 0 &&
         sideOfLine(m.a, l) * sideOfLine(m.b, l) <= 0;
}
int pos[300005];
bool cmp(CPoint a, CPoint b) {
  if (isZero(a.x - b.x)) {
    return a.y < b.y;
  }
  return a.x < b.x;
}
double cross(CPoint a, CPoint b, CPoint c) {
  return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}
int Graham(CPoint *Pts, CPoint *st, int n) {
  sort(Pts, Pts + n, cmp);
  int m = 0;
  for (int i = 0; i < n; i++) {
    if (i > 0 && Pts[i].x == Pts[i - 1].x && Pts[i].y == Pts[i - 1].y) {
      pos[i] = i - 1;
      continue;
    }
    pos[i] = i;
    while (m > 1 && Cmp(cross(st[m - 2], st[m - 1], Pts[i])) < 0) {
      m--;
    }
    st[m].i = Pts[i].i;
    st[m++] = Pts[i];
  }
  int k = m;
  for (int i = n - 2; i >= 0; i--) {
    while (m > k && Cmp(cross(st[m - 2], st[m - 1], Pts[i]) < 0)) {
      m--;
    }
    st[m].i = Pts[i].i;
    st[m++] = Pts[i];
  }
  return n > 1 ? m - 1 : m;
}
CPoint a[300005], b[300005];
bool v[300005];
int main() {
  int n;
  double minx = 10000.0, miny = 10000.0;
  memset(v, false, sizeof(v));
  pos[0] = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    a[i].Read();
    a[i].x = 100.0 / a[i].x;
    a[i].y = 100.0 / a[i].y;
    minx = min(minx, a[i].x);
    miny = min(miny, a[i].y);
    a[i].i = i;
  }
  int cnt = Graham(a, b, n);
  for (int i = 0; i < cnt; i++) {
    v[b[i].i] = true;
    if (isZero(b[i].y - miny)) {
      break;
    }
  }
  for (int i = 0; i < n; i++) {
    if (v[a[pos[i]].i]) {
      v[a[i].i] = true;
    }
  }
  for (int i = 0; i < n; i++) {
    if (v[i]) {
      printf("%d ", i + 1);
    }
  }
  printf("\n");
  return 0;
}
