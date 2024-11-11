#include <bits/stdc++.h>
using namespace std;
const int N = 1009, M = (1 << 12) + 9, mod = 1e9 + 7;
int son[N], ans, inv;
inline int read() {
  int res = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    res = (res << 1) + (res << 3) + ch - '0';
    ch = getchar();
  }
  return res * f;
}
inline int pls(int x, int y) { return x + y >= mod ? x + y - mod : x + y; }
struct Graph {
  int ver[N << 1], nxt[N << 1], h[N], tot;
  inline void add(int x, int y) { ver[++tot] = y, nxt[tot] = h[x], h[x] = tot; }
  void dfs(int u, int fa) {
    son[u] = 0;
    for (int i = h[u]; i; i = nxt[i]) {
      int v = ver[i];
      if (v == fa) continue;
      dfs(v, u);
      son[u] |= (1 << v - 1);
    }
  }
} S, T;
int n, m, f[N][M];
void dp(int u, int fa) {
  for (int i = 1; i < (1 << m); i++) f[u][i] = 0;
  f[u][0] = 1;
  for (int i = S.h[u]; i; i = S.nxt[i]) {
    int v = S.ver[i];
    if (v == fa) continue;
    dp(v, u);
    for (int S = (1 << m) - 1; S >= 0; S--)
      if (f[u][S])
        for (int i = 1; i <= m; i++)
          if (!(S & (1 << i - 1))) {
            int T = S | (1 << i - 1);
            f[u][T] = pls(f[u][T], 1ll * f[u][S] * f[v][son[i]] % mod);
          }
  }
}
inline int poww(int x, int k) {
  int res = 1;
  while (k) {
    if (k & 1) res = 1ll * res * x % mod;
    x = 1ll * x * x % mod;
    k >>= 1;
  }
  return res;
}
int main() {
  n = read();
  for (int i = 1; i < n; i++) {
    int x, y;
    x = read(), y = read();
    S.add(x, y), S.add(y, x);
  }
  m = read();
  for (int i = 1; i < m; i++) {
    int x, y;
    x = read(), y = read();
    T.add(x, y), T.add(y, x);
  }
  for (int i = 1; i <= m; i++) {
    T.dfs(i, 0);
    dp(1, 0);
    for (int j = 1; j <= n; j++) ans = pls(ans, f[j][son[i]]);
  }
  S = T;
  for (int i = 1; i <= m; i++) {
    T.dfs(i, 0);
    dp(1, 0);
    inv = pls(inv, f[1][son[i]]);
  }
  printf("%d\n", 1ll * ans * poww(inv, mod - 2) % mod);
  return 0;
}
