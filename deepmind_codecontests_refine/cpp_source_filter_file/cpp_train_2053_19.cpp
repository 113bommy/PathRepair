#include <bits/stdc++.h>
const long long mod = 1000000007;
long long n, D;
long long dp[3010][3010];
long long S[3010][3010];
bool memo[3010][3010];
std::vector<long long> child[3010];
long long solve(long long u, long long d) {
  if (memo[u][d]) return S[u][d];
  memo[u][d] = true;
  if (child[u].empty())
    dp[u][d] = 1;
  else {
    dp[u][d] = 1;
    for (int i = 0; i < child[u].size(); i++) {
      dp[u][d] = dp[u][d] * solve(child[u][i], d) % mod;
    }
  }
  S[u][d] = S[u][d - 1] + dp[u][d];
  return S[u][d];
}
long long power(long long x, long long r) {
  if (r == 0) return 1;
  if (r == 1) return x;
  long long res = power(x, r / 2);
  res = res * res % mod;
  if (r % 2 == 1) res = res * x % mod;
  return res;
}
long long prod;
long long fact[3010];
long long ans;
int main() {
  scanf("%lld%lld", &n, &D);
  for (long long u = 2; u <= n; u++) {
    long long parent;
    scanf("%lld", &parent);
    child[parent].push_back(u);
  }
  for (long long u = 1; u <= n; u++) {
    dp[u][1] = 1;
    S[u][1] = 1;
  }
  for (long long d = 2; d <= n + 1; d++) solve(1, d);
  if (D <= n + 1) {
    printf("%lld\n", S[1][D]);
    return 0;
  }
  prod = 1;
  for (long long p = 1; p <= n + 1; p++) prod = prod * (D - p) % mod;
  fact[0] = 1;
  for (long long p = 1; p <= n + 1; p++) fact[p] = fact[p - 1] * p % mod;
  for (long long d = 1; d <= n + 1; d++) {
    long long num = S[1][d] * prod % mod;
    long long den = fact[d - 1] * fact[n + 1 - d] % mod;
    den = (D - d) * den % mod;
    num = num * power(den, mod - 2) % mod;
    if ((n + 1 - d) % 2 == 1) num = (mod - num) % mod;
    ans = (ans + num) % mod;
  }
  printf("%lld\n", ans);
  return 0;
}
