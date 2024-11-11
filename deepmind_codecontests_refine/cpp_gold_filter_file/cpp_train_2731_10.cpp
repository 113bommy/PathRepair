#include <bits/stdc++.h>
const int LIM = 2e5 + 5;
using namespace std;
vector<bool> prime;
void SieveOfEratosthenes(long long n) {
  prime.assign(n + 1, 1);
  for (long long p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (long long i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
}
bool isPrime(long long n) {
  if (n < 2) return false;
  for (long long i = 2; i * i <= n; i++)
    if (n % i == 0) return false;
  return true;
}
std::vector<long long> generatePrimeFactors(long long n) {
  std::vector<long long> prime;
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      prime.push_back(i);
      while (n % i == 0) n = n / i;
    }
  }
  if (n != 1) prime.push_back(n);
  return prime;
}
map<long long, long long> generatePrimeFactorization(long long n) {
  map<long long, long long> cnt;
  for (long long i = 2; i * i <= n; i++) {
    while (n && n % i == 0) {
      n /= i;
      cnt[i]++;
    }
  }
  if (n != 1) cnt[n]++;
  return cnt;
}
std::vector<long long> generateFactors(long long n) {
  std::vector<long long> fact;
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      fact.push_back(i);
      if (n / i != i) fact.push_back(n / i);
    }
  }
  if (n != 1) fact.push_back(n);
  sort(fact.begin(), fact.end());
  return fact;
}
long long extendedGCD(long long a, long long b, long long &x, long long &y) {
  if (a == 0) {
    x = 0;
    y = 1;
    return b;
  }
  long long x1, y1, d;
  d = extendedGCD(b % a, a, x1, y1);
  x = y1 - (b / a) * x1;
  y = x1;
  return d;
}
long long gcd(long long a, long long b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
long long multiply(long long a, long long b, long long m);
long long singlemod(long long a, long long m);
long long modpow(long long x, long long n, long long m) {
  if (n == 0) return 1;
  long long res = 1;
  while (n) {
    if (n % 2) res = multiply(res, x, m);
    x = multiply(x, x, m);
    n = n >> 1;
  }
  return singlemod(res, m);
}
long long fastpow(long long x, long long n) {
  if (n == 0) return 1;
  long long res = 1;
  while (n) {
    if (n % 2) res = res * x;
    x = x * x;
    n = n >> 1;
  }
  return res;
}
long long modinverse(long long x, long long m) { return modpow(x, m - 2, m); }
long long add(long long a, long long b, long long m) {
  return (((a % m) + (b % m)) % m);
}
long long substract(long long a, long long b, long long m) {
  return (((a % m) - (b % m) + m) % m);
}
long long multiply(long long a, long long b, long long m) {
  return (((a % m) * (b % m)) % m);
}
long long divide(long long a, long long b, long long m) {
  long long temp = modinverse(b, m);
  return multiply(a, temp, m);
}
long long singlemod(long long a, long long m) { return (((a % m) + m) % m); }
long long eulerstotientfunction(long long n) {
  long long ans = n;
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      while (n % i == 0) n = n / i;
      ans -= ans / i;
    }
  }
  if (n > 1) ans -= ans / n;
  return ans;
}
long long ncr(long long n, long long k, long long m) {
  if (k > n) return 0;
  if (m == 0) {
    long long res = 1;
    k = min(k, n - k);
    for (long long i = 1; i <= k; i++) {
      res *= (n - i + 1);
      res /= i;
    }
    return res;
  } else {
    long long res = 1;
    k = min(k, n - k);
    for (long long i = 1; i <= k; i++) {
      res = multiply(res, n - i + 1, m);
      res = divide(res, i, m);
    }
    return singlemod(res, m);
  }
}
template <class T>
void printVector(const std::vector<T> arr) {
  for (auto i : arr) cout << i << " ";
  cout << '\n';
}
template <class T>
void printArray(T arr[], long long n) {
  for (long long i = 0; i < n; i++) cout << arr[i] << " ";
  cout << '\n';
}
template <class T>
void printUGraph(vector<T> arr[], long long n) {
  for (long long i = 0; i < n; i++) {
    cout << i << " : ";
    for (auto j : arr[i]) cout << j << " ";
    cout << '\n';
  }
}
template <class T>
void printWGraph(vector<T> arr[], long long n) {
  for (long long i = 0; i < n; i++) {
    cout << i << " : ";
    for (auto j : arr[i]) cout << j.fi << "," << j.se << " ";
    cout << '\n';
  }
}
const int N = 1e5 + 5;
int32_t main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  int tc;
  cin >> tc;
  while (tc--) {
    for (int i = 0; i < int(9); i++) {
      string s;
      cin >> s;
      for (auto &c : s)
        if (c == '2') c = '1';
      cout << s << '\n';
    }
  }
  return 0;
}
