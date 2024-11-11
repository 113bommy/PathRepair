#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
const int M = 1 << 19;
const char ADN[] = {'A', 'T', 'G', 'C'};
const double PI = 3.14159265358979323846;
int m, n, k, a[M], b[M], c[M];
char s[N + 1], t[N + 1];
complex<double> f1[M], f2[M];
void enter() {
  scanf("%d %d %d\n", &m, &n, &k);
  gets(s);
  gets(t);
}
template <typename num>
void fft(const num *x, int step, complex<double> *y, int n, bool inv = 0) {
  if (n == 1) {
    *y = *x;
    return;
  }
  int m = n >> 1;
  fft(x, step << 1, y, m, inv);
  fft(x + step, step << 1, y + m, m, inv);
  complex<double> w = 1, wlen = polar(1.0, (inv ? -1 : 1) * 2 * PI / n), t1, t2;
  for (int i = 0, j = m; j < n; ++i, ++j) {
    t1 = y[i] + w * y[j];
    t2 = y[i] - w * y[j];
    if (inv) t1 /= 2, t2 /= 2;
    y[i] = t1;
    y[j] = t2;
    w *= wlen;
  }
}
void mul_poly(const int *a, const int *b, int *c, int n) {
  fft(a, 1, f1, n);
  fft(b, 1, f2, n);
  for (int i = 0; i < n; ++i) f1[i] *= f2[i];
  fft(f1, 1, f2, n, true);
  for (int i = 0; i < n; ++i) c[i] += int(f2[i].real() + 0.5);
}
int convert_pow2(int x) {
  int r = 1;
  while (r < x) r <<= 1;
  return r;
}
void translate(const char *s, int *a, int n, int rad, char ch) {
  memset(a, 0, sizeof(int) * n);
  n = strlen(s);
  if (!rad) {
    for (int i = 0; i < n; ++i) a[i] = s[i] == ch;
    return;
  }
  list<int> lis;
  for (int i = 0; i < n; ++i)
    if (s[i] == ch) lis.push_back(i);
  list<int>::iterator it = lis.begin();
  for (int i = 0, l = i - rad, r = i + rad; i < n; ++i, ++l, ++r) {
    while (it != lis.end() && *it < l) ++it;
    a[i] = it != lis.end() && *it <= r;
  }
}
void print() {
  int res = 0;
  for (int i = m - 1; i; --i)
    if (c[i] == n) ++res;
  cout << res;
}
int main() {
  enter();
  int mn = convert_pow2(n + m);
  for (int i = 0; i < 4; ++i) {
    char ch = ADN[i];
    translate(s, a, mn, k, ch);
    translate(t, b, mn, 0, ch);
    reverse(a, a + m);
    mul_poly(a, b, c, mn);
  }
  print();
}
