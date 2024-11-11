#include <bits/stdc++.h>
using namespace std;
int f[510][1010], g[1010];
int n, m;
struct node {
  int l, r, w, v, s;
} p[510];
inline int rd() {
  int ret = 0, f = 1;
  char gc = getchar();
  while (gc < '0' || gc > '9') {
    if (gc == '-') f = -f;
    gc = getchar();
  }
  while (gc >= '0' && gc <= '9') ret = ret * 10 + (gc ^ '0'), gc = getchar();
  return ret * f;
}
bool cmp(const node &a, const node &b) {
  return (a.r == b.r) ? (a.l > b.r) : (a.r < b.r);
}
int main() {
  n = rd(), m = rd();
  int i, j, k, l;
  for (i = 1; i <= n; i++)
    p[i].l = rd(), p[i].r = rd(), p[i].w = rd(), p[i].s = min(m, rd()),
    p[i].v = rd();
  sort(p + 1, p + n + 1, cmp);
  p[n + 1].l = 0, p[n + 1].r = n << 1, p[n + 1].s = m;
  for (i = 1; i <= n + 1; i++)
    for (k = p[i].w; k <= m; k++) {
      g[l = p[i].l] = 0;
      for (j = 1; j < i; j++)
        if (p[j].l >= p[i].l) {
          while (l < p[j].r) l++, g[l] = g[l - 1];
          g[l] = max(g[l], g[p[j].l] + f[j][min(k - p[i].w, p[i].s)]);
        }
      f[i][k] = g[l] + p[i].v;
    }
  printf("%d", f[n + 1][m]);
  return 0;
}
