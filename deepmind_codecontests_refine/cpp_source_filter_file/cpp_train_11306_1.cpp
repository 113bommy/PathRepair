#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
void change(complex<double> y[], int n) {
  for (int i = 1, j = n >> 1; i < n - 1; i++) {
    if (i < j) swap(y[i], y[j]);
    int k = n / 2;
    while (j >= k) {
      j -= k;
      k >>= 1;
    }
    if (j < k) j += k;
  }
}
void fft(complex<double> y[], int n, int sgn = 1) {
  change(y, n);
  for (int h = 2; h <= n; h <<= 1) {
    complex<double> wn(cos(-sgn * 2 * PI / h), sin(-sgn * 2 * PI / h));
    for (int j = 0; j < n; j += h) {
      complex<double> w(1, 0);
      for (int k = j; k < j + h / 2; k++) {
        complex<double> u = y[k];
        complex<double> t = w * y[k + h / 2];
        y[k] = u + t;
        y[k + h / 2] = u - t;
        w = w * wn;
      }
    }
  }
  if (sgn == -1)
    for (int i = 0; i < n; i++) y[i].real(y[i].real() / n);
}
const int N = 1 << 21;
int n, c[N];
char str1[N], str2[N];
complex<double> x1[N], x2[N];
void init() { memset(c, 0, sizeof(c)); }
int a1[N], b1[N];
int get_fft(int *a1, int *b1, int len1, int len2, int *c) {
  int d = 1;
  while (d < len1 * 2 || d < len2 * 2) d <<= 1;
  int tmp = 0;
  for (int i = 0; i < len1; i++) x1[tmp++] = complex<double>(a1[i], 0);
  for (int i = len1; i < d; i++) x1[i] = complex<double>(0, 0);
  tmp = 0;
  for (int i = 0; i < len2; i++) x2[tmp++] = complex<double>(b1[i], 0);
  for (int i = len2; i < d; i++) x2[i] = complex<double>(0, 0);
  fft(x1, d);
  fft(x2, d);
  for (int i = 0; i < d; i++) x1[i] = x1[i] * x2[i];
  fft(x1, d, -1);
  for (int i = 0; i < d; i++) c[i] = (int)(x1[i].real() + 0.5);
  d = len1 + len2 - 1;
  while (c[d] == 0 && d > 0) d--;
  return d + 1;
}
int a[N], b[N], ans[N], cnt, res[N];
char str[N];
int main() {
  int T, n, i, j, lena, lenb;
  scanf("%d", &T);
  while (T--) {
    cnt = 0;
    scanf("%d%s", &n, str);
    for (i = 1; i <= n; i++) res[i] = 1;
    for (i = 0; i <= n; i++) c[3 * i] = 0, c[3 * i + 1], c[3 * i + 2] = 0;
    for (i = 0; i < n; i++) {
      if (str[i] == 'K')
        a[i] = 1;
      else
        a[i] = 0;
      if (str[i] == 'V')
        b[n - i - 1] = 1;
      else
        b[n - i - 1] = 0;
    }
    get_fft(a, b, n + 1, n + 1, c);
    for (i = 0; i < n; i++) {
      if (c[n - i - 1] || c[n + i - 1]) res[i] = 0;
    }
    for (i = 1; i <= n; i++) {
      if (res[i])
        for (j = i * 2; j <= n; j += i) {
          res[i] &= res[j];
        }
      if (res[i]) ans[cnt++] = i;
    }
    printf("%d\n", cnt);
    for (i = 0; i < cnt; i++) {
      printf("%d ", ans[i]);
    }
    printf("\n");
  }
}
