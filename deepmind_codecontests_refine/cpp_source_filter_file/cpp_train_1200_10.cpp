#include <bits/stdc++.h>
using namespace std;
using namespace std;
namespace pcf {
long long dp[100][100010];
unsigned int ar[(10000010 >> 6) + 5] = {0};
int len = 0, primes[666666], counter[10000010];
void Sieve() {
  (((ar[(0) >> 6]) |= (1 << (((0) >> 1) & 31)))),
      (((ar[(1) >> 6]) |= (1 << (((1) >> 1) & 31))));
  for (int i = 3; (i * i) < 10000010; i++, i++) {
    if (!(((ar[(i) >> 6]) & (1 << (((i) >> 1) & 31))))) {
      int k = i << 1;
      for (int j = (i * i); j < 10000010; j += k)
        (((ar[(j) >> 6]) |= (1 << (((j) >> 1) & 31))));
    }
  }
  for (int i = 1; i < 10000010; i++) {
    counter[i] = counter[i - 1];
    if ((((i) && ((i)&1) &&
          (!(((ar[((i)) >> 6]) & (1 << ((((i)) >> 1) & 31)))))) ||
         ((i) == 2)))
      primes[len++] = i, counter[i]++;
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
  for (i = a; primes[i] <= s; i++) res = res - Lehmer(m / primes[i]) + i - 1;
  return res;
}
}  // namespace pcf
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long n;
  cin >> n;
  pcf::init();
  long long res = 0;
  for (int i = 0; i < pcf::len; ++i) {
    long long p = pcf::primes[i];
    if (p * p * p > n) break;
    ++res;
  }
  for (int i = 0; i < pcf::len; ++i) {
    long long p = pcf::primes[i];
    if (p * p > n) break;
    long long q = n / p;
    res += pcf::Lehmer(q) - pcf::Lehmer(p);
  }
  cout << res;
  return 0;
}
