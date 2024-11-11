#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, k;
  cin >> n >> k;
  vector<long long> p(n);
  for (auto &i : p) cin >> i;
  for (auto i : p) cin >> i;
  sort(p.begin(), p.end());
  vector<int> mx(n), pre(n);
  for (int i = 0; i < n; i++) {
    int idx = upper_bound(p.begin(), p.end(), p[i] + k) - p.begin();
    mx[i] = idx - i;
  }
  pre[0] = mx[0];
  for (int i = 1; i < n; i++) {
    pre[i] = max(pre[i - 1], mx[i]);
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (p[i] - k <= p[0]) {
      ans = max(ans, mx[i] + i);
    } else {
      int idx = upper_bound(p.begin(), p.end(), p[i] - k) - p.begin() - 1;
      ans = max(ans, pre[idx] + mx[i]);
    }
  }
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
