#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N];
vector<vector<int> > g;
vector<int> ans;
void solve() {
  int n, m;
  cin >> n >> m;
  g.resize(n + 1);
  queue<int> q;
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (!a[i]) q.push(i);
  }
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    if (a[u]) continue;
    ans.push_back(u);
    a[u]--;
    for (auto v : g[u]) {
      a[v]++;
      if (!a[v]) q.push(v);
    }
  }
  cout << (int)ans.size() << '\n';
  for (auto x : ans) cout << x << ' ';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  solve();
}
