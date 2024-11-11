#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct Dinic {
  struct Edge {
    int u, v;
    ll cap, flow;
    Edge() : u(0), v(0), cap(0), flow(0) {}
    Edge(int uu, int vv, ll ccap) : u(uu), v(vv), cap(ccap), flow(0) {}
  };
  int size;
  vector<Edge> edges;
  vector<vector<int>> adjacency;
  vector<int> d, pt;
  Dinic(int NN) : size(NN), edges(0), adjacency(size), d(size), pt(size) {}
  void add_edge(int u, int v, ll cap_f, ll cap_r = 0) {
    if (u != v) {
      edges.emplace_back(Edge(u, v, cap_f));
      adjacency[u].emplace_back(edges.size() - 1);
      edges.emplace_back(Edge(v, u, cap_r));
      adjacency[v].emplace_back(edges.size() - 1);
    }
  }
  bool __bfs(int source, int sink) {
    queue<int> q({source});
    fill(d.begin(), d.end(), size + 1);
    d[source] = 0;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      if (u == sink) break;
      for (int k : adjacency[u]) {
        Edge &e = edges[k];
        if (e.flow < e.cap && d[e.v] > d[e.u] + 1) {
          d[e.v] = d[e.u] + 1;
          q.emplace(e.v);
        }
      }
    }
    return d[sink] != size + 1;
  }
  ll __dfs(int u, int sink, ll flow = -1) {
    if (u == sink || flow == 0) return flow;
    for (int &i = pt[u]; i < (int)adjacency[u].size(); ++i) {
      Edge &e = edges[adjacency[u][i]];
      Edge &oe = edges[adjacency[u][i] ^ 1];
      if (d[e.v] == d[e.u] + 1) {
        ll amt = e.cap - e.flow;
        if (flow != -1 && amt > flow) amt = flow;
        if (ll pushed = __dfs(e.v, sink, amt)) {
          e.flow += pushed;
          oe.flow -= pushed;
          return pushed;
        }
      }
    }
    return 0;
  }
  ll max_flow(int source, int sink) {
    ll total = 0;
    while (__bfs(source, sink)) {
      fill(pt.begin(), pt.end(), 0);
      while (ll flow = __dfs(source, sink)) total += flow;
    }
    return total;
  }
};
void solve() {
  const int K = 5;
  int n, b, q;
  cin >> n >> b >> q;
  vector<pair<int, int>> queries(q);
  for (auto &[x, y] : queries) cin >> x >> y;
  queries.emplace_back(0, 0);
  queries.emplace_back(b, n);
  sort(queries.begin(), queries.end());
  q = queries.size() - 1;
  vector<pair<int, int>> q2;
  int totalnumsseen = 0;
  for (int i = 1; i < q; i++) {
    int gap = queries[i].first - queries[i - 1].first;
    int extranums = queries[i].second - queries[i - 1].second;
    if (extranums > gap or extranums < 0) {
      cout << "unfair"
           << "\n";
      return;
    }
    q2.emplace_back(queries[i].first, extranums);
    totalnumsseen += extranums;
  }
  q = q2.size() - 1;
  int source = b + K + q + 1, sink = source + 1, nodes = sink + 2;
  Dinic dn(nodes);
  for (int i = 1; i <= b; i++) dn.add_edge(i, (b + q + i % K + 1), n);
  for (int i = 0; i < K; i++) dn.add_edge((b + q + i + 1), sink, n / K);
  int qq = 1;
  int prev = 1;
  for (auto &[limit, nums] : q2) {
    dn.add_edge(source, (b + qq), nums);
    for (int i = prev; i <= limit; i++) dn.add_edge((b + qq), i, 1);
    qq++;
    prev = limit + 1;
  }
  auto flow = dn.max_flow(source, sink);
  if (flow == n)
    cout << "fair"
         << "\n";
  else
    cout << "unfair"
         << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();
  return 0;
}
