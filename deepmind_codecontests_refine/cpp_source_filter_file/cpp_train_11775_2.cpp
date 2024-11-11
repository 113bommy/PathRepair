#include <bits/stdc++.h>
using namespace std;
set<pair<int, int>> st;
int dist[100009];
int vis[100009];
int par[100009];
vector<int> adj[100009];
void dfs(int s, int p) {
  if (vis[s]) return;
  vis[s] = 1;
  par[s] = p;
  for (int i = 0; i < adj[s].size(); i++) {
    if (!vis[adj[s][i]]) {
      dist[adj[s][i]] = dist[s] + 1;
      if (dist[adj[s][i]] > 2)
        st.insert(make_pair(-dist[adj[s][i]], adj[s][i]));
      dfs(adj[s][i], s);
    }
  }
}
int main() {
  int n;
  while (cin >> n) {
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n - 1; i++) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    dist[1] = 0;
    dfs(1, 1);
    int res = 0;
    while (!st.empty()) {
      int v = st.begin()->second;
      ++res;
      int nd = par[v];
      auto it = st.find(make_pair(-dist[nd], nd));
      if (it != st.end()) st.erase(it);
      for (auto node : adj[nd]) {
        it = st.find(make_pair(-dist[node], node));
        if (it != st.end()) {
          st.erase(it);
        }
      }
    }
    cout << res << endl;
    for (int i = 1; i <= n; i++) adj[i].clear();
  }
}
