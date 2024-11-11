#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
bool isPrime[1000005] = {false};
vector<long long> prm;
vector<long long> SPF(1000005);
void sieve() {
  isPrime[1] = isPrime[0] = 0;
  long long i;
  for (i = 2; i < 1000005; ++i) isPrime[i] = 1;
  for (i = 2; i * i < 1000005; ++i) {
    if (isPrime[i]) {
      for (long long j = i * i; j < 1000005; j += i) isPrime[j] = 0;
    }
  }
  if (!prm.empty()) prm.clear();
  for (i = 2; i < 1000005; ++i) {
    if (isPrime[i]) prm.push_back(i);
  }
}
bool flip(bool f) {
  if (f) return 0;
  return 1;
}
long long fastPower(long long a, long long b) {
  if (b == 0) return 1;
  long long prod = 1;
  while (b > 0) {
    if (b & 1) prod = prod * a;
    b = b >> 1;
    a = a * a;
  }
  return prod;
}
long long fact(long long n) {
  long long res = 1;
  for (long long i = 2; i <= n; i++) {
    res = (res * (i % mod)) % mod;
  }
  return res;
}
long long nCr(long long n, long long r) {
  return (long double)fact(n) / (long double)(fact(r) * fact(n - r));
}
void printa(bool f) {
  if (f)
    cout << "YES"
         << "\n";
  else
    cout << "NO"
         << "\n";
}
void solve() {
  long long n, m, k;
  cin >> n >> m >> k;
  long long i;
  map<long long, long long> mp;
  for (i = 0; i < n; ++i) {
    long long a, b;
    cin >> a >> b;
    if (mp.find(a) == mp.end()) {
      mp[a] = b;
    } else
      mp[a] = min(b, mp[a]);
  }
  long long sum = 0;
  for (auto x : mp) {
    sum += x.second;
  }
  sum = min(k, sum);
  cout << sum << "\n";
}
int main() {
  int tc = 1;
  while (tc--) {
    solve();
  }
  return 0;
}
