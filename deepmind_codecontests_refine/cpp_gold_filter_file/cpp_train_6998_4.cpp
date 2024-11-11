#include <bits/stdc++.h>
const int MAXN = 5e5 + 5;
struct Node {
  int x, d, id;
  Node(int x = 0, int d = 0, int id = 0) : x(x), d(d), id(id) {}
  bool operator<(const Node &t) const { return x == t.x ? d < t.d : x < t.x; }
} a[MAXN];
int n, m, k, N;
int pc[(1 << 15) + 3];
int pos[MAXN];
int g[MAXN];
int f[2][(1 << 15) + 3];
int now = 0;
inline int find0(int x) {
  for (int i = 0; i <= 9; ++i)
    if (!((x >> i) & 1)) return i;
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= (1 << 15); ++i) pc[i] = pc[i >> 1] + (i & 1);
  for (int i = 1; i <= n; ++i) {
    int l, r;
    scanf("%d%d", &l, &r);
    a[++N] = Node(l, 1, i);
    a[++N] = Node(r + 1, -1, i);
  }
  std::sort(a + 1, a + N + 1);
  for (int i = 0; i <= N - 1; ++i) {
    int dis = a[i + 1].x - a[i].x;
    if (i == 0) dis = 0;
    if (a[i + 1].d == 1) {
      int t = find0(g[i]);
      pos[a[i + 1].id] = t;
      g[i + 1] = g[i] | (1 << t);
      for (int S = 0; S <= (1 << k) - 1; ++S) {
        if ((S | g[i]) != g[i]) continue;
        f[now ^ 1][S] =
            std::max(f[now ^ 1][S], f[now][S] + (pc[S] & 1 ? dis : 0));
        f[now ^ 1][S | (1 << t)] = std::max(f[now ^ 1][S | (1 << t)],
                                            f[now][S] + (pc[S] & 1 ? dis : 0));
      }
    } else {
      int t = pos[a[i + 1].id];
      g[i + 1] = g[i] ^ (1 << t);
      for (int S = 0; S <= (1 << k) - 1; ++S) {
        if ((S | g[i]) != g[i]) continue;
        if (!((S >> t) & 1))
          f[now ^ 1][S] =
              std::max(f[now ^ 1][S], f[now][S] + (pc[S] & 1 ? dis : 0));
        else
          f[now ^ 1][S ^ (1 << t)] = std::max(
              f[now ^ 1][S ^ (1 << t)], f[now][S] + (pc[S] & 1 ? dis : 0));
      }
    }
    now ^= 1;
  }
  int ans = 0;
  for (int S = 0; S <= (1 << k) - 1; ++S) {
    if ((S | g[N]) != g[N]) continue;
    ans = std::max(ans, f[now][S]);
  }
  printf("%d\n", ans);
  return 0;
}
