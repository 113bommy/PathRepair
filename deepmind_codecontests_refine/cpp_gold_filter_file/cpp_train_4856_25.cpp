#include <bits/stdc++.h>
#pragma GCC optimize(3, "Ofast", "inline")
using namespace std;
bool Finish_read;
template <class T>
inline void read(T &x) {
  Finish_read = 0;
  x = 0;
  int f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    if (ch == EOF) return;
    ch = getchar();
  }
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  x *= f;
  Finish_read = 1;
}
template <class T>
inline void print(T x) {
  if (x / 10 != 0) print(x / 10);
  putchar(x % 10 + '0');
}
template <class T>
inline void writeln(T x) {
  if (x < 0) putchar('-');
  x = abs(x);
  print(x);
  putchar('\n');
}
template <class T>
inline void write(T x) {
  if (x < 0) putchar('-');
  x = abs(x);
  print(x);
}
const int Fmaxn = (1 << 17) + 5, mod = 1e9 + 7;
int cnt[Fmaxn], A[Fmaxn], B[18][Fmaxn], C[18][Fmaxn], D[Fmaxn], E[Fmaxn],
    F[Fmaxn], G[Fmaxn], n, lim, mx, fib[Fmaxn];
namespace {
inline int Add(const int &x, const int &y) {
  int res = x + y;
  if (res >= mod) res -= mod;
  return res;
}
inline int Sub(const int &x, const int &y) {
  int res = x - y;
  if (res < 0) res += mod;
  return res;
}
inline int Mul(const int &x, const int &y) { return 1ll * x * y % mod; }
inline int Half(const int &x) { return x & 1 ? x + mod >> 1 : x >> 1; }
}  // namespace
inline void FMT(int *x) {
  for (int i = 1; i < lim; i <<= 1)
    for (int j = 0; j < lim; ++j)
      if (j & i) x[j] = Add(x[j], x[j ^ i]);
}
inline void IFMT(int *x) {
  for (int i = 1; i < lim; i <<= 1)
    for (int j = 0; j < lim; ++j)
      if (j & i) x[j] = Sub(x[j], x[j ^ i]);
}
inline void FWTand(int *x) {
  for (int i = 1; i < lim; i <<= 1)
    for (int j = 0; j < lim; j += (i << 1))
      for (int k = 0; k < i; ++k) x[j + k] = Add(x[j + k], x[j + k + i]);
}
inline void IFWTand(int *x) {
  for (int i = 1; i < lim; i <<= 1)
    for (int j = 0; j < lim; j += (i << 1))
      for (int k = 0; k < i; ++k) x[j + k] = Sub(x[j + k], x[j + k + i]);
}
inline void FWTxor(int *x) {
  for (int i = 1; i < lim; i <<= 1)
    for (int j = 0; j < lim; j += (i << 1))
      for (int k = 0; k < i; ++k) {
        int y = x[j + k], z = x[j + k + i];
        x[j + k] = Add(y, z), x[j + k + i] = Sub(y, z);
      }
}
inline void IFWTxor(int *x) {
  for (int i = 1; i < lim; i <<= 1)
    for (int j = 0; j < lim; j += (i << 1))
      for (int k = 0; k < i; ++k) {
        int y = x[j + k], z = x[j + k + i];
        x[j + k] = Half(Add(y, z)), x[j + k + i] = Half(Sub(y, z));
      }
}
int main() {
  for (int i = 1; i < Fmaxn; ++i) cnt[i] = __builtin_popcount(i);
  fib[1] = 1;
  for (int i = 2; i < Fmaxn; ++i) fib[i] = Add(fib[i - 1], fib[i - 2]);
  read(n);
  for (int i = 0, x; i < n; ++i) read(x), mx = max(mx, x), A[x]++, E[x]++;
  for (n = lim = 1; lim <= mx; n++, lim <<= 1)
    ;
  for (int i = 0; i < lim; ++i) B[cnt[i]][i] = A[i];
  for (int i = 0; i < n; ++i) FMT(B[i]);
  for (int i = 0; i < n; ++i)
    for (int j = 0; i + j < n; ++j)
      for (int k = 0; k < lim; ++k)
        C[i + j][k] = Add(C[i + j][k], Mul(B[i][k], B[j][k]));
  for (int i = 0; i < n; ++i) IFMT(C[i]);
  for (int i = 0; i < lim; ++i) D[i] = C[cnt[i]][i];
  FWTxor(A);
  for (int i = 0; i < lim; ++i) F[i] = Mul(A[i], A[i]);
  IFWTxor(F);
  for (int i = 0; i < lim; ++i)
    D[i] = Mul(D[i], fib[i]), E[i] = Mul(E[i], fib[i]),
    F[i] = Mul(F[i], fib[i]);
  FWTand(D), FWTand(E), FWTand(F);
  for (int i = 0; i < lim; ++i) G[i] = Mul(D[i], Mul(E[i], F[i]));
  IFWTand(G);
  int ans = 0;
  for (int i = 0; i < n; ++i) ans = Add(ans, G[1 << i]);
  printf("%d\n", ans);
}
