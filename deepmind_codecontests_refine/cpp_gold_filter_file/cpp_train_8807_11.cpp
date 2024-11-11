#include <bits/stdc++.h>
using namespace std;
struct Dinic {
  struct Edge {
    int from, to;
    int cap, flow;
    int rev;
    Edge(int _from, int _to, int _cap, int _rev) {
      from = _from;
      to = _to;
      cap = _cap;
      flow = 0;
      rev = _rev;
    }
    Edge() {}
  };
  const int INF = 1000 * 1000 * 1000 + 7;
  vector<Edge> *g;
  int *dist;
  int *lastEdge;
  int n;
  Dinic() {}
  Dinic(int _n) {
    n = _n;
    g = new vector<Edge>[n + 1];
    dist = new int[n + 1];
    lastEdge = new int[n + 1];
  }
  void addEdge(int u, int v, int cap) {
    g[u].push_back(Edge(u, v, cap, (int)g[v].size()));
    g[v].push_back(Edge(v, u, 0, (int)g[u].size() - 1));
  }
  void bfs(int s, int minVal) {
    for (int i = 1; i <= n; i++) {
      dist[i] = INF;
    }
    dist[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (int i = 0; i < (int)g[u].size(); i++) {
        int to = g[u][i].to;
        if (g[u][i].cap - g[u][i].flow >= minVal && dist[to] > dist[u] + 1) {
          dist[to] = dist[u] + 1;
          q.push(to);
        }
      }
    }
  }
  int dfs(int v, int f, int flow, int minVal) {
    if (flow < minVal) return 0;
    if (v == f) return flow;
    int beg = lastEdge[v];
    for (int i = beg; i < (int)g[v].size(); i++) {
      lastEdge[v] = i;
      int to = g[v][i].to;
      if (dist[to] != dist[v] + 1) continue;
      int goFlow = dfs(to, f, min(flow, g[v][i].cap - g[v][i].flow), minVal);
      if (goFlow > 0) {
        g[v][i].flow += goFlow;
        g[to][g[v][i].rev].flow -= goFlow;
        return goFlow;
      }
    }
    return 0;
  }
  int calcFlow(int s, int f) {
    int flow = 0;
    for (int i = 25; i >= 0; i--) {
      while (1) {
        for (int i = 1; i <= n; i++) {
          lastEdge[i] = 0;
        }
        bfs(s, (1 << i));
        if (dist[f] >= INF) break;
        int tmp = dfs(s, f, INF, (1 << i));
        while (tmp > 0) {
          flow += tmp;
          tmp = dfs(s, f, INF, (1 << i));
        }
      }
    }
    return flow;
  }
};
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  vector<pair<int, int> > edges;
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    edges.push_back(make_pair(u, v));
  }
  if (m == 0) {
    puts("0");
    return 0;
  }
  int l = 0, r = n;
  while (r - l > 1) {
    int mg = (l + r) >> 1;
    Dinic d(n + m + 5);
    for (int i = 1; i <= n; i++) {
      d.addEdge(n + m + 1, i, mg);
    }
    for (int i = 0; i < m; i++) {
      d.addEdge(edges[i].first, n + 1 + i, 1);
      d.addEdge(edges[i].second, n + 1 + i, 1);
      d.addEdge(n + 1 + i, n + m + 2, 1);
    }
    if (d.calcFlow(n + m + 1, n + m + 2) == m) {
      r = mg;
    } else {
      l = mg;
    }
  }
  printf("%d\n", r);
  Dinic d(n + m + 5);
  for (int i = 1; i <= n; i++) {
    d.addEdge(n + m + 1, i, r);
  }
  for (int i = 0; i < m; i++) {
    d.addEdge(edges[i].first, n + 1 + i, 1);
    d.addEdge(edges[i].second, n + 1 + i, 1);
    d.addEdge(n + 1 + i, n + m + 2, 1);
  }
  assert(d.calcFlow(n + m + 1, n + m + 2) == m);
  for (int v = 1; v <= n; v++) {
    for (Dinic::Edge e : d.g[v]) {
      if (e.flow == 1) {
        int id = e.to - n - 1;
        if (id < 0 || id >= m) continue;
        pair<int, int> curEdge = edges[e.to - n - 1];
        if (curEdge.first != v) swap(curEdge.first, curEdge.second);
        printf("%d %d\n", curEdge.first, curEdge.second);
      }
    }
  }
  return 0;
}
