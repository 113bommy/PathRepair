#include <bits/stdc++.h>
const int N = 100005;
int n, factor[N], ifactor[N];
int cnt[10][N], pr[10], pt, mod, phi;
int pow(int x, int y, int ans = 1) {
  for (; y; y >>= 1, x = (long long)x * x % mod)
    if (y & 1) ans = (long long)ans * x % mod;
  return ans;
}
void factor_integer(int mod) {
  int tmp = mod;
  phi = mod;
  for (int i = 2; i * i <= tmp; ++i)
    if (tmp % i == 0) {
      phi = phi / i * (i - 1), pr[pt++] = i;
      do tmp /= i;
      while (tmp % i == 0);
    }
  if (tmp > 1) phi = phi / tmp * (tmp - 1), pr[pt++] = tmp;
  for (int i = 0; i < pt; ++i)
    for (int j = 1; j <= n; ++j) cnt[i][j] = cnt[i][j / pr[i]] + j / pr[i];
}
int clear(int x) {
  for (int i = 0; i < pt; ++i)
    while (x % pr[i] == 0) x /= pr[i];
  return x;
}
void init() {
  factor[0] = 1;
  for (int i = 1; i <= n; ++i)
    factor[i] = (long long)factor[i - 1] * clear(i) % mod;
  for (int i = 0; i <= n; ++i) ifactor[i] = pow(factor[i], phi - 1);
}
int C(int x, int y) {
  if (x < y) return 0;
  int prod = (long long)factor[x] * ifactor[y] % mod * ifactor[x - y] % mod;
  for (int i = 0; i < pt; ++i)
    prod = pow(pr[i], cnt[i][x] - cnt[i][y] - cnt[i][x - y], prod);
  return prod;
}
int f(int k) {
  int ans = 0;
  for (int i = k & 1; i <= n; i += 2) {
    ans = (ans + (long long)C(n, i) * C(i, (i + k) / 2)) % mod;
  }
  return ans;
}
int main() {
  std::ios::sync_with_stdio(0), std::cin.tie(0);
  int l, r;
  std::cin >> n >> mod >> l >> r, factor_integer(mod), init();
  std::cout << ((long long)f(l) + f(l + 1) + mod * 2 - f(r + 1) - f(r + 2)) %
                   mod
            << '\n';
  return 0;
}
