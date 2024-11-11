#include <bits/stdc++.h>
using namespace std;
const long long inf = 1000000000000000000LL;
const double EPS = 1e-9;
const long long mod = 1000000007ll;
const int maxn = 500500;
struct point {
  double x, y, z;
  point() {}
  point(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {}
  void read() { scanf("%lf%lf%lf", &x, &y, &z); }
  point operator-(const point& p) { return point(x - p.x, y - p.y, z - p.z); }
  point operator+(const point& p) { return point(x + p.x, y + p.y, z + p.z); }
  point operator*(double d) { return point(x * d, y * d, z * d); }
  double abs() { return sqrt(x * x + y * y + z * z); }
};
point polyline[maxn];
double vp, vs;
int n;
point where(double ti) {
  for (int i = 0; i < n; i++) {
    double segTime = (polyline[i + 1] - polyline[i]).abs() / vs;
    if (segTime >= ti) {
      point dir = (polyline[i + 1] - polyline[i]);
      return polyline[i] + dir * (ti / segTime);
    }
    ti -= segTime;
  }
  return polyline[n];
}
bool can(double ti) { return (polyline[n + 1] - where(ti)).abs() / vp <= ti; }
int main() {
  scanf("%d", &n);
  for (int i = 0; i < (int)(n + 1); ++i) polyline[i].read();
  scanf("%lf%lf", &vp, &vs);
  polyline[n + 1].read();
  double ti = 0;
  for (int i = 0; i < n; i++) ti += (polyline[i + 1] - polyline[i]).abs() / vs;
  if ((polyline[n] - polyline[n + 1]).abs() / vp > ti + EPS) {
    puts("NO");
    return 0;
  }
  double l = 0, r = 1e10;
  for (int st = 0; st < 100; st++) {
    double mid = (l + r) / 2.;
    if (can(mid))
      r = mid;
    else
      l = mid;
  }
  point loc = where(l);
  puts("YES");
  printf("%lf\n%lf %lf %lf", (loc - polyline[n + 1]).abs() / vp, loc.x, loc.y,
         loc.z);
}
