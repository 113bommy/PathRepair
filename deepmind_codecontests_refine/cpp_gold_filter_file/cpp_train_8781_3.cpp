#include <bits/stdc++.h>
using namespace std;
struct MinCostMaxFlow {
  static const int INF = 1e9;
  int n, s, t;
  struct edge {
    int u, v, c, f, cost;
  };
  vector<edge> E;
  vector<vector<int> > graph;
  vector<int> dist, head;
  vector<bool> inq;
  MinCostMaxFlow(int n = 0, int s = 0, int t = 0) : n(n), s(s), t(t) {
    E.clear();
    graph.assign(n + 1, vector<int>());
  }
  void addEdge(int u, int v, int c, int cost) {
    graph[u].push_back(E.size());
    E.push_back({u, v, c, 0, cost});
    graph[v].push_back(E.size());
    E.push_back({v, u, 0, 0, -cost});
  }
  bool SPFA() {
    head.assign(n + 1, -1);
    inq.assign(n + 1, 0);
    dist.assign(n + 1, 1e9);
    dist[s] = 0;
    queue<pair<int, int> > wl;
    wl.push({0, s});
    while (not wl.empty()) {
      int d = wl.front().first, u = wl.front().second;
      wl.pop();
      if (d > dist[u]) continue;
      for (int i : graph[u]) {
        if (dist[E[i].v] > d + E[i].cost && E[i].f < E[i].c) {
          dist[E[i].v] = d + E[i].cost, head[E[i].v] = i;
          wl.push({dist[E[i].v], E[i].v});
        }
      }
    }
    return (head[t] != -1);
  }
  int dfs() {
    int delta = INF;
    for (int u = t; u != s; u = E[head[u]].u) {
      int i = head[u];
      delta = min(delta, E[i].c - E[i].f);
    }
    for (int u = t; u != s; u = E[head[u]].u) {
      int i = head[u];
      E[i].f += delta, E[i ^ 1].f -= delta;
    }
    return delta;
  }
  int maxFlow() {
    int ans = 0, flow = 0;
    while (SPFA()) ans += dist[t] * dfs();
    for (int i : graph[s]) flow += E[i].f;
    return (flow < graph[t].size() ? -1 : ans);
  }
} mcmf;
int n, p[110], sum, src, snk, cnt;
string t, s[110];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> t >> n;
  sum = t.length();
  for (int i = 1; i <= n; i++) {
    cin >> s[i] >> p[i];
    sum += s[i].length();
  }
  src = sum + n + 1, snk = sum + n + 2, cnt = t.length() + 1;
  mcmf = MinCostMaxFlow(sum + n + 2, src, snk);
  for (int i = 1; i <= t.length(); i++) mcmf.addEdge(i, snk, 1, 0);
  for (int i = 1; i <= n; i++) {
    int ind = cnt++;
    mcmf.addEdge(src, ind, p[i], 0);
    for (int j = 0; j < s[i].length(); j++, cnt++) {
      mcmf.addEdge(ind, cnt, 1, 0);
      for (int k = 0; k < t.length(); k++) {
        if (s[i][j] == t[k]) {
          mcmf.addEdge(cnt, k + 1, 1, i);
        }
      }
    }
  }
  printf("%d", mcmf.maxFlow());
}
