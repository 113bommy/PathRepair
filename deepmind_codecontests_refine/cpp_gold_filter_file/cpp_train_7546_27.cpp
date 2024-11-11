#include <bits/stdc++.h>
using namespace std;
bool debug;
struct Combination {
 private:
  int n;
  long long mod;
  vector<long long> fact, inv, invFact;
  bool isPrimeModulus;
  vector<vector<long long>> memo;

 public:
  Combination(int n, long long mod) : n(n), mod(mod) {
    fact.resize(n + 5);
    fact[0] = 1;
    for (int i = 1; i < n + 5; i++) fact[i] = fact[i - 1] * i % mod;
    inv.assign(n + 5, 0);
    inv[1] = 1;
    invFact.assign(n + 5, 0);
    invFact[0] = invFact[1] = 1;
    for (int i = 2; i < n + 5; ++i) {
      inv[i] = mod - (mod / i) * inv[mod % i] % mod;
      invFact[i] = invFact[i - 1] * inv[i] % mod;
    }
    if (mod == 2 || mod == 3)
      isPrimeModulus = true;
    else if (mod <= 1 || (mod % 2 == 0) || (mod % 3 == 0))
      isPrimeModulus = false;
    else {
      isPrimeModulus = true;
      for (long long p = 5; p * p <= mod; p += 6)
        if (mod % p == 0 || mod % (p + 2) == 0) {
          isPrimeModulus = false;
          break;
        }
    }
    if (!isPrimeModulus) memo.assign(n + 1, vector<long long>(n + 1, -1));
  }
  long long factorial(int i) { return fact[i]; }
  long long inverseFactorial(int i) { return invFact[i]; }
  long long inverse(int i) {
    assert(i < n + 5);
    return inv[i];
  }
  long long P(int n, int k) {
    if (n < 0 || k < 0 || k > n) return 0;
    if (isPrimeModulus) {
      return fact[n] * invFact[n - k] % mod;
    } else {
      long long res = 1;
      for (int i = n; i > 0 && i > n - k; i--) res = res * i % mod;
      return res;
    }
  }
  long long C(int n, int k) {
    if (n < 0 || k < 0 || k > n) return 0;
    if (k == 0 || k == n) return 1;
    if (isPrimeModulus) {
      return fact[n] * invFact[n - k] % mod * invFact[k] % mod;
    } else {
      if (memo[n][k] != -1) {
        return memo[n][k];
      } else {
        return memo[n][k] = (C(n - 1, k - 1) + C(n - 1, k)) % mod;
      }
    }
  }
};
int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  debug = argc > 0;
  int n;
  cin >> n;
  Combination cmb(2 * n, 1000000007);
  long long tot = 0;
  for (int i = 0; i < n; i++) {
    tot = (tot + cmb.C(i + n - 1, i)) % 1000000007;
  }
  cout << ((tot * 2 - n) % 1000000007) << endl;
  return 0;
}
