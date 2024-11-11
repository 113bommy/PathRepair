#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 7;
const long long INF = 1e17;
int n, m;
long long a[N];
struct Dinic {
  struct Edge {
    int from, to;
    long long cap, flow;
    Edge(int u, int v, long long c, long long f)
        : from(u), to(v), cap(c), flow(f) {}
  };
  int n, m, s, t;
  vector<Edge> edges;
  vector<int> G[N];
  bool vis[N];
  int d[N];
  int cur[N];
  void init(int n) {
    this->n = n;
    for (int i = 0; i < n; i++) G[i].clear();
    edges.clear();
  }
  void AddEdge(int from, int to, long long cap) {
    edges.emplace_back(from, to, cap, 0);
    edges.emplace_back(to, from, 0, 0);
    m = edges.size();
    G[from].push_back(m - 2);
    G[to].push_back(m - 1);
  }
  bool BFS() {
    memset(vis, 0, sizeof(vis));
    memset(d, 0, sizeof(d));
    queue<int> q;
    q.push(s);
    d[s] = 0;
    vis[s] = 1;
    while (!q.empty()) {
      int x = q.front();
      q.pop();
      for (int i = 0; i < G[x].size(); i++) {
        Edge& e = edges[G[x][i]];
        if (!vis[e.to] && e.cap > e.flow) {
          vis[e.to] = 1;
          d[e.to] = d[x] + 1;
          q.push(e.to);
        }
      }
    }
    return vis[t];
  }
  int DFS(int x, long long a) {
    if (x == t || a == 0) return a;
    long long flow = 0, f;
    for (int& i = cur[x]; i < G[x].size(); i++) {
      Edge& e = edges[G[x][i]];
      if (d[x] + 1 == d[e.to] && (f = DFS(e.to, min(a, e.cap - e.flow))) > 0) {
        e.flow += f;
        edges[G[x][i] ^ 1].flow -= f;
        flow += f;
        a -= f;
        if (a == 0) break;
      }
    }
    return flow;
  }
  long long Maxflow(int s, int t) {
    this->s = s, this->t = t;
    long long flow = 0;
    while (BFS()) {
      memset(cur, 0, sizeof(cur));
      flow += DFS(s, INF);
    }
    return flow;
  }
} solver;
int main() {
  long long sum = 0;
  scanf("%d%d", &n, &m);
  solver.init(n + m + 3);
  long long s = 0, t = n + m + 1;
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &a[i]);
    solver.AddEdge(i, t, a[i]);
  }
  long long u, v, w;
  for (int i = 1; i <= m; ++i) {
    scanf("%lld%lld%lld", &u, &v, &w);
    sum += w;
    solver.AddEdge(s, n + i, w);
    solver.AddEdge(n + i, u, INF);
    solver.AddEdge(n + i, v, INF);
  }
  printf("%lld\n", sum - solver.Maxflow(s, t));
}
