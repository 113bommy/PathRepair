#include <bits/stdc++.h>
using namespace std;
long long Cnt(int n, long long a, long long b) {
  int i;
  long long rev = 0;
  long long res = 0;
  for (i = (n)-1; i >= (0); --i)
    if (a & (1LL << i)) {
      long long pref = b >> (n - i);
      long long suff = b & ((1LL << (n - i)) - 1);
      res += pref;
      if (rev < suff) ++res;
      rev |= 1LL << (n - 1 - i);
    }
  return res;
}
long long Sum(int n, long long a, long long b, long long mod) {
  int i;
  long long rev = 0;
  long long res = 0;
  for (i = (n)-1; i >= (0); --i)
    if (a & (1LL << i)) {
      long long pref = b >> (n - i);
      long long suff = b & ((1LL << (n - i)) - 1);
      long long x = pref;
      long long y = pref - 1;
      if (x & 1)
        y >>= 1;
      else
        x >>= 1;
      long long c = (x % mod) * (y % mod) % mod;
      res += c * ((1LL << (n - i)) % mod);
      res += (rev % mod) * (pref % mod);
      if (rev < suff) res += rev + (pref << (n - i));
      res %= mod;
      rev |= 1LL << (n - 1 - i);
    }
  return res;
}
long long F(long long n, long long mod, long long a, long long b) {
  int bits = 0;
  while ((1LL << bits) <= n) ++bits;
  long long Min = 0, Max = (1LL << bits);
  while (Max - Min > 1) {
    long long Mid = (Max + Min) >> 1;
    if (Cnt(bits, Mid, n) > b)
      Max = Mid;
    else
      Min = Mid;
  }
  return Cnt(bits, Min, a) + Sum(bits, Min, a, mod) % mod;
}
pair<long long, long long> G(long long n, long long mod, long long a,
                             long long b) {
  if (n == 0 || a == 0 || b == 0) return pair<long long, long long>(0, 0);
  if (n == 1 || a == 1 || b == 1) return pair<long long, long long>(1, 1);
  long long mid = (n + 1) >> 1;
  if (a < mid) {
    pair<long long, long long> res = G(mid, mod, a, (b + 1) >> 1);
    res.first = (res.first + res.first - (res.second % mod) + mod) % mod;
    return res;
  }
  long long x = min(mid, (b + 1) >> 1) % mod;
  pair<long long, long long> res = G(n - mid, mod, a - mid, b >> 1);
  res.first = (res.first + res.first + x * x) % mod;
  res.second += x;
  return res;
}
int main() {
  long long n;
  int m, mod;
  scanf("%lld%d%d", &n, &m, &mod);
  int i;
  for (i = (0); i < (m); ++i) {
    long long l, r, u, v;
    scanf("%lld%lld%lld%lld", &l, &r, &u, &v);
    u = min(n + 1, u);
    v = min(n, v);
    --l;
    --u;
    long long res = G(n, mod, l, u).first + G(n, mod, r, v).first -
                    G(n, mod, l, v).first - G(n, mod, r, u).first + mod + mod;
    printf("%d\n", int(res % mod));
  }
  return 0;
};
