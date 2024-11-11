#include <bits/stdc++.h>
using namespace std;
const int N = 10005;
const int inf = 1e9;
int n, m, high[N], nxt[N];
int visit[N * 2];
vector<pair<int, int> > E;
vector<int> G[N];
struct Dinic {
  int source, sink, n;
  struct edge {
    int to, c, f;
    edge(int to, int c, int f) : to(to), c(c), f(f) {}
  };
  vector<edge> E;
  vector<int> G[N * 4];
  void add_edge(int u, int v, int c) {
    G[u].push_back(E.size());
    E.push_back(edge(v, c, 0));
    G[v].push_back(E.size());
    E.push_back(edge(u, 0, 0));
  }
  int nxt[N * 4], dis[N * 4];
  bool bfs() {
    for (int i = 0; i <= n; ++i) dis[i] = inf;
    queue<int> qu;
    dis[source] = 0;
    qu.push(source);
    while (qu.size()) {
      int u = qu.front();
      qu.pop();
      for (int i = 0; i < G[u].size(); ++i) {
        int id = G[u][i];
        if (E[id].c > E[id].f && dis[E[id].to] == inf) {
          dis[E[id].to] = dis[u] + 1;
          qu.push(E[id].to);
        }
      }
    }
    return dis[sink] != inf;
  }
  int dfs(int u, int flow) {
    if (u == sink || !flow) return flow;
    for (int &i = nxt[u]; i < G[u].size(); ++i) {
      int id = G[u][i];
      if (dis[E[id].to] != dis[u] + 1) continue;
      int nxt_flow = dfs(E[id].to, min(flow, E[id].c - E[id].f));
      if (nxt_flow) {
        E[id].f += nxt_flow;
        E[id ^ 1].f -= nxt_flow;
        return nxt_flow;
      }
    }
    return 0;
  }
  int maxflow() {
    int res = 0;
    while (bfs()) {
      for (int i = 0; i <= n; ++i) nxt[i] = 0;
      while (int flow = dfs(source, inf)) res += flow;
    }
    return res;
  }
} flow;
void dfs(int u) {
  for (int i = 0; i < G[u].size(); ++i) {
    int id = G[u][i];
    if (high[E[id].first]) continue;
    high[E[id].first] = high[u] + 1;
    visit[id >> 1] = 1;
    nxt[E[id].first] = (id ^ 1);
    dfs(E[id].first);
  }
}
void pre(int num, int &cnt, int u, int v) {
  if (high[u] > high[v]) swap(u, v);
  while (high[v] > high[u]) {
    visit[nxt[v] >> 1] = -1;
    flow.add_edge(num, E[nxt[v]].second, 1);
    cnt++;
    v = E[nxt[v]].first;
  }
  while (u != v) {
    visit[nxt[v] >> 1] = visit[nxt[u] >> 1] = -1;
    flow.add_edge(num, E[nxt[v]].second, 1);
    flow.add_edge(num, E[nxt[u]].second, 1);
    cnt++;
    v = E[nxt[v]].first;
    cnt++;
    u = E[nxt[u]].first;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int u, v, c;
    cin >> u >> v >> c;
    G[u].push_back(E.size());
    E.push_back(pair<int, int>(v, c));
    G[v].push_back(E.size());
    E.push_back(pair<int, int>(u, c));
  }
  high[1] = 1;
  dfs(1);
  int num = m;
  flow.source = 0, flow.sink = m + m + 1, flow.n = m + m + 1;
  for (int i = 1; i <= m; ++i) flow.add_edge(i, flow.sink, 1);
  for (int i = 0; i < m; ++i) {
    if (!visit[i]) {
      int cnt = 0;
      num++;
      visit[i] = -1;
      flow.add_edge(num, E[i * 2].second, 1);
      pre(num, cnt, E[i * 2].first, E[i * 2 + 1].first);
      flow.add_edge(flow.source, num, cnt);
    }
  }
  for (int i = 0; i < m; ++i) {
    if (visit[i] != -1) {
      flow.add_edge(flow.source, ++num, 1);
      flow.add_edge(num, E[i * 2].second, 1);
    }
  }
  cout << flow.maxflow();
}
