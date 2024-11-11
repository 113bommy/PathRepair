#include <bits/stdc++.h>
using namespace std;
void fast_io() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
vector<int> g[200005];
int n;
vector<int> day[200005];
vector<bool> vis(200005, 0);
map<pair<int, int>, int> mp;
int max_cnt = 0;
void dfs(int node, int cnt) {
  vis[node] = 1;
  max_cnt = max(max_cnt, (int)g[node].size());
  int cur = 0;
  for (auto u : g[node]) {
    if (!vis[u]) {
      cur++;
      if (cur == cnt) cur++;
      day[cur].push_back(mp[{node, u}]);
      dfs(u, cur);
    }
  }
}
void solve() {
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
    mp[{u, v}] = i + 1;
    mp[{v, u}] = i + 1;
  }
  dfs(1, 1);
  cout << max_cnt << '\n';
  for (int i = 1; i <= max_cnt; i++) {
    cout << day[i].size() << " ";
    for (int u : day[i]) cout << u << " ";
    cout << '\n';
  }
}
int main() {
  fast_io();
  int T = 1;
  while (T--) {
    solve();
  }
}
