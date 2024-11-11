#include <bits/stdc++.h>
using namespace std;
const long double inf = 2e18 + 10;
const int N = 1e3 + 5;
const int ITER = 150;
long double sqr(long double x) { return x * x; }
struct point {
  long double x, y;
  point() {}
  point(long double x, long double y) : x(x), y(y) {}
  void read() {
    double t1, t2;
    scanf("%lf%lf", &t1, &t2);
    x = t1;
    y = t2;
  }
  point operator-(const point &a) const { return point(x - a.x, y - a.y); }
  point operator+(const point &a) const { return point(x + a.x, y + a.y); }
  long double length() const { return sqrt(sqr(x) + sqr(y)); }
  point norm() const { return point(x / length(), y / length()); }
  point rotate() const { return point(-y, x); }
  point operator*(long double m) { return point(x * m, y * m); }
};
bool intersection(const point &a, const point &b, long double r) {
  if ((a - b).length() <= 2 * r) return true;
  return false;
}
point p[N];
int n;
long double Ro(const point &A, const point &B, const point &C) {
  long double l = -1e9, r = 1e9;
  long double m1, m2;
  point v = (B - A).norm();
  for (int i = 0; i < ITER; ++i) {
    m1 = l + (r - l) / 3;
    m2 = r - (r - l) / 3;
    point x = A + v * m1;
    point y = A + v * m2;
    if ((C - x).length() < (C - y).length())
      r = m2;
    else
      l = m1;
  }
  return (C - (A + v * l)).length();
}
bool ok(const point &A, const point &C, const point &B, long double m) {
  if (Ro(A, B, C) > 2 * m) return true;
  return false;
}
bool check(long double m) {
  for (int i = 0; i < n; ++i) {
    if (intersection(p[i], p[i + 1], m)) return false;
  }
  for (int i = 0; i < n; ++i) {
    if (!ok(p[i], p[i + 1], p[i + 2], m)) return false;
  }
  return true;
}
void solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    p[i].read();
  }
  p[n] = p[0];
  p[n + 1] = p[1];
  long double m, l = 0, r = inf;
  for (int i = 0; i < ITER; ++i) {
    m = (l + r) / 2;
    if (check(m))
      l = m;
    else
      r = m;
  }
  printf("%.9lf\n", (double)m);
}
int main() {
  solve();
  return 0;
}
