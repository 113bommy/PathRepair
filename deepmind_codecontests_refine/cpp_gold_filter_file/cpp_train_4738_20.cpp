#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-10;
const int N = 1e3 + 10;
int n, m;
struct point {
  long double x, y;
  point(long double x = 0, long double y = 0) : x(x), y(y) {}
  point operator+(const point &p) const { return point(x + p.x, y + p.y); }
  point operator-(const point &p) const { return point(x - p.x, y - p.y); }
  point operator*(long double w) const { return point(x * w, y * w); }
  point operator/(long double w) const { return point(x / w, y / w); }
  long double cross(const point &p) const { return x * p.y - y * p.x; }
  long double dot(const point &p) const { return x * p.x + y * p.y; }
  long double dist() const { return sqrt(x * x + y * y); }
  long double angle() const { return atan2(y, x); }
  void read() {
    double _x, _y;
    scanf("%lf%lf", &_x, &_y);
    x = _x;
    y = _y;
  }
} p[N];
int sign(long double x) { return x > eps ? 1 : x < -eps ? -1 : 0; }
long double intersect(point a, point b, point c, point d) {
  return (d - c).cross(c - a) / (d - c).cross(b - a);
}
long double solve(point a, point b) {
  vector<pair<long double, int> > v;
  long double len = (b - a).dist();
  for (int i = 0; i < n; i++) {
    int s1 = sign((b - a).cross(p[(i + 1) % n] - a));
    int s2 = sign((b - a).cross(p[i] - a));
    if (s1 == s2) continue;
    v.emplace_back(intersect(a, b, p[i], p[(i + 1) % n]), s2 - s1);
  }
  sort(v.begin(), v.end());
  long double res = 0;
  int inside = 0;
  for (int i = 0; i < v.size(); i++) {
    if (inside) res += v[i].first - v[i - 1].first;
    inside += v[i].second;
  }
  return res * len;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) p[i].read();
  while (m--) {
    point a, b;
    a.read();
    b.read();
    printf("%.20lf\n", (double)solve(a, b));
  }
  return 0;
}
