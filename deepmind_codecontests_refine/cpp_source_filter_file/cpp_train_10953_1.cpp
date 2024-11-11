#include <bits/stdc++.h>
using namespace std;
int d[1 << 13];
int j[1 << 13][32];
int jcost[1 << 13][32];
int parentedge[1 << 13];
struct Edge {
  int u, v, w;
  Edge(int u, int v, int w) : u(u), v(v), w(w){};
};
vector<Edge> edges;
vector<int> adj[1 << 13];
int N;
void dfs(int u, int p, int pc, int dist, int pe) {
  j[u][0] = p;
  jcost[u][0] = pc;
  parentedge[u] = pe;
  d[u] = dist;
  for (int k = 1; k < 32 && j[u][k - 1] != -1; k++) {
    int mid = j[u][k - 1];
    j[u][k] = j[mid][k - 1];
    jcost[u][k] = min(jcost[u][k - 1], jcost[mid][k - 1]);
  }
  for (int e : adj[u]) {
    int v = u ^ edges[e].u ^ edges[e].v;
    int w = edges[e].w;
    if (v == p) continue;
    dfs(v, u, w, dist + 1, e);
  }
}
pair<int, int> walk(int u, int k) {
  int mincost = INT_MAX;
  for (int i = 31; i >= 0; i--) {
    if ((k & (1 << i)) != 0) {
      mincost = min(mincost, jcost[u][i]);
      u = j[u][i];
    }
  }
  return make_pair(u, mincost);
}
pair<int, int> getlca(int u, int v) {
  int mincost = INT_MAX;
  if (d[u] < d[v]) {
    pair<int, int> w = walk(v, d[v] - d[u]);
    mincost = min(mincost, w.second);
    v = w.first;
  }
  if (d[u] > d[v]) {
    pair<int, int> w = walk(u, d[u] - d[v]);
    mincost = min(mincost, w.second);
    u = w.first;
  }
  if (u == v) {
    return make_pair(u, mincost);
  }
  for (int k = 31; k >= 0; k--) {
    if (j[u][k] != j[v][k]) {
      mincost = min({mincost, jcost[u][k], jcost[v][k]});
      u = j[u][k];
      v = j[v][k];
    }
  }
  mincost = min({mincost, jcost[u][0], jcost[v][0]});
  return make_pair(j[u][0], mincost);
}
int M;
int m[1 << 13][3];
void set_edges(int e) {
  int u = m[e][0];
  int v = m[e][1];
  int w = m[e][2];
  int lca = getlca(u, v).first;
  for (int n : {u, v}) {
    while (n != lca) {
      int pe = parentedge[n];
      edges[pe].w = max(edges[pe].w, w);
      n = n ^ edges[pe].u ^ edges[pe].v;
    }
  }
}
int main() {
  scanf("%d", &N);
  for (int i = 0; i < N - 1; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--;
    v--;
    adj[u].push_back(edges.size());
    adj[v].push_back(edges.size());
    edges.emplace_back(u, v, 0);
  }
  for (int i = 0; i < N; i++) {
    fill(j[i], j[i] + 32, -1);
  }
  dfs(0, -1, 0, 0, -1);
  scanf("%d", &M);
  for (int i = 0; i < M; i++) {
    scanf("%d %d %d", &m[i][0], &m[i][1], &m[i][2]);
    m[i][0]--;
    m[i][1]--;
    set_edges(i);
  }
  dfs(0, -1, 0, 0, 0);
  for (int i = 0; i < M; i++) {
    int mincost = getlca(m[i][0], m[i][1]).second;
    if (mincost != m[i][2]) {
      printf("-1");
      return 0;
    }
  }
  for (Edge& e : edges) {
    printf("%d ", e.w);
  }
}
