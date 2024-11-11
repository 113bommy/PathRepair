#include <bits/stdc++.h>
using namespace std;
vector<int> adj[500005];
vector<pair<int, int>> ans;
int timer = 1;
void dfs(int u, int p) {
  for (auto a : adj[u]) {
    if (a != p) ans[a].first = timer++;
  }
  ans[u].second = timer++;
  reverse(adj[u].begin(), adj[u].end());
  for (auto a : adj[u]) {
    if (a != p) dfs(a, u);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  ans.assign(n, {});
  ans[0].first = 0;
  dfs(0, -1);
  for (auto a : ans) cout << a.first + 1 << " " << a.second + 1 << "\n";
}
