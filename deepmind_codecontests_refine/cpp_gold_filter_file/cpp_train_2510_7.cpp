#include <bits/stdc++.h>
using namespace std;
const long double pi = 3.14159265358979323;
const long long mod1 = 1e9 + 7;
const long long mod2 = 1e18;
const long long mod3 = 9e18;
long long power(long long x, long long n) {
  if (n == 0) return 1;
  long long temp = power(x, n / 2);
  if (n % 2 == 0)
    return temp * temp;
  else
    return x * temp * temp;
}
long long gcd(long long a, long long b) {
  if (a < b) return gcd(b, a);
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return (a * b) / (gcd(a, b)); }
void swap(int* a, int* b) {
  int t = *a;
  *a = *b;
  *b = t;
}
bool f(long long x, long long y) { return x > y; }
long long MAX(long long a, long long b) { return a > b ? a : b; }
long long MIN(long long x, long long y) { return x > y ? y : x; }
long long MAX(long long a, long long b, long long c) {
  return MAX(a, MAX(b, c));
}
long long MIN(long long a, long long b, long long c) {
  return MIN(a, MIN(b, c));
}
long long pmod(long long a, long long b, long long mod) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = (ans * a) % mod;
    b /= 2;
    a = (a * a) % mod;
  }
  return ans;
}
bool cmp2(pair<long long, long long>& a, pair<long long, long long>& b) {
  return a.second > b.second;
}
bool isPrime(long long num) {
  bool flag = true;
  for (long long i = 2; i <= num / 2; i++) {
    if (num % i == 0) {
      flag = false;
      break;
    }
  }
  return flag;
}
void solve() {
  long long n;
  cin >> n;
  long long div = 0;
  for (long long i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      if (i * i == n)
        div++;
      else
        div += 2;
    }
  }
  cout << div;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
