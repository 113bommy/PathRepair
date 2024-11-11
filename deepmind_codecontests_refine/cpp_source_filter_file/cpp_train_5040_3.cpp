#include <bits/stdc++.h>
using namespace std;
const int INF = 0x7f7f7f7f;
int src, snk, nNode, nEdge, n, edge[50 + 5][50 + 5];
int fin[52 + 5], pre[52 + 5], dist[52 + 5];
int cap[2 * 100000 + 5], cost[2 * 100000 + 5], Next[2 * 100000 + 5],
    to[2 * 100000 + 5], from[2 * 100000 + 5];
void init(int _src, int _snk, int nodes) {
  memset(fin, -1, sizeof(fin));
  nNode = nodes, nEdge = 0;
  src = _src, snk = _snk;
}
void addEdge(int u, int v, int _cost, int _cap) {
  from[nEdge] = u, to[nEdge] = v, cap[nEdge] = _cap, cost[nEdge] = _cost;
  Next[nEdge] = fin[u], fin[u] = nEdge++;
  from[nEdge] = v, to[nEdge] = u, cap[nEdge] = 0, cost[nEdge] = -(_cost);
  Next[nEdge] = fin[v], fin[v] = nEdge++;
  assert(nEdge <= 2 * 100000);
}
bool bellman() {
  int iter, u, v, i;
  bool flag = true;
  memset(dist, 0x7f, sizeof(dist));
  memset(pre, -1, sizeof(pre));
  dist[src] = 0;
  for (iter = 1; iter < nNode && flag; iter++) {
    flag = false;
    for (u = 1; u <= nNode; u++) {
      for (i = fin[u]; i >= 0; i = Next[i]) {
        v = to[i];
        if (cap[i] && dist[v] > dist[u] + cost[i]) {
          dist[v] = dist[u] + cost[i];
          pre[v] = i;
          flag = true;
        }
      }
    }
  }
  return (dist[snk] < INF);
}
int mcmf(int &fcost) {
  int netflow, i, bot, u;
  netflow = fcost = 0;
  while (bellman()) {
    bot = INF;
    for (u = pre[snk]; u >= 0; u = pre[from[u]]) bot = min(bot, cap[u]);
    for (u = pre[snk]; u >= 0; u = pre[from[u]]) {
      cap[u] -= bot;
      cap[u ^ 1] += bot;
      fcost += bot * cost[u];
    }
    netflow += bot;
  }
  return netflow;
}
int setFlow(int flw) {
  int i, j, c;
  src = n + 1;
  snk = n;
  init(src, snk, src);
  for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++) {
      c = edge[i][j];
      if (i == j || c == 0) continue;
      addEdge(i, j, 0, c);
      addEdge(i, j, 1, INF);
    }
  addEdge(src, 1, 0, flw);
  int min_cost, F;
  F = mcmf(min_cost);
  return (F == flw) ? min_cost : INF;
}
int main() {
  int i, j, k;
  int c;
  scanf("%d %d", &n, &k);
  for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++) scanf("%d", &edge[i][j]);
  int lo = 0, hi = 10000000, mid;
  while (lo != hi) {
    mid = lo + (hi - lo + 1) / 2;
    if (setFlow(mid) <= k)
      lo = mid;
    else
      hi = mid - 1;
  }
  printf("%d\n", lo);
  return 0;
}
