#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5, MAXK = 205, Mod = 1e9 + 7;
char buf[1 << 12], *pp1 = buf, *pp2 = buf, nc;
int ny;
inline char gc() {
  return pp1 == pp2 &&
                 (pp2 = (pp1 = buf) + fread(buf, 1, 1 << 12, stdin), pp1 == pp2)
             ? EOF
             : *pp1++;
}
inline int read() {
  int x = 0;
  for (ny = 1; nc = gc(), (nc < 48 || nc > 57) && nc != EOF;)
    if (nc == 45) ny = -1;
  if (nc < 0) return nc;
  for (x = nc - 48; nc = gc(), 47 < nc && nc < 58 && nc != EOF;
       x = (x << 3) + (x << 1) + (nc ^ 48))
    ;
  return x * ny;
}
int f[MAXN][MAXK], sz[MAXN], ans[MAXK], S[MAXK][MAXK], C[MAXK][MAXK], Fac[MAXK],
    n, k;
vector<int> G[MAXN];
void dfs(int x, int fa) {
  sz[x] = 1, f[x][0] = 1;
  for (auto y : G[x])
    if (y != fa) {
      dfs(y, x);
      static int g[MAXN];
      for (int i = (0); i <= (min(k, sz[x])); i++) g[i] = f[x][i];
      for (int i = (0); i <= (min(k, sz[y])); i++)
        f[x][i] = (1ll * f[x][i] + (i ? f[y][i - 1] : 0) + f[y][i]) % Mod;
      for (int i = (0); i <= (min(k, sz[x])); i++)
        for (int j = (0); j <= (min(k - i, sz[y])); j++)
          f[x][i + j] = (f[x][i + j] + 1ll * g[i] * f[y][j]) % Mod,
                   ans[i + j] = (ans[i + j] + 1ll * g[i] * f[y][j]) % Mod,
                   f[x][i + j + 1] =
                       (f[x][i + j + 1] + 1ll * g[i] * f[y][j]) % Mod,
                   ans[i + j + 1] =
                       (ans[i + j + 1] + 1ll * g[i] * f[y][j]) % Mod;
      sz[x] += sz[y];
    }
}
int main() {
  n = read(), k = read();
  for (int i = (2); i <= (n); i++) {
    int x = read(), y = read();
    G[x].push_back(y), G[y].push_back(x);
  }
  dfs(1, 0), S[0][0] = 1;
  for (int i = (1); i <= (k); i++)
    for (int j = (1); j <= (k); j++)
      S[i][j] = (S[i - 1][j - 1] + 1ll * S[i - 1][j] * j) % Mod;
  Fac[0] = 1;
  for (int i = (1); i <= (k); i++) Fac[i] = 1ll * Fac[i - 1] * i % Mod;
  int Ans = 0;
  for (int i = (1); i <= (k); i++)
    Ans = (Ans + 1ll * S[k][i] * Fac[i] % Mod * ans[i]) % Mod;
  cout << Ans << '\n';
  return 0;
}
