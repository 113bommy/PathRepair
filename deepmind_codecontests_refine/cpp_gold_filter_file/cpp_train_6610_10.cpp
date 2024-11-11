#include <bits/stdc++.h>
const int N = 157, inf = 1e9 + 500;
int n, m, del, t, dis[N];
int ans = inf;
std::queue<int> q;
struct node {
  int u, v, w;
  bool operator<(const node &a) const { return w < a.w; }
} e[N];
inline int read() {
  int x = 0;
  char c = getchar();
  while (!isdigit(c)) c = getchar();
  while (isdigit(c)) x = (x << 3) + (x << 1) + c - 48, c = getchar();
  return x;
}
struct matrix {
  std::bitset<N> v[N];
  matrix() {
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j) v[i][j] = 0;
  }
  void I() {
    for (int i = 1; i <= n; ++i) v[i][i] = 1;
  }
  friend matrix operator*(matrix a, matrix b) {
    matrix ret;
    for (int i = 1; i <= n; ++i) {
      for (int k = 1; k <= n; ++k) {
        if (a.v[i][k]) ret.v[i] |= b.v[k];
      }
    }
    return ret;
  }
} a, g;
matrix qp(matrix base, int p) {
  matrix ret;
  ret.I();
  while (p) {
    if (p & 1) ret = ret * base;
    base = base * base;
    p >>= 1;
  }
  return ret;
}
void bfs() {
  while (!q.empty()) q.pop();
  for (int i = 1; i <= n; ++i) dis[i] = inf;
  for (int i = 1; i <= n; ++i)
    if (a.v[1][i]) q.push(i), dis[i] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v = 1; v <= n; ++v) {
      if (g.v[u][v] && dis[v] == inf) {
        dis[v] = dis[u] + 1;
        q.push(v);
      }
    }
  }
}
int main() {
  n = read(), m = read();
  for (int i = 1; i <= m; ++i)
    e[i].u = read(), e[i].v = read(), e[i].w = read();
  std::sort(e + 1, e + 1 + m);
  a.v[1][1] = 1;
  dis[n] = inf;
  for (int i = 1; i <= m; ++i) {
    if (ans < e[i].w) break;
    del = e[i].w - t;
    t = e[i].w;
    a = a * qp(g, del);
    g.v[e[i].u][e[i].v] = 1;
    if (i == m || e[i + 1].w != e[i].w) bfs();
    ans = std::min(ans, dis[n] + t);
  }
  if (ans == inf)
    puts("Impossible");
  else
    printf("%d\n", ans);
}
