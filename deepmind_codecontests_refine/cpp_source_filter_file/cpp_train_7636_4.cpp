#include <bits/stdc++.h>
using namespace std;
struct point {
  double x, y;
  point(double x, double y) : x(x), y(y) {}
  point() {}
  inline void read() { scanf("%lf%lf", &x, &y); }
  inline double len() const { return sqrt(x * x + y * y); }
  inline double len2() const { return x * x + y * y; }
  inline point rot() { return point(-y, x); }
};
inline int sgn(double a) {
  if (a > 1e-7)
    return 1;
  else if (a < -1e-7)
    return -1;
  return 0;
}
inline point operator-(const point &a, const point &b) {
  return point(a.x - b.x, a.y - b.y);
}
inline point operator+(const point &a, const point &b) {
  return point(a.x + b.x, a.y + b.y);
}
inline point operator*(const point &a, double b) {
  return point(b * a.x, b * a.y);
}
inline point operator*(double b, const point &a) {
  return point(b * a.x, b * a.y);
}
inline double operator*(const point &a, const point &b) {
  return a.x * b.x + a.y * b.y;
}
inline double operator%(const point &a, const point &b) {
  return a.x * b.y - a.y * b.x;
}
inline bool operator==(const point &a, const point &b) {
  return sgn(a.x - b.x) == 0 && sgn(a.y - b.y) == 0;
}
inline bool operator!=(const point &a, const point &b) { return !(a == b); }
inline double dist(const point &a, const point &b) { return (a - b).len(); }
struct line {
  point a, b, v;
  line() {}
  line(const point &a, const point &b) : a(a), b(b), v(b - a) {}
};
double sqr(double a) { return a * a; }
inline double dist(const point &a, const line &b) {
  return abs((a - b.a) % b.v) / b.v.len();
}
point operator*(const line &a, const line &b) {
  return b.a + (((a.a - b.a) % a.v) / (b.v % a.v)) * b.v;
}
bool operator*(const point &a, const line &b) {
  return ((a - b.a) * b.v) * ((a - b.b) * b.v) < -1e-7;
}
bool Solve(point a, point b, point c) {
  if (a == b || b == c || c == a) return false;
  if (sgn((a - b) % (c - b)) == 0) return false;
  line l0((a + b) * 0.5, (a + b) * 0.5 + (b - a).rot()),
      l1(1.5 * b - 0.5 * c, 1.5 * b - 0.5 * c + (c - b).rot());
  point p[4];
  p[0] = l0 * l1;
  p[1] = 2 * b - p[0];
  p[3] = 2 * a - p[0];
  p[2] = 2 * c - p[1];
  if (sgn((p[1] - p[0]) % (p[2] - p[1])) > 1) reverse(p, p + 4);
  for (int i = 0; i < 4; i++) {
    if (sgn((p[(i + 1) % 4] - p[i]) % (p[(i + 2) % 4] - p[(i + 1) % 4])) >= 0)
      return false;
  }
  printf("YES\n");
  for (int i = 0; i < 4; i++) printf("%lf %lf ", p[i].x, p[i].y);
  printf("\n");
  return true;
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    point a, b, c;
    a.read(), b.read(), c.read();
    if (Solve(a, b, c)) continue;
    if (Solve(a, c, b)) continue;
    if (Solve(b, a, c)) continue;
    if (Solve(b, c, a)) continue;
    if (Solve(c, a, b)) continue;
    if (Solve(c, b, a)) continue;
    printf("NO\n\n");
  }
  return 0;
}
