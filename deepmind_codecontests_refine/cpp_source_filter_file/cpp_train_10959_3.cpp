#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char ch = 0;
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
const int mod = 1e9 + 7;
const int maxn = 1e6 + 100;
int T, m, x;
long long n;
long long qpow(long long x, long long p) {
  long long ret = 1;
  while (p) {
    if (p & 1) ret = ret * x % mod;
    x = x * x % mod;
    p >>= 1;
  }
  return ret;
}
inline void print(long long x) {
  if (x > 10) print(x / 10);
  putchar(x % 10 + 48);
}
int main() {
  T = read();
  const int _2 = 500000004;
  while (T--) {
    n = read();
    if (n % 4 < 2)
      print((n / 2 % mod + 2) * (n / 4 % mod + 1) % mod * _2 % mod);
    else
      print((n / 2 % mod + 3) * (n / 4 % mod + 1) % mod * _2 % mod);
    printf("\n");
  }
  return 0;
}
