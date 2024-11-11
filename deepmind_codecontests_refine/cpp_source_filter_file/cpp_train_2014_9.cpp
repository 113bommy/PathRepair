#include <bits/stdc++.h>
using namespace std;
const int ten = 10000000;
const int base = 1000000000;
const long long F = 10000000000000LL;
struct FYB {
  long long a, b, c;
  FYB(long long x = 0) : a(0), b(x / base), c(x % base) {}
};
long long f[15][3];
long long xh[15];
inline FYB operator*(FYB a, FYB b) {
  FYB t;
  t.c = a.c * b.c;
  t.b = a.b * b.c + a.c * b.b + t.c / base;
  t.a = a.a * b.c + a.b * b.b + a.c * b.a + t.b / base;
  t.c %= base;
  t.b %= base;
  t.a %= base;
  return t;
}
inline FYB operator+(FYB a, FYB b) {
  FYB t;
  t.c = a.c + b.c;
  t.b = a.b + b.b + t.c / base;
  t.a = a.a + b.a + t.b / base;
  t.c %= base;
  t.b %= base;
  t.a %= base;
  return t;
}
inline FYB operator%(FYB a, long long b) {
  FYB t;
  t.a = 0;
  if (b / base > 1)
    t.b = a.b % (b / base);
  else
    t.b = 0;
  if (b > base)
    t.c = a.c;
  else
    t.c = b;
  return t;
}
inline bool operator==(FYB a, long long b) {
  return a.a == 0 && a.b == b / base && a.c == b % base;
}
inline long long mult(long long a, long long b, long long md) {
  long long res = 0;
  for (; b; b >>= 1) {
    if (b & 1) {
      res = (res + a) % md;
    }
    a = (a + a) % md;
  }
  return res;
}
long long fyb(long long n, long long md) {
  --n;
  long long base[2][2] = {{1, 1}, {1, 0}};
  long long mat[2][2] = {{1, 0}, {0, 1}};
  for (; n; n >>= 1) {
    if (n & 1) {
      long long temp[2][2] = {{mat[0][0], mat[0][1]}, {mat[1][0], mat[1][1]}};
      mat[0][0] = (mult(temp[0][0], base[0][0], md) +
                   mult(temp[0][1], base[1][0], md)) %
                  md;
      mat[0][1] = (mult(temp[0][0], base[0][1], md) +
                   mult(temp[0][1], base[1][1], md)) %
                  md;
      mat[1][0] = (mult(temp[1][0], base[0][0], md) +
                   mult(temp[1][1], base[1][0], md)) %
                  md;
      mat[1][1] = (mult(temp[1][0], base[0][1], md) +
                   mult(temp[1][1], base[1][1], md)) %
                  md;
    }
    long long temp[2][2] = {{base[0][0], base[0][1]}, {base[1][0], base[1][1]}};
    base[0][0] =
        (mult(temp[0][0], temp[0][0], md) + mult(temp[0][1], temp[1][0], md)) %
        md;
    base[0][1] =
        (mult(temp[0][0], temp[0][1], md) + mult(temp[0][1], temp[1][1], md)) %
        md;
    base[1][0] =
        (mult(temp[1][0], temp[0][0], md) + mult(temp[1][1], temp[1][0], md)) %
        md;
    base[1][1] =
        (mult(temp[1][0], temp[0][1], md) + mult(temp[1][1], temp[1][1], md)) %
        md;
  }
  return mat[0][0];
}
void init() {
  xh[7] = 15000000;
  f[7][0] = fyb(xh[7] - 1, F);
  f[7][1] = fyb(xh[7], F);
  f[7][2] = fyb(xh[7] + 1, F);
}
int main() {
  init();
  long long n;
  cin >> n;
  if (!n || n == 1) {
    cout << n;
    return 0;
  }
  register long long t = 3, a0 = 1, a1 = 2, a2 = 1;
  long long ans = (long long)base * base;
  long long _ = n % ten;
  while (t <= xh[7] && t <= ans) {
    a2 = (a1 + a0) % ten;
    a0 = a1;
    a1 = a2;
    ++t;
    if (a2 == _) {
      int d = 1;
      long long ac = t;
      FYB x(f[7][2]), y(f[7][1]), z(f[7][0]), f0(fyb(t - 1, F)), f1(fyb(t, F));
      while ((!(f1 == n)) && d <= 550000 && ac < ans) {
        FYB sps((f1 * x + f0 * y) % F), zzq((f1 * y + f0 * z) % F);
        f0 = zzq;
        f1 = sps;
        ac += xh[7];
        ++d;
      }
      if (f1 == n) ans = min(ans, ac);
    }
  }
  if (ans >= (long long)base * base)
    cout << -1;
  else
    cout << ans;
  return 0;
}
