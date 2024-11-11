#include <bits/stdc++.h>
using namespace std;
int n, m, vis[1000010];
vector<int> g[1000010], v, pos;
int ans[1000010], a[1000010];
void dfs(int x) {
  vis[x] = 1;
  pos.push_back(x);
  for (auto &it : g[x]) {
    if (!vis[it]) dfs(it);
  }
}
int32_t main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin.exceptions(cin.failbit);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= m; ++i) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i = 1; i <= n; ++i) {
    if (!vis[i]) {
      pos.clear();
      v.clear();
      dfs(i);
      for (auto &it : pos) {
        v.push_back(a[it]);
      }
      sort(pos.begin(), pos.end());
      sort(v.begin(), v.end());
      reverse(v.begin(), v.end());
      for (int i = 0; i < (v).size(); ++i) {
        ans[pos[i]] = v[i];
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    cout << ans[i] << " ";
  }
  return 0;
}
