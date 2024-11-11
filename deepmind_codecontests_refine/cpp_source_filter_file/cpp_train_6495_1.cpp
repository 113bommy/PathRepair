#include <bits/stdc++.h>
using namespace std;
const int N = 90;
const int V = N * N;
const int E = 10 * V;
const int DX[] = {-1, 0, 1, 0};
const int DY[] = {0, -1, 0, 1};
const int INF = 1e9;
struct Edge {
  int to, flow, maxFlow, cost, ref;
  Edge() {}
  Edge(int to, int maxFlow, int cost, int ref)
      : to(to), flow(0), maxFlow(maxFlow), cost(cost), ref(ref) {}
};
int n, m, __inp[N][N], ind[N][N];
int vCnt, gs, gt;
Edge e[E];
int eSz;
int g[V];
void addEdge(int u, int v, int maxFlow, int cost) {
  e[eSz++] = Edge(v, maxFlow, cost, g[u]);
  g[u] = eSz - 1;
  e[eSz++] = Edge(u, 0, -cost, g[v]);
  g[v] = eSz - 1;
}
int d[V], par[V], parE[V];
int q[V];
bool inQ[E];
bool bfm() {
  fill(d, d + V, INF);
  d[gs] = 0;
  par[gs] = -1;
  int ql = 0, qr = 0;
  q[qr++] = gs;
  while (ql < qr) {
    int v = q[ql++];
    inQ[v] = false;
    for (int i = g[v]; i != -1; i = e[i].ref)
      if (e[i].flow < e[i].maxFlow && d[e[i].to] > d[v] + e[i].cost) {
        d[e[i].to] = d[v] + e[i].cost;
        par[e[i].to] = v;
        parE[e[i].to] = i;
        if (!inQ[e[i].to]) {
          q[qr++] = e[i].to;
          inQ[e[i].to] = true;
        }
      }
  }
  if (d[gt] == INF) return false;
  for (int i = gt; i != gs; i = par[i]) {
    e[parE[i]].flow += 1;
    e[parE[i] ^ 1].flow -= 1;
  }
  return true;
}
int main() {
  fill(g, g + V, -1);
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) scanf("%d", &__inp[i][j]);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) ind[i][j] = vCnt++;
  gs = vCnt++;
  gt = vCnt++;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if ((i + j) % 2 == 0) {
        for (int t = 0; t < 4; t++) {
          int x = i + DX[t];
          int y = j + DY[t];
          if (x >= 0 && x < n && y >= 0 && y < m)
            addEdge(ind[i][j], ind[x][y], 1, (__inp[i][j] != __inp[x][y]));
        }
      }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      if ((i + j) % 2 == 0)
        addEdge(gs, ind[i][j], 1, 0);
      else
        addEdge(ind[i][j], gt, 1, 0);
    }
  while (bfm())
    ;
  int total = 0;
  for (int i = 0; i < eSz; i++)
    if (e[i].maxFlow == 1) total += e[i].flow * e[i].cost;
  printf("%d\n", total);
  return 0;
}
