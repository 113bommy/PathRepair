#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
const int INF = 0x3f3f3f3f;
const long long INFF = 0x3f3f3f3f3f3f3f3fll;
const int MAX = 1 << (17) | 5;
const int MOD = 1e9 + 7;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
template <typename T>
inline T abs(T a) {
  return a > 0 ? a : -a;
}
template <class T>
inline void read(T &num) {
  bool start = false, neg = false;
  char c;
  num = 0;
  while ((c = getchar()) != EOF) {
    if (c == '-')
      start = neg = true;
    else if (c >= '0' && c <= '9') {
      start = true;
      num = num * 10 + c - '0';
    } else if (start)
      break;
  }
  if (neg) num = -num;
}
inline int powMM(int a, int b, int M) {
  int ret = 1;
  a %= M;
  while (b) {
    if (b & 1) ret = 1LL * ret * a % M;
    b >>= 1;
    a = 1LL * a * a % M;
  }
  return ret;
}
namespace {
inline int add(int x, int y) {
  x += y;
  if (x >= MOD) x -= MOD;
  return x;
}
inline void addi(int &x, int y) {
  x += y;
  if (x >= MOD) x -= MOD;
}
inline int mul(int x, int y) {
  long long re = 1LL * x * y;
  if (re >= MOD) re %= MOD;
  return re;
}
inline void muli(int &x, int y) { x = 1LL * x * y % MOD; }
inline int sub(int x, int y) {
  int res = x - y;
  if (res < 0) res += MOD;
  return res;
}
inline void subi(int &x, int y) {
  x -= y;
  if (x < 0) x += MOD;
}
inline int half(int x) { return x & 1 ? (x + MOD) >> 1 : x >> 1; }
}  // namespace
int n, lim, da;
inline void FMT(int *x) {
  for (int i = 1; i < lim; i <<= 1)
    for (int j = 0; j < lim; ++j)
      if (j & i) addi(x[j], x[j ^ i]);
}
inline void IFMT(int *x) {
  for (int i = 1; i < lim; i <<= 1)
    for (int j = 0; j < lim; ++j)
      if (j & i) subi(x[j], x[j ^ i]);
}
inline void FWTand(int *x) {
  for (int i = 1; i < lim; i <<= 1)
    for (int j = 0; j < lim; j += (i << 1))
      for (int k = 0; k < i; ++k) addi(x[j + k], x[j + k + i]);
}
inline void IFWTand(int *x) {
  for (int i = 1; i < lim; i <<= 1)
    for (int j = 0; j < lim; j += (i << 1))
      for (int k = 0; k < i; ++k) subi(x[j + k], x[j + k + i]);
}
inline void FWTxor(int *x) {
  for (int i = 1; i < lim; i <<= 1)
    for (int j = 0; j < lim; j += (i << 1))
      for (int k = 0; k < i; ++k) {
        int y = x[j + k], z = x[j + k + i];
        x[j + k] = add(y, z), x[j + k + i] = sub(y, z);
      }
}
inline void IFWTxor(int *x) {
  for (int i = 1; i < lim; i <<= 1)
    for (int j = 0; j < lim; j += (i << 1))
      for (int k = 0; k < i; ++k) {
        int y = x[j + k], z = x[j + k + i];
        x[j + k] = half(add(y, z)), x[j + k + i] = half(sub(y, z));
      }
}
int cnt[MAX], fib[MAX];
int a[MAX], b[20][MAX], c[20][MAX], d[MAX], e[MAX], f[MAX], g[MAX];
int main() {
  for (int i = 1; i < MAX; i++) cnt[i] = __builtin_popcount(i);
  fib[1] = 1;
  for (int i = 2; i < MAX; i++) fib[i] = add(fib[i - 1], fib[i - 2]);
  read(n);
  for (int i = 0, x; i < n; i++) {
    read(x);
    ++a[x];
    ++e[x];
    da = max(da, x);
  }
  for (n = lim = 1; lim <= da; lim <<= 1, ++n)
    ;
  for (int i = 0; i < lim; i++) b[cnt[i]][i] = a[i];
  for (int i = 0; i < n; i++) FMT(b[i]);
  for (int i = 0; i < n; i++)
    for (int j = 0; i + j < n; ++j)
      for (int k = 0; k < lim; k++) addi(c[i + j][k], mul(b[i][k], b[j][k]));
  for (int i = 0; i < n; i++) IFMT(c[i]);
  for (int i = 0; i < lim; i++) d[i] = c[cnt[i]][i];
  FWTxor(a);
  for (int i = 0; i < lim; i++) f[i] = mul(a[i], a[i]);
  IFWTxor(f);
  for (int i = 0; i < lim; i++) {
    d[i] = mul(d[i], fib[i]);
    e[i] = mul(e[i], fib[i]);
    f[i] = mul(f[i], fib[i]);
  }
  FWTand(d);
  FWTand(e);
  FWTand(f);
  for (int i = 0; i < lim; i++) g[i] = mul(d[i], mul(e[i], f[i]));
  IFWTand(g);
  int ans = 0;
  for (int i = 0; i < n; i++) addi(ans, g[1 << i]);
  printf("%d\n", ans);
  return 0;
}
