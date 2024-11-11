#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007LL;
const long long INF = 1LL << 60;
int main() {
  long long t, l, r;
  scanf("%lld %lld %lld", &t, &l, &r);
  vector<long long> minPrime(r + 1);
  for (long long i = 0; i <= r; i++) minPrime[i] = i;
  for (long long i = 2; i * i <= r; i++) {
    if (minPrime[i] == i) {
      for (long long j = 2; i * j <= r; j++) {
        minPrime[i * j] = min(minPrime[i * j], i);
      }
    }
  }
  vector<long long> f(r + 1, INF);
  f[0] = f[1] = 0;
  for (long long i = 2; i <= r; i++) {
    long long x = i;
    while (x != 1) {
      f[i] = min(f[i], f[i / minPrime[x]] + i * (minPrime[x] - 1) / 2);
      x /= minPrime[x];
    }
  }
  long long res = 0;
  long long p = 1;
  for (long long i = l; i <= r; i++) {
    f[i] %= MOD;
    res += p * f[i] % MOD;
    res %= MOD;
    p *= t;
    p %= MOD;
  }
  printf("%lld\n", res);
  return 0;
}
