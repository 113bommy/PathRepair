#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const double eps = 1e-9;
inline int read() {
  int ret = 0, sgn = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') sgn = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    ret = ret * 10 + ch - '0';
    ch = getchar();
  }
  return ret * sgn;
}
inline void Out(int a) {
  if (a > 9) Out(a / 10);
  putchar(a % 10 + '0');
}
long long __gcd(long long a, long long b) {
  return b == 0 ? a : __gcd(b, a % b);
}
long long lcm(long long a, long long b) { return a * b / __gcd(a, b); }
long long qpow(long long x, long long n, long long mod) {
  if (n == 0) return 1;
  long long res = qpow((x * x) % mod, n / 2, mod) % mod;
  if (n & 1) res = (res * x) % mod;
  return res % mod;
}
int Fermat(int a, int p) { return qpow(a, p - 2, p); }
long long exgcd(long long a, long long b, long long &x, long long &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  long long g = exgcd(b, a % b, x, y);
  long long t = x;
  x = y;
  y = t - a / b * y;
  return g;
}
const long long INF = 0x3f3f3f3f3f3f3f3fll;
const int N = 2e5 + 10;
int t;
int n, m;
int res, len, pre, now;
int a, b, c;
long long ans;
int a1, a2, a3;
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d%d", &a, &b, &c);
    ans = INF;
    for (int i = 1; i <= 12000; i++) {
      for (int j = 1; i * j <= 12000; j++) {
        for (int k = 1; i * j * k <= 12000; k++) {
          if (ans > abs(i - a) + abs(i * j - b) + abs(i * j * k - c)) {
            ans = abs(i - a) + abs(i * j - b) + abs(i * j * k - c);
            a1 = i, a2 = i * j, a3 = i * j * k;
          }
        }
      }
    }
    printf("%lld\n", ans);
    cout << a1 << ' ' << a2 << ' ' << a3 << '\n';
  }
  return 0;
}
