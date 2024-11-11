#include <bits/stdc++.h>
using namespace std;
const int N = 410, K = 5e3 + 10;
struct Edge {
  int u, v;
  long long cap, flow;
  int id;
  Edge() {}
  Edge(int u, int v, long long cap, int id)
      : u(u), v(v), cap(cap), flow(0), id(id) {}
};
struct Dinic {
  int n, m, N;
  vector<Edge> E;
  vector<vector<int>> g;
  vector<int> d, pt, lo, side, flowAt;
  vector<bool> vis;
  Dinic(int n, int m)
      : n(n),
        m(m),
        N(n + m + 2),
        E(0),
        g(N),
        d(N),
        pt(N),
        lo(N),
        side(N),
        flowAt(N),
        vis(N) {}
  void AddEdge(int u, int v, long long cap, int id) {
    if (u != v) {
      E.emplace_back(Edge(u, v, cap, id));
      g[u].emplace_back(E.size() - 1);
      E.emplace_back(Edge(v, u, 0, -1));
      g[v].emplace_back(E.size() - 1);
    }
  }
  bool BFS(int S, int T) {
    queue<int> q({S});
    fill(d.begin(), d.end(), N + 1);
    d[S] = 0;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      if (u == T) break;
      for (int k : g[u]) {
        Edge &e = E[k];
        if (e.flow < e.cap && d[e.v] > d[e.u] + 1) {
          d[e.v] = d[e.u] + 1;
          q.emplace(e.v);
        }
      }
    }
    return d[T] != N + 1;
  }
  long long DFS(int u, int T, long long flow = -1) {
    if (u == T || flow == 0) return flow;
    for (int &i = pt[u]; i < g[u].size(); ++i) {
      Edge &e = E[g[u][i]];
      Edge &oe = E[g[u][i] ^ 1];
      if (d[e.v] == d[e.u] + 1) {
        long long amt = e.cap - e.flow;
        if (flow != -1 && amt > flow) amt = flow;
        if (long long pushed = DFS(e.v, T, amt)) {
          e.flow += pushed;
          oe.flow -= pushed;
          return pushed;
        }
      }
    }
    return 0;
  }
  bool DFS2(int S, int u) {
    if (vis[u]) {
      return false;
    } else if (side[u] == side[S] and flowAt[u] > lo[u]) {
      --flowAt[u];
      return true;
    }
    vis[u] = true;
    for (auto k : g[u]) {
      auto &e = E[k];
      auto &oe = E[k ^ 1];
      if (e.flow < e.cap) {
        if (DFS2(S, e.v)) {
          ++e.flow;
          --oe.flow;
          return true;
        }
      }
    }
    return false;
  }
  bool DFS3(int S, int u) {
    if (vis[u]) {
      return false;
    } else if (side[u] == side[S] and flowAt[u] > lo[u]) {
      --flowAt[u];
      return true;
    }
    vis[u] = true;
    for (auto k : g[u]) {
      auto &e = E[k];
      auto &oe = E[k ^ 1];
      if (oe.flow < oe.cap) {
        if (DFS3(S, e.v)) {
          ++oe.flow;
          --e.flow;
          return true;
        }
      }
    }
    return false;
  }
  long long MaxFlow(int S, int T) {
    long long total = 0;
    while (BFS(S, T)) {
      fill(pt.begin(), pt.end(), 0);
      while (long long flow = DFS(S, T)) total += flow;
    }
    return total;
  }
  void enforceLowerBounds(int S, int T) {
    for (auto &k : g[S]) {
      auto &e = E[k];
      flowAt[e.v] = e.flow;
      side[e.v] = 1;
    }
    for (auto &k : g[T]) {
      auto &e = E[k ^ 1];
      flowAt[e.u] = e.flow;
      side[e.u] = 2;
    }
    for (int i = 1; i <= n; ++i) {
      if (flowAt[i] < lo[i]) {
        fill(vis.begin(), vis.end(), 0);
        vis[S] = vis[T] = 1;
        assert(DFS2(i, i));
        ++flowAt[i];
      }
    }
    for (int j = n + 1; j <= n + m; ++j) {
      if (flowAt[j] < lo[j]) {
        fill(vis.begin(), vis.end(), 0);
        vis[S] = vis[T] = 1;
        assert(DFS3(j, j));
        ++flowAt[j];
      }
    }
  }
};
int deg[N], lo[N], hi[N];
int u[K], v[K], type[K];
bool used[K];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, k, t;
  cin >> n >> m >> k >> t;
  for (int i = 1; i <= k; ++i) {
    cin >> u[i] >> v[i];
    v[i] += n;
    ++deg[u[i]];
    ++deg[v[i]];
  }
  int ans = 0;
  for (int i = 1; i <= n + m; ++i) {
    if (deg[i] % t) {
      ++ans;
    }
  }
  for (int c = 1; c <= t; ++c) {
    Dinic dinic(n, m);
    int source = 0, sink = n + m + 1;
    memset(deg, 0, sizeof(deg));
    for (int i = 1; i <= k; ++i) {
      if (!used[i]) {
        dinic.AddEdge(u[i], v[i], 1, i);
        ++deg[u[i]];
        ++deg[v[i]];
      }
    }
    int cur_t = (t - c + 1);
    for (int i = 0; i < dinic.N; ++i) {
      lo[i] = deg[i] / cur_t;
      hi[i] = (deg[i] + cur_t - 1) / cur_t;
      dinic.lo[i] = lo[i];
    }
    for (int i = 1; i <= n; ++i) {
      dinic.AddEdge(source, i, hi[i], -1);
    }
    for (int j = n + 1; j <= n + m; ++j) {
      dinic.AddEdge(j, sink, hi[j], -1);
    }
    dinic.MaxFlow(source, sink);
    dinic.enforceLowerBounds(source, sink);
    for (auto &e : dinic.E) {
      if (e.id != -1 and e.flow) {
        type[e.id] = c;
        used[e.id] = true;
      }
    }
  }
  cout << ans << '\n';
  for (int i = 1; i <= k; ++i) {
    cout << type[i] << ' ';
  }
  cout << endl;
}
