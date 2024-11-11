#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T read() {
  T x = 0;
  int f = 1;
  char k = getchar();
  for (; k > '9' || k < '0'; k = getchar())
    if (k == '-') f = -1;
  for (; k >= '0' && k <= '9'; k = getchar()) x = x * 10 + k - '0';
  return x * f;
}
template <class T>
inline T read(T &x) {
  return x = read<T>();
}
int _num, _buf[20];
inline void print(int x) {
  if (x == 0) return putchar('0'), void();
  if (x < 0) putchar('-'), x = -x;
  while (x) _buf[++_num] = x % 10, x /= 10;
  while (_num) putchar(_buf[_num--] + '0');
}
long long mul(long long a, long long b, long long mod) {
  long double c = 1.;
  return (a * b - (long long)(c * a * b / mod) * mod) % mod;
}
inline int qpow(int x, int m, int mod) {
  int res = 1, bas = x;
  while (m) {
    if (m & 1) res = (1ll * res * bas) % mod;
    bas = (1ll * bas * bas) % mod, m >>= 1;
  }
  return res;
}
int T;
long long a, k;
inline void Solve() {
  a = read<long long>(), k = read<long long>() - 1;
  while (k--) {
    long long tmp = a;
    int mx = 0, mn = 9;
    while (tmp) {
      int c = tmp % 10;
      mx = std::max(mx, c);
      mn = std::min(mn, c);
      tmp /= 10;
    }
    if (mn == 0) return print(a), puts(""), void();
    a += mx * mn;
  }
  print(a), puts("");
}
int main() {
  T = read<int>();
  while (T--) Solve();
  cerr << 1. * clock() / CLOCKS_PER_SEC << "\n";
  return 0;
}
