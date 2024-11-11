#include <bits/stdc++.h>
using namespace std;
const int RLEN = 1 << 20 | 1;
inline char gc() {
  static char ibuf[RLEN], *ib, *ob;
  (ib == ob) && (ob = (ib = ibuf) + fread(ibuf, 1, RLEN, stdin));
  return (ib == ob) ? EOF : *ib++;
}
inline int read() {
  char ch = gc();
  int res = 0;
  bool f = 1;
  while (!isdigit(ch)) f ^= ch == '-', ch = gc();
  while (isdigit(ch)) res = (res + (res << 2) << 1) + (ch ^ 48), ch = gc();
  return f ? res : -res;
}
template <class tp>
inline void chemx(tp &a, tp b) {
  a < b ? a = b : 0;
}
template <class tp>
inline void chemn(tp &a, tp b) {
  a > b ? a = b : 0;
}
unsigned long long tmp[20];
const int N = 100005;
int n, mx;
const unsigned long long inv5 = 57646075230342349ull;
const unsigned long long mod = (1ll << 58);
struct plx {
  unsigned long long a[10];
  plx() { memset(a, 0, sizeof(a)); }
  inline unsigned long long &operator[](const int &k) { return a[k]; }
  inline const unsigned long long &operator[](const int &k) const {
    return a[k];
  }
  friend inline plx operator*(plx a, plx b) {
    for (int i = 0; i < 10; i++)
      if (a[i])
        for (int j = 0; j < 10; j++) tmp[i + j] += a[i] * b[j];
    for (int i = 0; i < 10; i++)
      a[i] = tmp[i] + tmp[i + 10], tmp[i] = tmp[i + 10] = 0;
    return a;
  }
  inline unsigned long long val() {
    unsigned long long ret = 0;
    ret += (a[0] - a[5]) * 4;
    ret += a[1] - a[2] + a[3] - a[4] - a[6] + a[7] - a[8] + a[9];
    return (ret >> 2) % mod;
  }
} f[N << 1];
inline plx ksm(plx a, int b) {
  plx ret;
  ret[0] = 1;
  for (; b; b >>= 1, a = a * a)
    if (b & 1) ret = ret * a;
  return ret;
}
inline void fwt(plx *f, int lim, int kd) {
  unsigned long long tmp[10][20];
  for (int mid = 1; mid < lim; mid *= 10)
    for (int i = 0; i < lim; i += mid * 10)
      for (int j = 0; j < mid; j++) {
        for (int k = 0; k < 10; k++) {
          memset(tmp[k], 0, sizeof(tmp[k]));
          for (int p = 0; p < 10; p++) {
            int mt = k * p % 10;
            if (kd == -1) mt = (10 - mt) % 10;
            for (int l = 0; l < 10; l++)
              tmp[k][l + mt] += f[i + j + p * mid][l];
          }
          for (int l = 10; l < 20; l++) tmp[k][l - 10] += tmp[k][l];
        }
        if (kd == 1)
          for (int k = 0; k < 10; k++) {
            for (int p = 0; p < 10; p++) f[i + j + k * mid][p] = tmp[k][p];
          }
        else
          for (int k = 0; k < 10; k++) {
            for (int p = 0; p < 10; p++)
              f[i + j + k * mid][p] = (tmp[k][p] / 2) * inv5;
          }
      }
}
int main() {
  n = read();
  for (int i = 1; i <= n; i++) {
    int x = read();
    chemx(mx, x);
    f[x][0]++;
  }
  int lim = 1;
  while (lim <= mx) lim *= 10;
  fwt(f, lim, 1);
  for (int i = 0; i < lim; i++) f[i] = ksm(f[i], n);
  fwt(f, lim, -1);
  for (int i = 0; i < n; i++) cout << f[i].val() << '\n';
}
