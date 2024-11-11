#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const unsigned long long mod1 = 2e18 + 7;
const int inf = 0x7f7f7f7f;
const double tiaohe = 0.57721566490153286060651209;
long long oula(long long x) {
  long long res = x;
  for (register int i = 2; i <= x / i; ++i) {
    if (x % i == 0) {
      res = res / i * (i - 1);
      while (x % i == 0) x /= i;
    }
  }
  if (x > 1) res = res / x * (x - 1);
  return res;
}
long long quickmod(long long a, long long n, long long m) {
  long long s = 1;
  while (n) {
    if (n & 1) {
      s = s * a % m;
    }
    a = (a * a) % m;
    n = n / 2;
  }
  return s;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
void ex_gcd(long long a, long long b, long long &x, long long &y,
            long long &d) {
  if (!b) {
    d = a, x = 1, y = 0;
  } else {
    ex_gcd(b, a % b, y, x, d);
    y -= x * (a / b);
  }
}
long long inv(long long t, long long p) {
  long long d, x, y;
  ex_gcd(t, p, x, y, d);
  return d == 1 ? (x % p + p) % p : -1;
}
bool isPrime(long long x) {
  if (x == 2) return true;
  if (x % 2 == 0) return false;
  for (long long i = 2; i * i <= x; i++)
    if (x % i == 0) return false;
  return true;
}
double eqa = (1 + sqrt(5.0)) / 2.0;
const int N = 1e4 + 5;
int a[155][155];
int main() {
  int n;
  cin >> n;
  a[0][0] = 1;
  a[1][1] = 1;
  for (register int i = 2; i <= n; ++i) {
    for (register int j = 0; j <= i; ++j) {
      if (j > 0) a[i][j] = a[i - 1][j - 1];
      if (j <= i - 2) {
        if (a[i][j] + a[i - 2][j] > 1)
          a[i][j] -= a[i - 2][j];
        else
          a[i][j] += a[i - 2][j];
      }
    }
  }
  printf("%d\n", n);
  for (register int i = 0; i <= n; ++i) printf("%d ", a[n][i]);
  printf("\n");
  printf("%d\n", n - 1);
  for (register int i = 0; i <= n - 1; ++i) printf("%d ", a[n - 1][i]);
  printf("\n");
  return 0;
}
