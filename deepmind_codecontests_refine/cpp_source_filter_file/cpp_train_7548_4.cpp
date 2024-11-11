#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5, P = 1e9 + 7, M = 32768;
const double pi = acos(-1);
struct cp {
  long double x, y;
  inline cp() {}
  inline cp(long double _x, long double _y) : x(_x), y(_y) {}
  inline cp friend operator+(const cp &a, const cp &b) {
    return cp(a.x + b.x, a.y + b.y);
  }
  inline cp friend operator-(const cp &a, const cp &b) {
    return cp(a.x - b.x, a.y - b.y);
  }
  inline cp friend operator*(const cp &a, const cp &b) {
    return cp(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x);
  }
} a[maxn], b[maxn], a1[maxn], a2[maxn], b1[maxn], b2[maxn], c1[maxn], c2[maxn],
    c3[maxn];
int k, Ans, N = 1, len;
long long n;
int fac[maxn], facinv[maxn], inv[maxn], tmp[maxn], ans[maxn];
int power(int x, long long t) {
  int ret = 1;
  for (; t; t >>= 1, x = 1LL * x * x % P)
    if (t & 1) ret = 1LL * ret * x % P;
  return ret;
}
void FFT(cp *a, int f) {
  for (int i = 0; i < N; ++i) {
    int t = 0;
    for (int j = 0; j < len; ++j)
      if (i >> j & 1) t |= 1 << (len - j - 1);
    if (i < t) swap(a[i], a[t]);
  }
  for (int l = 2; l <= N; l <<= 1) {
    int m = l >> 1;
    cp w = cp(cos(pi / m), f * sin(pi / m));
    for (int i = 0; i < N; i += l) {
      cp t = cp(1, 0);
      for (int k = 0; k < m; ++k, t = t * w) {
        cp x = a[i + k], y = t * a[i + m + k];
        a[i + k] = x + y;
        a[i + m + k] = x - y;
      }
    }
  }
}
void mul(int *a, int w) {
  int c = 1;
  for (int i = 0; i <= k; ++i) a[i] = 1LL * a[i] * c % P, c = 1LL * c * w % P;
}
void mul(int *a, int *b, int *ret) {
  for (int i = 0; i < N; ++i) {
    a1[i] = cp(a[i] % M, 0);
    a2[i] = cp(a[i] / M, 0);
    b1[i] = cp(b[i] % M, 0);
    b2[i] = cp(b[i] / M, 0);
  }
  FFT(a1, 1);
  FFT(a2, 1);
  FFT(b1, 1);
  FFT(b2, 1);
  for (int i = 0; i < N; ++i) {
    c1[i] = a1[i] * b1[i];
    c3[i] = a2[i] * b2[i];
    c2[i] = (a1[i] + a2[i]) * (b1[i] + b2[i]) - c1[i] - c3[i];
  }
  FFT(c1, -1);
  FFT(c2, -1);
  FFT(c3, -1);
  for (int i = 0; i <= k; ++i) {
    int x = (long long)(c1[i].x / N + 0.5) % P;
    int y = (long long)(c2[i].x / N + 0.5) % P;
    int z = (long long)(c3[i].x / N + 0.5) % P;
    ret[i] = (1LL * z * M * M + 1LL * y * M % P + x) % P;
  }
}
void solve(long long n) {
  if (!n)
    ans[0] = 1;
  else if (n & 1) {
    solve(n - 1);
    tmp[0] = 0;
    for (int i = 1; i <= k; ++i) tmp[i] = facinv[i];
    mul(tmp, power(2, n - 1));
    mul(ans, tmp, ans);
  } else {
    solve(n / 2);
    for (int i = 0; i <= k; ++i) tmp[i] = ans[i];
    mul(tmp, power(2, n / 2));
    mul(ans, tmp, ans);
  }
}
int main() {
  scanf("%lld%d", &n, &k);
  inv[0] = 1;
  inv[1] = 1;
  facinv[0] = 1;
  fac[0] = 1;
  for (int i = 1; i <= k; ++i) {
    if (i != 1) inv[i] = 1LL * (P - P / i) * inv[P % i] % P;
    facinv[i] = 1LL * facinv[i - 1] * inv[i] % P;
    fac[i] = 1LL * fac[i - 1] * i % P;
  }
  while (N <= 2 * k + 2) N <<= 1, ++len;
  solve(n);
  for (int i = 1; i <= k; ++i)
    Ans = (Ans + 1LL * ans[i] * fac[k] % P * facinv[k - i] % P) % P;
  printf("%d\n", Ans);
  return 0;
}
