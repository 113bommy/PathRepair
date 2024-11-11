#include <bits/stdc++.h>
using namespace std;
const long long N = 3005, M = 1e9 + 7;
vector<long long> v[N];
long long x, y, n, D, f[N], h[N], g[N], ans[N], dp[N][N], inv[N];
void dfs(long long x, long long y) {
  for (long long i : v[x])
    if (i != y) dfs(i, x);
  for (long long i = 0; i <= n; i++) {
    long long s = 1;
    for (long long j : v[x]) (s *= dp[j][i]) %= M;
    dp[x][i] = (s + (i ? dp[x][i - 1] : 0)) % M;
  }
}
inline long long ksm(long long x, long long y) {
  long long ans = 1;
  for (; y; y >>= 1, x = x * x % M)
    if (y & 1) (ans *= x) %= M;
  return ans;
}
signed main() {
  scanf("%lld%lld", &n, &D);
  for (long long i = 2; i <= n; i++) {
    scanf("%lld", &y);
    v[y].push_back(i);
  }
  dfs(1, 0);
  f[0] = 1;
  for (long long i = 0; i <= n; i++)
    for (long long j = i + 1; j >= 0; j--)
      f[j] = ((j ? f[j - 1] : 0) + M - i * f[j] % M) % M;
  for (long long i = 1; i <= n; i++) inv[i] = ksm(i, M - 2);
  for (long long i = 0; i <= n; i++) {
    for (long long j = 0; j <= n + 1; j++) h[j] = f[j];
    for (long long j = n; j >= 0; j--) g[j] = h[j + 1], (h[j] += i * g[j]) %= M;
    long long s = dp[1][i];
    for (long long j = 0; j <= n; j++)
      if (i != j) {
        if (i > j)
          (s *= inv[i - j]) %= M;
        else
          (s *= M - inv[j - i]) %= M;
      }
    for (long long j = 0; j <= n; j++) (ans[j] += g[j] * s) %= M;
  }
  long long Ans = 0;
  D--;
  for (long long i = 0; i <= n; i++) (Ans += ksm(D, i) * ans[i]) %= M;
  printf("%lld\n", Ans);
}
