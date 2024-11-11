#include <bits/stdc++.h>
using namespace std;
void yup() { cout << "YES" << endl; }
void nope() { cout << "NO" << endl; }
bool comp(pair<long long, long long> a, pair<long long, long long> b) {
  if (a.first == b.first) {
    return a.second > b.second;
  }
  return a.first > b.first;
}
void nthPrime(vector<long long> &primes, long long MAX_SIZE) {
  bool IsPrime[MAX_SIZE];
  memset(IsPrime, true, sizeof(IsPrime));
  for (long long p = 2; p * p < MAX_SIZE; p++) {
    if (IsPrime[p] == true) {
      for (long long i = p * p; i < MAX_SIZE; i += p) IsPrime[i] = false;
    }
  }
  for (long long p = 2; p < MAX_SIZE; p++)
    if (IsPrime[p]) primes.push_back(p);
}
long long min(long long a, long long b) {
  if (a < b) {
    return a;
  }
  return b;
}
long long gcd(long long a, long long b) {
  if (b == 0) {
    return a;
  } else {
    return gcd(b, a % b);
  }
}
long long max(long long a, long long b) {
  if (a > b) {
    return a;
  }
  return b;
}
const long long MAX = 100005;
long long f[MAX] = {0};
long long fib(long long n) {
  if (n == 0) return 0;
  if (n == 1 || n == 2) return (f[n] = 1);
  if (f[n]) return f[n];
  long long k = (n & 1) ? (n + 1) / 2 : n / 2;
  f[n] = (n & 1)
             ? (((fib(k)) % 1000000007 * (fib(k)) % 1000000007) % 1000000007 +
                ((fib(k - 1)) % 1000000007 * (fib(k - 1)) % 1000000007) %
                    1000000007)
             : ((2 * (fib(k - 1)) % 1000000007 + (fib(k)) % 1000000007) *
                (fib(k)) % 1000000007) %
                   1000000007;
  return (f[n]) % 1000000007;
}
bool isPrime(long long n) {
  if (n == 2) {
    return true;
  }
  for (long long i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}
long long maxDiv(long long n) {
  long long res = 1;
  for (long long i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) {
      res = n / i;
      return res;
    }
  }
  return res;
}
bool valid(long long a, long long b, long long n, long long m) {
  return (a >= 0 && b >= 0 && a < n && b < m);
}
int32_t main() {
  long long t;
  cin >> t;
  while (t--) {
    long long a, b;
    cin >> a >> b;
    long long cnt = 0;
    for (long long i = 10; i <= b; i = i * 10) {
      cnt++;
    }
    cout << cnt * a << endl;
  }
}
