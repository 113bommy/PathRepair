#include <bits/stdc++.h>
using namespace std;
long double eps = 1e-09;
struct point {
  long double x, y;
  point(long double a, long double b) {
    x = a;
    y = b;
  }
  point(){};
};
struct segment {
  point p1, p2;
  segment(const point& a, const point& b) {
    p1 = a;
    p2 = b;
  }
  segment() {}
  bool on(const point&) const;
};
struct line {
  long double a, b, c;
  line(const point& p1, const point& p2) {
    a = p1.y - p2.y;
    b = p2.x - p1.x;
    c = -a * p1.x - b * p1.y;
    long double nc = sqrt(a * a + b * b);
    a /= nc;
    b /= nc;
    c /= nc;
  }
  line(const segment& s) {
    a = s.p1.y - s.p2.y;
    b = s.p2.x - s.p1.x;
    c = -a * s.p1.x - b * s.p1.y;
    long double nc = sqrt(a * a + b * b);
    a /= nc;
    b /= nc;
    c /= nc;
  }
  line() {}
  bool on(const point&) const;
};
long double operator*(const point& a, const line& b) {
  return a.x * b.a + a.y * b.b + b.c;
}
inline long double operator*(const line& b, const point& a) { return a * b; }
bool ldless(long double a, long double b) {
  return (a < b + eps || a < b + eps * b);
}
bool ldeql(long double a, long double b) {
  return (abs(a - b) < eps || abs(a - b) < a * eps);
}
int sign(long double a) {
  if (ldeql(a, 0)) return 0;
  if (a > eps) return 1;
  return -1;
}
bool line::on(const point& a) const { return sign((*this) * a) == 0; }
bool segment::on(const point& a) const {
  if (line(*this).on(a) == false) return false;
  if (!(ldless(min(p1.x, p2.x), a.x) && ldless(a.x, max(p1.x, p2.x))))
    return false;
  if (!(ldless(min(p1.y, p2.y), a.y) && ldless(a.y, max(p1.y, p2.y))))
    return false;
  return true;
}
long double paralel(const line& a, const line& b) {
  return ldeql(a.a * b.b, a.b * b.a);
}
long double eql(const line& a, const line& b) {
  return ldeql(a.a * b.b, a.b * b.a) && ldeql(a.a * b.c, a.c * b.a) &&
         ldeql(a.c * b.b, a.b * b.c);
}
bool intersec(const segment& a, const segment& b) {
  line l1(a);
  line l2(b);
  if (paralel(l1, l2)) {
    if (!eql(l1, l2)) return false;
    if (b.on(a.p1) || b.on(a.p2)) return true;
    if (a.on(b.p1) || a.on(b.p2)) return true;
    return false;
  }
  if (sign(b.p1 * l1) * sign(b.p2 * l1) == 1) return false;
  if (sign(a.p1 * l2) * sign(a.p2 * l2) == 1) return false;
  return true;
}
bool wintersec(const segment& a, const segment& b) {
  line l1(a);
  line l2(b);
  if (paralel(l1, l2)) return false;
  if (sign(b.p1 * l1) * sign(b.p2 * l1) == 1) return false;
  if (sign(a.p1 * l2) * sign(a.p2 * l2) == 1) return false;
  return true;
}
line serper(const segment& a) {
  point p1((a.p1.x + a.p2.x) / 2, (a.p1.y + a.p2.y) / 2);
  line l1(a);
  line l2;
  l2.a = -l1.b;
  l2.b = l1.a;
  l2.c = -l2.a * p1.x - l2.b * p1.y;
  return l2;
}
line per(const segment& a, const point& p1) {
  line l1(a);
  line l2;
  l2.a = -l1.b;
  l2.b = l1.a;
  l2.c = -l2.a * p1.x - l2.b * p1.y;
  return l2;
}
point intersecl(const line& a, const line& b) {
  point p;
  p.x = -(a.c * b.b - b.c * a.b) / (a.a * b.b - a.b * b.a);
  p.y = -(a.a * b.c - b.a * a.c) / (a.a * b.b - a.b * b.a);
  return p;
}
void YES() {
  printf("YES\n");
  exit(0);
}
void NO() {
  printf("NO\n");
  exit(0);
}
point operator-(point a, point b) { return point(a.x - b.x, a.y - b.y); }
point operator+(point a, point b) { return point(a.x + b.x, a.y + b.y); }
point operator*(point a, long double b) { return point(a.x * b, a.y * b); }
long double f(const point& a, const point& b, const segment& s, long double t) {
  point p1 = (s.p2 - s.p1) * t + s.p1;
  line l(s);
  point a1 = intersecl(per(s, b), line(a, p1));
  return abs(abs(b * l) - abs(a1 * l));
}
point findotr(const point& a, const point& b, segment s) {
  long double lf = -1e8;
  long double r = 1e8;
  line l(s);
  line tmp = per(s, a);
  if (sign(s.p1 * tmp) == -1) {
    tmp.a *= -1;
    tmp.b *= -1;
    tmp.c *= -1;
  }
  if (s.p1 * tmp > s.p2 * tmp) {
    swap(s.p1, s.p2);
  }
  long double dx = s.p2.x - s.p1.x;
  long double dy = s.p2.y - s.p1.y;
  if (sign(b * tmp) == 1) {
    point p = intersecl(tmp, l);
    if (sign(dx) != 0)
      lf = (p.x - s.p1.x) / dx;
    else
      lf = (p.y - s.p1.y) / dy;
    p = intersecl(per(s, b), l);
    if (sign(dx) != 0)
      r = (p.x - s.p1.x) / dx;
    else
      r = (p.y - s.p1.y) / dy;
  } else {
    point p = intersecl(tmp, l);
    if (sign(dx) != 0)
      lf = (p.x - s.p1.x) / dx;
    else
      lf = (p.y - s.p1.y) / dy;
    p = intersecl(per(s, b), l);
    if (sign(dx) != 0)
      r = (p.x - s.p1.x) / dx;
    else
      r = (p.y - s.p1.y) / dy;
    swap(lf, r);
  }
  for (int i = 0; i < 1000; i++) {
    long double t1 = lf + (r - lf) / 3;
    long double t2 = r - (r - lf) / 3;
    long double f1 = f(a, b, s, t1);
    long double f2 = f(a, b, s, t2);
    if (f1 < f2)
      r = t2;
    else
      lf = t1;
  }
  point p = (s.p1 + (s.p2 - s.p1) * ((lf + r) / 2));
  if (sign(f(a, b, s, (lf + r) / 2)) != 0 || s.on(p) == false) NO();
  return p;
}
int main() {
  point p1, p2;
  segment s1, s2;
  cin >> p1.x >> p1.y >> p2.x >> p2.y;
  cin >> s1.p1.x >> s1.p1.y >> s1.p2.x >> s1.p2.y;
  cin >> s2.p1.x >> s2.p1.y >> s2.p2.x >> s2.p2.y;
  segment ab(p1, p2);
  if (!wintersec(ab, s1) && !wintersec(ab, s2)) YES();
  line l2(s2);
  if (sign(p1 * l2) * sign(p2 * l2) != 1) NO();
  point po = findotr(p1, p2, s2);
  if (intersec(s1, segment(p1, po)) || intersec(s1, segment(p2, po))) NO();
  YES();
  return 0;
}
