#include <bits/stdc++.h>
using namespace std;
const int N = 105;
const int mod = 1e9 + 7;
const int inf = 2147483647;
long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') x = x * 10ll + ch - '0', ch = getchar();
  return x * f;
}
void up(int& x, int y) {
  x += y;
  if (x >= mod) x -= mod;
}
int n, k, sz[N], pw[N], C[N][N];
vector<int> G[N];
int f[N][N][2], g[N][2];
void dfs(int x, int fa) {
  sz[x] = 1;
  f[x][1][0] = f[x][1][1] = 1;
  for (int y : G[x]) {
    if (y == fa) continue;
    dfs(y, x);
    sz[x] += sz[y];
    for (int i = 1; i <= sz[x]; i++) g[i][0] = g[i][1] = 0;
    for (int i = 1; i <= sz[x]; i++)
      for (int j = 1; j <= min(i, sz[y]); j++) {
        up(g[i][0], (long long)f[y][j][1] * f[x][i - j][0] % mod);
        up(g[i][0], (long long)f[y][j][0] * f[x][i - j + 1][0] % mod);
        up(g[i][1], (long long)f[y][j][1] * f[x][i - j][1] % mod);
        up(g[i][1], (long long)f[y][j][0] * f[x][i - j + 1][1] % mod);
        up(g[i][1], (long long)f[y][j][1] * f[x][i - j + 1][0] % mod);
      }
    for (int i = 1; i <= sz[x]; i++) f[x][i][0] = g[i][0], f[x][i][1] = g[i][1];
  }
}
int main() {
  n = read();
  pw[0] = 1;
  for (int i = 1; i <= n; i++) pw[i] = (long long)pw[i - 1] * n % mod;
  C[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    C[i][0] = 1;
    for (int j = 1; j <= n; j++)
      C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
  }
  for (int i = 1; i < n; i++) {
    int x = read(), y = read();
    G[x].push_back(y), G[y].push_back(x);
  }
  dfs(1, 0);
  for (int i = 0; i < n; i++) {
    int ans = 0;
    for (int j = i; j < n - 1; j++)
      if ((i & 1) == (j & 1))
        up(ans,
           (long long)C[j][i] * pw[n - j - 2] % mod * f[1][n - j][1] % mod);
      else
        up(ans, mod - (long long)C[j][i] * pw[n - j - 2] % mod *
                          f[1][n - j][1] % mod);
    if ((i & 1) == ((n - 1) & 1))
      up(ans, C[n - 1][i]);
    else
      up(ans, mod - C[n - 1][i]);
    cout << ans << ends;
  }
}
