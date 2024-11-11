#include <bits/stdc++.h>
using namespace std;
const int N = 110;
const int P = 1000000007;
int k, n, m, x, y;
int h[N], nx[N << 1], t[N << 1], num;
int sz[N];
int f[N][N][N], F[N][N];
int Ans[N];
int Pow(int x, int y) {
  int Ans = 1;
  for (; y; y >>= 1, x = 1ll * x * x % P)
    if (y & 1) Ans = 1ll * Ans * x % P;
  return Ans;
}
void addedge(int x, int y) {
  t[++num] = y;
  nx[num] = h[x];
  h[x] = num;
}
void Add(int& x, int y) { x = (x + y) % P; }
void Dfs(int x, int y) {
  sz[x] = 1;
  f[x][1][0] = 1;
  for (int i = h[x]; i; i = nx[i])
    if (t[i] != y) {
      int v = t[i];
      Dfs(v, x);
      for (int i = 1; i <= sz[x] + sz[v]; i++)
        for (int j = 0; j < sz[x] + sz[v]; j++) F[i][j] = 0;
      for (int i = 1; i <= sz[x]; i++)
        for (int j = 1; j <= sz[v]; j++)
          for (int k = 0; k < sz[x]; k++)
            for (int p = 0; p < sz[v]; p++)
              if (f[x][i][k] && f[v][j][p]) {
                Add(F[i + j][k + p + 1], 1ll * f[x][i][k] * f[v][j][p] % P);
                Add(F[i][k + p],
                    1ll * f[x][i][k] * f[v][j][p] % P * n % P * j % P);
              }
      sz[x] += sz[v];
      for (int i = 1; i <= sz[x]; i++)
        for (int j = 0; j < sz[x]; j++) f[x][i][j] = F[i][j];
    }
}
int C(int n, int m) {
  int Ans = 1;
  for (int i = n - m + 1; i <= n; i++) Ans = 1ll * Ans * i % P;
  for (int i = 2; i <= m; i++) Ans = 1ll * Ans * Pow(m, P - 2) % P;
  return Ans;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++)
    scanf("%d%d", &x, &y), addedge(x, y), addedge(y, x);
  Dfs(1, 0);
  int t = Pow(n, P - 2);
  for (int i = 1; i <= n; i++)
    for (int j = 0; j < n; j++) Add(Ans[j], 1ll * f[1][i][j] * i % P * t % P);
  for (int i = n - 2; ~i; i--)
    for (int j = i + 1; j < n; j++) Add(Ans[i], -1ll * Ans[j] * C(j, i) % P);
  for (int i = 0; i < n; i++) printf("%d ", (Ans[i] + P) % P);
  return 0;
}
