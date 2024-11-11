#include <bits/stdc++.h>
using namespace std;
int last[200005];
vector<int> dfstree;
map<int, int> mp;
int dfs(vector<vector<int> >& adj, int curr) {
  dfstree.push_back(curr);
  mp[curr] = dfstree.size() - 1;
  sort(adj[curr].begin(), adj[curr].end());
  if (adj[curr].size() == 0) {
    last[curr] = 0;
    return last[curr] + 1;
  }
  last[curr] += dfs(adj, adj[curr][0]);
  for (int i = 1; i < adj[curr].size(); i++) {
    last[curr] += dfs(adj, adj[curr][i]);
  }
  return last[curr] + 1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, q;
  cin >> n >> q;
  vector<vector<int> > adj(n + 1);
  for (int i = 2; i <= n; i++) {
    int p;
    cin >> p;
    adj[p].push_back(i);
  }
  dfs(adj, 1);
  while (q--) {
    int u, k;
    cin >> u >> k;
    int ind = mp[u];
    if (ind + k - 1 > last[u])
      cout << -1 << "\n";
    else
      cout << dfstree[ind + k - 1] << "\n";
  }
  return 0;
}
