#include <bits/stdc++.h>
using namespace std;
template <typename T>
T read1() {
  T t = 0;
  char k;
  bool v = 0;
  do (k = getchar()) == '-' && (v = 1);
  while ('0' > k || k > '9');
  while ('0' <= k && k <= '9')
    t = (t << 3) + (t << 1) + (k ^ '0'), k = getchar();
  return v ? -t : t;
}
int fa[1000005][20], s, u = 2, v = 3, h[1000005];
int lca(int x, int y) {
  if (h[x] < h[y]) swap(x, y);
  for (int i = 0, w = h[x] - h[y]; w; ++i)
    if (w >> i & 1) {
      w ^= 1 << i;
      x = fa[x][i];
    }
  if (x == y) return x;
  for (int i = 20; i--;)
    if (fa[x][i] ^ fa[y][i]) {
      x = fa[x][i];
      y = fa[y][i];
    }
  return fa[x][0];
}
int len(int x, int y) { return h[x] + h[y] - 2 * h[lca(x, y)]; }
int main() {
  s = read1<long long>();
  fa[2][0] = fa[3][0] = fa[4][0] = 1;
  h[2] = h[3] = h[4] = 1;
  int ans = 2, t = 4;
  for (int i = 0; i < s; ++i) {
    h[++t] = h[fa[t][0] = read1<long long>()] + 1;
    for (int j = 0; fa[t][j + 1] = fa[fa[t][j]][j]; ++j)
      ;
    h[++t] = h[t - 1];
    fa[t][0] = fa[t - 1][0];
    for (int j = 0; fa[t][j + 1] = fa[fa[t][j]][j]; ++j)
      ;
    int tx = len(t, u), ty = len(t, v);
    if (tx < ty) swap(tx, ty), swap(u, v);
    if (tx > ans) ans = tx, v = t;
    printf("%d\n", ans);
  }
  return 0;
}
