#include <bits/stdc++.h>
using namespace std;
template <typename T>
struct Dinic {
  static const T eps = 1e-9;
  int n, src, sink;
  struct Edge {
    int from, to;
    T f, cap;
  };
  vector<vector<int>> G;
  vector<int> dist, Q, work;
  vector<Edge> edges;
  Dinic(int _n) : n(_n), G(n), dist(n), Q(n), work(n) {}
  int addEdge(int s, int t, T forwardCap, T backwardCap = 0) {
    int id = edges.size();
    G[s].push_back(id);
    edges.push_back({s, t, 0, forwardCap});
    G[t].push_back(id + 1);
    edges.push_back({t, s, 0, backwardCap});
    return id;
  }
  bool dinicBfs() {
    fill(dist.begin(), dist.begin() + n, -1);
    dist[src] = 0;
    int qt = 0;
    Q[qt++] = src;
    for (int qh = 0; qh < qt; ++qh) {
      int u = Q[qh];
      for (int eid : G[u]) {
        Edge& e = edges[eid];
        int v = e.to;
        if (dist[v] < 0 && e.cap - e.f > eps) {
          dist[v] = dist[u] + 1;
          Q[qt++] = v;
        }
      }
    }
    return dist[sink] >= 0;
  }
  T dinicDfs(int u, T f) {
    if (u == sink) return f;
    for (int& i = work[u]; i < G[u].size(); ++i) {
      int eid = G[u][i];
      Edge& e = edges[eid];
      if (e.cap <= e.f) continue;
      int v = e.to;
      if (dist[v] == dist[u] + 1) {
        T df = dinicDfs(v, min(f, e.cap - e.f));
        if (df > 0) {
          e.f += df;
          edges[eid ^ 1].f -= df;
          return df;
        }
      }
    }
    return 0;
  }
  T maxFlow() {
    assert(src != -1 && sink != -1);
    T result = 0;
    while (dinicBfs()) {
      fill(work.begin(), work.begin() + n, 0);
      for (;;) {
        T delta = dinicDfs(src, numeric_limits<T>::max());
        if (delta <= eps) break;
        result += delta;
      }
    }
    return result;
  }
  vector<bool> minCut() {
    maxFlow();
    vector<bool> ret(n);
    for (int i = 0; i < n; ++i) ret[i] = dist[i] >= 0;
    return ret;
  }
  int na, nb;
  vector<int> matcha, matchb;
  Dinic(int _na, int _nb) : Dinic(_na + _nb + 2) {
    na = _na;
    nb = _nb;
    src = n - 2;
    sink = n - 1;
    for (int i = 0; i < na; ++i) addEdge(src, i, 1);
    for (int i = 0; i < nb; ++i) addEdge(na + i, sink, 1);
  }
  int addMatchEdge(int s, int t) { return addEdge(s, t + na, 1); }
  int maxMatching() {
    int ret = maxFlow();
    matcha.resize(na);
    matchb.resize(nb);
    for (int i = 0; i < na; ++i) {
      for (int eid : G[i]) {
        auto& e = edges[eid];
        if (e.to != src && e.f == 1) {
          matcha[i] = e.to - na;
          matchb[e.to - na] = i;
        }
      }
    }
    return ret;
  }
};
const int DR[4] = {1, 0, -1, 0};
const int DC[4] = {0, 1, 0, -1};
const string CH = "DRUL";
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<vector<int>> M(n, vector<int>(m));
    vector<vector<char>> ans(n, vector<char>(m));
    vector<vector<int>> V(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j) scanf("%d", &M[i][j]);
    Dinic<int> g(n * m * 2 + 2);
    g.src = g.n - 2;
    g.sink = g.n - 1;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j) {
        for (int d = 0; d < 4; ++d) {
          int ii = i + DR[d], jj = j + DC[d];
          if (ii < 0 || jj < 0 || ii >= n || jj >= m) continue;
          if (M[ii][jj] < M[i][j]) {
            ans[i][j] = CH[d];
            V[i][j] = M[i][j] - M[ii][jj];
          }
          if (M[i][j] == M[ii][jj]) {
            g.addEdge(2 * (i * m + j) + 1, 2 * (ii * m + jj), 1);
          }
        }
      }
    int need = 0;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j) {
        if (ans[i][j]) {
          g.addEdge(2 * (i * m + j), 2 * (i * m + j) + 1, 1);
        } else {
          g.addEdge(g.src, 2 * (i * m + j) + 1, 1);
          g.addEdge(2 * (i * m + j), g.sink, 1);
          ++need;
        }
      }
    int flow = g.maxFlow();
    assert(flow <= need);
    if (flow < need) {
      printf("NO\n");
    } else {
      vector<int> nex(n * m, -1);
      for (auto& e : g.edges) {
        if (e.f == e.cap && e.cap == 1 && e.from != g.src && e.to != g.sink &&
            (e.from & 1)) {
          int a = e.from / 2;
          int b = e.to / 2;
          assert(a != b);
          nex[a] = b;
        }
      }
      42;
      for (int i = 0; i < n * m; ++i) {
        if (nex[i] == -1) continue;
        vector<int> cycle;
        for (int j = i; nex[j] != -1;) {
          int t = nex[j];
          nex[j] = -1;
          cycle.push_back(j);
          j = t;
        }
        assert(cycle.size() % 2 == 0);
        for (int j = 0; j < cycle.size(); j += 2) {
          int a = cycle[j];
          int b = cycle[j + 1];
          int ai = a / m, aj = a % m;
          int bi = b / m, bj = a % m;
          for (int d = 0; d < 4; ++d) {
            if (ai + DR[d] == bi && aj + DC[d] == bj) {
              ans[ai][aj] = CH[d];
              ans[bi][bj] = CH[(d + 2) % 4];
              V[ai][aj] = M[ai][aj] - 1;
              V[bi][bj] = 1;
              break;
            }
          }
        }
      }
      printf("YES\n");
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) printf("%d ", V[i][j]);
        printf("\n");
      }
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) printf("%c ", ans[i][j]);
        printf("\n");
      }
    }
  }
}
