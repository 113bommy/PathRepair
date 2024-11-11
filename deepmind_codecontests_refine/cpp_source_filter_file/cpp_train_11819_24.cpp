#include <bits/stdc++.h>
using namespace std;
template <class T>
struct Dinic {
  static const int MAXV = 200000;
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
const int MAXN = int(1e4);
const int MAXQ = int(1e4);
int N, B, Q;
int upTo[MAXQ + 1], quantity[MAXQ + 1];
int ord[MAXQ];
int cnt[MAXN + 1][5];
signed main() {
  ios::sync_with_stdio(0);
  cin >> N >> B >> Q;
  for (int i = 0; i < Q; ++i) {
    cin >> upTo[i] >> quantity[i];
    ord[i] = i;
  }
  upTo[Q] = B;
  quantity[Q] = N;
  ord[Q] = Q;
  ++Q;
  sort(ord, ord + Q, [&](int i, int j) { return upTo[i] < upTo[j]; });
  for (int i = 1; i <= MAXN; ++i) {
    for (int j = 0; j < 5; ++j) {
      cnt[i][j] = cnt[i - 1][j] + (i % 5 == j);
    }
  }
  Dinic<int> din(Q + 5 + 2, Q + 5, Q + 5 + 1);
  for (int i = 0, last = 0, psum = 0; i < Q; ++i) {
    if (last == upTo[ord[i]] and quantity[ord[i]] != psum)
      cout << "unfair" << endl, exit(0);
    if (quantity[ord[i]] < psum) cout << "unfair" << endl, exit(0);
    din.add_edge(Q + 5, ord[i], quantity[ord[i]] - psum);
    for (int j = 0; j < 5; ++j) {
      din.add_edge(ord[i], Q + j, cnt[upTo[ord[i]]][j] - cnt[last][j]);
    }
    last = upTo[ord[i]];
    psum = quantity[ord[i]];
  }
  for (int i = 0; i < 5; ++i) {
    din.add_edge(Q + i, Q + 5 + 1, N / 5);
  }
  cout << (din.flow() == N ? "fair" : "unfair") << endl;
  return 0;
}
