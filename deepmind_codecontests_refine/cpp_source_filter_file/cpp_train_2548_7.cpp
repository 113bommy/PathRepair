#include <bits/stdc++.h>
using namespace std;
int n, m;
int d[100008];
multiset<int> adj[100008];
vector<int> odd;
vector<int> sol;
void dfs(int u) {
  while (!adj[u].empty()) {
    int v = *adj[u].begin();
    adj[u].erase(adj[u].find(v));
    adj[v].erase(adj[v].find(u));
    dfs(v);
  }
  sol.push_back(u);
}
int main() {
  cin >> n >> m;
  memset(d, 0, sizeof(d));
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    d[u]++, d[v]++;
    adj[u].insert(v);
    adj[v].insert(u);
  }
  for (int i = 1; i <= n; i++)
    if (d[i] % 2) odd.push_back(i);
  for (int i = 0; i < (int)odd.size(); i += 2) {
    int u = odd[i], v = odd[i + 1];
    d[u]++;
    d[v]++;
    adj[u].insert(v);
    adj[v].insert(u);
    m++;
  }
  if (m % 2) {
    d[1] += 2;
    adj[1].insert(1);
    adj[1].insert(1);
  }
  dfs(1);
  cout << m << endl;
  for (int i = 0; i < (int)sol.size() - 1; i++)
    if (i % 2 == 0)
      cout << sol[i + 1] << " " << sol[i] << endl;
    else
      cout << sol[i] << " " << sol[i + 1] << endl;
}
