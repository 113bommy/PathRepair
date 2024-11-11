#include <bits/stdc++.h>
const int N = 2e5 + 1;
long long f[N][5], g[N][5], r;
int i, j, x, y, n, c, t, z, fa[N], en[N * 2], nxt[N * 2], siz[N][5];
void dfs(int u, int p) {
  long long t[c];
  int i = fa[u], v, s[c];
  memset(t, 0, 8 * c), memset(s, 0, 4 * c);
  for (*siz[u] = 1; i; i = nxt[i])
    if ((v = en[i]) ^ p) {
      for (dfs(v, u), x = 0; x < c;
           f[u][x] += f[v][x] + g[v][x], t[x] += g[v][x], ++x)
        for (y = 0; y < c; ++y) {
          z = (x - c) % c + (y - c) % c + 2;
          f[u][(x + y + 2) % c] +=
              t[x] * siz[v][y] + g[v][y] * s[x] +
              1ll * (z < 0 ? z / c : (z + c - 1) / c) * siz[v][y] * s[x];
        }
      for (x = 0; x < c; ++x)
        s[x] += siz[v][x], siz[u][(x + 1) % c] += siz[v][x];
      for (x = 0; x < c; ++x) g[u][(x + 1) % c] += g[v][x] + !x * siz[v][x];
    }
}
int main() {
  for (scanf("%d%d", &n, &c); ++x < n;) {
    scanf("%d%d", &i, &j);
    en[++t] = j, nxt[t] = fa[i], fa[i] = t;
    en[++t] = i, nxt[t] = fa[j], fa[j] = t;
  }
  for (dfs(1, i = 0); i < c; ++i) r += f[1][i] + g[1][i];
  printf("%I64d", r);
}
