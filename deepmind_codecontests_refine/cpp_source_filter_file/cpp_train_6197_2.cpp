#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 10;
const int inf = (-1u) >> 1;
const double eps = 1e-6;
int sgn(double x) { return (x > eps) - (x < -eps); }
struct point {
  double x, y;
  point() {}
  point(double _x, double _y) : x(_x), y(_y) {}
  bool operator<(const point& p) const {
    return sgn(x - p.x) == 0 ? sgn(y - p.y) < 0 : sgn(x - p.x) < 0;
  }
  bool operator==(const point& p) const {
    return sgn(x - p.x) == 0 && sgn(y - p.y) == 0;
  }
  point operator+(const point& p) const { return point(x + p.x, y + p.y); }
  point operator-(const point& p) const { return point(x - p.x, y - p.y); }
  point operator*(const double& d) const { return point(d * x, d * y); }
  point operator/(const double& d) const { return point(x / d, y / d); }
  double operator^(const point& p) const { return x * p.x + y * p.y; }
  double operator*(const point& p) const { return x * p.y - y * p.x; }
  double len() const { return sqrt(x * x + y * y); }
  point trunc(const double& l) const {
    double rate = l / len();
    return point(x * rate, y * rate);
  }
  void input() { scanf("%lf%lf", &x, &y); }
  void output() { printf("%lf %lf\n", x, y); }
};
bool get_intersection(const point& p1, const point& p2, const point& p3,
                      const point& p4, point& c) {
  double d1 = (p2 - p1) * (p3 - p1), d2 = (p2 - p1) * (p4 - p1);
  double d3 = (p4 - p3) * (p1 - p3), d4 = (p4 - p3) * (p2 - p3);
  int s1 = sgn(d1), s2 = sgn(d2), s3 = sgn(d3), s4 = sgn(d4);
  if (s1 == 0 && s2 == 0 && s3 == 0 && s4 == 0) return false;
  c = point((p3.x * d2 - p4.x * d1) / (d2 - d1),
            (p3.y * d2 - p4.y * d1) / (d2 - d1));
  return s1 * s2 <= 0 && s3 * s4 <= 0;
}
struct triangle {
  point p[3];
  void input() {
    for (int i = 0; i < 3; ++i) p[i].input();
    if (sgn((p[1] - p[0]) * (p[2] - p[0])) < 0) swap(p[1], p[2]);
  }
  bool isIn(const point& t) const {
    for (int i = 0; i < 3; ++i) {
      if (sgn((p[(i + 1) % 3] - p[i]) * (t - p[i])) <= 0) return false;
    }
    return true;
  }
};
triangle tri[maxn];
int n;
bool check(const point& p1, const point& p2) {
  point mid = (p1 + p2) / 2;
  for (int i = 0; i < (n); ++i)
    if (tri[i].isIn(mid)) {
      return false;
    }
  return true;
}
double cal(const point& p1, const point& p2, int x) {
  vector<point> cross;
  for (int i = 0; i < (n); ++i)
    if (i != x) {
      for (int j = 0; j < (3); ++j) {
        point c;
        if (get_intersection(p1, p2, tri[i].p[j], tri[i].p[(j + 1) % 3], c)) {
          cross.push_back(c);
        }
      }
    }
  cross.push_back(p1), cross.push_back(p2);
  sort(cross.begin(), cross.end());
  double res = 0.0;
  for (int i = 0; i < (((int)((cross).size())) - 1); ++i) {
    if (check(cross[i], cross[i + 1])) {
      res += (cross[i + 1] - cross[i]).len();
    }
  }
  return res;
}
void solve() {
  double ans = 0.0;
  for (int i = 0; i < (n); ++i)
    for (int j = 0; j < (3); ++j) {
      ans += cal(tri[i].p[j], tri[i].p[(j + 1) % 3], i);
    }
  printf("%.10lf\n", ans);
}
int main() {
  while (scanf("%d", &n) != EOF) {
    for (int i = 0; i < (n); ++i) {
      tri[i].input();
    }
    solve();
  }
  return 0;
}
