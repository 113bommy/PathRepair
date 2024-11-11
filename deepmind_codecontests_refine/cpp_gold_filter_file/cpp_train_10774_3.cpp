#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
double calc(double x, vector<double> a) {
  int n = (int)a.size();
  for (int i = 0; i < n; ++i) a[i] -= x;
  double vmax = -1e18, vmin = 1e18;
  int p = 0, pp;
  while (p < n) {
    while (p < n && a[p] > 0.0) ++p;
    double cur = 0.0;
    pp = p;
    while (pp < n && cur + a[pp] <= 0.0) {
      cur += a[pp];
      vmin = min(vmin, cur);
      ++pp;
    }
    p = pp;
  }
  p = 0, pp;
  while (p < n) {
    while (p < n && a[p] < 0.0) ++p;
    double cur = 0.0;
    pp = p;
    while (pp < n && cur + a[pp] >= 0.0) {
      cur += a[pp];
      vmax = max(vmax, cur);
      ++pp;
    }
    p = pp;
  }
  return max(vmax, -vmin);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(12);
  cout << fixed;
  int n;
  cin >> n;
  vector<double> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  double l = -1e4, r = 1e4;
  for (int k = 0; k < 100; ++k) {
    double x1 = (2 * l + r) / 3;
    double x2 = (l + 2 * r) / 3;
    double v1 = calc(x1, a);
    double v2 = calc(x2, a);
    if (v1 < v2)
      r = x2;
    else
      l = x1;
  }
  cout << calc(l, a) << '\n';
  return 0;
}
