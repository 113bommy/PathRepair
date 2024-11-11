#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
const double PI = acos(-1.0);
int n, k, a[N << 1], b[N << 1];
struct CP {
  double x, y;
  CP(double x = 0, double y = 0) : x(x), y(y) {}
  CP operator+(const CP &b) const { return CP(x + b.x, y + b.y); }
  CP operator-(const CP &b) const { return CP(x - b.x, y - b.y); }
  CP operator*(const CP &b) const {
    return CP(x * b.x - y * b.y, x * b.y + y * b.x);
  }
} x1[N << 2], x2[N << 2];
void change(CP y[], int len) {
  for (int i = 1, j = len >> 1; i < len - 1; ++i) {
    if (i < j) swap(y[i], y[j]);
    int k = len >> 1;
    while (j >= k) j -= k, k >>= 1;
    if (j < k) j += k;
  }
}
void fft(CP y[], int len, int on) {
  change(y, len);
  for (int h = 2; h <= len; h <<= 1) {
    CP wn(cos(-on * 2 * PI / h), sin(-on * 2 * PI / h));
    for (int j = 0; j < len; j += h) {
      CP w(1, 0);
      for (int k = j; k < j + h / 2; ++k) {
        CP u = y[k], t = w * y[k + h / 2];
        y[k] = u + t, y[k + h / 2] = u - t;
        w = w * wn;
      }
    }
  }
  if (on == -1) {
    for (int i = 0; i < len; ++i) y[i].x /= len;
  }
}
void mul(int p[], int &np, int q[], int nq) {
  int len = 1;
  while (len < np + nq) len <<= 1;
  for (int i = 0; i < len; ++i) {
    x1[i] = i < np ? CP(p[i]) : CP();
    x2[i] = i < nq ? CP(q[i]) : CP();
  }
  fft(x1, len, 1);
  fft(x2, len, 1);
  for (int i = 0; i < len; ++i) x1[i] = x1[i] * x2[i];
  fft(x1, len, -1);
  for (int i = 0; i < np + nq - 1; ++i) p[i] = (int)(x1[i].x + 0.5);
  np += nq - 1;
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1, x; i <= n; ++i) {
    scanf("%d", &x);
    a[x] = 1;
  }
  b[0] = 1;
  int lena = 1001, lenb = 1;
  while (k) {
    if (k & 1) mul(b, lenb, a, lena);
    if (k > 1) mul(a, lena, a, lena);
    k >>= 1;
  }
  for (int i = 1; i < lenb; ++i)
    if (b[i]) printf("%d ", i);
  puts("");
  return 0;
}
