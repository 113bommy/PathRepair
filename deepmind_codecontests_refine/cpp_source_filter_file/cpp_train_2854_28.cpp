#include <bits/stdc++.h>
using namespace std;
vector<bool> prime(1000000, 1);
long long M = 1e9 + 7;
long long powmodM(long long a, long long b, long long c = M) {
  long long res = 1;
  while (b) {
    if (b & 1) res = (res * a) % M;
    a = (a * a) % M;
    b /= 2;
  }
  return res;
}
long long power(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = (res * a);
    a = (a * a);
    b /= 2;
  }
  return res;
}
long long gcd(long long a, long long b) {
  while (a && b) a > b ? a %= b : b %= a;
  return a + b;
}
long long lcm(long long a, long long b) {
  return (max(a, b) / gcd(a, b)) * min(a, b);
}
vector<long long> sieve(int n) {
  vector<long long> ans;
  prime[0] = false;
  prime[1] = false;
  for (int p = 2; p * p <= n; p++)
    if (prime[p])
      for (int i = p * p; i <= n; i += p) prime[i] = 0;
  for (long long p = (2); p <= (n); ++p)
    if (prime[p]) ans.push_back(p);
  return ans;
}
long long modInverse(long long n, long long p = M) {
  return powmodM(n, p - 2, p);
}
long long nCrModP(long long n, long long r, long long p = M) {
  if (r == 0) return 1;
  long long fac[n + 1];
  fac[0] = 1;
  for (long long i = (1); i <= (n); ++i) fac[i] = fac[i - 1] * i % p;
  return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) %
         p;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, m;
  cin >> n;
  vector<long long> a(n);
  for (long long i = (0); i <= (n - 1); ++i) cin >> a[i];
  if (n < 3) {
    cout << n;
    return 0;
  }
  int maax = 2;
  for (long long i = (2); i <= (n - 1); ++i) {
    if (a[i] == a[i - 1] + a[i - 2]) {
      int curr = 2;
      int left = i - 2, right = 0;
      for (long long j = (i); j <= (n - 1); ++j) {
        if (a[j] != a[j - 1] + a[j - 2]) {
          right = j;
          break;
        }
      }
      if (right == 0) right = n;
      maax = (max(maax, right - left));
      i = right + 1;
    }
  }
  cout << maax;
  return 0;
}
