#include <bits/stdc++.h>
using namespace std;
const int MAX = 3e5 + 5;
int n, m, r, ctr;
pair<int, int> edge[MAX];
int vis[MAX];
vector<int> g1[MAX];
vector<pair<int, int>> g[MAX];
string ans = "";
vector<int> adj[MAX];
int mark[MAX];
void dfs(int u) {
  vis[u] = 1;
  for (auto it : g[u]) {
    if (vis[it.first]) {
      continue;
    }
    if (edge[it.second].first == u) {
      ans[it.second] = '+';
    }
    dfs(it.first);
  }
  for (auto it : g1[u]) {
    if (vis[it]) {
      continue;
    }
    dfs(it);
  }
}
void dfs2(int u) {
  vis[u] = 1;
  mark[u] = 1;
  for (auto it : g1[u]) {
    if (vis[it]) {
      continue;
    }
    dfs2(it);
  }
}
void solve() {
  for (int i = 1; i <= n; ++i) {
    adj[i].clear();
  }
  for (int i = 1; i <= n; ++i) {
    for (auto it : g1[i]) {
      adj[i].push_back(it);
    }
  }
  for (int i = 0; i < ctr; ++i) {
    if (ans[i] == '+') {
      adj[edge[i].first].push_back(edge[i].second);
    } else {
      adj[edge[i].second].push_back(edge[i].first);
    }
  }
  for (int i = 1; i <= n; ++i) {
    sort(adj[i].begin(), adj[i].end());
    adj[i].erase(unique(adj[i].begin(), adj[i].end()), adj[i].end());
  }
  fill(vis, vis + MAX, 0);
  queue<int> q;
  q.push(r);
  vis[r] = 1;
  int x = 0;
  while (!q.empty()) {
    int u = q.front();
    x += 1;
    q.pop();
    for (auto v : adj[u]) {
      if (!vis[v]) {
        vis[v] = 1;
        q.push(v);
      }
    }
  }
  cout << x << "\n";
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m >> r;
  int t, x, y;
  for (int i = 0; i < m; ++i) {
    cin >> t >> x >> y;
    if (t == 1) {
      g1[x].push_back(y);
    } else {
      ans += '-';
      edge[ctr] = {x, y};
      g[x].push_back({y, ctr});
      g[y].push_back({x, ctr});
      ctr += 1;
    }
  }
  fill(vis, vis + MAX, 0);
  dfs(r);
  solve();
  fill(vis, vis + MAX, 0);
  dfs2(r);
  for (int i = 0; i < ans.length(); ++i) {
    if (edge[i].second == r) {
      ans[i] = '+';
      continue;
    }
    if (mark[edge[i].second] == 1) {
      ans[i] = '+';
      continue;
    }
    ans[i] = '-';
  }
  solve();
  return 0;
}
