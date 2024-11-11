#include <bits/stdc++.h>
using namespace std;
pair<int, int> edge[5010];
int n, m;
int src, des;
vector<int> adjl[11000];
vector<int> rc[11000];
vector<int> rev_idx[11000];
int lev[11000];
int vis[11000];
bool dinic_bfs() {
  memset((vis), 0, sizeof(vis));
  memset((lev), 0, sizeof(lev));
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
int shuru[11000];
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
    memset((shuru), 0, sizeof(shuru));
    while (1) {
      int ff = dinic_dfs(src, 1000000000);
      if (ff == 0) break;
      ans += ff;
    }
  }
  return ans;
}
void add_edge(int u, int v, int w) {
  adjl[u].push_back(v);
  adjl[v].push_back(u);
  rc[u].push_back(w);
  rc[v].push_back(0);
  rev_idx[u].push_back(adjl[v].size() - 1);
  rev_idx[v].push_back(adjl[u].size() - 1);
}
int node_idx(int u) { return m + u; }
int flow(int threshold) {
  for (int i = src; i <= des; i++) {
    adjl[i].clear();
    rc[i].clear();
    rev_idx[i].clear();
  }
  for (int i = 1; i <= m; i++) {
    int u = edge[i].first;
    int v = edge[i].second;
    add_edge(src, i, 1);
    add_edge(i, node_idx(u), 1);
    add_edge(i, node_idx(v), 1);
  }
  for (int i = 1; i <= n; i++) {
    add_edge(node_idx(i), des, threshold);
  }
  return dinic();
}
int main() {
  cin >> n >> m;
  src = 0;
  des = (n + m + 1);
  for (int i = 1; i <= m; i++) {
    int a, b;
    cin >> a >> b;
    int u = min(a, b);
    int v = max(a, b);
    edge[i] = make_pair(u, v);
  }
  int lo = 0, hi = m;
  while (lo < hi) {
    int mid = lo + ((hi - lo) / 2);
    if (flow(mid) == m) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }
  cout << lo << "\n";
  flow(lo);
  for (int i = 1; i <= m; i++) {
    int u = edge[i].first;
    int v = edge[i].second;
    if (rc[i][1] == 0) {
      cout << v << " " << u << "\n";
    } else {
      cout << u << " " << v << "\n";
    }
  }
  return 0;
}
