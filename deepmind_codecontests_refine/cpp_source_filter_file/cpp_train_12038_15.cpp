#include <bits/stdc++.h>
using namespace std;
inline char nc() {
  static char buf[100000], *l = buf, *r = buf;
  return l == r && (r = (l = buf) + fread(buf, 1, 100000, stdin), l == r)
             ? EOF
             : *l++;
}
template <class T>
void read(T &x) {
  x = 0;
  int f = 1, ch = nc();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = nc();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 - '0' + ch;
    ch = nc();
  }
  x *= f;
}
const double pi = acos(-1.0);
const double eps = 1e-9;
int n;
vector<pair<double, double> > rec0, rec1;
inline int sign(double a) {
  if (fabs(a) < eps) return 0;
  return a < 0 ? -1 : 1;
}
struct Point {
  double x, y;
  Point(double x = 0, double y = 0) : x(x), y(y) {}
  inline friend Point operator-(const Point &a, const Point &b) {
    return Point(a.x - b.x, a.y - b.y);
  }
  inline friend Point operator+(const Point &a, const Point &b) {
    return Point(a.x + b.x, a.y + b.y);
  }
  inline friend Point operator*(const Point &a, const double &b) {
    return Point(a.x * b, a.y * b);
  }
};
Point p0, p1, m, v;
namespace geometry {
inline double dot(Point a, Point b) { return a.x * b.x + a.y * b.y; }
inline double det(Point a, Point b) { return a.x * b.y - a.y * b.x; }
inline double norm(Point a) { return dot(a, a); }
inline double abs(Point a) { return sqrt(norm(a)); }
inline Point rotate(Point a, double b) {
  return Point(a.x * cos(b) - a.y * sin(b), a.x * sin(b) + a.y * cos(b));
}
}  // namespace geometry
inline Point cal(double d) { return m + v * d; }
inline double judge(double mid, Point a, double b) {
  Point O = cal(mid);
  double r = geometry ::abs(p0 - O), d = geometry ::abs(a - O);
  return r + b - d;
}
double find(Point a, double b) {
  double l = -1e12, r = 1e12, f = 1;
  if (sign(geometry ::det(p0 - m, a - m)) != 1) f = -1;
  int T = 70;
  while (T--) {
    double mid = (l + r) / 2.0;
    if (judge(f * mid, a, b) >= 0)
      r = mid;
    else
      l = mid;
  }
  return l * f;
}
double sol(const vector<pair<double, double> > &v) {
  double now = 0;
  for (unsigned int i = 0; i < v.size(); ++i) {
    if (now < v[i].first) return now;
    now = max(now, v[i].second + 1e-15);
  }
  return now;
}
int main() {
  read(p0.x), read(p0.y);
  read(p1.x), read(p1.y);
  m = (p0 + p1) * 0.5;
  v = geometry ::rotate(p0 - m, pi / 2.0);
  read(n);
  for (int i = 1; i <= n; ++i) {
    Point p;
    int r;
    read(p.x), read(p.y), read(r);
    double L = find(p, r), R = find(p, -r);
    L += 1e-15, R -= 1e-15;
    if (L > R) swap(L, R);
    if (R < 0)
      rec0.push_back(pair<double, double>(-R, -L));
    else if (L > 0)
      rec1.push_back(pair<double, double>(L, R));
    else {
      rec0.push_back(pair<double, double>(0, -L));
      rec1.push_back(pair<double, double>(0, R));
    }
  }
  sort(rec0.begin(), rec0.end());
  sort(rec1.begin(), rec1.end());
  double a = sol(rec0), b = sol(rec1);
  printf("%.10lf\n", geometry ::abs(p0 - cal(min(a, b))));
  return 0;
}
