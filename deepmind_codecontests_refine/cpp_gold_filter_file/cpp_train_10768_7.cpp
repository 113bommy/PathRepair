#include <bits/stdc++.h>
using namespace std;
template <class T>
struct Dinic {
  static const int MAXV = 20000;
  static constexpr T INF = 1e9;
  struct Edge {
    int v;
    T f;
    int re;
    Edge(int _v, T _f, int _re) : v(_v), f(_f), re(_re) {}
  };
  int n, s, t, level[MAXV];
  vector<Edge> E[MAXV];
  int now[MAXV];
  Dinic(int _n, int _s, int _t) : n(_n), s(_s), t(_t) {}
  void add_edge(int u, int v, T f) {
    E[u].emplace_back(v, f, E[v].size());
    E[v].emplace_back(u, 0, E[u].size() - 1);
  }
  bool BFS() {
    memset(level, -1, sizeof(level));
    queue<int> que;
    que.emplace(s);
    level[s] = 0;
    while (not que.empty()) {
      int u = que.front();
      que.pop();
      for (auto it : E[u]) {
        if (it.f > 0 and level[it.v] == -1) {
          level[it.v] = level[u] + 1;
          que.emplace(it.v);
        }
      }
    }
    return level[t] != -1;
  }
  T DFS(int u, T nf) {
    if (u == t) return nf;
    T res = 0;
    while (now[u] < E[u].size()) {
      Edge &it = E[u][now[u]];
      if (it.f > 0 and level[it.v] == level[u] + 1) {
        T tf = DFS(it.v, min(nf, it.f));
        res += tf;
        nf -= tf;
        it.f -= tf;
        E[it.v][it.re].f += tf;
        if (nf == 0) return res;
      } else
        ++now[u];
    }
    if (not res) level[u] = -1;
    return res;
  }
  T flow(T res = 0) {
    while (BFS()) {
      T temp;
      memset(now, 0, sizeof(now));
      while (temp = DFS(s, INF)) {
        res += temp;
        res = min(res, INF);
      }
    }
    return res;
  }
};
const int MAXN = 50;
const int MAXM = 100;
int N, M;
int A[MAXN], B[MAXN], C[MAXN];
int L[MAXN], R[MAXN];
int base[MAXN + 1];
int U[MAXM], V[MAXM], D[MAXM];
const int MAXF = 201000;
signed main() {
  ios::sync_with_stdio(false);
  cin >> N >> M;
  for (int i = 0; i < N; ++i) {
    cin >> A[i] >> B[i] >> C[i];
  }
  for (int i = 0; i < N; ++i) {
    cin >> L[i] >> R[i];
    base[i + 1] = base[i] + R[i] - L[i] + 2;
  }
  int SRC = base[N], DST = SRC + 1;
  Dinic<int> din(base[N] + 2, SRC, DST);
  for (int i = 0; i < N; ++i) {
    din.add_edge(SRC, base[i], din.INF);
    for (int j = L[i]; j <= R[i]; ++j) {
      static auto f = [&](int i, int x) {
        return A[i] * x * x + B[i] * x + C[i];
      };
      din.add_edge(base[i] + j - L[i], base[i] + j - L[i] + 1, MAXF - f(i, j));
    }
    din.add_edge(base[i] + R[i] - L[i] + 1, DST, din.INF);
  }
  for (int i = 0; i < M; ++i) {
    int u, v, d;
    cin >> u >> v >> d;
    --u, --v;
    for (int j = L[u]; j <= R[u] + 1; ++j) {
      if (L[v] <= j - d - 1 and j - d - 1 <= R[v]) {
        din.add_edge(base[u] + j - L[u], base[v] + j - d - L[v], din.INF);
      }
    }
  }
  cout << N * MAXF - din.flow() << endl;
  return 0;
}
