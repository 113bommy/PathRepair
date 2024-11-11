#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const double eps = 1e-9;
const long long INF = 0x3f3f3f3f3f3f3f3fll;
const int inf = 0x3f3f3f3f;
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
long long qpow(long long a, long long b, long long mod) {
  if (a >= mod) a = a % mod + mod;
  long long ans = 1;
  while (b) {
    if (b & 1) {
      ans = ans * a;
      if (ans >= mod) ans = ans % mod + mod;
    }
    a *= a;
    if (a >= mod) a = a % mod + mod;
    b >>= 1;
  }
  return ans;
}
int Fermat(int a, int p) { return qpow(a, p - 2, p); }
long long exgcd(long long a, long long b, long long &x, long long &y) {
  if (b == 0) {
    x = 1, y = 0;
    return a;
  }
  long long d = exgcd(b, a % b, x, y);
  long long z = x;
  x = y;
  y = z - y * (a / b);
  return d;
}
long long china(int a[], int b[], int n) {
  long long M = 1, y, x = 0;
  for (int i = 0; i < n; ++i) M *= a[i];
  for (int i = 0; i < n; ++i) {
    int w = M / a[i];
    long long tx = 0;
    long long t = exgcd(w, a[i], tx, y);
    x = (x + w * (b[i] / t) * x) % M;
  }
  return (x + M) % M;
}
long long a, b;
long long l, r;
int main() {
  int m;
  scanf("%d", &m);
  int cnt, res, sum = 0;
  for (int i = 1; i <= 100000; i++) {
    cnt = 0;
    res = i;
    while (1) {
      if (res % 5 == 0) {
        cnt++;
        res /= 5;
      } else
        break;
    }
    sum += cnt;
    if (sum == m) {
      puts("5");
      for (int j = i; j <= i + 4; j++) {
        printf("%d ", j);
      }
      return 0;
    } else if (sum > m) {
      break;
    }
  }
  puts("0");
  return 0;
}
