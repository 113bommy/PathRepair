#include <bits/stdc++.h>
using namespace std;
int n, vis[1001], l[1001], r[1001], ans[1001];
void solve() {
  cin >> n;
  for (int i = 1; i < n + 1; i++) {
    cin >> l[i];
  }
  for (int i = 1; i < n + 1; i++) {
    cin >> r[i];
  }
  for (int val = n; val > 0; val--) {
    vector<int> v;
    bool f = 0;
    for (int i = 1; i < n + 1; i++) {
      if (vis[i]) continue;
      f = 1;
      if (l[i] == 0 and r[i] == 0) v.push_back(i), vis[i] = 1;
    }
    if (f == 1 and (int) v.size() == 0) {
      cout << "NO" << '\n';
      return;
    }
    for (auto i : v) {
      for (int j = 1; j < i; j++) {
        if (vis[j]) continue;
        r[j]--;
        if (r[j] < 0) {
          cout << "NO" << '\n';
          return;
        }
      }
      for (int j = i + 1; j < n + 1; j++) {
        if (vis[j]) continue;
        l[j]--;
        if (l[j] < 0) {
          cout << "NO" << '\n';
          return;
        }
      }
    }
    for (auto i : v) ans[i] = val;
  }
  cout << "YES" << '\n';
  for (int i = 1; i < n + 1; i++) cout << ans[i] << " ";
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
