#include <bits/stdc++.h>
using namespace std;
const int N = 1500000 + 10;
const int mod = 100;
const double PI = acos(-1.0);
vector<int> a, b;
int v[N];
int sz_v = 0;
int k;
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
void mul(vector<int> a, vector<int> b, vector<int> &c) {
  int len = 1;
  int sz1 = a.size(), sz2 = b.size();
  while (len <= sz1 + sz2 - 1) len <<= 1;
  for (int i(0); i <= (sz1 - 1); ++i) x1[i] = Complex(a[i], 0);
  for (int i(sz1); i <= (len); ++i) x1[i] = Complex(0, 0);
  for (int i(0); i <= (sz2 - 1); ++i) x2[i] = Complex(b[i], 0);
  for (int i(sz2); i <= (len); ++i) x2[i] = Complex(0, 0);
  fft(x1, len, 1);
  fft(x2, len, 1);
  for (int i(0); i <= (len - 1); ++i) x1[i] = x1[i] * x2[i];
  fft(x1, len, -1);
  c.clear();
  for (int i(0); i <= (sz1 + sz2 - 2); ++i) {
    c.push_back((int)(x1[i].x + 0.5));
  }
}
void relax(vector<int> &a) {
  int p = 0, sz = (int)a.size();
  for (int i = 0; i < sz || p; ++i) {
    if (i >= sz) a.push_back(0);
    long long cnt = a[i] + p;
    a[i] = cnt % mod;
    p = cnt / mod;
  }
}
void calc(int k) {
  a.push_back(3);
  b.push_back(1);
  for (; k; k >>= 1, mul(a, a, a), relax(a)) {
    if (k & 1) mul(b, a, b), relax(b);
  }
}
void mul3() {
  for (auto &u : b) u *= 3;
  relax(b);
}
int cmp(vector<int> a) {
  int sz_a = (int)a.size();
  if (sz_a < sz_v) return 0;
  if (sz_a > sz_v) return 1;
  for (int i(sz_a - 1); i >= (0); --i) {
    if (a[i] < v[i]) return 0;
    if (a[i] > v[i]) return 1;
  }
  return 1;
}
int check(int x) {
  vector<int> c;
  for (auto u : b) c.push_back(u * x);
  relax(c);
  return cmp(c);
}
int base, ans, len;
char s[N];
void extra() {
  int x = s[0] - '0';
  if (x <= 5)
    printf("%d\n", x);
  else if (x == 6)
    printf("%d\n", 5);
  else
    printf("%d\n", 6);
}
int main() {
  scanf("%s", s);
  len = strlen(s);
  if (len < 2) {
    extra();
    return 0;
  }
  reverse(s, s + len);
  for (int i = 0; i < len; i += 2) {
    int x = s[i] - '0';
    if (i + 1 < len) x = x + (s[i + 1] - '0') * 10;
    v[sz_v++] = x;
  }
  base = (len - 1) * (double)(log(10) / log(3));
  --base;
  calc(base);
  for (ans = base * 3;; ans += 3, mul3()) {
    for (int i(2); i <= (4); ++i)
      if (check(i)) return 0 * printf("%d\n", ans + i);
  }
}
