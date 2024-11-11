#include <bits/stdc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize(3)
using namespace std;
const int inf = 0x3f3f3f3f;
const double eps = 1e-7;
const int N = 3e3 + 10, mod = 1e9 + 7;
int head[N], to[N], nex[N], cnt = 1, n, d;
long long dp[N][N], pre[N], suc[N], fac[N], inv[N];
long long quick_pow(long long a, int n) {
  long long ans = 1;
  while (n) {
    if (n & 1) ans = ans * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return ans;
}
void add(int x, int y) {
  to[cnt] = y;
  nex[cnt] = head[x];
  head[x] = cnt++;
}
void dfs(int rt, int fa) {
  for (int i = 1; i <= n; i++) dp[rt][i] = 1;
  for (int i = head[rt]; i; i = nex[i]) {
    if (to[i] == fa) continue;
    dfs(to[i], rt);
    for (int j = 1; j <= n; j++) {
      dp[rt][j] = (1ll * dp[rt][j] * dp[to[i]][j]) % mod;
    }
  }
  for (int i = 1; i <= n; i++) dp[rt][i] = (dp[rt][i] + dp[rt][i - 1]) % mod;
}
long long solve(int x) {
  if (x <= n) return dp[1][x];
  for (int i = n; i >= 0; i--) dp[1][i + 1] = dp[1][i];
  n++;
  x++;
  pre[0] = suc[n + 1] = fac[0] = inv[0] = 1;
  for (int i = 1; i <= n; i++) {
    pre[i] = 1ll * pre[i - 1] * (x - i) % mod;
    fac[i] = 1ll * fac[i - 1] * i % mod;
  }
  fac[n + 1] = 1ll * fac[n] * (n + 1) % mod;
  inv[n + 1] = quick_pow(fac[n + 1], mod - 2);
  for (int i = n; i >= 1; i--) {
    suc[i] = 1ll * suc[i + 1] * (x - i) % mod;
    inv[i] = 1ll * inv[i + 1] * (i + 1) % mod;
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    long long a = 1ll * pre[i - 1] * suc[i + 1] % mod * dp[1][i] % mod;
    long long b = 1ll * inv[i - 1] * inv[n - i] % mod;
    if ((n - i) & 1) b *= -1;
    ans = ((ans + a * b % mod) % mod + mod) % mod;
  }
  return ans;
}
int main() {
  scanf("%d %d", &n, &d);
  for (int i = 2; i <= n; i++) {
    int x;
    scanf("%d", &x);
    add(x, i);
  }
  dfs(1, 0);
  printf("%lld\n", solve(d));
  return 0;
}
