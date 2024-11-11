#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
const int N = 2e5 + 10, p = 1e9 + 7;
int las[N], to[N << 1], nxt[N << 1], cnt;
inline void add(int u, int v) {
  cnt++;
  to[cnt] = v;
  nxt[cnt] = las[u];
  las[u] = cnt;
}
inline void add2() {
  int a, b;
  scanf("%d%d", &a, &b);
  add(a, b);
  add(b, a);
}
int n, ans, rt, fa[N], val[N], siz[N], tot[N][2];
void dfs(int now, int la, int x) {
  int i;
  fa[now] = la;
  siz[now] = tot[now][x] = 1;
  for (i = las[now]; i; i = nxt[i])
    if (to[i] != la)
      dfs(to[i], now, x ^ 1), siz[now] += siz[to[i]],
          tot[now][x] += tot[to[i]][x], tot[now][x ^ 1] += tot[to[i]][x ^ 1];
}
void dfs(int now, int x) {
  int i;
  for (i = las[now]; i; i = nxt[i])
    if (to[i] != fa[now])
      dfs(to[i], x ^ 1),
          ans = (ans + (long long)(tot[to[i]][x] - tot[to[i]][x ^ 1] + p) % p *
                           (n - siz[to[i]]) % p * val[now] % p) %
                p;
  ans = (ans + (long long)((tot[rt][x] - tot[now][x]) -
                           (tot[rt][x ^ 1] - tot[now][x ^ 1]) + p) %
                   p * siz[now] % p * val[now] % p) %
        p;
  ans = (ans + (long long)(n - 1) * val[now] % p) % p;
}
int main() {
  int i;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) scanf("%d", &val[i]), val[i] = (val[i] + p) % p;
  for (i = 1; i < n; i++) add2();
  dfs(rt = 1, 0, 0);
  dfs(rt, 0);
  printf("%d\n", ans);
  return 0;
}
