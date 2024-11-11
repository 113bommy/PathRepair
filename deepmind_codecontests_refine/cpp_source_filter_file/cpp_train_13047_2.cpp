#include <bits/stdc++.h>
using namespace std;
const double dbl_eps = 1e-13;
const long long inf = 1e18;
void solve() {
  long long n, k, h;
  cin >> n >> k >> h;
  vector<pair<pair<long long, long long>, long long>> aa(n);
  for (long long i = 0; i < n; ++i) {
    cin >> aa[i].first.first;
  }
  for (long long i = 0; i < n; ++i) {
    cin >> aa[i].first.second;
  }
  for (long long i = 0; i < n; ++i) {
    aa[i].second = i + 1;
  }
  sort(aa.begin(), aa.end());
  reverse(aa.begin(), aa.end());
  double lhs = 0, rhs = k * h + 1;
  while ((rhs - lhs) / rhs > dbl_eps) {
    double mid = (rhs + lhs) / 2;
    long long ind = k;
    for (long long i = 0; i < n && ind > 0; ++i) {
      if (1.0 * ind * h <= 1.0 * mid * aa[i].first.second) {
        --ind;
      }
    }
    if (ind == 0) {
      rhs = mid;
    } else {
      lhs = mid;
    }
  }
  long long ind = k;
  string ss;
  for (long long i = 0; i < n && ind > 0; ++i) {
    if (1.0 * ind * h <= 1.0 * rhs * aa[i].first.second) {
      --ind;
      string str = to_string(aa[i].second);
      reverse(str.begin(), str.end());
      ss += str + " ";
    }
  }
  ss.pop_back();
  reverse(ss.begin(), ss.end());
  cout << ss;
  return;
}
signed main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);
  long long q = 1;
  while (q--) {
    solve();
  }
  return 0;
}
