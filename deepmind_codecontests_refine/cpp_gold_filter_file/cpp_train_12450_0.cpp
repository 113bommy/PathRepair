#include <bits/stdc++.h>
using namespace std;
int n;
double r;
pair<double, double> pr[100100];
bool f(double x) {
  double s = 0;
  for (int i = 0; i < n; ++i) {
    double p = x * pr[i].first;
    if (p <= pr[i].second) continue;
    s += (p - pr[i].second) / r;
    if (s > x) return false;
  }
  return s <= x;
}
void solve() {
  double l = 0, r = 1e18, ans = 1e18;
  for (int i = 0; i < 100; ++i) {
    double mid = (l + r) / 2.0;
    if (f(mid))
      l = mid, ans = mid;
    else
      r = mid;
  }
  printf("%.6f", ans);
}
int main() {
  cin >> n >> r;
  double s;
  for (int i = 0; i < n; ++i) {
    scanf("%lf%lf", &pr[i].first, &pr[i].second);
    s += pr[i].first;
  }
  if (r >= s) {
    cout << -1;
    return 0;
  }
  solve();
}
