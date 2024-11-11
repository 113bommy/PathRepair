#include <bits/stdc++.h>
using namespace std;
long long mult(long long a, long long b, long long p = 1000000007) {
  return ((a % p) * (b % p)) % p;
}
long long multbig(long long a, long long b, long long mod) {
  if (a == 0 or b == 0) return 0;
  if (a == 1 or b == 1) return (a * b) % mod;
  long long cur = multbig(a, b / 2, mod);
  cur = (2 * cur) % mod;
  if (b % 2) cur = (cur + a) % mod;
  return cur;
}
long long add(long long a, long long b, long long p = 1000000007) {
  return (a % p + b % p) % p;
}
long long fpow(long long n, long long k, long long p = 1000000007) {
  long long r = 1;
  for (; k; k >>= 1LL) {
    if (k & 1LL) r = mult(r, n, p);
    n = mult(n, n, p);
  }
  return r;
}
long long inv(long long a, long long p = 1000000007) {
  return fpow(a, p - 2, p);
}
long long inv_euclid(long long a, long long m = 1000000007) {
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
int main() {
  ios::sync_with_stdio(0);
  long long n;
  cin >> n;
  long long a[100];
  for (long long i = 0; i < (long long)n; i++) {
    cin >> a[i];
  }
  long long minn = *min_element(a, a + n);
  long long ans = 0;
  for (long long i = 0; i < (long long)n; i++) {
    if (a[i] == minn) {
      ans++;
    }
  }
  if (ans >= n / 2) {
    cout << "Alice\n";
  } else
    cout << "Bob\n";
}
