#include <bits/stdc++.h>
using namespace std;
const int MAXN = 50;
const int MAXK = 1000;
const int oops = MAXN + 5;
class Edge {
 public:
  int u, v, cap, flow, rev;
  Edge() {}
  Edge(int u, int v, int cap, int flow, int rev)
      : u(u), v(v), cap(cap), flow(flow), rev(rev) {}
  static void addEdge(int, int, int);
};
vector<Edge> G[MAXN + 5];
bool vis[MAXN + 5];
int path[MAXN + 5];
Edge* dad[MAXN + 5];
int n, k;
void Edge::addEdge(int u, int v, int cap) {
  G[u].push_back(Edge(u, v, cap, 0, G[v].size()));
  G[v].push_back(Edge(v, u, 0, 0, G[u].size() - 1));
}
bool dfs(int u, int sink, int flow) {
  if (u == sink) return true;
  if (vis[u]) return false;
  vis[u] = true;
  for (int c = 0; c < G[u].size(); c++) {
    if (G[u][c].cap - G[u][c].flow < flow) continue;
    const int v = G[u][c].v;
    if (dfs(v, sink, flow)) {
      G[u][c].flow += flow;
      G[v][G[u][c].rev].flow -= flow;
      return true;
    }
  }
  return false;
}
int maxFlow(int source, int sink) {
  int ret = 0;
  for (int flow = 1 << 20; flow > 0; flow >>= 1)
    while (memset(vis, 0, sizeof(vis)), dfs(source, sink, flow)) ret += flow;
  return ret;
}
int belmanba2f(int source, int sink) {
  for (int c = 0; c < n; c++) path[c] = oops;
  path[source] = 0;
  dad[source] = NULL;
  queue<int> q;
  q.push(source);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int c = 0; c < G[u].size(); c++) {
      const int v = G[u][c].v;
      if (!G[u][c].cap && !G[v][G[u][c].rev].flow) continue;
      const int cost = G[u][c].cap > G[u][c].flow
                           ? -(G[v][G[u][c].rev].cap < G[v][G[u][c].rev].flow)
                           : 1;
      if (path[v] > path[u] + cost) {
        path[v] = path[u] + cost;
        dad[v] = &G[u][c];
        q.push(v);
      }
    }
  }
  for (Edge* e = dad[sink]; e; e = dad[e->u]) {
    e->flow++;
    G[e->v][e->rev].flow--;
  }
  return path[sink];
}
int main() {
  int c, c2;
  scanf("%d%d", &n, &k);
  for (c = 0; c < n; c++)
    for (c2 = 0; c2 < n; c2++) {
      int cap;
      scanf("%d", &cap);
      if (!cap) continue;
      Edge::addEdge(c, c2, cap);
    }
  int ret = maxFlow(0, n - 1);
  while ((k -= belmanba2f(0, n - 1)) >= 0) ret++;
  printf("%d\n", ret);
  return 0;
}
