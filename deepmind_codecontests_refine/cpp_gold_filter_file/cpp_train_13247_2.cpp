#include <bits/stdc++.h>
using namespace std;
long long inv_euclid(long long a, long long m = 998244353) {
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
long long power(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long max(long long a, long long b) {
  if (a > b) return a;
  return b;
}
long long min(long long a, long long b) {
  if (a < b) return a;
  return b;
}
long long ssum(long long n) { return (n * (n + 1)) / 2; }
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return (a * b) / (gcd(a, b)); }
int main() {
  long long n;
  cin >> n;
  string s, t;
  cin >> s >> t;
  long long sum = 0;
  long long a[n];
  for (long long i = 0; i < n; i++) {
    if (s[i] == t[i])
      a[i] = 0;
    else if (s[i] == '1')
      a[i] = 1;
    else
      a[i] = -1;
    sum += a[i];
  }
  if (sum) {
    cout << "-1";
    return 0;
  }
  long long ans = 0;
  for (long long i = 0; i < n; i++) {
    sum = max(sum + a[i], a[i]);
    ans = max(ans, sum);
  }
  long long aa = 0, ss = 0;
  for (long long i = 0; i < n; i++) {
    ss = min(ss + a[i], a[i]);
    aa = min(aa, ss);
  }
  cout << max(ans, abs(aa)) << "\n";
}
