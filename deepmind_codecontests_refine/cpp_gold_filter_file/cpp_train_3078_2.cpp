#include <bits/stdc++.h>
using namespace std;
const int MAXN = 6007;
const int oo = 0x3f3f3f3f;
struct Edge {
  int from, to, cap, flow, cost;
  Edge() {}
  Edge(int _a, int _b, int _c, int _d, int _e) {
    from = _a;
    to = _b;
    cap = _c;
    flow = _d;
    cost = _e;
  }
};
struct MCMF {
  int n, m, s, t;
  vector<Edge> edges;
  vector<int> G[MAXN];
  int inq[MAXN];
  int d[MAXN];
  int p[MAXN];
  int a[MAXN];
  void init(int n) {
    this->n = n;
    for (int i = 1; i <= n; i++) G[i].clear();
    edges.clear();
  }
  void addedge(int from, int to, int cap, int cost) {
    edges.push_back(Edge(from, to, cap, 0, cost));
    edges.push_back(Edge(to, from, 0, 0, -cost));
    m = edges.size();
    G[from].push_back(m - 2);
    G[to].push_back(m - 1);
  }
  bool BellmanFord(int s, int t, int &flow, int &cost) {
    for (int i = 1; i <= n; i++) {
      d[i] = oo;
    }
    memset(inq, 0, sizeof(inq));
    d[s] = 0;
    inq[s] = 1;
    p[s] = 0;
    a[s] = oo;
    queue<int> Q;
    Q.push(s);
    while (!Q.empty()) {
      int u = Q.front();
      Q.pop();
      inq[u] = 0;
      for (int i = 0; i < G[u].size(); i++) {
        Edge &e = edges[G[u][i]];
        if (e.cap > e.flow && d[e.to] > d[u] + e.cost) {
          d[e.to] = d[u] + e.cost;
          p[e.to] = G[u][i];
          a[e.to] = min(a[u], e.cap - e.flow);
          if (!inq[e.to]) {
            Q.push(e.to);
            inq[e.to] = 1;
          }
        }
      }
    }
    if (d[t] == oo) return false;
    flow += a[t];
    cost += d[t] * a[t];
    int u = t;
    while (u != s) {
      edges[p[u]].flow += a[t];
      edges[p[u] ^ 1].flow -= a[t];
      u = edges[p[u]].from;
    }
    return true;
  }
  int mincost(int s, int t) {
    int flow = 0, cost = 0;
    while (BellmanFord(s, t, flow, cost))
      ;
    return cost;
  }
} mcmf;
int main() {
  int n, p, q;
  cin >> n >> p >> q;
  mcmf.init(n + 4);
  const int ss = n + 3, st = n + 4;
  const int sp = n + 1, sq = n + 2;
  mcmf.addedge(sp, st, p, 0);
  mcmf.addedge(sq, st, q, 0);
  for (int i = 1; i <= n; i++) {
    mcmf.addedge(ss, i, 1, 0);
  }
  for (int i = 1; i <= n; i++) {
    int ta;
    scanf("%d", &ta);
    mcmf.addedge(i, sp, 1, -ta);
  }
  for (int i = 1; i <= n; i++) {
    int ta;
    scanf("%d", &ta);
    mcmf.addedge(i, sq, 1, -ta);
  }
  int res = mcmf.mincost(ss, st);
  printf("%d\n", -res);
  for (int i = 0; i < mcmf.G[sp].size(); i++) {
    int u = mcmf.G[sp][i];
    if (mcmf.edges[u ^ 1].flow == mcmf.edges[u ^ 1].cap)
      printf("%d ", mcmf.edges[u ^ 1].from);
  }
  printf("\n");
  for (int i = 0; i < mcmf.G[sq].size(); i++) {
    int u = mcmf.G[sq][i];
    if (mcmf.edges[u ^ 1].flow == mcmf.edges[u ^ 1].cap)
      printf("%d ", mcmf.edges[u ^ 1].from);
  }
  printf("\n");
}
