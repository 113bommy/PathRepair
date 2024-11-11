#include <bits/stdc++.h>
using namespace std;
const string TASK = "";
signed solve() {
  int n;
  cin >> n;
  vector<int> mx(n);
  vector<int> a(n);
  int res = 0;
  for (int i = 0; i < n; ++i) {
    int m;
    cin >> m;
    a[i] = m;
    for (int j = 0, x; j < m; ++j) {
      cin >> x;
      mx[i] = max(mx[i], x);
      res = max(res, x);
    }
  }
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += a[i] * 1ll * (res - mx[i]);
  }
  cout << ans << endl;
  return 0;
}
signed main() {
  if (TASK.size())
    freopen((TASK + ".in").c_str(), "r", stdin),
        freopen((TASK + ".out").c_str(), "w", stdout);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tests = 1;
  for (int tt = 0; tt < tests; ++tt) solve();
  return 0;
}
