#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5005, MAXM = 100005;
struct Edge {
  int u, v, len, id;
  Edge() {}
  Edge(int u, int v, int len, int id) : u(u), v(v), len(len), id(id) {}
  bool operator<(const Edge &t) const { return len < t.len; }
};
struct AdjEdge {
  int v, len, id;
  AdjEdge() {}
  AdjEdge(int v, int len, int id) : v(v), len(len), id(id) {}
};
int dsu[MAXN];
int Root(int x) {
  if (dsu[x] == 0) return x;
  return dsu[x] = Root(dsu[x]);
}
int n, m, k;
Edge edge[MAXM];
bool use[MAXM];
vector<AdjEdge> adj[MAXN];
void AddEdge(int i) {
  adj[edge[i].u].push_back(AdjEdge(edge[i].v, edge[i].len, i));
  adj[edge[i].v].push_back(AdjEdge(edge[i].u, edge[i].len, i));
}
void Kruskal() {
  sort(edge + 1, edge + m + 1);
  for (int i = 1; i <= m; i++) {
    if (edge[i].u == 1 || edge[i].v == 1) continue;
    int r1 = Root(edge[i].u), r2 = Root(edge[i].v);
    if (r1 == r2) continue;
    dsu[r1] = r2;
    AddEdge(i);
    use[i] = true;
  }
}
int dp[MAXN], dpid[MAXN];
void DP(int u, int f = 0) {
  for (int i = 0; i < (int)adj[u].size(); i++) {
    AdjEdge e = adj[u][i];
    if (e.v == f || !use[e.id]) continue;
    if (u != 1) {
      if (dp[u] > e.len)
        dp[e.v] = dp[u], dpid[e.v] = dpid[u];
      else
        dp[e.v] = e.len, dpid[e.v] = e.id;
    } else
      dp[e.v] = 0;
    DP(e.v, u);
  }
}
int blkc;
int minE[MAXN];
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= m; i++) {
    int u, v, len;
    scanf("%d%d%d", &u, &v, &len);
    edge[i] = Edge(u, v, len, i);
  }
  Kruskal();
  for (int i = 1; i <= m; i++)
    if (edge[i].u == 1 || edge[i].v == 1) {
      int v = (edge[i].u != 1 ? edge[i].u : edge[i].v);
      int r = Root(v);
      if (minE[r] == 0) {
        blkc++;
        minE[r] = i;
      }
    }
  if (blkc > k) {
    puts("-1");
    return 0;
  }
  for (int i = 1; i <= n; i++)
    if (minE[i] != 0) {
      AddEdge(minE[i]);
      use[minE[i]] = true;
    }
  for (int i = blkc + 1; i <= k; i++) {
    DP(1);
    int best = 0x3F3F3F3F, e, e1;
    for (int j = 1; j <= m; j++)
      if (!use[j] && (edge[j].u == 1 || edge[j].v == 1)) {
        int v = (edge[j].u != 1 ? edge[j].u : edge[j].v);
        if (best > edge[j].len - dp[v]) {
          best = edge[j].len - dp[v];
          e = dpid[v];
          e1 = j;
        }
      }
    AddEdge(e1);
    use[e1] = true;
    use[e] = false;
  }
  printf("%d\n", n - 1);
  for (int i = 1; i <= m; i++)
    if (use[i]) printf("%d ", edge[i].id);
  puts("");
  return 0;
}
