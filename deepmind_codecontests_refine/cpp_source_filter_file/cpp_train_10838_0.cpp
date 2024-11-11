#include <bits/stdc++.h>
using namespace std;
const int M = 6e5 + 10, P = 490019;
const double PI = acos(-1.0);
int a[M << 1], b[M << 1], c[M << 1], pw[M], inv[M], C[M << 1], oo, n, m, cc,
    r[M << 1], N, l;
struct cp {
  double x, y;
  cp(double _x = 0, double _y = 0) : x(_x), y(_y) {}
} p[M << 1], q[M << 1], w[M << 1], x[M << 1], y[M << 1], u[M << 1], v[M << 1];
inline cp operator+(cp a, cp b) { return cp(a.x + b.x, a.y + b.y); }
inline cp operator-(cp a, cp b) { return cp(a.x - b.x, a.y - b.y); }
inline cp operator*(cp a, cp b) {
  return cp(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x);
}
inline cp operator!(cp a) { return cp(a.x, -a.y); }
void fft(cp *a) {
  for (int i = (0); i <= (N - 1); ++i)
    if (i < r[i]) swap(a[i], a[r[i]]);
  for (int mid = 1; mid < N; mid <<= 1)
    for (int R = mid << 1, j = 0; j < N; j += R) {
      cp *l = a + j, *r = a + j + mid, y;
      for (int k = 0; k < mid; ++k, ++l, ++r)
        y = (*r) * w[N / 2 / mid * k], *r = *l - y, *l = *l + y;
    }
}
void conv(int *a, int *b, int *c, int n, int m) {
  cp _u(0.5, 0), _v(0, -0.5), I(0, 1);
  for (N = 1, l = 0; N < n + m; N <<= 1, ++l)
    ;
  for (int i = (0); i <= (N - 1); ++i)
    r[i] = i & 1 ? r[i ^ 1] | (1 << l - 1) : r[i >> 1] >> 1,
    w[i] = cp(cos(2 * PI * i / N), sin(2 * PI * i / N)),
    p[i] = cp(a[i] >> 15, a[i] & 0x7fff), q[i] = cp(b[i] >> 15, b[i] & 0x7fff);
  fft(p);
  fft(q);
  for (int i = (0); i <= (N - 1); ++i) {
    int j = i ? N - i : 0;
    cp k1 = (p[i] + !p[j]) * _u, k2 = (q[i] + !q[j]) * _u,
       b1 = (p[i] - !p[j]) * _v, b2 = (q[i] - !q[j]) * _v;
    x[j] = k1 * k2, y[j] = k1 * b2, u[j] = b1 * k2, v[j] = b1 * b2;
  }
  for (int i = (0); i <= (N - 1); ++i)
    p[i] = x[i] + y[i] * I, q[i] = u[i] + v[i] * I;
  fft(p);
  fft(q);
  for (int i = (0); i <= (N - 1); ++i) {
    long long x = (long long)(p[i].x / N + 0.5) % P,
              y = (long long)(p[i].y / N + 0.5) % P,
              u = (long long)(q[i].x / N + 0.5) % P,
              v = (long long)(q[i].y / N + 0.5) % P;
    c[i] = ((x << 30) + (y + u << 15) + v) % P;
  }
}
int main() {
  scanf("%d%d%d", &n, &m, &cc);
  pw[0] = inv[1] = 1;
  for (int i = (0); i <= (n - 1); ++i)
    scanf("%d", &oo), a[i * i % (P - 1)] += oo;
  for (int i = (0); i <= (m - 1); ++i)
    scanf("%d", &oo), b[1ll * i * i * i % (P - 1)] += oo;
  for (int i = (1); i <= (P - 1); ++i) pw[i] = 1ll * pw[i - 1] * cc % P;
  for (int i = (0); i <= (2 * P - 4); ++i)
    C[i] = 1ll * i * (i - 1) / 2 % (P - 1);
  for (int i = (2); i <= (P - 1); ++i)
    inv[i] = 1ll * (P - P / i) * inv[P % i] % P;
  for (int i = (0); i <= (P - 2); ++i)
    a[i] = 1ll * a[i] * inv[pw[C[i]]] % P,
    b[i] = 1ll * b[i] * inv[pw[C[i]]] % P;
  conv(a, b, c, P - 2, P - 2);
  long long ans = 0;
  for (int i = (0); i <= (2 * P - 4); ++i) ans += 1ll * c[i] * pw[C[i]] % P;
  printf("%lld\n", ans % P);
  return 0;
}
