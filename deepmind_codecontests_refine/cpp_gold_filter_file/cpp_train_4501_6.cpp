#include <bits/stdc++.h>
const uint64_t MOD = 998244353;
const uint64_t MAX_N = 2e5;
uint64_t fact[MAX_N + 5], invFact[MAX_N + 5];
uint64_t fast_pow(uint64_t x, uint64_t pw) {
  if (pw == 0) {
    return 1;
  } else if (pw % 2 == 0) {
    uint64_t aux = fast_pow(x, pw / 2);
    return (aux * aux) % MOD;
  } else {
    return (x * fast_pow(x, pw - 1)) % MOD;
  }
}
void precompute() {
  fact[0] = 1;
  invFact[0] = fast_pow(fact[0], MOD - 2);
  for (uint64_t i = 1; i <= MAX_N; i++) {
    fact[i] = (fact[i - 1] * i) % MOD;
    invFact[i] = fast_pow(fact[i], MOD - 2);
  }
}
uint64_t get_comb(uint64_t x, uint64_t y) {
  return (((fact[x] * invFact[x - y]) % MOD) * invFact[y]) % MOD;
}
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  precompute();
  uint64_t n, m;
  std::cin >> n >> m;
  if (n == 2) {
    std::cout << 0 << '\n';
    return 0;
  }
  uint64_t pw = 1;
  for (uint64_t i = 0; i < n - 3; i++) {
    pw = (pw * 2) % MOD;
  }
  uint64_t ans = 0;
  for (uint64_t i = n - 1; i <= m; i++) {
    ans = (ans + ((get_comb(i - 1, n - 3) * (i - n + 2)) % MOD) * pw) % MOD;
  }
  std::cout << ans << '\n';
}
