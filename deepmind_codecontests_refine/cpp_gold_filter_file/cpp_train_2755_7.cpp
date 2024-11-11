#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e5 + 5;
void c_p_c() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
bool isPrime(long long n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long i = 5; i * i <= n; i += 6) {
    if (n % i == 0 || n % (i + 2) == 0) return false;
  }
  return true;
}
set<long long> Sieve(long long n) {
  bool prime[n + 1];
  memset(prime, true, sizeof(prime));
  for (long long i = 2; i * i <= n; i++) {
    if (prime[i]) {
      for (long long j = i * i; j <= n; j += i) {
        prime[j] = false;
      }
    }
  }
  set<long long> primes;
  for (long long i = 2; i <= n; i++) {
    if (prime[i]) primes.insert(i);
  }
  return primes;
}
set<long long> primeFactors(long long n) {
  set<long long> factors;
  while (n % 2 == 0) {
    n /= 2;
    factors.insert(2);
  }
  for (long long i = 3; i <= sqrt(n); i += 2) {
    while (n % i == 0) {
      factors.insert(i);
      n /= i;
    }
  }
  if (n > 2) factors.insert(n);
  return factors;
}
long long power(long long x, unsigned long long y, long long p) {
  long long res = 1;
  x = x % p;
  if (x == 0) return 0;
  ;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
unsigned long long gcd(unsigned long long a, unsigned long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
bool isPower(long long x, long long y) {
  if (x == 1) return (y == 1);
  unsigned long long a = 1;
  while (a < y) a *= x;
  return (a == y);
}
set<long long> getDivisor(long long n) {
  set<long long> ans;
  ans.insert(1);
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      ans.insert(i);
      ans.insert(n / i);
    }
  }
  ans.insert(n);
  return ans;
}
int32_t main() {
  c_p_c();
  long long n;
  cin >> n;
  vector<long long> v(n);
  for (long long i = 0; i < n; i++) cin >> v[i];
  if (n == 3)
    cout << v[2] - v[0] << '\n';
  else {
    long long toRemove = -1;
    long long mn = INT_MAX;
    for (long long i = 1; i < n - 1; i++) {
      long long distance = (v[i] - v[i - 1]) + (v[i + 1] - v[i]);
      if (distance <= mn) {
        toRemove = i;
        mn = distance;
      }
    }
    v.erase(v.begin() + toRemove);
    long long ans = 0;
    for (long long i = 0; i < v.size() - 1; i++) {
      ans = max(ans, v[i + 1] - v[i]);
    }
    cout << ans << '\n';
  }
}
