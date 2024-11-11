#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, M = 210, mod = 1e9 + 7;
int n, k, x, y, cnt, head[N], sz[N], f[N][M], g[M], ans[M], S[M][M], fac[M],
    Ans;
struct edge {
  int to, nxt;
} e[N << 1];
void adde(int x, int y) {
  e[++cnt].to = y;
  e[cnt].nxt = head[x];
  head[x] = cnt;
}
inline void upd(int &x, int y) {
  x += y;
  x -= x >= mod ? mod : 0;
}
void dfs(int u, int par) {
  sz[u] = 1, f[u][0] = 2;
  for (int i = head[u], v; i; i = e[i].nxt)
    if (v = e[i].to, v != par) {
      dfs(v, u);
      for (int j = (0); j <= (min(sz[u], k)); j++) g[j] = f[u][j], f[u][j] = 0;
      for (int j = (0); j <= (min(sz[u], k)); j++)
        for (int l = (0); l <= (min(sz[v], k)); l++)
          upd(f[u][j + l], (long long)g[j] * f[v][l] % mod);
      for (int j = (0); j <= (min(sz[v], k)); j++) upd(ans[j], mod - f[v][j]);
      sz[u] += sz[v];
    }
  for (int i = (0); i <= (min(sz[u], k)); i++) upd(ans[i], f[u][i]);
  for (int i = min(sz[u], k); i; i--) upd(f[u][i], f[u][i - 1]);
  upd(f[u][1], mod - 1);
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = (1); i <= (n - 1); i++)
    scanf("%d%d", &x, &y), adde(x, y), adde(y, x);
  dfs(1, 0);
  fac[0] = 1;
  for (int i = (1); i <= (k); i++)
    S[i][1] = 1, fac[i] = (long long)fac[i - 1] * i % mod;
  for (int i = (2); i <= (k); i++)
    for (int j = (1); j <= (i); j++)
      S[i][j] = ((long long)S[i - 1][j] * j + S[i - 1][j - 1]) % mod;
  for (int i = (0); i <= (k); i++)
    upd(Ans, (long long)S[k][i] * fac[i] % mod * ans[i] % mod);
  printf("%d\n", Ans);
  return 0;
}
