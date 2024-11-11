#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &x) {
  x = 0;
  char c = getchar(), f = 0;
  for (; c < '0' || c > '9'; c = getchar())
    if (c == '-') f = 1;
  for (; c >= '0' && c <= '9'; c = getchar())
    x = (x << 1) + (x << 3) + (c ^ 48);
  if (f) x = -x;
}
const long long P = 1e9 + 7;
long long T, m, y[1000005], fc[1000005], iv[1000005];
long long n;
inline long long ksm(long long x, long long q = P - 2) {
  long long r = 1;
  x %= P;
  for (; q; q >>= 1, x = 1ll * x * x % P)
    if (q & 1) r = 1ll * r * x % P;
  return r;
}
inline long long getk(long long v) {
  v %= P;
  long long res = 0, T = 1;
  if (v <= m + 3) return y[v];
  for (long long i = 1; i <= m + 3; i++) T = 1ll * T * (v - i + P) % P;
  for (long long i = 1; i <= m + 3; i++)
    (res += 1ll * y[i] * T % P * ksm(-1, m + 3 - i) * iv[i - 1] % P *
                iv[m + 3 - i] % P * ksm(v - i) % P +
            P) %= P;
  return (res + P) % P;
}
inline void init() {
  fc[0] = iv[0] = 1;
  for (long long i = 1; i <= 1000001; i++) fc[i] = 1ll * fc[i - 1] * i % P;
  iv[1000001] = ksm(fc[1000001]);
  for (long long i = 1000000; i; i--) iv[i] = 1ll * iv[i + 1] * (i + 1) % P;
}
signed main() {
  init(), read(n), read(m);
  for (long long i = 1; i <= m + 3; i++) y[i] = (y[i - 1] + ksm(i, m)) % P;
  return printf("%lld\n", getk(n)), 0;
}
