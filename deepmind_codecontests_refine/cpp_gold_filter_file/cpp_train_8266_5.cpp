#include <bits/stdc++.h>
using namespace std;
const double EPS = 1E-10;
const double PI = acos(-1.0);
inline int sgn(double x) { return x < -EPS ? -1 : x > EPS; }
struct Point {
  double x, y;
  Point() {}
  Point(double a, double b) : x(a), y(b) {}
  Point operator+(const Point &p) const { return Point(x + p.x, y + p.y); }
  Point operator-(const Point &p) const { return Point(x - p.x, y - p.y); }
  Point operator*(double d) const { return Point(x * d, y * d); }
  Point operator/(double d) const { return Point(x / d, y / d); }
  int read() { return scanf("%lf%lf", &x, &y); }
  int write() { return printf("%lf,%lf\n", x, y); }
  Point rot(double d) const {
    double c = cos(d), s = sin(d);
    return Point(x * c - y * s, y * c + x * s);
  }
};
inline double crs(const Point &o, const Point &s, const Point &t) {
  return (s.x - o.x) * (t.y - o.y) - (s.y - o.y) * (t.x - o.x);
}
Point line_inter(Point p1, Point p2, Point q1, Point q2) {
  double a1 = crs(q1, q2, p1), a2 = -crs(q1, q2, p2);
  return (p1 * a2 + p2 * a1) / (a1 + a2);
}
const double INF = 1e100;
int n;
double l, r;
Point point[20], o(0, 0), ox(1, 0);
double alpha[20];
double dp[1 << 20];
double dfs(int mask) {
  if (mask == 0) return l;
  double &ans = dp[mask];
  if (ans != -INF) return ans;
  for (int i = 0; i < n; ++i) {
    if (((mask >> i) & 1) == 0) continue;
    double last = dfs(mask ^ (1 << i));
    Point p = (Point(last, 0) - point[i]).rot(alpha[i]);
    if (sgn(p.y) >= 0) ans = INF;
    ans = max(ans, line_inter(o, ox, point[i], point[i] + p).x);
  }
  return ans;
}
int main() {
  scanf("%d%lf%lf", &n, &l, &r);
  for (int i = 0; i < n; ++i) {
    point[i].read();
    scanf("%lf", &alpha[i]);
    alpha[i] = alpha[i] / 180.0 * PI;
  }
  fill(dp, dp + (1 << n), -INF);
  printf("%.9f\n", min(r - l, dfs((1 << n) - 1) - l));
  return 0;
}
