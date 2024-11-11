#include <bits/stdc++.h>
using namespace std;
long long p = 1000000009;
long long gcd(long long a, long long b) {
  if (a < b) return (gcd(b, a));
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long power(long long x, long long y) {
  long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
int main() {
  long long n, m, k, s, d, x, y, ans;
  cin >> n >> m >> k;
  s = (n / k) * (k - 1) + (n % k);
  if (s >= m) {
    cout << s % p;
  } else {
    d = m - s;
    x = power(2, d + 1);
    y = m - d * k;
    ans = (((k % p) * (x - 2 + p) % p) % p + y % p) % p;
    cout << ans;
  }
}
