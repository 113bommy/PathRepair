#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
using namespace std;
long long MOD = 998244353;
long long mpow(long long a, long long b) {
  if (b >= (MOD - 1)) b %= (MOD - 1);
  if (b == 0) return 1;
  long long t1 = mpow(a, b / 2);
  t1 *= t1;
  t1 %= MOD;
  if (b % 2) t1 *= a;
  t1 %= MOD;
  return t1;
}
long long mpow(long long a, long long b, long long p) {
  if (b == 0) return 1;
  long long t1 = mpow(a, b / 2, p);
  t1 *= t1;
  t1 %= p;
  if (b % 2) t1 *= a;
  t1 %= p;
  return t1;
}
long long modinverse(long long a, long long m) {
  long long m0 = m;
  long long y = 0, x = 1;
  if (m == 1) return 0;
  while (a > 1) {
    long long q = a / m;
    long long t = m;
    m = a % m, a = t;
    t = y;
    y = x - q * y;
    x = t;
  }
  if (x < 0) x += m0;
  return x;
}
long long range(long long l, long long r) { return l + rand() % (r - l + 1); }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;
    int ls = pow(10, 7), aa = a, bb = b, cc = c;
    for (int i = 1; i <= c; i++) {
      for (int j = i; j <= c; j += i) {
        int tls = abs(i - a) + abs(j - b);
        if (c % j < (abs(j - (c % j)))) {
          tls += (c % j);
          if (tls < ls) aa = i, bb = j, cc = (c - (c % j)), ls = tls;
        } else {
          tls += abs(j - (c % j));
          if (tls < ls) aa = i, bb = j, cc = c + (abs(j - (c % j))), ls = tls;
        }
      }
    }
    cout << ls << endl;
    cout << aa << " " << bb << " " << cc << endl;
  }
}
