#include <bits/stdc++.h>
using namespace std;
int n;
double l, r, m, ans, mx, mn;
pair<double, double> xy[100005];
pair<double, double> inter(pair<double, double> a, pair<double, double> b) {
  a.first = max(a.first, b.first);
  a.second = min(a.second, b.second);
  return a;
}
bool check(double r) {
  pair<double, double> sm;
  sm = make_pair(-100000000000000, 100000000000000);
  for (int i = 0; i < n; i++) {
    pair<double, double> nxt = make_pair(
        xy[i].first - 1.0 * sqrt(2 * r - xy[i].second) * sqrt(xy[i].second),
        xy[i].first + 1.0 * sqrt(2 * r - xy[i].second) * sqrt(xy[i].second));
    sm = inter(nxt, sm);
  }
  if (sm.second < sm.first) return 0;
  return 1;
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> xy[i].first >> xy[i].second;
    mx = max(mx, xy[i].second);
    mn = min(mn, xy[i].second);
  }
  if (mx > 0 && mn < 0) {
    cout << -1 << endl;
    return 0;
  }
  l = mx / 2;
  r = 10e16;
  if (mx < 0) {
    l = -mn / 2;
    for (int i = 0; i < n; i++) xy[i].second *= -1;
  }
  while ((r - l) / r >= 10e-16) {
    m = (l + r) / 2;
    if (check(m)) {
      r = m;
      ans = m;
    } else
      l = m;
  }
  printf("%.15f\n", ans);
  return 0;
}
