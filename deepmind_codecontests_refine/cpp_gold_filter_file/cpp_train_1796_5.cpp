#include <bits/stdc++.h>
using namespace std;
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
vector<bool> Sieve(long long n) {
  bool prime[n + 1];
  memset(prime, true, sizeof(prime));
  for (long long i = 2; i * i <= n; i++) {
    if (prime[i]) {
      for (long long j = i * i; j <= n; j += i) {
        prime[j] = false;
      }
    }
  }
  vector<bool> primes(n + 1);
  primes[0] = false;
  primes[1] = false;
  for (long long i = 2; i <= n; i++) {
    if (prime[i]) primes[i] = true;
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
bool func(long long n) {
  while (n % 2 == 0) n /= 2;
  while (n % 3 == 0) n /= 3;
  return (n == 1);
}
int32_t main() {
  c_p_c();
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    long long x = n - (k - 1);
    if ((x > 0) && (x & 1)) {
      cout << "YES" << '\n';
      for (long long i = 1; i <= k - 1; i++) cout << "1 ";
      cout << x << '\n';
      continue;
    }
    x = n - 2 * (k - 1);
    if ((x > 0) && (!(x & 1))) {
      cout << "YES" << '\n';
      for (long long i = 1; i <= k - 1; i++) cout << "2 ";
      cout << x << '\n';
      continue;
    }
    cout << "NO" << '\n';
  }
}
