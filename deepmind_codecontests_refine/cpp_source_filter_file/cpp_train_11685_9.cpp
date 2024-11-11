#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 100000 + 5;
const int MAX_L = 20;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;
vector<pair<int, int>> ans;
vector<int> adj[MAX_N];
int mx_deg = 0, t = 0;
void dfs(int u, int backT = -1, int p = 0) {
  ans.push_back({u, t});
  int num_child = 0;
  for (int v : adj[u])
    if (v != p) num_child++;
  for (int v : adj[u]) {
    if (v == p) continue;
    if (t == mx_deg) {
      t = backT - 1 - num_child;
      ans.push_back({u, t});
    }
    t++;
    dfs(v, t, u);
    ans.push_back({u, t});
    num_child--;
  }
  if (u == 1) return;
  if (t >= backT) {
    t = backT - 1;
    ans.push_back({u, t});
  }
  t++;
}
void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for (int i = 0; i < n; i++) mx_deg = max(mx_deg, int(adj[i].size()));
  dfs(1);
  cout << ans.size() << "\n";
  for (int i = 0; i < ans.size(); ++i)
    cout << ans[i].first << " " << ans[i].second << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc = 1;
  for (int t = 1; t <= tc; t++) {
    solve();
  }
}
