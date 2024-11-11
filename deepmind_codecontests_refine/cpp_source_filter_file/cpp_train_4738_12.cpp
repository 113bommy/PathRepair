#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8, pi = acos(-1.0);
int cmp(double x) { return (x > eps) - (x < eps); }
double sqr(double x) { return x * x; }
struct Point {
  double x, y;
  Point(double a = 0, double b = 0) : x(a), y(b) {}
  void input() { scanf("%lf%lf", &x, &y); }
  bool operator<(const Point& R) const {
    if (cmp(x - R.x) == 0) return cmp(y - R.y) < 0;
    return cmp(x - R.x) < 0;
  }
  bool operator==(const Point& R) const {
    return cmp(x - R.x) == 0 && cmp(y - R.y) == 0;
  }
  Point operator+(const Point& R) const { return Point(x + R.x, y + R.y); }
  Point operator-(const Point& R) const { return Point(x - R.x, y - R.y); }
  Point operator*(const double& R) const { return Point(x * R, y * R); }
  Point operator/(const double& R) const { return Point(x / R, y / R); }
  double operator^(const Point& R) const { return x * R.y - y * R.x; }
  double operator%(const Point& R) const { return x * R.x + y * R.y; }
  double len() { return sqrt(sqr(x) + sqr(y)); }
  double angle() { return atan2(y, x); }
} p[1010], a, b;
int n, m;
double calc() {
  vector<pair<long double, int> > pp;
  for (int i = 0; i < n; i++) {
    int l = cmp((p[i] - a) ^ (b - a));
    int r = cmp((p[i + 1] - a) ^ (b - a));
    if (l == r) continue;
    long double pos =
        ((p[i + 1] - p[i]) ^ (p[i + 1] - a)) / ((p[i + 1] - p[i]) ^ (b - a));
    if (l > r)
      pp.push_back(make_pair(pos, (!l || !r) ? -1 : -2));
    else
      pp.push_back(make_pair(pos, (!l || !r) ? 1 : 2));
  }
  sort(pp.begin(), pp.end());
  int now = 0;
  long double sum = 0;
  for (int i = 0; i + 1 < pp.size(); i++) {
    now += pp[i].second;
    if (now) sum += pp[i + 1].first - pp[i].first;
  }
  return sum * (b - a).len();
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) p[i].input();
  p[0] = p[n];
  for (int i = 0; i < m; i++) {
    a.input(), b.input();
    printf("%.12f\n", calc());
  }
  return 0;
}
