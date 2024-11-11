#include <bits/stdc++.h>
using namespace std;
const int maxn = 3005;
const long long mod = 1e9 + 7;
int n;
long long dp[maxn][maxn], D;
vector<int> G[maxn];
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= mod;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
namespace polysum {
const int D = 101000;
long long a[D], f[D], g[D], p[D], p1[D], p2[D], b[D], h[D][2], C[D];
long long calcn(int d, long long *a, long long n) {
  if (n <= d) return a[n];
  p1[0] = p2[0] = 1;
  for (int i = 0; i < d + 1; i++) {
    long long t = (n - i + mod) % mod;
    p1[i + 1] = p1[i] * t % mod;
  }
  for (int i = 0; i < d + 1; i++) {
    long long t = (n - d + i + mod) % mod;
    p2[i + 1] = p2[i] * t % mod;
  }
  long long ans = 0;
  for (int i = 0; i < d + 1; i++) {
    long long t =
        g[i] * g[d - i] % mod * p1[i] % mod * p2[d - i] % mod * a[i] % mod;
    if ((d - i) & 1)
      ans = (ans - t + mod) % mod;
    else
      ans = (ans + t) % mod;
  }
  return ans;
}
void init(int M) {
  f[0] = f[1] = g[0] = g[1] = 1;
  for (int i = 2; i < M + 5; i++) f[i] = f[i - 1] * i % mod;
  g[M + 4] = powmod(f[M + 4], mod - 2);
  for (int i = M + 4 - 1; i >= 1; i--) g[i] = g[i + 1] * (i + 1) % mod;
}
long long polysum(long long n, long long *a, long long m) {
  a[m + 1] = calcn(m, a, m + 1);
  for (int i = 1; i < m + 2; i++) a[i] = (a[i - 1] + a[i]) % mod;
  return calcn(m + 1, a, n - 1);
}
long long qpolysum(long long R, long long n, long long *a, long long m) {
  if (R == 1) return polysum(n, a, m);
  a[m + 1] = calcn(m, a, m + 1);
  long long r = powmod(R, mod - 2), p3 = 0, p4 = 0, c, ans;
  h[0][0] = 0;
  h[0][1] = 1;
  for (int i = 1; i < m + 2; i++) {
    h[i][0] = (h[i - 1][0] + a[i - 1]) * r % mod;
    h[i][1] = h[i - 1][1] * r % mod;
  }
  for (int i = 0; i < m + 2; i++) {
    long long t = g[i] * g[m + 1 - i] % mod;
    if (i & 1)
      p3 = ((p3 - h[i][0] * t) % mod + mod) % mod,
      p4 = ((p4 - h[i][1] * t) % mod + mod) % mod;
    else
      p3 = (p3 + h[i][0] * t) % mod, p4 = (p4 + h[i][1] * t) % mod;
  }
  c = powmod(p4, mod - 2) * (mod - p3) % mod;
  for (int i = 0; i < m + 2; i++) h[i][0] = (h[i][0] + h[i][1] * c) % mod;
  for (int i = 0; i < m + 2; i++) C[i] = h[i][0];
  ans = (calcn(m, C, n) * powmod(R, n) - c) % mod;
  if (ans < 0) ans += mod;
  return ans;
}
}  // namespace polysum
void dfs(int u) {
  for (int i = 0; i <= n; ++i) dp[u][i] = 1;
  for (int i = 0; i < (int)G[u].size(); ++i) {
    int v = G[u][i];
    dfs(v);
    long long t = 0;
    for (int j = 0; j <= n; ++j) {
      t = (t + dp[v][j]) % mod;
      dp[u][j] = dp[u][j] * t % mod;
    }
  }
}
int main() {
  scanf("%d%I64d", &n, &D);
  --D;
  for (int i = 2; i <= n; ++i) {
    int p;
    scanf("%d", &p);
    G[p].push_back(i);
  }
  dfs(1);
  for (int i = 1; i <= n; ++i) dp[1][i] = (dp[1][i] + dp[1][i - 1]) % mod;
  polysum::init(2999);
  printf("%I64d\n", polysum::calcn(n, dp[1], D));
  return 0;
}
