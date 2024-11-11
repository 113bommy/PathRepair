#include <bits/stdc++.h>
using namespace std;
long long T, n, bin[70000], m;
const long long p = 998244353, yg = 3;
long long pow(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % p;
    a = a * a % p;
    b >>= 1;
  }
  return ans;
}
long long g[70000], f[70000], N;
void ntt(long long *a, long long n, long long op) {
  for (long long i = 0; i < n; i++)
    bin[i] = (bin[i >> 1] >> 1) | ((i & 1) * (n >> 1));
  for (long long i = 0; i < n; i++)
    if (i < bin[i]) swap(a[i], a[bin[i]]);
  for (long long i = 1; i < n; i <<= 1) {
    long long wn = pow(yg, op == 1 ? (p - 1) / (2 * i)
                                   : (p - 1) - (p - 1) / (2 * i)),
              w, t;
    for (long long j = 0; j < n; j += i << 1) {
      w = 1;
      for (long long k = 0; k < i; k++) {
        t = a[i + j + k] * w % p;
        w = w * wn % p;
        a[i + j + k] = (a[j + k] - t + p) % p;
        a[j + k] = (a[j + k] + t) % p;
      }
    }
  }
  if (op == -1) {
    long long Inv = pow(n, p - 2);
    for (long long i = 0; i < n; i++) a[i] = a[i] * Inv % p;
  }
}
long long A[70000], B[70000];
long long t1[70000], t2[70000], t3[70000];
void mul() {
  for (long long i = 0; i < N; i++) A[i] = B[i] = 0;
  for (long long i = 0; i <= m; i++) A[i] = g[i], B[i] = f[i];
  ntt(A, N, 1);
  ntt(B, N, 1);
  for (long long i = 0; i < N; i++)
    t1[i] = A[i] * A[i] % p, t2[i] = B[i] * B[i] % p,
    t3[i] = A[i] * B[i] * 2 % p;
  ntt(t1, N, -1);
  ntt(t2, N, -1);
  ntt(t3, N, -1);
  for (long long i = 1; i <= m; i++)
    g[i] = (t1[i] + t2[i - 1]) % p,
    f[i] = (t3[i] - t2[i - 1] - t2[i] + p + p) % p;
}
void insert() {
  for (long long i = m; i >= 1; i--)
    f[i] = g[i], g[i] = (g[i] + f[i - 1] + g[i - 1]) % p;
  f[0] = g[0] = 1;
}
int main() {
  scanf("%lld %lld", &n, &m);
  N = 1;
  while (N <= 2 * m) N <<= 1;
  long long b = 0;
  g[0] = 1;
  for (long long i = 1 << 30; i; i >>= 1) {
    if (b) mul(), b <<= 1;
    if (n & i) insert(), b |= 1;
  }
  for (long long i = 1; i <= m; i++) printf("%lld ", g[i]);
}
