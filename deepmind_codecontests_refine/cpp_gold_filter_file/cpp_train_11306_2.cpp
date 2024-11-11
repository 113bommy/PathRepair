#include <bits/stdc++.h>
using namespace std;
namespace io {
inline void readFile() { freopen("data.in", "r", stdin); }
inline void readOp(char &c) {
  c = getchar();
  while (c < 'A' || c > 'Z') c = getchar();
}
inline void read(int &x) {
  static int f;
  static char c;
  x = 0;
  f = 1;
  c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  x *= f;
}
inline int read() {
  int x;
  read(x);
  return x;
}
}  // namespace io
void readS(int *s, int len) {
  static char ch = getchar();
  while (ch != 'V' && ch != 'K' && ch != '?') ch = getchar();
  for (int i = 1; i <= len; ++i) {
    s[i] = ch == 'V' ? 1 : (ch == 'K' ? 2 : 0);
    ch = getchar();
  }
}
namespace FFT {
const int M = 262145 * 4;
const double pi = 3.1415926535897932384626433832795;
struct E {
  double r, i;
  E(double _r, double _i) : r(_r), i(_i) {}
  E() {}
  E operator+(const E &b) { return E(r + b.r, i + b.i); }
  E operator-(const E &b) { return E(r - b.r, i - b.i); }
  E operator*(const E &b) { return E(r * b.r - i * b.i, r * b.i + i * b.r); }
} x[M], y[M];
int n, m;
int c[M];
void change(E y[], int len) {
  int i, j, k;
  for (i = 1, j = len / 2; i < len - 1; i++) {
    if (i < j) swap(y[i], y[j]);
    k = len / 2;
    while (j >= k) {
      j -= k;
      k /= 2;
    }
    if (j < k) j += k;
  }
}
void fft(E y[], int len, int on) {
  change(y, len);
  for (int h = 2; h <= len; h <<= 1) {
    E wn(cos(-on * 2 * pi / h), sin(-on * 2 * pi / h));
    for (int j = 0; j < len; j += h) {
      E w(1, 0);
      for (int k = j; k < j + h / 2; k++) {
        E u = y[k];
        E t = w * y[k + h / 2];
        y[k] = u + t;
        y[k + h / 2] = u - t;
        w = w * wn;
      }
    }
  }
  if (on == -1)
    for (int i = 0; i < len; i++) y[i].r /= len;
}
void init(int x) { n = m = x; }
void work() {
  int len = 1;
  while (len < n * 2) len = len * 2;
  x[0] = y[0] = E(0, 0);
  for (int i = n; i < (len * 2) && (i < M); ++i) x[i] = y[i] = E(0, 0);
  fft(x, len, 1);
  fft(y, len, 1);
  for (int i = 0; i < len; ++i) x[i] = x[i] * y[i];
  fft(x, len, -1);
  for (int i = 0; i < n * 2; ++i) c[i] = round(x[i].r);
}
}  // namespace FFT
using namespace io;
const int N = 5e5 + 5;
int n, n2;
int s[N];
int p[N], pc;
bool v[N];
int main() {
  int T = read();
  while (T--) {
    read(n);
    n2 = n << 1;
    readS(s, n);
    FFT::init(n + 1);
    for (int i = 1; i <= n; ++i) {
      FFT::x[i] = FFT::E(s[i] == 1, 0);
      FFT::y[n - i + 1] = FFT::E(s[i] == 2, 0);
    }
    FFT::work();
    for (int i = 2; i <= n2; ++i) {
      if (FFT::c[i] > 0) v[abs(n + 1 - i)] = true;
    }
    pc = 0;
    for (int i = 1; i <= n; ++i) {
      for (int j = i << 1; j <= n; j += i) v[i] |= v[j];
      if (!v[i]) p[pc++] = i;
    }
    printf("%d\n%d", pc, p[0]);
    for (int i = 1; i < pc; ++i) printf(" %d", p[i]);
    putchar('\n');
    if (T > 0) {
      memset(v, 0, sizeof(int) * (n + 1));
    }
  }
  return 0;
}
