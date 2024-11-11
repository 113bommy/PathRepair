#include <bits/stdc++.h>
using namespace std;
const int N = 2e6, MOD = 1e9 + 7;
const long double EPS = 0.000000001;
pair<long long, long long> p[N];
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long x, x1, y, y1, n, ans1 = INT_MAX;
  cin >> n >> x >> y >> x1 >> y1;
  vector<pair<long long, long long>> ans;
  for (long long i = 0; i < n; i++) {
    cin >> p[i].first >> p[i].second;
    ans.push_back(p[i]);
  }
  for (long long i = 0; i < n; i++) {
    long long x12 = p[i].first - x, y12 = p[i].second - y;
    x12 = x12 * x12, y12 = y12 * y12;
    long long r = x12 + y12, r1 = 0;
    for (auto to : ans) {
      long long x11 = to.first - x1, y11 = to.second - y1;
      long long po =
          (to.first - x) * (to.first - x) + (to.second - y) * (to.second - y);
      x11 = x11 * x11 + y11 * y11;
      if (po > r) {
        r1 = max(r1, x11);
      }
    }
    ans1 = min(ans1, r1 + r);
    r1 = (p[i].first - x1) * (p[i].first - x1) +
         (p[i].second - y1) * (p[i].second - y1);
    r = 0;
    for (auto to : ans) {
      long long x11 = to.first - x, y11 = to.second - y;
      long long po = (to.first - x1) * (to.first - x1) +
                     (to.second - y1) * (to.second - y1);
      x11 = x11 * x11 + y11 * y11;
      if (po > r) {
        r = max(r, x11);
      }
    }
    ans1 = min(ans1, r1 + r);
  }
  cout << ans1;
}
