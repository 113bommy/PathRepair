#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:1024000000,1024000000")
const long long mod = 1000000007;
const long long inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
long long qpow(long long a, long long b) {
  long long s = 1;
  while (b > 0) {
    if (b % 2 == 1) {
      s = s * a;
    }
    a = a * a;
    b = b >> 1;
  }
  return s;
}
long long qpowmod(long long a, long long b, long long c) {
  long long res, t;
  res = 1;
  t = a % c;
  while (b) {
    if (b & 1) {
      res = res * t % c;
    }
    t = t * t % c;
    b >>= 1;
  }
  return res;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
inline long long read() {
  long long k = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    k = k * 10 + ch - '0';
    ch = getchar();
  }
  return k * f;
}
inline void write(long long x) {
  if (x < 0) x = -x, putchar('-');
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
const long long maxn = 2e5 + 5;
long long n, m;
signed main() {
  cin >> n >> m;
  if (n >= 5 && m >= 5) {
    if (qpow(n, m) > qpow(m, n))
      cout << ">"
           << "\n";
    else if (qpow(n, m) == qpow(m, n))
      cout << "="
           << "\n";
    else
      cout << "<"
           << "\n";
  } else {
    if (n == 1 || m == 1) {
      if (n == 1)
        cout << "<"
             << "\n";
      else
        cout << ">"
             << "\n";
    } else {
      if (n > m)
        cout << "<"
             << "\n";
      else if (n < m)
        cout << ">"
             << "\n";
      else
        cout << "="
             << "\n";
    }
  }
  return 0;
}
