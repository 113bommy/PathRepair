#include <bits/stdc++.h>
using namespace std;
const int N = 305;
vector<int> G[N];
bool used[N];
int mt[N];
bool kuhn(int v) {
  if (used[v]) return false;
  used[v] = true;
  for (int to : G[v]) {
    if (mt[to] == -1 || kuhn(mt[to])) {
      mt[to] = v;
      return true;
    }
  }
  return false;
}
struct Edge {
  int from, to;
  int cap, flow;
  Edge(int _from, int _to, int _cap) {
    from = _from;
    to = _to;
    cap = _cap;
    flow = 0;
  }
  Edge(){};
};
const int INF = 1e9 + 5;
vector<Edge> edges;
vector<int> g[N];
int n;
int S, T;
int d[N], it[N];
void addEdge(int u, int v, int c) {
  g[u].push_back((int)edges.size());
  edges.push_back(Edge(u, v, c));
  g[v].push_back((int)edges.size());
  edges.push_back(Edge(v, u, 0));
}
bool bfs() {
  for (int v = 0; v < n; ++v) {
    used[v] = false;
    d[v] = N;
  }
  queue<int> Q;
  d[S] = 0;
  used[S] = true;
  Q.push(S);
  while (!Q.empty()) {
    static int v;
    v = Q.front();
    Q.pop();
    for (int i : g[v]) {
      static int u;
      u = edges[i].to;
      if (!used[u] && edges[i].flow < edges[i].cap) {
        d[u] = d[v] + 1;
        used[u] = true;
        Q.push(u);
      }
    }
  }
  return d[T] < N;
}
int dfs(int v, int cmin) {
  if (v == T) return cmin;
  for (; it[v] < (int)g[v].size(); ++it[v]) {
    Edge& e = edges[g[v][it[v]]];
    if (d[e.to] == d[v] + 1 && e.flow < e.cap) {
      static int df;
      df = dfs(e.to, min(cmin, e.cap - e.flow));
      if (df != 0) {
        e.flow += df;
        edges[g[v][it[v]] ^ 1].flow -= df;
        return df;
      }
    }
  }
  return 0;
}
int Dinic() {
  int Flow = 0;
  while (bfs()) {
    for (int v = 0; v < n; ++v) it[v] = 0;
    while (int df = dfs(S, 2 * INF)) Flow += df;
  }
  return Flow;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    static int m;
    scanf("%d", &m);
    while (m--) {
      static int x;
      scanf("%d", &x);
      --x;
      G[i].push_back(x);
    }
  }
  for (int to = 0; to < n; ++to) mt[to] = -1;
  for (int i = 0; i < n; ++i) {
    kuhn(i);
    for (int j = 0; j < n; ++j) used[j] = false;
  }
  int ans = 0;
  S = n;
  T = n + 1;
  for (int i = 0; i < n; ++i) {
    static int w;
    scanf("%d", &w);
    if (w < 0) {
      ans += w;
      addEdge(S, i, -w);
    } else
      addEdge(i, T, w);
  }
  for (int v = 0; v < n; ++v) {
    for (int u : G[v]) {
      if (mt[u] != v) addEdge(v, mt[u], INF);
    }
  }
  n += 2;
  ans += Dinic();
  printf("%d", ans);
}
