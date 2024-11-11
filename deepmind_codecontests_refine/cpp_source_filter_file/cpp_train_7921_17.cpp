#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;
long long gcd(long long x, long long y) {
  if (y == 0)
    return x;
  else
    return gcd(y, x % y);
}
long long ksm(long long a, long long b) {
  long long r = 1;
  while (b) {
    if (b & 1) r = (r * a) % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return r;
}
void exgcd(long long a, long long b, long long &x, long long &y, long long &d) {
  if (!b)
    d = a, x = 1, y = 0;
  else
    exgcd(b, a % b, y, x, d), y -= a / b * x;
}
long long inv(long long a, long long p) {
  long long x, y, d;
  exgcd(a, p, x, y, d);
  x = (x % p + p) % p;
  return x;
}
inline int read() {
  char c = getchar();
  int x = 0, f = 1;
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x * f;
}
const int maxn = 1e5 + 100;
long long n, m, k, t;
int main() {
  cin >> n >> m;
  if (n > m) swap(n, m);
  int ans = 0;
  if (n == 1) {
    ans += m / 6 * 6;
    m %= 6;
    if (m == 4) ans += 2;
    if (m == 5) ans += 4;
  } else if (n == 2) {
    if (m <= 2)
      ans = 0;
    else if (m == 3 || m == 7)
      ans = n * m - 2;
    else
      ans = n * m;
  } else if (n == 3) {
    if (m % 2)
      ans = n * m - 1;
    else
      ans = n * m;
  } else if (n == 4) {
    ans = n * m;
  } else
    ans = n * m - (n * m) % 2;
  cout << ans << endl;
  return 0;
}
