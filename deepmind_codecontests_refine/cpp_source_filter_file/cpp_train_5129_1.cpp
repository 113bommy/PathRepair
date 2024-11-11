#include <bits/stdc++.h>
using namespace std;
const int N = 400005;
struct Complex {
  double r, i;
};
inline Complex operator+(const Complex &a, const Complex &b) {
  return {a.r + b.r, a.i + b.i};
}
inline Complex operator-(const Complex &a, const Complex &b) {
  return {a.r - b.r, a.i - b.i};
}
inline Complex operator*(const Complex &a, const Complex &b) {
  return {a.r * b.r - a.i * b.i, a.i * b.r + a.r * b.i};
}
int rev[N], lim;
const double PI = acos(-1);
void FFT(Complex a[], int n, int fl) {
  for (int i = 0; i < n; i++)
    if (i < rev[i]) swap(a[i], a[rev[i]]);
  for (int s = 1; s < n; s <<= 1) {
    Complex wn = {cos(PI / s), sin(PI / s) * fl};
    for (int i = 0; i < n; i += s << 1) {
      Complex w = {1, 0};
      for (int j = 0; j < s; j++, w = w * wn) {
        Complex x = a[i + j], y = w * a[i + s + j];
        a[i + j] = x + y;
        a[i + s + j] = x - y;
      }
    }
  }
  if (fl == -1)
    for (int i = 0; i < n; i++) a[i].r /= n, a[i].i /= n;
}
using ll = long long;
int n, m, qq, a[N], b[N];
ll v1[N], v2[N], e1[N], e2[N], f1[N], f2[N];
Complex f[N], g[N], h[N], d[N], e[N], q[N], a1[N], a2[N], a3[N], a4[N], a5[N],
    a6[N], a7[N];
inline void mul(Complex *a, Complex *b, Complex *c) {
  for (int i = 0; i < lim; i++) a[i] = b[i] * c[i];
  FFT(a, lim, -1);
}
inline ll I(double x) { return x + 0.5; }
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m >> qq;
  int mx = 0;
  for (int i = 1; i <= n; i++) cin >> a[i], ++f[a[i]].r, mx = max(mx, a[i]);
  for (int i = 1; i <= m; i++) cin >> b[i], ++g[b[i]].r, mx = max(mx, b[i]);
  int dd = 0;
  lim = 1;
  while (lim < mx * 2 + 3) lim <<= 1, ++dd;
  for (int i = 1; i < lim; i++)
    rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (dd - 1));
  for (int i = 2; i <= n; i++)
    ++h[min(a[i], a[i - 1])].r, ++e[max(a[i], a[i - 1])].r;
  for (int i = 2; i <= m; i++)
    ++d[min(b[i], b[i - 1])].r, ++q[max(b[i], b[i - 1])].r;
  FFT(f, lim, 1);
  FFT(g, lim, 1);
  FFT(h, lim, 1);
  FFT(d, lim, 1);
  FFT(e, lim, 1);
  FFT(q, lim, 1);
  mul(a1, f, g);
  mul(a2, f, d);
  mul(a3, g, h);
  mul(a4, f, q);
  mul(a5, g, e);
  mul(a6, h, d);
  mul(a7, e, q);
  for (int i = 0; i <= lim; i++) {
    v1[i] = I(a1[i].r);
    v2[i] = I(a1[i].r);
    e1[i] = I(a2[i].r) + I(a3[i].r);
    e2[i] = I(a4[i].r) + I(a5[i].r);
    f1[i] = I(a6[i].r);
    f2[i] = I(a7[i].r);
  }
  for (int i = lim - 1; i > 0; --i)
    v1[i - 1] += v1[i], e1[i - 1] += e1[i], f1[i - 1] += f1[i];
  for (int i = 1; i < lim; i++)
    v2[i] += v2[i - 1], e2[i] += e2[i - 1], f2[i] += f2[i - 1];
  while (qq--) {
    int x;
    cin >> x;
    cout << v1[x] - v2[x - 1] + f1[x] - f2[x - 1] - e1[x] + e2[x - 1] << endl;
  }
  return 0;
}
