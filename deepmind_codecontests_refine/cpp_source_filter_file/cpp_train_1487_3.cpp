#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 5;
int a[maxn];
void solve() {
  int n;
  cin >> n;
  vector<vector<int> > v(n + 1);
  vector<int> f(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    v[a[i]].push_back(i);
  }
  for (int i = 0; i < n; i++) {
    if (v[i].empty()) continue;
    f[i] = v[i][0];
    for (int j = 1; j < v[i].size(); j++) {
      f[i] = max(f[i], v[i][j] - v[i][j - 1]);
    }
    f[i] = max(f[i], n - v[i].back());
  }
  vector<int> ans(n + 1, maxn);
  for (int i = 1; i <= n; i++) {
    ans[f[i]] = min(ans[f[i]], i);
  }
  if (ans[1] == maxn) cout << "-1 ";
  if (ans[1] != maxn) cout << ans[1] << " ";
  for (int i = 2; i <= n; i++) {
    ans[i] = min(ans[i], ans[i - 1]);
    if (ans[i] == maxn) {
      cout << "-1 ";
      continue;
    }
    cout << ans[i] << " ";
  }
  cout << "\n";
  return;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
