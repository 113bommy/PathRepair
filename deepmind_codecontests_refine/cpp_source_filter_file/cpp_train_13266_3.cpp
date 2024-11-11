#include <bits/stdc++.h>
using namespace std;
const long long inf = 1000000000ll;
const long long inf64 = inf * inf;
const long long N = 100100;
bool solve() {
  long long n, m, b;
  cin >> n >> m >> b;
  vector<pair<pair<long long, long long>, pair<long long, long long> > > f(n);
  for (int i(0); i < n; i++) {
    cin >> f[i].first.second >> f[i].first.first >> f[i].second.first;
    f[i].second.second = 0;
    for (long long x, j(0); j < f[i].second.first; j++) {
      cin >> x;
      f[i].second.second |= (1 << (x - 1));
    }
  }
  sort((f).begin(), (f).end());
  vector<long long> dp(1ll << m, inf64 * 9);
  dp[0] = 0;
  long long ans = inf64 * 9;
  for (int i(0); i < n; i++) {
    for (int j(0); j < (1 << m); j++) {
      if (dp[j] + f[i].first.second < dp[j | f[i].second.second])
        dp[j | f[i].second.second] = dp[j] + f[i].first.second;
      long long tmp = dp[(1 << m) - 1] + f[i].first.first * b;
      ans = min(ans, tmp);
    }
  }
  cout << (ans == inf64 * 9 ? -1 : ans) << '\n';
  return true;
}
int main() {
  solve();
  return 0;
}
