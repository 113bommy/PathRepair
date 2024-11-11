#include <bits/stdc++.h>
using namespace std;
long long mul(long long x, long long y, long long mod) {
  long long s = 0;
  for (; y; y /= 2, x = (x + x) % mod)
    if (y & 1) s = (s + x) % mod;
  return s;
}
long long gcd(long long x, long long y) { return y ? gcd(y, x % y) : x; }
long long power(long long x, long long y, long long mo) {
  long long s = 1;
  for (; y; y /= 2, x = mul(x, x, mo))
    if (y & 1) s = mul(s, x, mo);
  return s;
}
bool isPrime(long long x) {
  if (x == 2) return 1;
  for (int T = 10; T; T--) {
    long long a = rand() % (x - 2) + 2;
    if (power(a, x - 1, x) != 1) return 0;
    int p = x - 1;
    for (; p % 2 == 0;) {
      p /= 2;
      long long v = power(a, p, x);
      if (mul(v, v, x) == 1 && v != 1 && v != x - 1) return 0;
    }
  }
  return 1;
}
long long pollard(long long n, int c) {
  long long i = 0, k = 2, x = rand() % (n - 1) + 1, y = x;
  for (;;) {
    x = (mul(x, x, n) + c) % n;
    long long g = gcd((y - x + n) % n, n);
    if (g != 1 && g != n) return g;
    if (x == y) return n;
    if ((++i) == k) y = x, k <<= 1;
  }
}
void getprimes(long long n, vector<long long>& p) {
  if (n == 1) return;
  if (isPrime(n)) {
    p.push_back(n);
    return;
  }
  long long d = n;
  for (int i = 2; d == n; i++) d = pollard(n, i);
  getprimes(d, p);
  getprimes(n / d, p);
}
vector<int> factorize(long long x, vector<long long>& primes) {
  int n = primes.size();
  vector<int> powers(n, 0);
  for (int i = 0; i < n; i++) {
    long long p = primes[i];
    while (x % p == 0) {
      powers[i]++;
      x /= p;
    }
  }
  return powers;
}
long long x, y, a[200000];
int n;
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> x >> y;
  for (int i = 0; i < n; i++) cin >> a[i];
  if (y % x > 0) {
    cout << 0;
    return 0;
  }
  vector<long long> primes;
  getprimes(y, primes);
  auto xpowers = factorize(x, primes);
  auto ypowers = factorize(y, primes);
  int k = primes.size();
  vector<int> ai, aj;
  for (int i = 0; i < n; i++) {
    auto p = factorize(a[i], primes);
    int x = 0;
    for (int j = 0, l = 0; j < k; j++) {
      if (p[j] < xpowers[j]) {
        x = -1;
        break;
      }
      if (ypowers[j] != xpowers[j]) {
        if (p[j] == xpowers[j]) x |= 1 << l;
        l++;
      }
    }
    if (x != -1) ai.push_back(x);
    x = 0;
    if (p[k] == 0) {
      for (int j = 0, l = 0; j < k; j++) {
        if (p[j] > ypowers[j]) {
          x = -1;
          break;
        }
        if (ypowers[j] != xpowers[j]) {
          if (p[j] == ypowers[j]) x |= 1 << l;
          l++;
        }
      }
      if (x != -1) aj.push_back(x);
    }
  }
  long long cnt = 0;
  int ones = 1;
  for (int i = 0; i < k; i++)
    if (ypowers[i] != xpowers[i]) ones <<= 1;
  ones--;
  sort(ai.begin(), ai.end());
  sort(aj.begin(), aj.end());
  vector<pair<int, long long>> ajv, aiv;
  for (int i = 0, n = 0; i <= ai.size(); i++, n++) {
    if (i > 0 && (i == ai.size() || ai[i] != ai[i - 1])) {
      aiv.push_back(make_pair(ai[i - 1], n));
      n = 0;
    }
  }
  for (int i = 0, n = 0; i <= aj.size(); i++, n++) {
    if (i > 0 && (i == aj.size() || aj[i] != aj[i - 1])) {
      ajv.push_back(make_pair(aj[i - 1], n));
      n = 0;
    }
  }
  for (auto aai : aiv)
    for (auto aaj : ajv)
      if ((aai.first | aaj.first) == ones) cnt += aai.second * aaj.second;
  cout << cnt;
  return 0;
}
