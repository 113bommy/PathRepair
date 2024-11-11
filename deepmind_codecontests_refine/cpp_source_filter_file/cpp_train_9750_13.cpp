#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const int N = 125010;
struct dsu {
  int father[10];
  void init() {
    for (int i(0); i <= (7); ++i) father[i] = i;
  }
  int getfather(int x) {
    return father[x] == x ? x : father[x] = getfather(father[x]);
  }
} c[N];
char s[N], t[N];
int a[N << 1], b[N << 1];
int n, m;
int ans[N];
struct Complex {
  double x, y;
  Complex(double x = 0.0, double y = 0.0) : x(x), y(y) {}
  Complex operator+(const Complex &b) const {
    return Complex(x + b.x, y + b.y);
  }
  Complex operator-(const Complex &b) const {
    return Complex(x - b.x, y - b.y);
  }
  Complex operator*(const Complex &b) const {
    return Complex(x * b.x - y * b.y, x * b.y + y * b.x);
  }
};
Complex x1[N << 1], x2[N << 1];
void change(Complex y[], int len) {
  for (int i = 1, j = len / 2; i < len - 1; i++) {
    if (i < j) swap(y[i], y[j]);
    int k = len / 2;
    while (j >= k) {
      j -= k;
      k /= 2;
    }
    if (j < k) j += k;
  }
}
void fft(Complex y[], int len, int on) {
  change(y, len);
  for (int h = 2; h <= len; h <<= 1) {
    Complex wn(cos(-on * 2 * PI / h), sin(-on * 2 * PI / h));
    for (int j = 0; j < len; j += h) {
      Complex w(1, 0);
      for (int k = j; k < j + h / 2; k++) {
        Complex u = y[k];
        Complex t = w * y[k + h / 2];
        y[k] = u + t;
        y[k + h / 2] = u - t;
        w = w * wn;
      }
    }
  }
  if (on == -1) {
    for (int i(0); i <= (len - 1); ++i) y[i].x /= len;
  }
}
void mul(int p[], int dp, int q[], int dq) {
  int len = 1;
  while (len <= dp + dq) len <<= 1;
  for (int i(0); i <= (dp); ++i) x1[i] = Complex(p[i], 0);
  for (int i(dp + 1); i <= (len - 1); ++i) x1[i] = Complex(0, 0);
  for (int i(0); i <= (dq); ++i) x2[i] = Complex(q[i], 0);
  for (int i(dq + 1); i <= (len - 1); ++i) x2[i] = Complex(0, 0);
  fft(x1, len, 1);
  fft(x2, len, 1);
  for (int i(0); i <= (len - 1); ++i) x1[i] = x1[i] * x2[i];
  fft(x1, len, -1);
  for (int i(0); i <= (dp + dq); ++i) p[i] = (int)(x1[i].x + 0.5);
  for (int i(0); i <= (dp + dq); ++i)
    if (p[i] > 0) p[i] = 1;
  dp += dq;
}
void work(int pos, int x, int y) {
  int fx = c[pos].getfather(x), fy = c[pos].getfather(y);
  if (fx == fy) return;
  assert(pos >= 1 && pos <= n - m + 1);
  ++ans[pos];
  c[pos].father[fx] = fy;
}
int main() {
  scanf("%s%s", s, t);
  n = strlen(s), m = strlen(t);
  for (int i(1); i <= (n - m + 1); ++i) c[i].init();
  for (int i(0); i <= (5); ++i) {
    for (int j(0); j <= (5); ++j) {
      if (i == j) continue;
      memset(a, 0, sizeof a);
      memset(b, 0, sizeof b);
      for (int k(0); k <= (n - 1); ++k) a[k] = (s[k] - 'a' == i);
      for (int k(0); k <= (m - 1); ++k) b[k] = (t[k] - 'a' == j);
      reverse(b, b + m);
      mul(a, n, b, m);
      for (int k = m - 1, cnt = 1; cnt <= n - m + 1; ++k, ++cnt) {
        if (a[k]) {
          work(cnt, i + 1, j + 1);
        }
      }
    }
  }
  for (int i(1); i <= (n - m + 1); ++i) printf("%d\n", ans[i]);
  return 0;
}
