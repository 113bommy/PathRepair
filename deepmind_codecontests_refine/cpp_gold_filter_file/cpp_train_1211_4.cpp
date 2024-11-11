#include <bits/stdc++.h>
int read() {
  char c = getchar();
  int flag = 1;
  int x = 0;
  while (c < '0' || c > '9') {
    if (c == '-') flag = -flag;
    c = getchar();
  }
  while ('0' <= c && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x * flag;
}
const int mod = 1e9 + 7;
int dp[105][105][105], h[105][105], n, u, v, f[105], g[105], C[105][105],
    size[105];
std::vector<int> ch[105];
int qpow(int a, int b) {
  if (b == 0) return 1;
  long long d = qpow(a, b >> 1);
  d = d * d % mod;
  if (b & 1) d = d * a % mod;
  return d;
}
int pw(int a, int b) {
  if (b >= 0) return qpow(a, b);
  return qpow(a, mod - 2);
}
void dfs(int u, int fa) {
  dp[u][0][1] = 1;
  size[u] = 1;
  for (int v : ch[u]) {
    if (v == fa) continue;
    dfs(v, u);
    std::memset(h, 0, sizeof(h));
    for (int j = 0; j < size[u]; ++j) {
      for (int k = 0; k < size[v]; ++k) {
        for (int l = 1; l <= size[u]; ++l) {
          for (int r = 1; r <= size[v]; ++r) {
            h[j + k][l] = (h[j + k][l] + (long long)dp[u][j][l] * dp[v][k][r] %
                                             mod * r % mod) %
                          mod;
            h[j + k + 1][l + r] = (h[j + k + 1][l + r] +
                                   (long long)dp[u][j][l] * dp[v][k][r] % mod) %
                                  mod;
          }
        }
      }
    }
    std::memcpy(dp[u], h, sizeof(h));
    size[u] += size[v];
  }
}
int det(int x) { return x & 1 ? mod - 1 : 1; }
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    scanf("%d%d", &u, &v);
    ch[u].push_back(v);
    ch[v].push_back(u);
  }
  dfs(1, 0);
  for (int i = 0; i <= n; ++i) {
    C[i][0] = 1;
    for (int j = 1; j <= i; ++j)
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
  }
  for (int i = 0; i < n; ++i)
    for (int j = 1; j <= n; ++j)
      g[i] =
          (g[i] + (long long)dp[1][i][j] * j % mod * pw(n, n - i - 2) % mod) %
          mod;
  for (int i = 0; i < n; ++i)
    for (int j = i; j < n; ++j)
      f[i] = (f[i] + (long long)det(j - i) * C[j][i] % mod * g[j] % mod) % mod;
  for (int i = 0; i < n; ++i) printf("%d ", f[i]);
  return 0;
}
