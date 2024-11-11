#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int f = 1, x = 0;
  char s = getchar();
  while (s < '0' || s > '9') {
    if (s == '-') f = -1;
    s = getchar();
  }
  while (s >= '0' && s <= '9') {
    x = x * 10 + s - 48;
    s = getchar();
  }
  return f * x;
}
const int p = 1e9 + 7;
inline int ksm(int a, int b) {
  int ans = 1;
  for (; b; b >>= 1, a = 1ll * a * a % p)
    if (b & 1) ans = 1ll * ans * a % p;
  return ans;
}
inline int add(int a, int b) { return a + b >= p ? a + b - p : a + b; }
inline int sub(int a, int b) { return a - b < 0 ? a - b + p : a - b; }
const int N = 1e5 + 10;
int n, k, size[N], dp[N][205], f[205], sum[205], S[205][205];
struct Graph {
  int tot, next[N << 1], to[N << 1], head[N];
  inline void add(int a, int b) {
    to[++tot] = b;
    next[tot] = head[a];
    head[a] = tot;
  }
  inline void link(int a, int b) {
    add(a, b);
    add(b, a);
  }
} T;
void dfs(int u, int fa) {
  size[u] = 1;
  dp[u][0] = 2;
  for (int i = T.head[u]; i; i = T.next[i]) {
    int v = T.to[i];
    if (v == fa) continue;
    dfs(v, u);
    for (int j = 0; j <= k; j++) f[j] = 0;
    for (int j = 0; j <= min(k, size[v]); j++)
      for (int x = 0; x <= min(k - j, size[v]); x++)
        f[j + x] = add(f[j + x], 1ll * dp[u][j] * dp[v][x] % p);
    for (int j = 0; j <= k; j++) dp[u][j] = f[j];
    for (int j = 0; j <= k; j++) sum[j] = sub(sum[j], dp[v][j]);
    size[u] += size[v];
  }
  for (int i = 0; i <= k; i++) sum[i] = add(sum[i], dp[u][i]);
  for (int i = k; i >= 1; i--) dp[u][i] = add(dp[u][i], dp[u][i - 1]);
  dp[u][1] = sub(dp[u][1], 1);
}
int main() {
  n = read(), k = read();
  for (int i = 1; i < n; i++) {
    int a = read(), b = read();
    T.link(a, b);
  }
  S[1][1] = 1;
  for (int i = 2; i <= k; i++)
    for (int j = 1; j <= k; j++)
      S[i][j] = add(S[i - 1][j - 1], 1ll * j * S[i - 1][j] % p);
  dfs(1, 0);
  int fac = 1, ans = 0;
  for (int i = 1; i <= k; i++) {
    fac = 1ll * fac * i % p;
    ans = add(ans, 1ll * fac * S[k][i] % p * sum[i] % p);
  }
  printf("%d\n", ans);
  return 0;
}
