#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int fac[200010];
int head[200010];
int to[400010];
int nex[400010];
int tot;
int f[200010];
int g[200010];
int n;
int x, y;
void add(int x, int y) {
  nex[++tot] = head[x];
  head[x] = tot;
  to[tot] = y;
}
int quick(int x, int y) {
  int res = 1;
  while (y) {
    if (y & 1) {
      res = 1ll * x * res % mod;
    }
    y >>= 1;
    x = 1ll * x * x % mod;
  }
  return res;
}
void dfs(int x, int fa) {
  f[x] = 1;
  for (int i = head[x]; i; i = nex[i]) {
    if (to[i] != fa) {
      dfs(to[i], x);
      f[x] = 1ll * f[x] * f[to[i]];
      g[x]++;
    }
  }
  if (x == 1)
    f[x] = 1ll * f[x] * fac[g[x]] % mod;
  else
    f[x] = 1ll * f[x] * fac[g[x] + 1] % mod;
}
int main() {
  scanf("%d", &n);
  fac[0] = fac[1] = 1;
  for (int i = 2; i <= n + 1; i++) {
    fac[i] = 1ll * fac[i - 1] * i % mod;
  }
  for (int i = 1; i < n; i++) {
    scanf("%d%d", &x, &y);
    add(x, y);
    add(y, x);
  }
  dfs(1, 0);
  printf("%d", 1ll * f[1] * n % mod);
}
