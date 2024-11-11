#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = ll(1e9)+7;

ll modinv(ll a, ll m) {
  return a == 1 ? 1 : m - modinv(m % a, a) * m / a;
}

ll choose(ll n, ll r) {
  r = min(r, n - r);
  if (r < 0) return 0;
  ll num = 1, den = 1;
  for (int i = 0; i < r; i++) {
    num *= (n - i), num %= mod;
    den *= i+1, den %= mod;
  }
  return num * modinv(den, mod) % mod;
}

int main() {
  ll N, M, K; cin >> N >> M >> K;
  ll res = (M + N) % mod * M % mod * N % mod * ((M * N - 1) % mod) % mod;
  res *= modinv(6, mod), res %= mod;
  res *= choose(N * M - 2, K), res %= mod;
  cout << res << '\n';
}