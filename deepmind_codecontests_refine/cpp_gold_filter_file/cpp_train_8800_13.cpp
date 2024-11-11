#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const int N = 2e5 + 20;
long long n, k, l, r, f[N], inv[N];
long long powmod(long long x, long long n) {
  long long s = 1;
  while (n) {
    if (n & 1) s = (s * x) % mod;
    n >>= 1, x = (x * x) % mod;
  }
  return s;
}
void init() {
  f[0] = inv[0] = 1;
  for (int i = 1; i < N; i++)
    f[i] = (f[i - 1] * i) % mod, inv[i] = powmod(f[i], mod - 2) % mod;
}
long long Comb(long long n, long long k) {
  long long res = (f[n] * inv[n - k]) % mod;
  return (res * inv[k]) % mod;
}
map<long long, long long> mp;
int main() {
  init();
  while (cin >> n >> k) {
    mp.clear();
    for (int i = 0; i < n; i++) {
      scanf("%I64d%I64d", &l, &r);
      mp[l]++, mp[r + 1]--;
    }
    int l = mp.begin()->first;
    long long sum = 0, ans = 0;
    map<long long, long long>::iterator it;
    for (it = mp.begin(); it != mp.end(); it++) {
      long long num = it->first - l;
      if (sum >= k) ans = (ans + (num * Comb(sum, k)) % mod) % mod;
      sum += it->second;
      l = it->first;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
