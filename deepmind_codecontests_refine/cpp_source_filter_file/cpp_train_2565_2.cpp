#include <bits/stdc++.h>
using namespace std;
int r[524300], len, l, n, m;
long long f[100010], g[100010], fac[100010], ifac[100010];
long long A[524300], B[524300], C[524300], w[2][524300];
const long long p = 998244353, _g[2] = {3, 332748118};
long long pw(long long a, long long b) {
  long long ret = 1;
  while (b) {
    if (b & 1) ret = ret * a % p;
    a = a * a % p, b >>= 1;
  }
  return ret;
}
void modify(int x) {
  for (len = 1, l = 0; len <= x; len <<= 1, l++)
    ;
  for (int i = 0; i < len; i++) r[i] = (r[i >> 1] >> 1) | ((i & 1) << (l - 1));
}
void NTT(long long *x, int tp) {
  for (int i = 0; i < len; i++) {
    if (i < r[i]) swap(x[i], x[r[i]]);
  }
  for (int i = 2; i <= len; i <<= 1) {
    int m = i >> 1;
    for (long long *tmp = x; tmp != x + len; tmp += i) {
      for (int j = 0; j < m; j++) {
        long long t = w[tp][524288 / i * j] * tmp[m + j] % p;
        tmp[m + j] = (tmp[j] - t + p) % p;
        tmp[j] = (tmp[j] + t) % p;
      }
    }
  }
  if (tp) {
    long long ivln = pw(len, p - 2);
    for (int i = 0; i < len; i++) x[i] = x[i] * ivln % p;
  }
}
void init() {
  fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % p;
  ifac[n] = pw(fac[n], p - 2);
  for (int i = n - 1; ~i; i--) ifac[i] = ifac[i + 1] * (i + 1) % p;
  for (int i = 0; i < 2; i++) {
    w[i][0] = 1;
    long long wn = pw(_g[i], (p - 1) / 524288);
    for (int j = 1; j < 524288; j++) w[i][j] = w[i][j - 1] * wn % p;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin >> n >> m, init();
  for (int i = 0; i <= n; i++) cin >> f[i];
  modify(n * 2);
  for (int i = 0; i < len; i++) {
    A[i] = i <= n ? f[i] * fac[i] % p : 0;
    B[i] = i <= n ? ifac[n - i] : 0;
  }
  NTT(A, 0), NTT(B, 0);
  for (int i = 0; i < len; i++) C[i] = A[i] * B[i] % p;
  NTT(C, 1);
  for (int i = 0; i <= n; i++)
    g[i] = C[i + n] * ifac[i] % p * pw(pw(i + 1, m), p - 2) % p;
  for (int i = 0; i < len; i++)
    A[i] = i <= n ? g[i] * fac[i] % p * (i & 1 ? p - 1 : 1) % p : 0;
  NTT(A, 0);
  for (int i = 0; i < len; i++) C[i] = A[i] * B[i] % p;
  NTT(C, 1);
  for (int i = 0; i <= n; i++)
    cout << C[i + n] * ifac[i] % p * (i & 1 ? p - 1 : 1) % p << " ";
  return 0;
}
