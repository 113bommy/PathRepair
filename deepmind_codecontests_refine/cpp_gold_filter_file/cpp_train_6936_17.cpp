#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e6 + 6;
const int MOD = 1e9 + 7;
int fact[N]{1};
int invFact[N]{1};
int primeD[N]{-1, -1};
int power(int b, int p) {
  int ans = 1;
  while (p) {
    if (p & 1) {
      ans = (ans * 1ll * b) % MOD;
    }
    b = (b * 1ll * b) % MOD;
    p /= 2;
  }
  return ans;
}
void compute() {
  for (int i = 1; i < N; ++i) {
    fact[i] = (fact[i - 1] * 1ll * i) % MOD;
    invFact[i] = power(fact[i], MOD - 2);
    if (primeD[i]) {
      continue;
    }
    primeD[i] = i;
    for (ll j = i * 1ll * i; j < N; j += i) {
      primeD[j] = i;
    }
  }
}
vector<int> getPrimeDivisorsFrequencies(int x) {
  vector<int> frequencies;
  for (int prime = primeD[x]; prime > 0; prime = primeD[x]) {
    int frequency = 0;
    while (x % prime == 0) {
      x /= prime;
      ++frequency;
    }
    frequencies.emplace_back(frequency);
  }
  return frequencies;
}
int ncr(int n, int r) {
  return ((fact[n] * 1ll * invFact[r]) % MOD) * invFact[n - r] % MOD;
}
int main() {
  compute();
  int q;
  cin >> q;
  while (q--) {
    int x, y;
    cin >> x >> y;
    int ans = 1;
    vector<int> f = getPrimeDivisorsFrequencies(x);
    for (int x : f) {
      ans = (ans * 1ll * ncr(x + y - 1, x)) % MOD;
    }
    ans = (ans * 1ll * power(2, y - 1)) % MOD;
    cout << ans << '\n';
  }
  return 0;
}
