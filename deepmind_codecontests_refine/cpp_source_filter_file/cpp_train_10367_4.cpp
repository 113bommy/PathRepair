#include <bits/stdc++.h>
const long long N = 2e5 + 7, mo = 1e9 + 7;
long long f, w, h;
long long fac[N], inv[N];
long long qp(long long base, long long p) {
  long long res = 1;
  while (p) {
    if (p & 1) (res = res * base % mo);
    p >>= 1;
    base = (base * base % mo);
  }
  return res;
}
void pre() {
  fac[0] = 1;
  for (long long i = 1; i <= 200000; ++i) fac[i] = fac[i - 1] * i % mo;
  inv[200000] = qp(fac[200000], mo - 2);
  for (long long i = 199999; i >= 0; --i) inv[i] = inv[i + 1] * (i + 1) % mo;
}
inline long long C(long long x, long long y) {
  if (x < 0 || y < 0) return 0;
  if (x < y) return 0;
  return fac[x] * inv[y] % mo * inv[x - y] % mo;
}
inline long long hf(long long S, long long k) { return C(S - 1, k - 1); }
signed main() {
  std::cin >> f >> w >> h;
  if (w == 0) {
    puts("0");
    return 0;
  }
  if (f == 0) {
    if (h < w)
      puts("1");
    else
      puts("0");
    return 0;
  }
  pre();
  long long fz = 0, fm = 0;
  long long sum_w = 1, sum_f = 0;
  for (long long i = 2; i <= f + w; ++i) {
    if (i & 1)
      ++sum_w;
    else
      ++sum_f;
    (fm += hf(w, sum_w) * hf(f, sum_f) % mo) %= mo;
    (fz += hf(w - h * sum_w, sum_w) * hf(f, sum_f) % mo) %= mo;
  }
  sum_w = 0;
  sum_f = 1;
  for (long long i = 2; i <= f + w; ++i) {
    if (i & 1)
      ++sum_f;
    else
      ++sum_w;
    (fm += hf(w, sum_w) * hf(f, sum_f) % mo) %= mo;
    (fz += hf(w - h * sum_w, sum_w) * hf(f, sum_f) % mo) %= mo;
  }
  printf("%lld\n", fz * qp(fm, mo - 2) % mo);
  return 0;
}
