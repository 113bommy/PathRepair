#include <bits/stdc++.h>
using namespace std;
const double eps = 0.00000001;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int64_t n;
  cin >> n;
  double x1, x2, y1, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  pair<double, double> a[n], b[n];
  for (int64_t i = 0; i < n; ++i)
    cin >> a[i].first >> a[i].second >> b[i].first >> b[i].second;
  vector<pair<double, int64_t> > mass;
  for (int64_t i = 0; i < n; ++i) {
    int64_t x = a[i].first, y = a[i].second;
    double l1, l2, r1, r2;
    if (b[i].first != 0) {
      l1 = (x1 - x) / b[i].first;
      r1 = (x2 - x) / b[i].first;
    } else {
      if (x > x1 && x < x2) {
        l1 = 0.0;
        r1 = 1e9;
      } else {
        cout << -1;
        return 0;
      }
    }
    if (b[i].second != 0) {
      l2 = (y1 - y) / b[i].second;
      r2 = (y2 - y) / b[i].second;
    } else {
      if (y > y1 && y < y2) {
        l2 = 0.0;
        r2 = 1e9;
      } else {
        cout << -1;
        return 0;
      }
    }
    double l = max(min(l1, r1), min(l2, r2)), r = min(max(l1, r1), max(l2, r2));
    l = max(l, 0.0);
    if (r < 0.0 || l >= r) {
      cout << -1;
      return 0;
    }
    mass.push_back(make_pair(l, 0));
    mass.push_back(make_pair(r, 1));
  }
  bool flag1 = false, flag2 = false;
  int64_t cnt = 0;
  double l, r;
  sort(mass.begin(), mass.end());
  for (int64_t i = 0; i < ((int64_t)mass.size()); ++i) {
    int64_t s = mass[i].second;
    if (s == 0)
      ++cnt;
    else
      --cnt;
    if (cnt == n) {
      flag1 = true;
      l = mass[i].first;
    }
    if (cnt == (n - 1) && flag1) {
      flag2 = true;
      r = mass[i].first;
    }
  }
  if (flag1 && flag2) {
    l = max(l, 0.0);
    if (r > l)
      cout << fixed << setprecision(10) << l + eps;
    else
      cout << -1;
  } else
    cout << -1;
  return 0;
}
