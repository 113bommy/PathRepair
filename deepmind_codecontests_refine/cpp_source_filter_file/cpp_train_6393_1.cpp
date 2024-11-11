#include <bits/stdc++.h>
using namespace std;
long long n, x, a[1000000], p[1000000], i, j, as, s, mn, q, k, mod = 1000000007;
long long mul(long long a, long long b) {
  long long q = (long long)((long double)a * (long double)b / (long double)mod);
  long long r = a * b - q * mod;
  return (r + 5 * mod) % mod;
}
long long binpow(long long a, long long n) {
  long long res = 1;
  while (n)
    if (n & 1) {
      res = mul(res, a);
      --n;
    } else {
      a = mul(a, a);
      n >>= 1;
    }
  return res;
}
int main() {
  scanf("%I64d%I64d", &n, &x);
  map<long long, long long> m;
  as = 0;
  for (i = 0; i < n; i++) scanf("%I64d", &a[i]), as += a[i];
  for (i = 0; i < n; i++) {
    p[i] = as - a[i];
    m[p[i]]++;
  }
  for (map<long long, long long>::iterator it = m.begin(); it != m.end();
       it++) {
    if (it->second / x) m[it->first + 1] += it->second / x;
    it->second %= x;
  }
  for (map<long long, long long>::iterator it = m.begin(); it != m.end(); it++)
    if (it->second) {
      cout << binpow(x, it->first);
      return 0;
    }
  cout << 1;
  return 0;
}
