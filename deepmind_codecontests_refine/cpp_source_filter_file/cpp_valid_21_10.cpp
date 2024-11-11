#include <bits/stdc++.h>
using namespace std;
vector<int> x, y, s, dp;
void solve() {
  int n;
  cin >> n;
  x.push_back(0);
  y.push_back(0);
  s.push_back(0);
  dp.push_back(0);
  for (int i = 1; i < n + 1; i++) {
    x.push_back(0);
    y.push_back(0);
    s.push_back(0);
    dp.push_back(0);
    cin >> x[i] >> y[i] >> s[i];
  }
  for (int i = 1; i < n + 1; i++) {
    int tmp = lower_bound(x.begin(), x.end(), y[i]) - x.begin();
    dp[i] = dp[i - 1] + dp[i - 1] - dp[tmp - 1] + (x[i] - y[i]);
    dp[i] = (dp[i] + (long long)(998244353)) % (long long)(998244353);
  }
  long long ans = x[n] + 1;
  ans %= (long long)(998244353);
  for (int i = 1; i < n + 1; i++) {
    if (s[i]) {
      ans += dp[i] - dp[i - 1];
      ans = (ans + (long long)(998244353)) % (long long)(998244353);
    }
  }
  cout << ans << endl;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ;
  int t;
  t = 1;
  while (t--) {
    solve();
  }
}
