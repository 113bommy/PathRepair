#include <bits/stdc++.h>
using namespace std;
namespace pcf {
long long dp[100][100010];
unsigned int ar[(10000010 >> 6) + 5] = {0};
int len = 0, primes[666666], counter[10000010] = {0};
void Sieve() {
  for (int i = 2; i < 10000010; i++) {
    if (!counter[i]) primes[len++] = i;
    for (int j = 0; j < len && primes[j] * i < 10000010; j++) {
      counter[primes[j] * i] = 1;
      if (i % primes[j] == 0) break;
    }
  }
  for (int i = 1; i < 10000010; i++) {
    if (counter[i] == 0)
      counter[i] = 1;
    else
      counter[i] = 0;
    counter[i] += counter[i - 1];
  }
}
void init() {
  Sieve();
  for (int n = 0; n < 100; n++) {
    for (int m = 0; m < 100010; m++) {
      if (!n)
        dp[n][m] = m;
      else
        dp[n][m] = dp[n - 1][m] - dp[n - 1][m / primes[n - 1]];
    }
  }
}
long long phi(long long m, int n) {
  if (n == 0) return m;
  if (primes[n - 1] >= m) return 1;
  if (m < 100010 && n < 100) return dp[n][m];
  return phi(m, n - 1) - phi(m / primes[n - 1], n - 1);
}
long long Lehmer(long long m) {
  if (m < 10000010) return counter[m];
  long long w, res = 0;
  int i, a, s, c, x, y;
  s = sqrt(0.9 + m), y = c = cbrt(0.9 + m);
  a = counter[y], res = phi(m, a) + a - 1;
  for (i = a; primes[i] <= s; i++)
    res = res - Lehmer(m / primes[i]) + Lehmer(primes[i]) - 1;
  return res;
}
}  // namespace pcf
long long solve(long long n) {
  int i, j, k, l;
  long long x, y, res = 0;
  for (i = 0; i < pcf::len; i++) {
    x = pcf::primes[i], y = n / x;
    if ((x * x) > n) break;
    res += (pcf::Lehmer(y) - pcf::Lehmer(x));
  }
  for (i = 0; i < pcf::len; i++) {
    x = pcf::primes[i];
    if ((x * x * x) > n) break;
    res++;
  }
  return res;
}
int main() {
  pcf::init();
  long long n;
  while (~scanf("%lld", &n)) {
    printf("%lld\n", solve(n));
  }
  return 0;
}
