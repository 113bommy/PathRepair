#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
struct Point {
  double x, y;
  Point() = default;
  Point(double x, double y) : x(x), y(y) {}
};
struct Line {
  double A, B, C;
  Line() = default;
  Line(double A, double B, double C) : A(A), B(B), C(C) {}
  Line(Point &p, Point &q)
      : A(q.y - p.y), B(p.x - q.x), C(p.y * q.x - p.x * q.y) {}
};
inline Point operator+(const Point &a, const Point &b) {
  return Point(a.x + b.x, a.y + b.y);
}
inline Point operator-(const Point &a, const Point &b) {
  return Point(a.x - b.x, a.y - b.y);
}
inline Point operator/(const Point &a, const double &o) {
  return Point(a.x / o, a.y / o);
}
int n, q;
double f[102333], ans[102333];
Point p[102333];
vector<tuple<double, int, double, double> > E;
void create_events(const Point &p, const Point &q, int k) {
  if (abs(q.x - p.x) < 1e-10) return;
  if (p.x > q.x)
    create_events(q, p, -k);
  else {
    double A = (q.y - p.y) / (q.x - p.x), B = p.y - p.x * A;
    E.emplace_back(p.x, 0, k * A, k * B);
    E.emplace_back(q.x, 0, -k * A, -k * B);
  }
}
Point getp(const Point &a, const Point &b, const Point &p) {
  return {(b.x - a.x) * (p.y - a.y) / (b.y - a.y) + a.x, p.y};
}
int main() {
  scanf("%d%d", &n, &q);
  int sp = 1;
  double area = 0;
  for (int i = 1; i <= n; ++i) scanf("%lf%lf", &p[i].x, &p[i].y);
  for (int i = 1; i <= n; ++i)
    if (p[i].y < p[sp].y) sp = i;
  for (int i = 1; i <= q; ++i)
    scanf("%lf", f + i), E.emplace_back(f[i], i, -1, -1);
  for (int i = 1; i <= n; ++i) {
    int j = i % n + 1;
    area += p[i].x * p[j].y - p[i].y * p[j].x;
    if (p[i].y > p[j].y)
      create_events(p[i], p[j], 1);
    else
      create_events(p[j], p[i], 1);
  }
  area = abs(area / 2.0);
  rotate(p + 1, p + sp, p + n + 1);
  Point M = p[1], MM;
  int L = 1, R = 1;
  for (int i = 1; i < n; ++i) {
    int LL = L + 1, RR = (R + n - 2) % n + 1;
    if (p[LL].y < p[RR].y)
      MM = (p[LL] + getp(p[R], p[RR], p[LL])) / 2.0, L = LL;
    else
      MM = (p[RR] + getp(p[L], p[LL], p[RR])) / 2.0, R = RR;
    create_events(M, MM, 2);
    M = MM;
  }
  sort(E.begin(), E.end());
  double a = 0, b = 0;
  double pos, A, B;
  int index;
  for (auto e : E) {
    tie(pos, index, A, B) = e;
    if (index)
      ans[index] = area + (a * pos * pos / 2.0 + b * pos);
    else
      (area -= (A * pos * pos / 2.0 + B * pos)), a += A, b += B;
  }
  for (int i = 1; i <= q; ++i) printf("%.12lf\n", ans[i]);
  return 0;
}
