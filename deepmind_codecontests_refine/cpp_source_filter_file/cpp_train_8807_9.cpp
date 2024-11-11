#include <bits/stdc++.h>
template <int xn, int xe>
struct flow {
  int head[xn], next[xe], to[xe], fl[xe], N, E, q[xn + 1], dep[xn], cur[xn];
  inline void add(int u, int v, int f) {
    next[E] = head[u], to[E] = v, fl[E] = f, head[u] = E++;
    next[E] = head[v], to[E] = u, fl[E] = 0, head[v] = E++;
  }
  void clear(int n) {
    N = n, E = 0;
    for (int i = 0; i < N; i++) head[i] = -1;
  }
  bool BFS() {
    for (int i = 0; i < N; i++) {
      dep[i] = 0;
      cur[i] = head[i];
    }
    int H = 0, T = 1, u;
    q[1] = 0;
    dep[0] = 1;
    while (H < T)
      for (int e = head[u = q[++H]]; ~e; e = next[e])
        if (fl[e] && !dep[to[e]]) {
          dep[q[++T] = to[e]] = dep[u] + 1;
          if (to[e] == N - 1) return true;
        }
    return false;
  }
  int DFS(int p, int f) {
    if (p == N - 1) return f;
    int u = 0, y;
    for (int &e = cur[p]; ~e; e = next[e])
      if (fl[e] && dep[to[e]] == dep[p] + 1)
        if (y = DFS(to[e], std::min(fl[e], f))) {
          u += y;
          f -= y;
          fl[e] -= y;
          fl[e ^ 1] += y;
          if (!f) return u;
        }
    if (!u) dep[p] = 0;
    return u;
  }
  int operator()() {
    int r = 0;
    while (BFS()) r += DFS(0, 1000000000);
    return r;
  }
};
flow<100000, 100000> G;
int N, M, u[5001], v[5001];
bool check(int x) {
  G.clear(1 + N + M + 1);
  for (int i = 1; i <= N; i++) G.add(0, i, x);
  for (int i = 1; i <= M; i++) {
    G.add(u[i], N + i, 1);
    G.add(v[i], N + i, 1);
    G.add(N + i, G.N - 1, 1);
  }
  return G() == M;
}
int main() {
  scanf("%d%d", &N, &M);
  for (int i = 1; i <= M; i++) scanf("%d%d", u + i, v + i);
  int l = 1, r = M;
  while (l < r) {
    int m = l + r >> 1;
    if (check(m))
      r = m;
    else
      l = m + 1;
  }
  check(l);
  printf("%d\n", l);
  for (int i = 1; i <= M; i++) {
    int LittleFairyMY = 0, BigFairyNBC = 0;
    for (int e = G.head[N + i]; ~e; e = G.next[e])
      if (G.to[e] <= N) (G.fl[e] ? LittleFairyMY : BigFairyNBC) = G.to[e];
    printf("%d %d\n", LittleFairyMY, BigFairyNBC);
  }
  return 0;
}
