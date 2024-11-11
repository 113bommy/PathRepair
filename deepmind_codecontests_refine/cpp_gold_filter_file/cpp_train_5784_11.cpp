#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 5;
struct edge {
  int from, to, id, cost;
};
int N, M, s, t;
vector<edge> G[MAXN];
bool vis[MAXN], found;
vector<edge> path;
void dfs1(int u, int id = -1) {
  if (u == t) return void(found = true);
  vis[u] = true;
  for (int i = 0; i < G[u].size(); i++) {
    if (G[u][i].id == id) continue;
    int v = G[u][i].to;
    if (vis[v]) continue;
    dfs1(v, id);
    if (found) {
      if (id == -1) path.push_back(G[u][i]);
      return;
    }
  }
}
int td[MAXN], low[MAXN];
vector<edge> bridges;
bool dfs(int u, int idp, int id) {
  bool ret = (u == t);
  low[u] = td[u];
  for (int i = 0; i < G[u].size(); i++) {
    if (G[u][i].id == id || G[u][i].id == idp) continue;
    int v = G[u][i].to;
    if (td[v] > td[u]) continue;
    if (td[v] == -1) {
      td[v] = td[u] + 1;
      bool vret = dfs(v, G[u][i].id, id);
      ret |= vret;
      low[u] = min(low[u], low[v]);
      if (low[v] == td[v] && vret) bridges.push_back(G[u][i]);
    } else {
      low[u] = min(low[u], td[v]);
    }
  }
  return ret;
}
int main() {
  scanf("%d", &N), scanf("%d", &M);
  scanf("%d", &s), scanf("%d", &t);
  s--;
  t--;
  for (int i = 0; i < M; i++) {
    int u, v, cost;
    scanf("%d", &u), scanf("%d", &v);
    u--;
    v--;
    scanf("%d", &cost);
    G[u].push_back({u, v, i, cost});
    G[v].push_back({v, u, i, cost});
  }
  dfs1(s);
  if (!found) {
    printf("0\n0\n");
    return 0;
  }
  int ans = -1;
  vector<int> vans;
  for (int i = 0; i < path.size(); i++) {
    int id = path[i].id;
    found = false;
    memset(vis, false, N * sizeof(bool));
    dfs1(s, id);
    if (!found) {
      if (ans == -1 || path[i].cost < ans) {
        ans = path[i].cost;
        vans.clear();
        vans.push_back(id);
      }
    } else {
      bridges.clear();
      memset(td, -1, sizeof(td));
      td[s] = 0;
      dfs(s, -1, id);
      if (bridges.size() > 0) {
        for (int j = 0; j < bridges.size(); j++) {
          int nans = path[i].cost + bridges[j].cost;
          if (ans == -1 || nans < ans) {
            ans = nans;
            vans.clear();
            vans.push_back(id);
            vans.push_back(bridges[j].id);
          }
        }
      }
    }
  }
  printf("%d\n", ans);
  if (ans != -1) {
    printf("%d\n", (int)vans.size());
    for (int i = 0; i < vans.size(); i++) {
      printf("%d%c", vans[i] + 1, " \n"[i == vans.size() - 1]);
    }
  }
}
