#include <bits/stdc++.h>
const int maxk = 2e2 + 5;
const int maxn = 1e5 + 5;
const int mo = 1e9 + 7;
using namespace std;
int rd() {
  int x = 0, f = 1;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) x = (x << 3) + (x << 1) + c - '0', c = getchar();
  return x * f;
}
int n, k, S[maxk][maxk], head[maxn], tot, ans[maxk], sum, fac[maxk], sz[maxn],
    g[maxk];
int f[maxn][maxk];
struct node {
  int v, nxt;
} e[maxn << 1];
void add(int u, int v) {
  e[++tot].v = v;
  e[tot].nxt = head[u];
  head[u] = tot;
}
int pls(int x, int y) { return x + y >= mo ? x + y - mo : x + y; }
int dec(int x, int y) { return x - y < 0 ? x - y + mo : x - y; }
int mul(int x, int y) { return 1LL * x * y % mo; }
void dp(int u, int y) {
  sz[u] = 1;
  f[u][0] = 2;
  for (int i = head[u]; i; i = e[i].nxt) {
    int v = e[i].v;
    if (v == y) continue;
    dp(v, u);
    for (int j = 0; j <= k; j++) g[j] = 0;
    for (int x = 0; x <= min(k, sz[u]); x++)
      for (int y = 0; y <= min(k - x, sz[v]); y++)
        g[x + y] = pls(g[x + y], mul(f[u][x], f[v][y]));
    for (int j = 0; j <= k; j++) f[u][j] = g[j], ans[j] = dec(ans[j], f[v][j]);
    sz[u] += sz[v];
  }
  for (int i = 0; i <= k; i++) ans[i] = pls(ans[i], f[u][i]);
  for (int i = k; i >= 1; i--) f[u][i] = pls(f[u][i], f[u][i - 1]);
  f[u][1] = dec(f[u][1], 1);
}
int main() {
  n = rd();
  k = rd();
  for (int i = 1, u, v; i < n; i++) {
    u = rd();
    v = rd();
    add(u, v);
    add(v, u);
  }
  S[0][0] = 1;
  fac[0] = 1;
  for (int i = 1; i <= k; i++) {
    fac[i] = mul(i, fac[i - 1]);
    for (int j = 1; j <= i; j++)
      S[i][j] = pls(S[i - 1][j - 1], mul(j, S[i - 1][j]));
  }
  dp(1, 0);
  for (int i = 0; i <= k; i++)
    sum = pls(sum, mul(S[k][i], mul(fac[i], ans[i])));
  printf("%d\n", sum);
  return 0;
}
