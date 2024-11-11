#include <bits/stdc++.h>
using namespace std;
const unsigned mod = 1000000000 + 7;
int n;
long long dp[27][5100];
long long sum[5100];
char input[6000];
long long binom[10000];
long long inv(long long x) {
  int pow = mod - 2;
  long long res = 1;
  while (pow) {
    if (pow & 1) res = x * res % mod;
    x = x * x % mod;
    pow >>= 1;
  }
  return res;
}
int main() {
  scanf("%d", &n);
  scanf("%s", input);
  for (int i = 0; i < n; ++i) {
    if (i > 0 && input[i] == input[i - 1]) continue;
    int num = input[i] - 'a';
    for (int j = i + 1; j > 1; --j) {
      unsigned old = dp[num][j];
      dp[num][j] = (sum[j - 1] - dp[num][j - 1]) % mod;
      sum[j] = (sum[j] + dp[num][j] - old) % mod;
    }
    if (dp[num][1] == 0) {
      dp[num][1] = 1;
      ++sum[1];
    }
  }
  binom[0] = 1;
  for (int i = 1; i < n; ++i)
    binom[i] = (binom[i - 1] * (n - i) % mod) * inv(i) % mod;
  long long res = 0;
  for (int i = 1; i <= n; ++i) res += binom[i - 1] * sum[i] % mod;
  res %= mod;
  if (res < 0) res += mod;
  printf("%lld\n", res % mod);
  return 0;
}
