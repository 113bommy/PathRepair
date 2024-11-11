#include <bits/stdc++.h>
using namespace std;
template <class t>
inline t read(t &x) {
  char c = getchar();
  bool f = 0;
  x = 0;
  while (!isdigit(c)) f |= c == '-', c = getchar();
  while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
  if (f) x = -x;
  return x;
}
template <class t>
inline void write(t x) {
  if (x < 0)
    putchar('-'), write(-x);
  else {
    if (x > 9) write(x / 10);
    putchar('0' + x % 10);
  }
}
const long long MOD = 998244353;
long long n, ton[3], a, ans, fact[1000005], finv[1000005], ffact[1000005],
    ffinv[1000005];
long long power(long long A, long long B) {
  A %= MOD;
  long long res = 1;
  while (B) {
    if (B & 1) {
      res = res * A % MOD;
    }
    B >>= 1;
    A = A * A % MOD;
  }
  return res;
}
signed main() {
  read(n);
  for (long long i = 1; i <= n; ++i) {
    read(a);
    ++ton[a];
  }
  fact[0] = 1;
  ffact[0] = ffact[1] = 1;
  for (long long i = 1; i <= n; ++i) {
    fact[i] = fact[i - 1] * i % MOD;
  }
  for (long long i = 2; i <= n; ++i) {
    ffact[i] = ffact[i - 2] * i % MOD;
  }
  finv[n] = power(fact[n], MOD - 2);
  ffinv[n] = power(ffact[n], MOD - 2);
  ffinv[n - 1] = power(ffact[n - 1], MOD - 2);
  for (long long i = n; i > 0; --i) {
    finv[i - 1] = finv[i] * i % MOD;
  }
  for (long long i = n; i > 1; --i) {
    ffinv[i - 2] = ffinv[i] * i % MOD;
  }
  for (long long i = 0; i <= ton[1] / 2; ++i) {
    (ans += fact[ton[1]] * finv[ton[1] - i - i] % MOD * ffinv[i + i] % MOD) %=
        MOD;
  }
  for (long long i = 0; i < ton[2]; ++i) {
    (ans *= n - i) %= MOD;
  }
  write(ans);
  return 0;
}
