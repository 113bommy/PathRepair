#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int n_ = 1e5 + 1000;
long long gcd(long long a, long long b) { return (a ? gcd(b % a, a) : b); }
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
long long a, b, c, l = 1, r = 2e9;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> a >> b >> c;
  if (c == 0) {
    if (a == b)
      cout << "YES\n";
    else
      cout << "NO\n";
    return 0;
  }
  l = b - a;
  r = l / c;
  cout << (l >= 0 && r * c == l ? "YES\n" : "NO\n");
  return 0;
}
