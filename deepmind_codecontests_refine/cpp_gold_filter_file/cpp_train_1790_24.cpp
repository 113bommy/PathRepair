#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
clock_t time_p = clock();
void rtime() {
  time_p = clock() - time_p;
  cerr << "Time Taken : " << fixed << (float)(time_p) / CLOCKS_PER_SEC << "\n";
}
bool isPrime(long long n) {
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
  x = x;
  while (y > 0) {
    if (y & 1) res = (res * x) % mod;
    y = y >> 1;
    x = (x * x) % mod;
  }
  return res % mod;
}
long long ncr(long long n, long long r) {
  long long res = 1;
  if (r > n) return 0;
  if (r > n - r) r = n - r;
  for (long long i = 0; i < r; i++) {
    res *= (n - i);
    res /= (i + 1);
  }
  return res;
}
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long lcm(long long a, long long b) { return (a / gcd(a, b) * b); }
long long max(long long a, long long b) {
  long long ans = a > b ? a : b;
  return ans;
}
long long min(long long a, long long b) {
  long long ans = a < b ? a : b;
  return ans;
}
bool cmp(long long x, long long y) { return x > y; }
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    if (n == 2)
      cout << "2\n";
    else if (n % 2 == 0)
      cout << "0\n";
    else
      cout << "1\n";
  }
  rtime();
}
