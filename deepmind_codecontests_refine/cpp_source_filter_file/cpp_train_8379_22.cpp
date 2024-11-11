#include <bits/stdc++.h>
using namespace std;
constexpr double EPS = 1e-9;
constexpr int MAX = int(2e5) + 7;
constexpr int MOD = int(1e9) + 7;
unsigned long long powmod(unsigned long long base, unsigned long long exponent,
                          unsigned long long modulus = MOD) {
  base %= modulus;
  unsigned long long res = 1ULL;
  while (exponent) {
    if (exponent & 1ULL) res = res * base % modulus;
    base = base * base % modulus;
    exponent >>= 1U;
  }
  return res;
}
void run_case() {
  unsigned n;
  cin >> n;
  unsigned ans = 0;
  for (unsigned i = 0; i < n; ++i) {
    ans += powmod(27, n - 1 - i) * powmod(7, i) % MOD;
    ans %= MOD;
  }
  ans *= 20;
  ans %= MOD;
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  run_case();
}
