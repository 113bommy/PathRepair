#include <bits/stdc++.h>
using namespace std;
long long modexpo(long long x, long long p) {
  long long res = 1;
  x = x % 1000000007;
  while (p) {
    if (p % 2) res = res * x;
    p >>= 1;
    x = x * x % 1000000007;
    res %= 1000000007;
  }
  return res;
}
struct compare {
  bool operator()(const long long a, const long long b) const { return a < b; }
};
const long long nax = 1e5 + 5;
long long sieve[nax];
bool isPrime(long long x) {
  if (x < 2) {
    return false;
  }
  for (long long i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      return false;
    }
  }
  return true;
}
map<long long, long long> mp;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  for (long long i = 2; i < nax; i++) {
    if (sieve[i]) {
      continue;
    }
    sieve[i] = 1;
    for (long long j = 2 * i; j < nax; j += i) {
      sieve[j] = 2;
    }
  }
  vector<long long> primes;
  for (long long i = 2; i < nax; i++) {
    if (sieve[i] == 1) {
      primes.push_back(i);
      mp[i] = 1;
    }
  }
  long long n;
  cin >> n;
  if (isPrime(n)) {
    cout << 1 << " " << n << "\n";
    exit(0);
  }
  if (isPrime(n - 2)) {
    cout << 2 << " " << n - 2 << " " << 2 << "\n";
    exit(0);
  }
  if (isPrime(n - 4)) {
    cout << 3 << " " << 2 << " " << 2 << " " << n - 4 << "\n";
    exit(0);
  }
  long long x = n - 5;
  cout << 3 << "\n";
  for (long long i : primes) {
    if (mp.count(x - i)) {
      cout << 5 << " " << i << " " << n - i << "\n";
      exit(0);
    }
    if (isPrime(x - i)) {
      cout << 5 << " " << i << " " << n - i << "\n";
      exit(0);
    }
  }
  if (n % 3 == 0 && isPrime(n / 3)) {
    cout << n / 3 << " " << n / 3 << " " << n / 3 << "\n";
  }
  assert(false);
}
