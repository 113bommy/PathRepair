#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse4,avx2,abm,fma,tune=native")
#pragma GCC optimize("fast-math")
using namespace std;
const char nl = '\n';
const double INF = 1e18;
const double EPS = 1e-9;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
struct pt {
  double x, y;
  pt(const double& _x = 0, const double& _y = 0) : x(_x), y(_y) {}
  pt operator+(const pt& o) const { return pt(x + o.x, y + o.y); }
  pt operator-(const pt& o) const { return pt(x - o.x, y - o.y); }
};
pt operator*(const double& c, const pt& v) { return pt(c * v.x, c * v.y); }
inline int sqr(int x) { return x * x; }
int sgn(const double& x) { return x < -EPS ? -1 : x <= EPS ? 0 : 1; }
inline int cp(const pt& a, const pt& b) { return a.x * b.y - a.y * b.x; }
inline int dp(const pt& a, const pt& b) { return a.x * b.x + a.y * b.y; }
inline double cpl(const pt& a, const pt& b) { return a.x * b.y - a.y * b.x; }
inline double dpl(const pt& a, const pt& b) { return a.x * b.x + a.y * b.y; }
inline pt line_inter(const pt& a, const pt& b, const pt& c, const pt& d) {
  return a + cpl(c - a, d - c) / cpl(b - a, d - c) * (b - a);
}
struct Car {
  pt v, d;
  int s;
  Car(int x, int y, int dx, int dy, int _s) : v(x, y), d(dx, dy), s(_s) {}
  double hit(const pt& it) const {
    pt len = it - (v);
    return sgn(dpl(len, (d))) >= 0 ? dpl(len, len) / sqr(s) : INF;
  }
};
double parallel(const Car& a, const Car& b) {
  pt len = b.v - a.v;
  if (sgn(cp(len, a.d)) != 0) return INF;
  int da = sgn(dp(len, a.d)), db = sgn(dp(len, b.d));
  if (da >= 0 && db <= 0) return dp(len, len) / (double)sqr(a.s + b.s);
  if (da >= 0 && db >= 0 && a.s != b.s) return dp(len, len) / (double)sqr(a.s);
  if (da <= 0 && db <= 0 && a.s != b.s) return dp(len, len) / (double)sqr(b.s);
  return INF;
}
double collide(const Car& a, const Car& b) {
  if (sgn(cp(a.d, b.d)) == 0) return parallel(a, b);
  pt it = line_inter((a.v), (a.v + a.d), (b.v), (b.v + b.d));
  return max(a.hit(it), b.hit(it));
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(10);
  int n;
  cin >> n;
  vector<Car> v;
  for (int i = 0; i < n; i++) {
    int x, y, dx, dy, s;
    cin >> x >> y >> dx >> dy >> s;
    v.emplace_back(x, y, dx, dy, s);
  }
  double ans = INF;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      ans = min(ans, collide(v[i], v[j]));
    }
  }
  if (ans < INF) {
    cout << sqrt(ans) << nl;
  } else {
    cout << "No show :(" << nl;
  }
  return 0;
}
