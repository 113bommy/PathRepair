#include <bits/stdc++.h>
using namespace std;
bool prime(unsigned long long n) {
  bool p = true;
  for (unsigned long long i = 2; i <= pow(n, 0.5); i++) {
    if (n % i == 0) {
      p = false;
      break;
    }
  }
  if (n <= 1) p = false;
  return p;
}
unsigned long long gcd(unsigned long long x, unsigned long long y) {
  if (x == 0) return y;
  return gcd(y % x, x);
}
unsigned long long lcm(unsigned long long x, unsigned long long y) {
  return x * y / gcd(x, y);
}
unsigned long long p(unsigned long long x, unsigned long long y,
                     unsigned long long p) {
  unsigned long long ans = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y % 2 == 1) ans = (ans * x) % p;
    y /= 2;
    x = (x * x) % p;
  }
  return ans;
}
unsigned long long fib(unsigned long long n) {
  unsigned long long a = 0, b = 1, c, i;
  if (n == 0) return a;
  for (i = 2; i <= n; i++) {
    c = a + b;
    a = b;
    b = c;
  }
  return b;
}
unsigned long long ceiling(unsigned long long a, unsigned long long b) {
  return (a + b - 1) / b;
}
vector<long long> sieve(long long n) {
  bool prime[n + 1];
  memset(prime, true, sizeof(prime));
  for (long long p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (long long i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
  vector<long long> ans;
  for (long long p = 2; p <= n; ++p) {
    if (prime[p]) ans.push_back(p * p);
  }
  return ans;
}
void solve() {
  int n, ans = 0;
  string s;
  cin >> n >> s;
  for (int i = n; i < s.length(); i += 1) {
    ans = (s[i - 1] == s[i - 2] && s[i - 1] == s[i - 3] ? ++ans : ans);
  }
  cout << ans;
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  solve();
}
