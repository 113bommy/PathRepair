#include <bits/stdc++.h>
using namespace std;
const int max_n = 1000005;
const long long mod = 998244353;
int n, k;
int w[max_n];
long long x1[max_n * 4];
long long x2[max_n * 4];
long long quick_pow(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a % mod;
    b >>= 1;
    a = a * a % mod;
  }
  return res;
}
void change(long long y[], int len) {
  int i, j, k;
  for (i = 1, j = len / 2; i < len - 1; i++) {
    if (i < j) swap(y[i], y[j]);
    k = len / 2;
    while (j >= k) j -= k, k /= 2;
    if (j < k) j += k;
  }
}
void ntt(long long y[], int len, int on) {
  change(y, len);
  for (int h = 2; h <= len; h <<= 1) {
    long long wn = quick_pow(3, (mod - 1) / h);
    if (on == -1) wn = quick_pow(wn, mod - 2);
    for (int j = 0; j < len; j += h) {
      long long w = 1;
      for (int k = j; k < j + h / 2; k++) {
        long long u = y[k];
        long long t = y[k + h / 2] * w % mod;
        y[k] = (u + t) % mod;
        y[k + h / 2] = (u - t + mod) % mod;
        w = w * wn % mod;
      }
    }
  }
  if (on == -1) {
    long long rlen = quick_pow(len, mod - 2);
    for (int i = 0; i < len; i++) y[i] = y[i] * rlen % mod;
  }
}
long long res[max_n * 4];
int len;
long long ans;
long long qntt(long long x1[], long long n) {
  res[0] = 1;
  ntt(x1, len, 1);
  ntt(res, len, 1);
  while (n) {
    if (n & 1)
      for (int i = 0; i < len; i++) res[i] = res[i] * x1[i] % mod;
    n >>= 1;
    for (int i = 0; i < len; i++) x1[i] = x1[i] * x1[i] % mod;
  }
  ntt(res, len, -1);
  for (int i = 0; i < len; i++) ans += res[i] * res[i] % mod, ans %= mod;
  return ans;
}
int main() {
  scanf("%d%d", &n, &k);
  int x;
  for (int i = 0; i < k; i++) {
    scanf("%d", &x);
    w[x] = 1;
  }
  n /= 2;
  len = 1;
  while (len - 1 < n * 9) len <<= 1;
  for (int i = 0; i <= 9; i++) x1[i] = w[i];
  ans = qntt(x1, n);
  printf("%lld\n", ans);
  return 0;
}
