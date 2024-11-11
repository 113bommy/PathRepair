#include <bits/stdc++.h>
template <typename T>
inline void read(T &x) {
  x = 0;
  char c = getchar();
  bool flag = false;
  while (!isdigit(c)) {
    if (c == '-') flag = true;
    c = getchar();
  }
  while (isdigit(c)) x = x * 10 + (c ^ 48), c = getchar();
  if (flag) x = -x;
}
using namespace std;
const int P = 1e9 + 7;
const int inv2 = (P + 1) / 2;
inline void ADD(long long &a, long long b) {
  a += b;
  if (a >= P) a -= P;
}
inline void DEC(long long &a, long long b) {
  a -= b;
  if (a < 0) a += P;
}
int n;
long long bin[201000], f[201000];
long long A[20][201000], PA[20][201000], B[201000], C[201000];
inline void FWT_OR(long long *f) {
  for (int i = 1; i < n; i <<= 1)
    for (int j = 0; j < n; j += (i << 1))
      for (int k = 0; k < i; ++k) ADD(f[i + j + k], f[j + k]);
}
inline void IFWT_OR(long long *f) {
  for (int i = 1; i < n; i <<= 1)
    for (int j = 0; j < n; j += (i << 1))
      for (int k = 0; k < i; ++k) DEC(f[i + j + k], f[j + k]);
}
inline void FWT_AND(long long *f) {
  for (int i = 1; i < n; i <<= 1)
    for (int j = 0; j < n; j += (i << 1))
      for (int k = 0; k < i; ++k) ADD(f[j + k], f[i + j + k]);
}
inline void IFWT_AND(long long *f) {
  for (int i = 1; i < n; i <<= 1)
    for (int j = 0; j < n; j += (i << 1))
      for (int k = 0; k < i; ++k) DEC(f[j + k], f[i + j + k]);
}
inline void FWT_XOR(long long *f) {
  for (int i = 1; i < n; i <<= 1)
    for (int j = 0; j < n; j += (i << 1))
      for (int k = 0; k < i; ++k) {
        int nx = f[j + k], ny = f[i + j + k];
        f[j + k] = (nx + ny) % P;
        f[i + j + k] = (nx - ny + P) % P;
      }
}
inline void IFWT_XOR(long long *f) {
  for (int i = 1; i < n; i <<= 1)
    for (int j = 0; j < n; j += (i << 1))
      for (int k = 0; k < i; ++k) {
        long long nx = f[j + k], ny = f[i + j + k];
        f[j + k] = (nx + ny) * inv2 % P;
        f[i + j + k] = (nx - ny + P) * inv2 % P;
      }
}
int siz[201000];
int main() {
  read(n);
  for (int i = 1; i <= n; ++i) {
    int x;
    read(x);
    ++bin[x];
  }
  n = (1 << 17);
  f[0] = 0, f[1] = 1;
  for (int i = 2; i < n; ++i) f[i] = (f[i - 1] + f[i - 2]) % P;
  siz[0] = 0;
  A[0][0] = bin[0];
  for (int i = 1; i < n; ++i)
    siz[i] = siz[i >> 1] + (i & 1), A[siz[i]][i] = bin[i];
  for (int i = 0; i < 17; ++i) FWT_OR(A[i]);
  memcpy(PA, A, sizeof(A));
  memset(A, 0, sizeof(A));
  for (int i = 16; ~i; --i) {
    for (int j = i; ~j; --j) {
      for (int s = 0; s < n; ++s) {
        A[i][s] = (A[i][s] + PA[j][s] * PA[i - j][s]) % P;
      }
    }
  }
  for (int i = 0; i < 17; ++i) IFWT_OR(A[i]);
  for (int i = 0; i < n; ++i) C[i] = A[siz[i]][i];
  memcpy(B, bin, sizeof(B));
  FWT_XOR(B);
  for (int i = 0; i < n; ++i) B[i] = B[i] * B[i] % P;
  IFWT_XOR(B);
  for (int i = 0; i < n; ++i) {
    C[i] = C[i] * f[i] % P, B[i] = B[i] * f[i] % P, bin[i] = bin[i] * f[i] % P;
  }
  FWT_AND(C);
  FWT_AND(B);
  FWT_AND(bin);
  for (int i = 0; i < n; ++i) B[i] = C[i] * B[i] % P * bin[i] % P;
  IFWT_AND(B);
  long long res = 0;
  for (int i = 1; i < n; i <<= 1) res += B[i];
  printf("%lld\n", (res % P + P) % P);
  return 0;
}
