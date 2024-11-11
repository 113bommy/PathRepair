#include <bits/stdc++.h>
#pragma GCC optimize(3)
using namespace std;
long long pow_mod(long long a, long long i) {
  long long s = 1;
  while (i) {
    if (i & 1) s = s * a % 1000000007;
    a = a * a % 1000000007;
    i >>= 1;
  }
  return s;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
namespace polysum {
const long long D = 100005;
long long a[D], f[D], g[D], p[D], p1[D], p2[D], b[D], h[D][2], C[D];
long long calcn(long long d, long long *a, long long n) {
  if (n <= d) return a[n];
  p1[0] = p2[0] = 1;
  for (long long i = 0; i <= d; i++) {
    long long t = (n - i + 1000000007) % 1000000007;
    p1[i + 1] = p1[i] * t % 1000000007;
  }
  for (long long i = 0; i <= d; i++) {
    long long t = (n - d + i + 1000000007) % 1000000007;
    p2[i + 1] = p2[i] * t % 1000000007;
  }
  long long ans = 0;
  for (long long i = 0; i <= d; i++) {
    long long t = g[i] * g[d - 1] % 1000000007 * p1[i] % 1000000007 *
                  p2[d - i] % 1000000007 * a[i] % 1000000007;
    if ((d - i) & 1)
      ans = (ans - t + 1000000007) % 1000000007;
    else
      ans = (ans + t) % 1000000007;
  }
  return ans;
}
void init(long long M) {
  f[0] = f[1] = g[0] = g[1] = 1;
  for (long long i = 2; i <= M + 4; i++) f[i] = f[i - 1] * i % 1000000007;
  g[M + 4] = pow_mod(f[M + 4], 1000000007 - 2);
  for (long long i = M + 3; i >= 1; i--) g[i] = g[i + 1] * (i + 1) % 1000000007;
}
long long polysum(long long n, long long *a, long long m) {
  a[m + 1] = calcn(m, a, m + 1);
  for (long long i = 1; i <= m + 1; i++) a[i] = (a[i - 1] + a[i]) % 1000000007;
  return calcn(m + 1, a, n - 1);
}
long long qpolysum(long long R, long long n, long long *a, long long m) {
  if (R == 1) return polysum(n, a, m);
  a[m + 1] = calcn(m, a, m + 1);
  long long r = pow_mod(R, 1000000007 - 2), p3 = 0, p4 = 0, c, ans;
  h[0][0] = 0;
  h[0][1] = 1;
  for (long long i = 1; i <= m + 1; i++) {
    h[i][0] = (h[i - 1][0] + a[i - 1]) * r % 1000000007;
    h[i][1] = h[i - 1][1] * r % 1000000007;
  }
  for (long long i = 0; i <= m + 1; i++) {
    long long t = g[i] * g[m + 1 - i] % 1000000007;
    if (i & 1)
      p3 = ((p3 - h[i][0] * t) % 1000000007 + 1000000007) % 1000000007,
      p4 = ((p4 - h[i][1] * t) % 1000000007 + 1000000007) % 1000000007;
    else
      p3 = (p3 + h[i][0] * t) % 1000000007,
      p4 = (p4 + h[i][1] * t) % 1000000007;
  }
  c = pow_mod(p4, 1000000007 - 2) * (1000000007 - p3) % 1000000007;
  for (long long i = 0; i <= m + 1; i++)
    h[i][0] = (h[i][0] + h[i][1] * c) % 1000000007;
  for (long long i = 0; i <= m + 1; i++) C[i] = h[i][0];
  ans = (calcn(m, C, n) * pow_mod(R, n) - c) % 1000000007;
  if (ans < 0) ans += 1000000007;
  return ans;
}
}  // namespace polysum
long long n, D, dp[2005][2005], a[2005];
vector<long long> G[2005];
void dfs(long long v, long long p, long long d) {
  for (long long i = 0; i <= d; i++) dp[v][i] = 1;
  for (long long i = 0; i < (int)G[v].size(); i++) {
    long long to = G[v][i];
    if (to == p) continue;
    dfs(to, v, d);
    for (long long j = 0; j <= d; j++) a[j] = dp[to][j];
    for (long long j = 1; j <= d; j++) a[j] = (a[j] + a[j - 1]) % 1000000007;
    for (long long j = 0; j <= d; j++)
      dp[v][j] = 1LL * dp[v][j] * a[j] % 1000000007;
  }
}
int main() {
  scanf("%lld%lld", &n, &D);
  for (long long i = 2; i <= n; i++) {
    long long x;
    scanf("%lld", &x);
    G[i].push_back(x);
    G[x].push_back(i);
  }
  dfs(1, 0, n);
  for (long long i = 0; i <= n; i++) a[i] = dp[1][i];
  for (long long i = 1; i <= n; i++) a[i] = (a[i] + a[i - 1] % 1000000007);
  polysum::init(4000);
  printf("%lld\n", polysum::calcn(n, a, D - 1));
  return 0;
}
