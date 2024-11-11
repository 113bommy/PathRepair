#include <bits/stdc++.h>
using namespace std;
priority_queue<int> Q;
struct Edge {
  int t, w, nx;
} e[100010 << 1];
struct Node {
  int w, f;
  Node() {}
  Node(int w, int f) : w(w), f(f){};
} a[100010];
int i, j, k, n, m, h[100010], x, y, z, Num, f[100010], g[100010], b[100010], M,
    Top, Sum;
inline void Add(int x, int y, int z) {
  e[++Num].t = y;
  e[Num].w = z;
  e[Num].nx = h[x];
  h[x] = Num;
}
inline int Max(int x, int y) { return x < y ? y : x; }
inline bool Cmp(Node a, Node b) { return a.w > b.w; }
inline void Getf(int x, int y) {
  Top = Sum = 0;
  for (int i = h[x]; i; i = e[i].nx)
    if (e[i].t != y) {
      Sum += g[e[i].t] + e[i].w;
      a[++Top] = Node(g[e[i].t] + e[i].w, e[i].t);
    }
  if (Top <= k) {
    for (int i = 1; i <= Top; i++)
      f[x] = Max(f[x], Sum - g[a[i].f] + f[a[i].f]);
    return;
  }
  sort(a + 1, a + Top + 1, Cmp);
  Sum = 0;
  for (int i = 1; i < k; i++) b[a[i].f] = x, Sum += a[i].w;
  for (int i = 1; i < k; i++)
    f[x] = Max(f[x], a[k].w + Sum - g[a[i].f] + f[a[i].f]);
  for (int i = h[x]; i; i = e[i].nx)
    if (e[i].t != y && b[e[i].t] != x)
      f[x] = Max(f[x], Sum + f[e[i].t] + e[i].w);
}
inline void Getg(int x, int y) {
  Top = 0;
  for (int i = h[x]; i; i = e[i].nx)
    if (e[i].t != y) a[++Top] = Node(g[e[i].t] + e[i].w, e[i].t);
  sort(a + 1, a + Top + 1, Cmp);
  for (int i = 1; i < k && i <= Top; i++) g[x] += a[i].w;
}
inline void Dfs(int x, int y) {
  for (int i = h[x]; i; i = e[i].nx)
    if (e[i].t != y) Dfs(e[i].t, x);
  Getf(x, y);
  Getg(x, y);
}
int main() {
  scanf("%d%d", &n, &k);
  for (i = 1; i < n; i++)
    scanf("%d%d%d", &x, &y, &z), Add(++x, ++y, z), Add(y, x, z);
  Dfs(1, 0);
  printf("%d\n", f[1]);
  return 0;
}
