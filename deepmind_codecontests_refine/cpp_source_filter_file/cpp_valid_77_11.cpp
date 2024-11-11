#include <bits/stdc++.h>
using namespace std;
const long long maxn = 5e6 + 10;
long long dp[maxn];
long long sum[maxn];
int main() {
  long long n, mod;
  scanf("%lld%lld", &n, &mod);
  dp[n] = 1;
  sum[n] = 1;
  for (long long i = n - 1; i >= 1; i--) {
    dp[i] += sum[i + 1];
    dp[i] %= mod;
    for (long long j = 2; j * i <= n; j++) {
      int r = min(n + 1, i * j + j);
      int l = i * j;
      dp[i] = dp[i] + ((sum[l] - sum[r + 1]) % mod + mod) % mod;
    }
    sum[i] = (sum[i + 1] + dp[i]) % mod;
  }
  printf("%lld\n", dp[1] % mod);
}
