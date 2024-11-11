#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline bool upmin(T &x, T y) {
  return y < x ? x = y, 1 : 0;
}
template <typename T>
inline bool upmax(T &x, T y) {
  return x < y ? x = y, 1 : 0;
}
const long double eps = 1e-11;
const long double pi = acos(-1);
const int oo = 1 << 30;
const long long loo = 1ll << 62;
const int MAXN = 2000005;
const int INF = 0x3f3f3f3f;
inline long long read() {
  long long f = 1, x = 0;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 3) + (x << 1) + (c ^ 48);
    c = getchar();
  }
  return x * f;
}
long long Lim, invlim, e[MAXN], b[MAXN], c[MAXN], Ans[MAXN], m, t, mods;
long long upd(long long x, long long y) {
  return x + y >= mods ? x + y - mods : (x + y < 0 ? x + y + mods : x + y);
}
long long mul(long long x, long long y, long long mods) {
  long long tmp =
      (x * y - (long long)((long double)x / mods * y + 1.0e-8) * mods);
  return tmp < 0 ? tmp + mods : tmp;
}
long long quick_pow(long long x, long long y) {
  long long ret = 1;
  for (; y; y >>= 1) {
    if (y & 1) ret = mul(ret, x, mods);
    x = mul(x, x, mods);
  }
  return ret;
}
void Fwt_xor(long long *a, int Lim, int opt) {
  for (int l = 2; l <= Lim; l <<= 1)
    for (int j = 0, i = l >> 1; j < Lim; j += l)
      for (int k = j; k < j + i; k++) {
        long long x = a[k], y = a[k + i];
        a[k] = upd(x, y), a[k + i] = upd(x, -y);
      }
  if (opt != 1)
    for (int i = 0; i < Lim; i++) a[i] /= Lim;
}
int popcount(int x) {
  int cnt = 0;
  for (; x; x = x & (x - 1)) cnt++;
  return cnt;
}
int main() {
  m = read(), Lim = 1 << m, t = read(), mods = read() * Lim;
  for (int i = 0; i < Lim; i++) e[i] = read();
  for (int i = 0; i <= m; i++) b[i] = read();
  for (int i = 0; i < Lim; i++) c[i] = b[popcount(i)];
  Fwt_xor(e, Lim, 1), Fwt_xor(c, Lim, 1);
  for (int i = 0; i < Lim; i++) Ans[i] = quick_pow(c[i], t);
  for (int i = 0; i < Lim; i++) Ans[i] = mul(Ans[i], e[i], mods);
  Fwt_xor(Ans, Lim, -1);
  for (int i = 0; i < Lim; i++) printf("%lld\n", Ans[i]);
  return 0;
}
