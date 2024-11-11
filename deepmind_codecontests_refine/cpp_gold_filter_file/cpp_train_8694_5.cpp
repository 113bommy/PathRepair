#include <bits/stdc++.h>
using namespace std;
long long power(long long a, long long n) {
  long long p = 1;
  while (n > 0) {
    if (n % 2) {
      p = p * a;
    }
    n >>= 1;
    a *= a;
  }
  return p;
}
long long power(long long a, long long n, long long mod) {
  long long p = 1;
  while (n > 0) {
    if (n % 2) {
      p = p * a;
      p %= mod;
    }
    n >>= 1;
    a *= a;
    a %= mod;
  }
  return p % mod;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long lcm(long long a, long long b) { return a * (b / gcd(a, b)); }
int main() {
  long long t = 1;
  while (t--) {
    long double a, b, c;
    cin >> a >> b >> c;
    long double val1 = (b * b - 4 * a * c);
    val1 = sqrt(val1);
    long double val2 = -1 * (b)-val1;
    long double val3 = -1 * (b) + val1;
    val2 = val2 / (2 * a);
    val3 = val3 / (2 * a);
    cout << fixed << setprecision(15) << max(val2, val3) << "\n";
    cout << fixed << setprecision(15) << min(val2, val3) << "\n";
  }
  return 0;
}
