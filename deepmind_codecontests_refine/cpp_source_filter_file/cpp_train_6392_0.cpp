#include <bits/stdc++.h>
using namespace std;
const int inf = 2000000000;
static inline int Rint() {
  struct X {
    int dig[256];
    X() {
      for (int i = '0'; i <= '9'; ++i) dig[i] = 1;
      dig['-'] = 1;
    }
  };
  static X fuck;
  int s = 1, v = 0, c;
  for (; !fuck.dig[c = getchar()];)
    ;
  if (c == '-')
    s = 0;
  else if (fuck.dig[c])
    v = c ^ 48;
  for (; fuck.dig[c = getchar()]; v = v * 10 + (c ^ 48))
    ;
  return s ? v : -v;
}
template <typename T>
static inline void cmax(T& a, const T& b) {
  if (b > a) a = b;
}
template <typename T>
static inline void cmin(T& a, const T& b) {
  if (b < a) a = b;
}
const int maxn = 100005;
int main() {
  const int m = Rint(), r = Rint();
  const double coe = sqrt(2.0);
  double total = 0;
  for (int i = 1; i <= m; ++i) {
    total += 2 * r;
    if (i + 1 <= m) {
      total += 2 * r + coe * r;
    }
    if (i - 1 >= 1) {
      total += 2 * r + coe * r;
    }
    if (m >= i + 2) {
      long long cnt = m - i - 1;
      double u = 2 * r + 2 * coe + r;
      double v = 2 * r * cnt + 2 * coe + r;
      total += (u + v) * cnt / 2;
    }
    if (i >= 3) {
      long long cnt = i - 2;
      double u = 2 * r + 2 * coe + r;
      double v = 2 * r * cnt + 2 * coe + r;
      total += (u + v) * cnt / 2;
    }
  }
  printf("%.16f\n", total / (1. * m * m));
  return 0;
}
