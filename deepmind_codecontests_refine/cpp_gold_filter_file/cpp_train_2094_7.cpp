#include <bits/stdc++.h>
using namespace std;
const int inf32 = 1e9 + 9;
const unsigned long long inf64 = 1e18 + 18;
const unsigned long long mod = 1e9 + 7;
const int MAX = 160, LG = 50;
const int N = 51;
const int P = 37;
const unsigned long long MOD = mod;
const long double eps = 1e-12;
map<unsigned long long, unsigned long long> get_prime_divisors(
    unsigned long long k) {
  map<unsigned long long, unsigned long long> res;
  for (unsigned long long i = 2; i * i <= k; ++i) {
    while (k % i == 0) {
      res[i]++;
      k /= i;
    }
  }
  if (k != 1) res[k]++;
  return res;
}
vector<pair<unsigned long long, unsigned long long>> subsolve(
    unsigned long long n, unsigned long long m, unsigned long long k) {
  if (2 * n * m % k != 0) return {};
  auto res = get_prime_divisors(2 * n);
  for (auto& p : get_prime_divisors(m)) {
    res[p.first] += p.second;
  }
  for (auto& p : get_prime_divisors(k)) {
    res[p.first] -= p.second;
  }
  set<unsigned long long> maybe;
  maybe.insert(1);
  for (auto& p : res) {
    for (int i = 0; i < p.second; ++i) {
      vector<unsigned long long> to_add;
      for (auto& x : maybe) {
        if (x * p.first <= n) to_add.push_back(x * p.first);
      }
      for (auto& x : to_add) maybe.insert(x);
    }
  }
  unsigned long long mx = *maybe.rbegin();
  if (2 * n * m / k / mx > m) {
    return {};
  }
  return {{0ll, 0ll}, {mx, 0ll}, {mx, 2ll * n * m / k / mx}};
}
void solve() {
  unsigned long long n, m, k;
  cin >> n >> m >> k;
  auto res = subsolve(n, m, k);
  if (res.size() == 0) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
    for (auto& p : res) {
      cout << p.first << ' ' << p.second << endl;
    }
  }
}
int main() { solve(); }
