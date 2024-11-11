#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e5 + 5;
long long power(long long x, long long n) {
  long long res = 1;
  while (n) {
    if (n & 1) res = 1LL * res * x % mod;
    x = 1LL * x * x % mod;
    n >>= 1;
  }
  return res;
}
bool isPrime(long long n) {
  static long long i = 2;
  if (n == 0 || n == 1) {
    return false;
  }
  if (n == i) return true;
  if (n % i == 0) {
    return false;
  }
  i++;
  return isPrime(n);
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long c, d;
    cin >> c >> d;
    if (c == 0 && d == 0) {
      cout << 0 << '\n';
      continue;
    }
    long long diff = abs(c - d);
    if (diff == 0) {
      cout << 1 << '\n';
    } else if ((c + d) & 1) {
      cout << -1 << '\n';
    } else {
      cout << 2 << '\n';
    }
  }
  return 0;
}
