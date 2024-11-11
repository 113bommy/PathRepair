#include <bits/stdc++.h>
using namespace std;
const int MAXO = 1e5, MAX = 1e5;
int node, edge;
int src, des;
vector<int> adjl[MAX];
vector<int> rc[MAX];
vector<int> rev_idx[MAX];
void add_edge(int u, int v, int w) {
  adjl[u].push_back(v);
  adjl[v].push_back(u);
  rc[u].push_back(w);
  rc[v].push_back(0);
  rev_idx[u].push_back(adjl[v].size() - 1);
  rev_idx[v].push_back(adjl[u].size() - 1);
}
int lev[MAX];
int vis[MAX];
bool dinic_bfs() {
  memset(vis, 0, sizeof(vis));
  memset(lev, 0, sizeof(lev));
  lev[src] = 0;
  vis[src] = 1;
  queue<int> myq;
  myq.push(src);
  while (!myq.empty()) {
    int u = myq.front();
    myq.pop();
    int sz = adjl[u].size();
    for (int i = 0; i <= sz - 1; i++) {
      int v = adjl[u][i];
      if (rc[u][i] == 0) {
        continue;
      }
      if (vis[v] == 0) {
        vis[v] = 1;
        lev[v] = lev[u] + 1;
        myq.push(v);
      }
    }
  }
  if (vis[des]) {
    return 1;
  }
  return 0;
}
int shuru[MAX];
int dinic_dfs(int u, int flow) {
  if (u == des) {
    return flow;
  }
  for (int i = shuru[u]; i <= (int)adjl[u].size() - 1; i++) {
    shuru[u] = i;
    int v = adjl[u][i];
    if ((lev[v] == lev[u] + 1) && (rc[u][i])) {
      int ff = dinic_dfs(v, min(flow, rc[u][i]));
      if (ff) {
        rc[u][i] -= ff;
        rc[v][rev_idx[u][i]] += ff;
        return ff;
      }
    }
  }
  shuru[u] = adjl[u].size();
  return 0;
}
int dinic() {
  int ans = 0;
  while (dinic_bfs()) {
    memset(shuru, 0, sizeof(shuru));
    while (1) {
      int ff = dinic_dfs(src, MAXO);
      if (ff == 0) break;
      ans += ff;
    }
  }
  return ans;
}
int n, m;
vector<pair<int, int> > pp;
pair<int, int> ed[MAX];
int main() {
  ios::sync_with_stdio(false);
  int u, v;
  cin >> n >> m;
  src = 0;
  des = 1;
  for (int i = 1; i <= n; i++) add_edge(src, i + des, 0);
  for (int i = 1; i <= m; i++) add_edge(n + des + i, des, 1);
  for (int i = 1; i <= m; i++) {
    cin >> u >> v;
    ed[i] = {u, v};
    add_edge(u + des, n + des + i, 1);
    add_edge(v + des, n + des + i, 1);
  }
  int prin = 0, s = 0;
  for (int i = 1; i <= m; i++) {
    s++;
    for (int &x : rc[src]) x++;
    prin += dinic();
    if (prin == m) break;
  }
  cout << s << endl;
  for (int p = 1; p <= m; p++) {
    int u = n + des + p;
    int sz = adjl[u].size();
    for (int i = 0; i <= sz - 1; i++) {
      int v = adjl[u][i];
      if (rc[u][i])
        if (ed[p].first != v - des) swap(ed[p].first, ed[p].second);
    }
    cout << ed[p].first << ' ' << ed[p].second << endl;
  }
  return 0;
}
