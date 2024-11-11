#include <bits/stdc++.h>
using namespace std;
const long long maxn = 100005;
const long long mod = 1000000000 + 7;
const long long inf = 0x3f3f3f3f;
long long n;
long long cnt[maxn];
long long pow2[maxn];
long long miu[maxn];
bool sieve[maxn];
vector<long long> primes;
void eulersieve() {
  memset(sieve, 0, sizeof(sieve));
  primes.clear();
  miu[1] = 1;
  for (long long i = 2; i < maxn; i++) {
    if (!sieve[i]) {
      primes.push_back(i);
      miu[i] = -1;
    }
    for (long long j = 1; j < primes.size() && i * primes[j] < maxn; j++) {
      sieve[i * primes[j]] = 1;
      if (i % primes[j] == 0) break;
      miu[i * primes[j]] = -miu[i];
    }
  }
}
int main() {
  pow2[0] = 1;
  for (long long i = 1; i < maxn; i++) pow2[i] = (pow2[i - 1] << 1) % mod;
  eulersieve();
  while (cin >> n) {
    long long Max = -inf;
    memset(cnt, 0, sizeof(cnt));
    for (long long i = 1; i <= n; i++) {
      long long x;
      scanf("%I64d", &x);
      Max = max(Max, x);
      for (long long j = 1; j * j <= x; j++)
        if (x % j == 0) {
          cnt[j]++;
          cnt[x / j] += (j != x / j);
        }
    }
    long long ans = 0;
    for (long long i = 1; i <= Max; i++)
      ans = (ans + miu[i] * (pow2[cnt[i]] - 1)) % mod;
    printf("%I64d\n", (ans % mod + mod) % mod);
  }
  return 0;
}
