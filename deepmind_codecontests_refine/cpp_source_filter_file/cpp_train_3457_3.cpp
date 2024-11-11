#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> a(n), b(n), c(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i] >> c[i];
  }
  vector<int> mx(n, -1);
  while (m--) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    mx[v] = max(mx[v], u);
  }
  vector<vector<int>> adj(n);
  for (int i = 0; i < n; i++) {
    if (mx[i] >= 0) {
      adj[mx[i]].push_back(i);
    } else {
      adj[i].push_back(i);
    }
  }
  set<int> s;
  for (int i = 0; i < n; i++) {
    if (k >= a[i]) {
      k += b[i];
      for (int j = 0; j < adj[i].size(); j++) {
        s.insert(c[adj[i][j]]);
        k--;
      }
    } else {
      while (!s.empty() && k < a[i]) {
        s.erase(s.begin());
        k++;
      }
      if (k < a[i]) {
        cout << -1 << '\n';
        return 0;
      }
      i--;
    }
  }
  int ans = 0;
  while (!s.empty() && k < 0) {
    s.erase(s.begin());
    k++;
  }
  while (!s.empty()) {
    ans += *s.begin();
    s.erase(s.begin());
  }
  cout << ans << '\n';
}
