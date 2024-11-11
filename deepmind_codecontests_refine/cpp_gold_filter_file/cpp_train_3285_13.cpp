#include <bits/stdc++.h>
const int maxn = 309, mod = 998244353;
inline int Read() {
  int x(0), f(1);
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 3) + (x << 1) + c - '0';
    c = getchar();
  }
  return x * f;
}
int n, a, b, c, d;
int visit1[maxn], visit[maxn], nxt[maxn], a1[maxn], b1[maxn], ans[maxn],
    ru[maxn], fac[maxn];
int f[maxn], g[maxn], h[maxn];
int strl1[maxn][maxn], C[maxn][maxn], D[maxn][maxn];
void Dfs(int x) {
  if (!x) return;
  visit1[x] = true;
  visit[x] = true;
  if (nxt[x] != x) {
    if (visit1[nxt[x]])
      ++d;
    else {
      Dfs(nxt[x]);
      nxt[x] = nxt[nxt[x]];
    }
  }
  visit1[x] = 0;
}
int main() {
  n = Read();
  for (int i = 1; i <= n; ++i) a1[i] = Read();
  for (int i = 1; i <= n; ++i) b1[i] = Read();
  for (int i = 1; i <= n; ++i) nxt[i] = i;
  for (int i = 1; i <= n; ++i) {
    if (a1[i]) {
      if (a1[i] == b1[i]) {
        ++d;
        visit[a1[i]] = true;
      } else {
        nxt[a1[i]] = b1[i];
      }
    }
    if (b1[i]) ++ru[b1[i]];
  }
  for (int i = 1; i <= n; ++i)
    if (!visit[i]) Dfs(i);
  for (int i = 1; i <= n; ++i)
    if (!a1[i]) {
      if (nxt[b1[i]])
        ++b;
      else
        ++a;
    } else if (!ru[a1[i]] && !nxt[b1[i]])
      ++c;
  strl1[0][0] = strl1[1][1] = 1;
  for (int i = 2; i <= n; ++i)
    for (int j = 1; j <= i; ++j)
      strl1[i][j] =
          (strl1[i - 1][j - 1] + 1ll * (i - 1) * strl1[i - 1][j]) % mod;
  C[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= i; ++j)
      C[i][j] = 1ll * (C[i - 1][j - 1] + C[i - 1][j]) % mod;
    C[i][0] = 1;
  }
  D[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    D[i][0] = 1;
    for (int j = 1; j <= i; ++j)
      D[i][j] = 1ll * D[i][j - 1] * (i - j + 1) % mod;
  }
  fac[0] = fac[1] = 1;
  for (int i = 2; i <= n; ++i) fac[i] = 1ll * fac[i - 1] * i % mod;
  for (int i = 0; i <= b; ++i)
    for (int j = i; j <= b; ++j)
      f[i] = (f[i] + 1ll * strl1[j][i] * C[b][j] % mod *
                         (a + b - j - 1 >= 0 ? D[a + b - j - 1][b - j] : 1) %
                         mod) %
             mod;
  for (int i = 0; i <= c; ++i) {
    for (int j = i; j <= c; ++j)
      g[i] = (g[i] + 1ll * strl1[j][i] * C[c][j] % mod *
                         (a + c - j - 1 >= 0 ? D[a + c - j - 1][c - j] : 1) %
                         mod) %
             mod;
  }
  for (int i = 0; i <= a; ++i) h[i] = 1ll * strl1[a][i] * fac[a] % mod;
  for (int i = 0; i <= n; ++i)
    for (int j = 0; j <= i; ++j)
      for (int k = 0; k <= i - j; ++k)
        ans[i] = (ans[i] + 1ll * h[j] * f[k] % mod * g[i - j - k] % mod) % mod;
  for (int i = 0; i < n; ++i) {
    if (n - i - d < 0)
      printf("0 ");
    else
      printf("%d ", ans[n - i - d]);
  }
  return 0;
}
