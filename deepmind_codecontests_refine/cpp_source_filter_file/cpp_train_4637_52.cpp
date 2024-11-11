#include <bits/stdc++.h>
using namespace std;
struct Point {
  double x, y, z;
  Point(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}
  bool operator<(const Point& rhs) const {
    return x < rhs.x || (x == rhs.x && y < rhs.y) ||
           (x == rhs.x && y == rhs.y && z < rhs.z);
  }
};
Point operator+(Point a, Point b) {
  return Point(a.x + b.x, a.y + b.y, a.z + b.z);
}
Point operator-(Point a, Point b) {
  return Point(a.x - b.x, a.y - b.y, a.z - b.z);
}
Point operator*(Point a, double p) { return Point(a.x * p, a.y * p, a.z * p); }
Point operator/(Point a, double p) { return Point(a.x / p, a.y / p, a.z / p); }
double distance(Point a, Point b) {
  return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2) + pow(a.z - b.z, 2));
}
vector<Point> v;
vector<double> d;
int n;
double vs, vp;
Point start;
void init() {
  scanf("%d", &n);
  d.push_back(0.0);
  for (int i = 0; i < n + 1; i++) {
    Point x;
    scanf("%lf %lf %lf", &x.x, &x.y, &x.z);
    v.push_back(x);
    if (i != 0) d.push_back(d.back() + distance(v[i - 1], v[i]));
  }
  scanf("%lf %lf", &vp, &vs);
  scanf("%lf %lf %lf", &start.x, &start.y, &start.z);
  return;
}
bool ok(int x) {
  double tHarry = distance(start, v[x]) / vp, tSintch = d[x] / vs;
  return tHarry <= tSintch;
}
bool ok2(Point x, int p) {
  double tHarry = distance(start, x) / vp,
         tSintch = (d[p - 1] + distance(v[p - 1], x)) / vs;
  return tHarry <= tSintch;
}
void solve() {
  int L = 0, R = n, M;
  while (L < R) {
    M = (L + R) / 2;
    if (ok(M))
      R = M;
    else
      L = M + 1;
  }
  Point l = v[L - 1], r = v[L], m;
  for (int i = 0; i < 100; i++) {
    m = (l + r) / 2;
    if (ok2(m, L))
      r = m;
    else
      l = m;
  }
  if (!ok(L))
    printf("NO\n");
  else {
    printf("YES\n");
    printf("%.10lf\n", distance(start, r) / vs);
    printf("%.10lf %.10lf %.10lf\n", r.x, r.y, r.z);
  }
}
int main() {
  init();
  solve();
}
