#include <bits/stdc++.h>
using namespace std;
const int maxn = 1 << 17;
const int md = 1e9 + 7;
inline long long PowMod(long long a, long long b) {
  long long r = 1;
  while (b) {
    if (b & 1) r = r * a % md;
    a = a * a % md, b >>= 1;
  }
  return r;
}
inline int bitcnt(int x) {
  int r = 0;
  while (x) r += x & 1, x >>= 1;
  return r;
}
long long inv2 = PowMod(2, md - 2);
void FWT1(long long *a, int len, int type) {
  for (int l = 1; l < len; l <<= 1) {
    for (int i = 0; i < len; i += (l << 1))
      for (int k = 0; k < l; ++k) {
        long long x = a[i + k], y = a[i + k + l];
        if (type == 1) {
          a[i + k] = (x + y) % md;
          a[i + k + l] = (x - y + md) % md;
        } else {
          a[i + k] = (x + y) % md * inv2 % md;
          a[i + k + l] = (x - y + md) % md * inv2 % md;
        }
      }
  }
}
void FWT2(long long *a, int len, int type) {
  for (int l = 1; l < len; l <<= 1) {
    for (int i = 0; i < len; i += (l << 1))
      for (int k = 0; k < l; ++k) {
        long long x = a[i + k], y = a[i + k + l];
        if (type == 1)
          a[i + k] = (x + y) % md;
        else
          a[i + k] = (x - y + md) % md;
      }
  }
}
void FWT3(long long a[][18], int len, int type) {
  for (int l = 1; l < len; l <<= 1) {
    for (int i = 0; i < len; i += (l << 1))
      for (int k = 0; k < l; ++k) {
        for (int t = 0; t <= 17; ++t) {
          long long x = a[i + k][t], y = a[i + k + l][t];
          if (type == 1)
            a[i + k + l][t] = (x + y) % md;
          else
            a[i + k + l][t] = (y - x + md) % md;
        }
      }
  }
}
int n;
long long fib[maxn + 5], S[maxn + 5];
long long A[maxn + 5][18], B[maxn + 5], C[maxn + 5];
int main() {
  fib[0] = 0, fib[1] = 1;
  for (int i = 2; i < maxn; ++i) fib[i] = (fib[i - 1] + fib[i - 2]) % md;
  int a, len = maxn;
  long long buf[18];
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a), ++S[a];
  for (int i = 0; i < len; ++i) A[i][bitcnt(i)] = S[i];
  FWT3(A, len, 1);
  for (int i = 0; i < len; ++i) {
    memset(buf, 0, sizeof(buf));
    for (int k = 0; k <= 17; ++k)
      for (int j = 0; k + j <= 17; ++j)
        buf[k + j] = (buf[k + j] + A[i][k] * A[i][j]) % md;
    for (int k = 0; k <= 17; ++k) A[i][k] = buf[k];
  }
  FWT3(A, len, -1);
  for (int i = 0; i < len; ++i) B[i] = A[i][bitcnt(i)];
  for (int i = 0; i < len; ++i) C[i] = S[i];
  FWT1(C, len, 1);
  for (int i = 0; i < len; ++i) C[i] = C[i] * C[i] % md;
  FWT1(C, len, -1);
  for (int i = 0; i < len; ++i) {
    B[i] = B[i] * fib[i] % md;
    C[i] = C[i] * fib[i] % md;
    S[i] = S[i] * fib[i] % md;
  }
  FWT2(B, len, 1), FWT2(C, len, 1), FWT2(S, len, 1);
  for (int i = 0; i < len; ++i) B[i] = B[i] * C[i] % md * S[i] % md;
  FWT2(B, len, -1);
  long long ans = 0;
  for (int i = 0; i < 17; ++i) ans = (ans + B[1 << i]) % md;
  printf("%lld\n", ans);
  return 0;
}
