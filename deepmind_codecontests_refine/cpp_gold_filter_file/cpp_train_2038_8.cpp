#include <bits/stdc++.h>
using namespace std;
struct point {
  double x, y;
  point(double x, double y) : x(x), y(y) {}
  point() {}
  inline void read() { scanf("%lf%lf", &x, &y); }
  inline double len() const { return sqrt(x * x + y * y); }
  inline double len2() const { return x * x + y * y; }
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
  return ((a - b.a) * b.v) * ((a - b.b) * b.v) < 1e-7;
}
int n;
point points[1000], S, T;
point c[2];
int belong[2];
int main() {
  S.read();
  T.read();
  scanf("%d", &n);
  for (int i = 0; i < n; i++) points[i].read();
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    line a = line(S, T), b = line(points[i], points[(i + 1) % n]);
    if (sgn(a.v % b.v) == 0) continue;
    point p = a * b;
    for (int j = 0; j <= cnt; j++) {
      if (j == cnt && p * a && p * b && cnt < 2) {
        c[cnt] = p;
        belong[cnt++] = i;
        break;
      }
      if (c[j] == p) break;
    }
  }
  if (cnt < 2) {
    printf("%.15lf\n", (S - T).len());
    return 0;
  }
  if ((c[0] - S).len() > (c[1] - S).len())
    swap(c[0], c[1]), swap(belong[0], belong[1]);
  double ans = (c[0] - c[1]).len() * 2;
  double cir = 0, l = 0;
  for (int i = 0; i < n; i++) cir += (points[i] - points[(i + 1) % n]).len();
  l += (points[(belong[1] + 1) % n] - c[1]).len() +
       (points[belong[0]] - c[0]).len();
  for (int i = (belong[1] + 1) % n; i != belong[0]; i = (i + 1) % n)
    l += (points[(i + 1) % n] - points[i]).len();
  ans = min(ans, min(l, cir - l));
  ans += (c[0] - S).len() + (c[1] - T).len();
  printf("%.15lf\n", ans);
  return 0;
}
