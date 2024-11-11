#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll gcd(ll a, ll b) { return b == 0LL ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a * b) / gcd(a, b); }
ll mod_pow(ll base, ll power, ll mod) {
  base %= mod;
  ll ret = 1LL;
  while (power) {
    if (power & 1) ret = (ret * base) % mod;
    base = (base * base) % mod;
    power >>= 1;
  }
  return ret;
}
vector<ll> primes_global;
vector<ll> seive(ll _upper_bound = 10000000) {
  bitset<10000007> bs;
  bs.set();
  if (_upper_bound > 10000000) _upper_bound = 10000000;
  vector<ll> primes;
  ll _seive_size = _upper_bound;
  bs[0] = bs[1] = 0;
  for (ll i = 2; i <= _seive_size; i++) {
    if (bs[i]) {
      for (ll j = i * i; j <= _seive_size; j += i) bs[j] = 0;
      primes.push_back(i);
    }
  }
  primes_global = primes;
  return primes;
}
bool is_prime(ll _number) {
  if (primes_global.empty()) seive();
  for (int i = 0; primes_global[i] * primes_global[i] <= _number and
                  i < primes_global.size();
       i++) {
    if (_number % primes_global[i] == 0) return false;
  }
  return true;
}
vector<ll> prime_factors(ll _number) {
  if (primes_global.empty()) {
    seive();
  }
  vector<ll> factors;
  ll pf_idx = 0, pf = primes_global[pf_idx];
  if (is_prime(_number)) {
    factors.push_back(_number);
    return factors;
  }
  while (pf * pf <= _number) {
    if (_number % pf == 0) {
      factors.push_back(pf);
      while (_number % pf == 0) _number /= pf;
    }
    pf = primes_global[++pf_idx];
  }
  if (_number != 1) factors.push_back(_number);
  return factors;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin.tie(0);
  int n, m, k, tt;
  cin >> n >> k >> m >> tt;
  int left = k - 1;
  int right = n - k;
  while (tt--) {
    int t;
    cin >> t;
    if (t == 0) {
      int now;
      cin >> now;
      if (now < k) {
        left -= now;
        k = left + 1;
      } else {
        right = now - (k);
      }
      cout << left + right + 1 << " " << k << endl;
    } else {
      int now;
      cin >> now;
      if (now <= k) {
        left++;
        k = left + 1;
      } else {
        right++;
      }
      cout << left + 1 + right << " " << k << endl;
    }
  }
}
