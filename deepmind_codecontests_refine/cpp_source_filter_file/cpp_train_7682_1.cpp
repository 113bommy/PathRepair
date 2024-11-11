#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

vector<ll> fact;
vector<ll> ifact;
const int mod = 1e9 + 7;

ll mod_pow(ll x, ll n, ll mod) {
  if (n == 0) return 1;
  ll ret = (n & 1) ? x : 1;
  ll half = mod_pow(x, n / 2, mod);
  ret *= half * half % mod;
  return ret % mod;
}

void init() {
  fact.resize(200001);
  ifacr.resize(200001);
  fact[0] = 1, ifact[0] = 1;
  for(int i = 1; i <= 200000; i++) {
    fact[i] = (fact[i - 1] * i) % mod;
    ifact[i] = mod_pow(fact[i], mod - 2, mod);
  }
}

ll comb(ll n, ll k) {
  return fact[n] * ifact[n - k] % mod * ifact[k] % mod;
}

int main() {
  init();
  ll N, M, K;
  cin >> N >> M >> K;
  ll sum = 0;
  for(ll d = 1; d <= N; d++) {
    sum += (d * (N - d)) % mod * M % mod * M % mod;
    sum %= mod;
  }
  for(ll d = 1; d <= M; d++) {
    sum += (d * (M - d)) % mod * N % mod * N % mod;
    sum %= mod;
  }
  cout << sum * comb(N * M - 2, K - 2) % mod << endl;
}