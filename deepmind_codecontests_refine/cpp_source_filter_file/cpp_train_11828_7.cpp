#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline T read() {
  T f = 0, x = 0;
  char c = getchar();
  while (!isdigit(c)) f = c == '-', c = getchar();
  while (isdigit(c)) x = x * 10 + c - 48, c = getchar();
  return f ? -x : x;
}
namespace run {
const int N = 1 << 18;
int n, K, mod;
inline int add(int x, int y) { return x + y >= mod ? x - mod + y : x + y; }
inline int sub(int x, int y) { return x >= y ? x - y : x + mod - y; }
inline int qpow(int x, int y) {
  int ret = 1;
  while (y) {
    if (y & 1) ret = 1LL * x * ret % mod;
    x = 1LL * x * x % mod, y >>= 1;
  }
  return ret;
}
int limit, bit;
inline void fwt_or(int *a, int inv) {
  for (int mid = 1; mid < limit; mid <<= 1)
    for (int i = 0; i < limit; i += (mid << 1))
      for (int j = 0; j < mid; j++)
        if (~inv)
          a[i + j + mid] = add(a[i + j], a[i + j + mid]);
        else
          a[i + j + mid] = sub(a[i + j + mid], a[i + j]);
}
int inv[N];
inline void Getln(int *a, int *b) {
  assert(a[0] == 1), b[0] = 0;
  for (int i = 0; i < bit; i++) {
    int sum = 1LL * (i + 1) * a[i + 1] % mod;
    for (int j = 0; j < i; j++)
      sum = sub(sum, 1LL * a[i - j] * (j + 1) % mod * b[j + 1] % mod);
    b[i + 1] = 1LL * sum * inv[i + 1] % mod;
  }
}
inline void Getexp(int *a, int *b) {
  assert(a[0] == 0), b[0] = 1;
  for (int i = 0; i < bit; i++) {
    int sum = 0;
    for (int j = 0; j <= i; j++)
      sum = (1LL * (j + 1) * a[j + 1] % mod * b[i - j] + sum) % mod;
    b[i + 1] = 1LL * sum * inv[i + 1] % mod;
  }
}
int ifac[N], g[19][N], count[N];
inline int dp() {
  limit = 1, bit = 0;
  while (limit <= n) limit <<= 1, bit++;
  inv[0] = inv[1] = ifac[0] = ifac[1] = 1;
  for (int i = 2; i < limit; i++)
    inv[i] = 1LL * (mod - mod / i) * inv[mod % i] % mod;
  for (int i = 2; i < limit; i++) ifac[i] = 1LL * inv[i] * ifac[i - 1] % mod;
  for (int i = 1; i < limit; i++) count[i] = count[i >> 1] + (i & 1);
  for (int i = 0; i < limit; i++) g[count[i]][i] = ifac[i];
  for (int i = 0; i <= bit; i++) fwt_or(g[i], 1);
  for (int s = 0; s < limit; s++) {
    int a[19], b[19];
    for (int i = 0; i <= bit; i++) a[i] = g[i][s];
    Getln(a, b);
    for (int i = 0; i <= bit; i++) b[i] = 1LL * b[i] * K % mod;
    Getexp(b, a);
    for (int i = 0; i <= bit; i++) g[i][s] = b[i];
  }
  fwt_or(g[count[n]], -1);
  int ret = g[count[n]][n];
  for (int i = 2; i <= n; i++) ret = 1LL * ret * i % mod;
  return ret;
}
int main() {
  n = read<int>(), K = read<int>(), mod = read<int>();
  if (n & 1)
    printf("%d\n", qpow(K, n));
  else
    printf("%d\n", sub(qpow(K, n), dp()));
  return 0;
}
}  // namespace run
int main() { return run::main(); }
