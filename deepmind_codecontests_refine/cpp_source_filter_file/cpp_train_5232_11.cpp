#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, cnt = 0;
  cin >> n;
  vector<int> v(n), inv(n);
  map<int, int> m;
  for (int& x : v) cin >> x, m[x];
  for (auto& x : m) x.second = cnt++;
  cnt = 0;
  for (int& x : v) {
    x = m[x];
    inv[x] = cnt++;
  }
  int ans = 1e9;
  vector<int> dp(n, 1);
  for (int i = n - 2; i >= 0; --i) {
    if (inv[i] < inv[i + 1])
      dp[i] = dp[i + 1] + 1;
    else
      dp[i] = 1;
    ans = min(ans, n - dp[i]);
  }
  cout << ans << '\n';
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
