#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long double pi = 3.1415926535897932384626433;
const long long inf = 1e18;
bool isprime(long long n) {
  for (long long i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}
long long factorial(long long n) {
  return (n == 1 || n == 0) ? 1 : n * factorial(n - 1);
}
long long power(long long x, long long y) {
  long long res = 1;
  x = x % mod;
  while (y > 0) {
    if (y & 1) res = ((res % mod) * (x % mod)) % mod;
    y = y >> 1;
    x = ((x % mod) * (x % mod)) % mod;
  }
  return res;
}
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long lcm(long long a, long long b) { return (a / gcd(a, b) * b); }
long long max(long long a, long long b) {
  long long sol = a > b ? a : b;
  return sol;
}
long long min(long long a, long long b) {
  long long sol = a < b ? a : b;
  return sol;
}
long long modular(long long a, long long b, char c) {
  if (c == '+') return ((a % mod) + (b % mod)) % mod;
  if (c == '-') return ((a % mod) - (b % mod)) % mod;
  if (c == '*') return ((a % mod) * (b % mod)) % mod;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n;
  cin >> n;
  long long ans = 0;
  for (long long i = 13; i <= 999983; i++) {
    string s;
    s = to_string(i);
    reverse(s.begin(), s.end());
    long long b = stoll(s);
    if (isprime(b) and b != i and isprime(i)) {
      ans++;
    }
    if (ans == n) {
      cout << i;
      return 0;
    }
  }
}
