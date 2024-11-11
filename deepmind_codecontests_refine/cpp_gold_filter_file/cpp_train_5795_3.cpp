#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long mod2 = 998244353;
const int inf = 0x3f3f3f3f;
const double tiaohe = 0.57721566490153286060651209;
long long oula(long long x) {
  long long res = x;
  for (int i = 2; i <= x / i; ++i) {
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
inline int in() {
  char ch = getchar();
  int x = 0, f = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
double eqa = (1 + sqrt(5.0)) / 2.0;
const double eps = 1e-6;
const int N = 1e5 + 5;
int a[N];
int f[N];
int main() {
  int n = in();
  for (int i = 1; i <= n; ++i) a[i] = in();
  int mx = 0;
  for (int i = n; i >= 1; --i) {
    mx = max(a[i] + 1, mx - 1);
    f[i] = mx;
  }
  for (int i = 2; i <= n; ++i) f[i] = max(f[i], f[i - 1]);
  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    ans += f[i] - 1 - a[i];
  }
  cout << ans << endl;
  return 0;
}
