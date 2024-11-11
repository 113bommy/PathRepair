#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 7;
vector<int> adj[N], odd, p;
vector<pair<int, int>> ans;
int mark[N], from[N], to[N], num;
void dfs(int v) {
  while (adj[v].size()) {
    int i = adj[v].back();
    adj[v].pop_back();
    if (mark[i]) continue;
    mark[i] = 1;
    int u = from[i] + to[i] - v;
    dfs(u);
    if (num & 1)
      ans.push_back({v, u});
    else
      ans.push_back({u, v});
  }
  p.push_back(v);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    from[i] = u;
    to[i] = v;
    adj[u].push_back(i);
    adj[v].push_back(i);
  }
  for (int i = 0; i < n; i++)
    if (adj[i].size() & 1) odd.push_back(i);
  for (int i = 0; i < odd.size(); i += 2) {
    int id = m++;
    adj[odd[i]].push_back(id);
    adj[odd[i ^ 1]].push_back(id);
    from[id] = odd[i];
    to[id] = odd[i + 1];
  }
  if (m & 1) adj[0].push_back(m++);
  dfs(0);
  if (ans.size() & 1) ans.push_back({0, 0});
  cout << ans.size() << "\n";
  for (int i = 0; i < ans.size(); i++)
    if (i & 1)
      cout << ans[i].first + 1 << " " << ans[i].second + 1 << "\n";
    else
      cout << ans[i].second + 1 << " " << ans[i].first + 1 << "\n";
  return 0;
}
