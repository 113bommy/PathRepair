#include <bits/stdc++.h>
using namespace std;
long long mod_pow(long long a, long long b, long long mod) {
  long long res = 1, c = a;
  while (b) {
    if (b & 1) res = res * c % mod;
    c = c * c % mod;
    b /= 2;
  }
  return res;
}
long long sol(vector<long long> &a) {
  int n = (int)a.size();
  long long mod = 998244353;
  long long sum = 0;
  long long sum2 = 0;
  long long sum3 = 0;
  for (int i = 0; i < n; i++) {
    sum += a[i];
    sum2 += a[i] * i;
    sum3 += a[i];
    sum %= (mod - 1);
    sum2 %= mod;
    sum3 %= mod;
  }
  long long res = 0;
  long long c1 = mod_pow(2, sum + (mod - 1) - 2, mod);
  for (int i = 0; i < n; i++) {
    res = (res + a[i] * i % mod * i % mod * c1 % mod * (sum3 + mod - 1) % mod) %
          mod;
  }
  sum2 = sum2 * sum2 % mod;
  for (int i = 0; i < n; i++) {
    sum2 = (sum2 + mod - a[i] * i % mod * i % mod) % mod;
  }
  res = (res + sum2 * mod_pow(2, sum - 3 + (mod - 1), mod) % mod * sum3 % mod) %
        mod;
  return res;
}
vector<int> minimum_prime_fuctors(int x) {
  vector<int> res(x + 1);
  vector<int> primes;
  for (int i = 2; i <= x; i++) {
    if (res[i] == 0) {
      res[i] = i;
      primes.push_back(i);
    }
    for (int j = 0;
         j < primes.size() && primes[j] <= res[i] && primes[j] * i <= x; j++) {
      res[i * primes[j]] = primes[j];
    }
  }
  return res;
}
vector<int> mobius_function(int x) {
  vector<int> res(x + 1);
  vector<int> mp = minimum_prime_fuctors(x);
  res[1] = 1;
  for (int i = 2; i <= x; i++) {
    if (mp[i] == mp[i / mp[i]])
      res[i] = 0;
    else
      res[i] = -res[i / mp[i]];
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  int mx = 101010;
  vector<long long> a(mx);
  for (int i = 0; i < n; i++) {
    int v;
    long long x;
    cin >> v >> x;
    a[v] = x;
  }
  vector<int> moe = mobius_function(mx);
  long long res = 0;
  long long mod = 998244353;
  for (int i = 1; i < mx; i++) {
    vector<long long> s(1, 0);
    for (int j = i; j < mx; j += i) {
      s.push_back(a[j]);
    }
    res = (res + mod + sol(s) * i % mod * i % mod * moe[i] % mod) % mod;
  }
  cout << res << "\n";
  return 0;
}
