#include <bits/stdc++.h>
const double PI = acos(-1.0);
const int DIR = 4;
const int X[] = {1, 0, -1, 0};
const int Y[] = {0, 1, 0, -1};
using namespace std;
struct Edge {
  int v, to, cap, flow;
};
struct Graph {
  vector<Edge> edges;
  vector<vector<int> > g;
  vector<int> d, ptr;
  int n;
  queue<int> q;
  Graph() {}
  void addEdge(int v, int to, int cap) {
    g[v].push_back((int)edges.size());
    edges.push_back({v, to, cap, 0});
    g[to].push_back((int)edges.size());
    edges.push_back({to, v, 0, 0});
  }
  Graph(const vector<pair<int, int> >& e, int _n, int _m, int x)
      : edges(0),
        g(_n + _m + 2),
        d(_n + _m + 2),
        ptr(_n + _m + 2),
        n(_n + _m + 1) {
    for (int i = 1; i <= _m; i++) addEdge(0, i, 1);
    for (int i = 0; i < _m; i++)
      addEdge(i + 1, e[i].first + _m, 1), addEdge(i + 1, e[i].second + _m, 1);
    for (int i = 1; i <= _n; i++) addEdge(_m + i, n, x);
  }
  bool bfs() {
    fill(d.begin(), d.end(), -1);
    d[0] = 0;
    q.push(0);
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      for (auto id : g[v]) {
        Edge e = edges[id];
        int to = e.to;
        if (e.flow < e.cap && d[to] == -1) {
          d[to] = d[v] + 1;
          q.push(to);
        }
      }
    }
    return d[n] != -1;
  }
  bool dfs(int v) {
    if (v == n) return true;
    for (int& id = ptr[v]; id < (int)g[v].size(); id++) {
      Edge& e = edges[g[v][id]];
      Edge& backEdge = edges[g[v][id] ^ 1];
      int to = e.to;
      if (d[to] == d[v] + 1 && e.flow < e.cap && dfs(to)) {
        e.flow++, backEdge.flow--;
        return true;
      }
    }
    return false;
  }
  int dinic() {
    int res = 0;
    while (bfs()) {
      fill(ptr.begin(), ptr.end(), 0);
      while (int flow = dfs(0)) res += flow;
    }
    return res;
  }
} graph;
vector<pair<int, int> > e;
int n, m;
bool check(int x) {
  graph = Graph(e, n, m, x);
  return graph.dinic() == m;
}
int main() {
  scanf("%d%d", &n, &m);
  e.resize(m);
  for (int i = 0; i < m; i++) scanf("%d%d", &e[i].first, &e[i].second);
  int l = -1, r = m + 1, mid;
  while (l < r - 1) {
    mid = (l + r) / 2;
    if (check(mid))
      r = mid;
    else
      l = mid;
  }
  printf("%d\n", r);
  check(r);
  for (auto it : graph.edges) {
    if (it.v >= 1 && it.v <= m && it.to >= m + 1 && it.to <= n + m &&
        it.flow > 0) {
      if (it.to - m == e[it.v - 1].first)
        printf("%d %d\n", e[it.v - 1].first, e[it.v - 1].second);
      else
        printf("%d %d\n", e[it.v - 1].second, e[it.v - 1].first);
    }
  }
  return 0;
}
