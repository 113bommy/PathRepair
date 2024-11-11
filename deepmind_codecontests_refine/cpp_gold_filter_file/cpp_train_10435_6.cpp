#include <bits/stdc++.h>
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
} x[1 << 18], y[1 << 18], z[1 << 18], w[1 << 18];
void fft(cp x[], int k, int v) {
  for (int i = 0, j = 0; i < k; i++) {
    if (i > j) std::swap(x[i], x[j]);
    for (int l = k >> 1; (j ^= l) < l; l >>= 1)
      ;
  }
  w[0] = (cp){1, 0};
  for (int i = 2; i <= k; i <<= 1) {
    cp g = (cp){cos(2 * pi / i), (v ? -1 : 1) * sin(2 * pi / i)};
    for (int j = (i >> 1); j >= 0; j -= 2) w[j] = w[j >> 1];
    for (int j = 1; j < i >> 1; j += 2) w[j] = w[j - 1] * g;
    for (int j = 0; j < k; j += i) {
      cp *a = x + j, *b = a + (i >> 1);
      for (int l = 0; l < i >> 1; l++) {
        cp o = b[l] * w[l];
        b[l] = a[l] - o;
        a[l] = a[l] + o;
      }
    }
  }
  if (v)
    for (int i = 0; i < k; i++) x[i] = (cp){x[i].a / k, x[i].b / k};
}
int p[30], v[200005];
char s[200005], t[200005];
int main() {
  for (int i = 1; i <= 26; i++) scanf("%d", &p[i]);
  scanf("%s %s", t, s);
  int n = strlen(s), m = strlen(t);
  int r = 1;
  while (r <= n + m) r *= 2;
  r /= 2;
  std::reverse(t, t + m);
  for (int i = 1; i <= 26; i++) {
    memset(x, 0, sizeof(x));
    memset(y, 0, sizeof(y));
    for (int i0 = 0; i0 < n; i0++)
      (i0 & 1 ? x[i0 >> 1].b : x[i0 >> 1].a) = (s[i0] - 'a' + 1 == i);
    for (int i0 = 0; i0 < m; i0++)
      (i0 & 1 ? y[i0 >> 1].b : y[i0 >> 1].a) =
          (t[i0] - 'a' + 1 == i || p[t[i0] - 'a' + 1] == i);
    fft(x, r, 0);
    fft(y, r, 0);
    for (int i0 = 0; i0 < r; i0++) {
      int j = r - 1 & r - i0;
      z[i0] =
          (x[i0] * y[i0] * 4 - (x[i0] - !x[j]) * (y[i0] - !y[j]) *
                                   (((i0 & r >> 1) ? (cp){1, 0} - w[i0 ^ r >> 1]
                                                   : w[i0] + (cp){1, 0}))) *
          0.25;
    }
    fft(z, r, 1);
    for (int i0 = m - 1; i0 < n; i0++) {
      if (i0 & 1)
        v[i0] += ((int)(z[i0 >> 1].b + 0.1));
      else
        v[i0] += ((int)(z[i0 >> 1].a + 0.1));
    }
  }
  for (int i = m - 1; i < n; i++) printf("%d", v[i] == m);
  return 0;
}
