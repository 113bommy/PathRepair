#include <bits/stdc++.h>
const long long INF = (1LL << 60);
struct edge {
  int u, v;
  long long cost, cap, flow;
  edge(int u, int v, long long cap, long long cost)
      : u(u), v(v), cap(cap), cost(cost), flow(0) {}
};
struct flow_network {
  int n, s, t, *par, *in_queue, *num_vis;
  long long *dist;
  std::vector<edge> edges;
  std::vector<int> *adj;
  flow_network(int n, int s, int t) : n(n), s(s), t(t) {
    adj = new std::vector<int>[n];
    par = new int[n];
    in_queue = new int[n];
    num_vis = new int[n];
    dist = new long long[n];
  }
  void add_edge(int u, int v, long long cap, long long cost) {
    adj[u].push_back(edges.size());
    edges.push_back(edge(u, v, cap, cost));
    adj[v].push_back(edges.size());
    edges.push_back(edge(v, u, cap, cost));
  }
  long long res(edge &e) { return e.cap - e.flow; }
  bool spfa() {
    std::queue<int> q;
    q.push(s);
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      in_queue[u] = 0;
      if (++num_vis[u] >= n) {
        dist[u] = -INF;
        return false;
      }
      for (int i : adj[u]) {
        edge e = edges[i];
        if (res(e) <= 0) continue;
        long long nd = dist[u] + e.cost;
        if (dist[e.v] > nd) {
          dist[e.v] = nd;
          par[e.v] = i;
          if (not in_queue[e.v]) {
            q.push(e.v);
            in_queue[e.v] = 1;
          }
        }
      }
    }
    return dist[t] != INF;
  }
  bool aug_path() {
    for (int u = 0; u < n; ++u) {
      par[u] = -1;
      in_queue[u] = 0;
      num_vis[u] = 0;
      dist[u] = INF;
    }
    dist[s] = 0;
    in_queue[s] = 1;
    return spfa();
  }
  std::pair<long long, long long> calc_max_flow() {
    long long total_cost = 0, total_flow = 0;
    while (aug_path()) {
      long long f = INF;
      for (int i = par[t]; i != -1; i = par[edges[i].u])
        f = std::min(f, res(edges[i]));
      for (int i = par[t]; i != -1; i = par[edges[i].u]) {
        edges[i].flow += f;
        edges[i ^ 1].flow -= f;
      }
      total_cost += f * dist[t];
      total_flow += f;
    }
    return {total_cost, total_flow};
  }
};
int N, Q, MINV[51], MAXV[51];
int pad_node(int u) { return u + N; }
int main() {
  std::cin >> N >> Q;
  for (int u = 1; u <= N; ++u) {
    MINV[u] = 1;
    MAXV[u] = N;
  }
  while (Q--) {
    int t, l, r, v;
    std::cin >> t >> l >> r >> v;
    if (t == 1)
      for (int u = l; u <= r; ++u) MINV[u] = std::max(MINV[u], v);
    else
      for (int u = l; u <= r; ++u) MAXV[u] = std::min(MAXV[u], v);
  }
  int nn = 2 * N + 2;
  int s = 0;
  int t = nn - 1;
  flow_network g(nn, s, t);
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= N; ++j) g.add_edge(s, i, 1, 2 * j - 1);
    for (int u = 1; u <= N; ++u)
      if (MINV[u] <= i and i <= MAXV[u]) g.add_edge(i, pad_node(u), 1, 0);
  }
  for (int u = 1; u <= N; ++u) g.add_edge(pad_node(u), t, 1, 0);
  std::pair<long long, long long> res = g.calc_max_flow();
  if (res.second == N)
    std::cout << res.first << "\n";
  else
    std::cout << "-1\n";
  return 0;
}
