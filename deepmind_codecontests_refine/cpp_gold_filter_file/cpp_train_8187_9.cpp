#include <bits/stdc++.h>
using namespace std;
struct edge {
  int u, v, f, c;
  edge(int u, int v, int c) : u(u), v(v), f(0), c(c) {}
};
int n1, n2, m;
vector<int> adj[4010];
vector<edge> edges;
vector<int> ans[4010];
int level[4010];
int nxt[4010];
void add_edge(int u, int v, int c) {
  adj[u].push_back(edges.size());
  edges.push_back({u, v, c});
  adj[v].push_back(edges.size());
  edges.push_back({v, u, 0});
}
bool bfs() {
  queue<int> q;
  q.push(0);
  memset(level, -1, sizeof level);
  level[0] = 0;
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int e : adj[v]) {
      if (edges[e].c - edges[e].f > 0 && level[edges[e].v] == -1) {
        level[edges[e].v] = level[v] + 1;
        q.push(edges[e].v);
      }
    }
  }
  return level[n1 + n2 + 1] != -1;
}
int dfs(int v, int cur) {
  if (!cur) return 0;
  if (v == n1 + n2 + 1) return cur;
  for (int& i = nxt[v]; i < (int)adj[v].size(); i++) {
    int e = adj[v][i];
    if (level[v] + 1 == level[edges[e].v] && edges[e].c - edges[e].f > 0) {
      int w = dfs(edges[e].v, min(cur, edges[e].c - edges[e].f));
      if (w) {
        edges[e].f += w;
        edges[e ^ 1].f -= w;
        return w;
      }
    }
  }
  return 0;
}
int dinic() {
  int flow = 0;
  while (true) {
    if (!bfs()) break;
    memset(nxt, 0, sizeof nxt);
    while (int f = dfs(0, 4010)) flow += f;
  }
  return flow;
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n1 >> n2 >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    b += n1;
    add_edge(a, b, 1);
  }
  int min_deg = 4010;
  for (int i = 1; i <= n1 + n2; i++) {
    min_deg = min<int>(min_deg, adj[i].size());
  }
  for (int i = 1; i <= n1; i++) {
    add_edge(0, i, adj[i].size() - min_deg);
  }
  for (int i = n1 + 1; i <= n1 + n2; i++) {
    add_edge(i, n1 + n2 + 1, adj[i].size() - min_deg);
  }
  for (int k = min_deg; k >= 0; k--) {
    dinic();
    for (int i = 0; i < 2 * m; i += 2) {
      if (!edges[i].f) ans[k].push_back(i / 2);
    }
    for (int i = 2 * m; i < (int)edges.size(); i += 2) {
      edges[i].c++;
    }
  }
  for (int i = 0; i <= min_deg; i++) {
    cout << ans[i].size() << ' ';
    for (int x : ans[i]) cout << x + 1 << ' ';
    cout << '\n';
  }
  return 0;
}
