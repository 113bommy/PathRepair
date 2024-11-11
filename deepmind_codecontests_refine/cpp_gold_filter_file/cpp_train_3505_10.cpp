#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e5 + 5;
int a[maxn], s[maxn];
long long f[maxn], g[maxn], h[maxn * 2];
class Fft {
 public:
  const double pi = acos(-1.0);
  struct cp {
    double a, b;
    cp operator+(const cp &o) const { return (cp){a + o.a, b + o.b}; }
    cp operator-(const cp &o) const { return (cp){a - o.a, b - o.b}; }
    cp operator*(const cp &o) const {
      return (cp){a * o.a - b * o.b, b * o.a + a * o.b};
    }
    cp operator*(const double &o) const { return (cp){a * o, b * o}; }
    cp operator!() const { return (cp){a, -b}; }
  } w[810000];
  int pos[810000];
  cp x[810000], y[810000], z[810000];
  void fft_init(int len) {
    int j = 0;
    while ((1 << j) < len) ++j;
    --j;
    for (int i = 0; i < len; i++) pos[i] = pos[i >> 1] >> 1 | ((i & 1) << j);
  }
  void fft(cp *x, int len, int sta) {
    for (int i = 0; i < len; i++)
      if (i < pos[i]) swap(x[i], x[pos[i]]);
    w[0] = {1, 0};
    for (int i = 2; i <= len; i <<= 1) {
      cp g = {cos(2 * pi / i), sin(2 * pi / i) * sta};
      for (int j = i >> 1; j >= 0; j -= 2) w[j] = w[j >> 1];
      for (int j = 1; j < i >> 1; j += 2) w[j] = w[j - 1] * g;
      for (int j = 0; j < len; j += i) {
        cp *a = x + j, *b = a + (i >> 1);
        for (int k = 0; k < i >> 1; k++) {
          cp o = b[k] * w[k];
          b[k] = a[k] - o;
          a[k] = a[k] + o;
        }
      }
    }
    if (sta == -1)
      for (int i = 0; i < len; i++) x[i].a /= len, x[i].b /= len;
  }
  void FFT(long long *a, long long *b, int n, int m, long long *c) {
    int len = 1;
    while (len <= (n + m) >> 1) len <<= 1;
    fft_init(len);
    for (int i = (n >> 1); i < len; i++) x[i].a = x[i].b = 0;
    for (int i = (m >> 1); i < len; i++) y[i].a = y[i].b = 0;
    for (int i = 0; i < n; i++) (i & 1 ? x[i >> 1].b : x[i >> 1].a) = a[i];
    for (int i = 0; i < m; i++) (i & 1 ? y[i >> 1].b : y[i >> 1].a) = b[i];
    fft(x, len, 1);
    fft(y, len, 1);
    for (int i = 0; i < (len >> 1); i++) {
      int j = len - 1 & len - i;
      z[i] = x[i] * y[i] -
             (x[i] - !x[j]) * (y[i] - !y[j]) * (w[i] + (cp){1, 0}) * 0.25;
    }
    for (int i = (len >> 1); i < len; i++) {
      int j = len - 1 & len - i;
      z[i] = x[i] * y[i] - (x[i] - !x[j]) * (y[i] - !y[j]) *
                               ((cp){1, 0} - w[i ^ len >> 1]) * 0.25;
    }
    fft(z, len, -1);
    for (int i = 0; i < n + m; i++) {
      if (i & 1)
        c[i] = (long long)(z[i >> 1].b + 0.5);
      else
        c[i] = (long long)(z[i >> 1].a + 0.5);
    }
  }
} T;
int main() {
  int n, x;
  scanf("%d%d", &n, &x);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    if (a[i] < x)
      a[i] = 1;
    else
      a[i] = 0;
  }
  s[0] = 0, f[0] = 1;
  for (int i = 1; i <= n; i++) {
    s[i] = s[i - 1] + a[i];
    f[s[i]]++;
  }
  for (int i = 0; i <= n; i++) g[i] = f[n - i];
  T.FFT(f, g, 2 * n, 2 * n, h);
  printf("%lld", (long long)floor(1.0 * (h[n] - n - 1) / 2));
  for (int i = n + 1; i <= 2 * n; i++) printf(" %lld", h[i]);
  puts("");
  return 0;
}
