#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e3 + 5;
int n, m, fst[MAXN], to[MAXN << 1], nxt[MAXN << 1], ne;
inline void insert(int u, int v) {
  nxt[++ne] = fst[u], fst[u] = ne, to[ne] = v;
}
template <class T>
inline void RD(T &a) {
  register int ch = getchar();
  bool ng = 0;
  for (; ch < '0' || ch > '9'; ch = getchar())
    if (ch == '-') ng = 1;
  for (a = 0; ch >= '0' && ch <= '9'; ch = getchar())
    a = (a << 1) + (a << 3) + (ch ^ '0');
  if (ng) a = ~a + 1;
}
int d[MAXN][MAXN], q[MAXN];
inline void bfs(int s) {
  int st = 1, fn = 0;
  for (int i(1), b_(n); i <= b_; ++i) d[s][i] = -1e6;
  d[s][s] = 0, q[st] = s;
  while (st != fn) {
    int u = q[++fn];
    for (int i = fst[u]; i; i = nxt[i]) {
      int v = to[i];
      if (d[s][v] != -1e6) continue;
      d[s][v] = d[s][u] + 1, q[++st] = v;
    }
  }
}
int in[MAXN][MAXN], out[MAXN][MAXN];
int main() {
  RD(n), RD(m);
  for (int i(1), b_(m); i <= b_; ++i) {
    int u, v;
    RD(u), RD(v);
    insert(u, v);
  }
  for (int i(1), b_(n); i <= b_; ++i)
    for (int j(1), b_(n); j <= b_; ++j) {
      in[i][j] = out[i][j] = j;
    }
  for (int i(1), b_(n); i <= b_; ++i) {
    bfs(i);
  }
  for (int i(1), b_(n); i <= b_; ++i) {
    partial_sort(in[i] + 1, in[i] + 3, in[i] + n + 1,
                 [i](int u, int v) { return d[u][i] > d[v][i]; });
    partial_sort(out[i] + 1, out[i] + 3, out[i] + n + 1,
                 [i](int u, int v) { return d[i][u] > d[i][v]; });
  }
  int ra, rb, rc, rd, mx = -1e9;
  for (int i(1), b_(n); i <= b_; ++i)
    for (int j(1), b_(n); j <= b_; ++j)
      if (i != j)
        for (int k(1), b_(3); k <= b_; ++k) {
          int x = in[i][k];
          if (x != i && x != j)
            for (int l(1), b_(3); l <= b_; ++l) {
              int y = out[j][l];
              if (y != x && y != i && y != j)
                if (mx < d[x][i] + d[i][j] + d[j][y]) {
                  mx = d[x][i] + d[i][j] + d[j][y];
                  ra = x, rb = i, rc = j, rd = y;
                }
            }
        }
  printf("%d %d %d %d", ra, rb, rc, rd);
  return 0;
}
