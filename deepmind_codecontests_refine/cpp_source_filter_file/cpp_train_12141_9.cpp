#include <bits/stdc++.h>
int n, mod;
std::string s;
int pow(int x, int y, int ans = 1) {
  for (; y; y >>= 1, x = (long long)x * x % mod)
    if (y & 1) ans = (long long)ans * x % mod;
  return ans;
}
bool prime_test(int mod) {
  for (int i = 2; i * i <= mod; ++i)
    if (mod % i == 0) return 0;
  return 1;
}
int prime[100], pt;
void factor_integer() {
  int n = mod - 1;
  for (int i = 2; i * i <= n; ++i)
    if (n % i == 0) {
      prime[pt++] = i;
      while ((n /= i) % i == 0)
        ;
    }
  if (n > 1) prime[pt++] = n;
}
int primitive_root() {
  for (int g = 2;; ++g) {
    bool ok = 1;
    for (int i = 0; i < pt; ++i)
      if (pow(g, (mod - 1) / prime[i]) == 1) {
        ok = 0;
        break;
      }
    if (ok) return g;
  }
  return assert(0), -1;
}
bool check() {
  factor_integer();
  int w = pow(primitive_root(), (mod - 1) / n), ans = 0;
  for (int i = n - 1; ~i; --i) ans = ((long long)ans * w + s[i]) % mod;
  return ans == 0;
}
int main() {
  std::ios::sync_with_stdio(0), std::cin.tie(0);
  std::cin >> n >> s;
  int test = 0;
  for (int i = 0; i < n; ++i) s[i] &= 15;
  for (mod = n + 1; test <= 0; mod += n)
    if (prime_test(mod)) {
      if (!check()) return std::cout << "NO" << '\n', 0;
      ++test;
    }
  return std::cout << "YES\n", 0;
}
