#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int n, m, sccn, dfs_clock;
vector<int> adj[N], edges[N];
bool vis[N];
stack<int> s;
int low[N], disc[N], scc[N];
int lift[N][20];
int height[N];
void dfs1(int u, int p) {
  vis[u] = 1;
  height[u] = height[p] + 1;
  lift[u][0] = p;
  for (int i = 1; i < 20; i++) lift[u][i] = lift[lift[u][i - 1]][i - 1];
  for (int v : edges[u])
    if (!vis[v]) dfs1(v, u);
}
int climb(int u, int step) {
  for (int i = 0; i < 20; i++)
    if ((1 << i) & step) u = lift[u][i];
  return u;
}
int lca(int a, int b, int jump = 19) {
  if (a == b) return a;
  if (lift[a][0] == lift[b][0]) return lift[a][0];
  while (lift[a][jump] == lift[b][jump]) {
    jump--;
  }
  return lca(lift[a][jump], lift[b][jump], jump);
}
void dfs(int u, int p) {
  vis[u] = 1;
  low[u] = disc[u] = ++dfs_clock;
  s.push(u);
  for (int v : adj[u]) {
    if (!vis[v]) {
      dfs(v, u);
      low[u] = min(low[u], low[v]);
    } else if (v != p)
      low[u] = min(low[u], disc[v]);
  }
  if (low[u] == disc[u]) {
    scc[u] = sccn;
    while (s.top() != u) {
      int v = s.top();
      scc[v] = sccn;
      s.pop();
    }
    s.pop();
    sccn++;
  }
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  for (int i = 0; i < n; i++)
    if (!vis[i]) dfs(i, i);
  memset(vis, 0, sizeof(vis));
  for (int i = 0; i < n; i++)
    for (int v : adj[i])
      if (scc[i] != scc[v]) edges[scc[i]].push_back(scc[v]);
  dfs1(0, 0);
  int q;
  cin >> q;
  while (q--) {
    int a, b;
    cin >> a >> b;
    a = scc[a - 1], b = scc[b - 1];
    int u = a, v = b;
    if (height[a] < height[b])
      v = climb(b, height[b] - height[a]);
    else
      u = climb(a, height[a] - height[b]);
    int parent = lca(u, v);
    cout << height[a] + height[b] - 2 * height[parent] << "\n";
  }
}
