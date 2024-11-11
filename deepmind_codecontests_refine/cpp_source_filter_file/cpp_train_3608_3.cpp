#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long mypow(long long base, long long exp) {
  long long res = 1;
  while (exp) {
    if (exp & 1) res = (res * base) % mod;
    exp >>= 1, base = (base * base) % mod;
  }
  return res;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long mult(long long a, long long b) {
  if (a < 0) {
    a += mod;
  }
  if (b < 0) {
    b += mod;
  }
  return ((a % mod) * (b % mod)) % mod;
}
long long add(long long a, long long b) {
  if (a < 0) {
    a += mod;
  }
  if (b < 0) {
    b += mod;
  }
  return (a % mod + b % mod) % mod;
}
long long sub(long long a, long long b) {
  if (a < 0) {
    a += mod;
  }
  if (b < 0) {
    b += mod;
  }
  return (a % mod + mod - b % mod) % mod;
}
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << " | ";
  err(++it, args...);
}
const long long inf = 1e18;
const int nax = 1e5 + 5;
void SolveTestCase() {
  long long n;
  cin >> n;
  long long a[n];
  long long sum = 0;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  long long sum2 = 0;
  for (long long i = 0; i < n; i++) {
    sum2 += a[i];
    if (sum2 >= (sum) / 2) {
      cout << i + 1;
      break;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  for (long long i = 0; i < t; i++) {
    SolveTestCase();
  }
  return 0;
}
