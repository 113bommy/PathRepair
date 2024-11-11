#include <bits/stdc++.h>
using namespace std;
constexpr long long MOD = 998244353;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  long long n;
  cin >> n;
  mt19937_64 rng((int)chrono::steady_clock::now().time_since_epoch().count());
  map<long long, long long> prime_hash;
  vector<long long> n_hash(n + 1), f_hash(n + 1);
  vector<int> min_primes(n + 1), primes;
  primes.reserve(1e5);
  for (int i = 2; i <= n; i++) {
    if (!min_primes[i])
      min_primes[i] = i, primes.push_back(i), prime_hash[i] = rng();
    for (auto& p : primes) {
      if (i * p > n) break;
      min_primes[i * p] = p;
      if (i % p == 0) break;
    }
  }
  long long rolling = 0;
  for (int i = 2; i <= n; i++) {
    int x = i;
    while (x > 1) {
      n_hash[i] ^= prime_hash[min_primes[x]];
      x /= min_primes[x];
    }
    f_hash[i] = n_hash[i] ^ f_hash[i - 1];
    rolling ^= f_hash[i];
  }
  map<long long, long long> inv_f_hash;
  for (int i = 2; i <= n; i++) inv_f_hash[f_hash[i]] = i;
  if (rolling == 0) {
    cout << n << "\n";
    for (int i = 1; i <= n; i++) cout << i << " ";
  } else if (inv_f_hash.count(rolling)) {
    cout << n - 1 << "\n";
    long long wont = inv_f_hash[rolling];
    for (int i = 1; i <= n; i++)
      if (i != wont) cout << i << " ";
  } else {
    for (int k = 2; k <= n; k++) {
      if (inv_f_hash.count(rolling ^ f_hash[k])) {
        cout << n - 2 << "\n";
        long long wont = inv_f_hash[rolling ^ f_hash[k]];
        for (int i = 1; i <= n; i++)
          if (i != wont && i != k) cout << i << " ";
        return 0;
      }
    }
    cout << n - 3 << "\n";
    for (int i = 1; i <= n; i++)
      if (i != 2 && i != n && i != (n + 1) / 2) cout << i << " ";
  }
  cout << "\n";
}
