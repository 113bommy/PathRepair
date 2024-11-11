#include <bits/stdc++.h>
using namespace std;
long long get() {
  long long x = 0, f = 1;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x * f;
}
const long long N = 405;
long long P, A[N], I[N], B[N][N], fac[N], inv[N];
long long qpow(long long x, long long y) {
  long long res = 1;
  while (y) res = res * ((y & 1) ? x : 1) % P, x = x * x % P, y >>= 1;
  return res;
}
void init(long long n) {
  fac[0] = 1;
  for (long long i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % P;
  inv[n] = qpow(fac[n], P - 2);
  for (long long i = n; i >= 1; i--) inv[i - 1] = inv[i] * i % P;
  I[1] = 1;
  for (long long i = 2; i <= n; i++) {
    I[i] = fac[i];
    for (long long j = 1; j < i; j++)
      I[i] = (I[i] - I[j] * fac[i - j] % P + P) % P;
  }
  B[0][0] = 1;
  for (long long i = 1; i <= n; i++)
    for (long long j = 1; j <= i; j++)
      for (long long k = 1; k <= i; k++)
        B[i][j] = (B[i][j] + B[i - k][j - 1] * fac[k] % P) % P;
  A[1] = 1, A[2] = A[3] = 0;
  for (long long i = 4; i <= n; i++) {
    A[i] = fac[i];
    long long sum1 = 0, sum2 = 0;
    for (long long j = 1; j < i; j++) sum1 = (sum1 + I[j] * fac[i - j] % P) % P;
    A[i] = (A[i] - sum1 * 2 % P + P) % P;
    for (long long j = 4; j < i; j++) sum2 = (sum2 + B[i][j] * A[j] % P) % P;
    A[i] = (A[i] - sum2 + P) % P;
  }
}
signed main() {
  long long T = get();
  P = get();
  init(400);
  while (T--) printf("%d\n", A[get()]);
  return 0;
}
