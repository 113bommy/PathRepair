#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1);
struct P {
  double x, y;
  P operator+(const P b) const { return P{x + b.x, y + b.y}; }
  P operator-(const P b) const { return P{x - b.x, y - b.y}; }
  P operator*(const double b) const { return P{x * b, y * b}; }
  P operator/(const double b) const { return P{x / b, y / b}; }
  P unit() const { return *this / abs(); }
  double abs() const { return hypot(x, y); }
  P spin() { return P{-y, x}; }
  double angle() const { return atan2(y, x); }
};
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<P> ps(n);
  vector<double> d(n);
  for (int i = 0; i < n; ++i) {
    cin >> ps[i].x >> ps[i].y;
    d[i] = ps[i].abs();
  }
  auto covers = [&](double r) -> int {
    static vector<pair<double, int>> evs;
    evs.clear();
    auto add_seg = [&](double l, double r) {
      evs.emplace_back(l, 1);
      evs.emplace_back(r, -1);
    };
    for (int i = 0; i < n; ++i) {
      if (d[i] >= r - 1e-9) continue;
      if (d[i] < 1e-9) {
        evs.emplace_back(-1000, 1);
        continue;
      }
      P le = ps[i].spin().unit();
      P ri = ps[i].spin().spin().spin().unit();
      double extend = sqrt(r * r - d[i] * d[i]);
      le = ps[i] + le * extend;
      ri = ps[i] + ri * extend;
      double omn = ri.angle();
      double omx = le.angle();
      if (omn > omx) {
        add_seg(omn, pi);
        add_seg(-pi, omx);
      } else {
        add_seg(omn, omx);
      }
    }
    sort(evs.begin(), evs.end());
    int cnt = 0, mx = 0;
    for (auto [o, t] : evs) {
      cnt += t;
      mx = max(mx, cnt);
    }
    return mx;
  };
  double L = 0, R = 1e9;
  for (int i = 0; i < 100; ++i) {
    double M = (L + R) / 2;
    if (covers(M) >= k)
      R = M;
    else
      L = M;
  }
  cout << fixed << setprecision(12) << L / 2 << endl;
}
