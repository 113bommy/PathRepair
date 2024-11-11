#include <bits/stdc++.h>
using namespace std;
template <typename T>
void chkmax(T &x, T y) {
  x = x > y ? x : y;
}
template <typename T>
void chkmin(T &x, T y) {
  x = x < y ? x : y;
}
template <typename T>
void read(T &x) {
  x = 0;
  int f = 1;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
  x *= f;
}
const int N = 200010, mod = 1e9 + 7;
int main() {
  int n, k;
  read(n), read(k);
  static int fac[N], Inv[N], inv[N];
  fac[0] = fac[1] = Inv[0] = Inv[1] = inv[1] = 1;
  for (int i = 2; i <= n; i++) {
    inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;
    Inv[i] = 1ll * Inv[i - 1] * inv[i] % mod;
    fac[i] = 1ll * fac[i - 1] * i % mod;
  }
  auto C = [&](int n, int m) {
    return 1ll * fac[n] * Inv[m] % mod * Inv[n - m] % mod;
  };
  auto Pow = [&](int x, int y) {
    int ret = 1;
    for (; y; y >>= 1, x = 1ll * x * x % mod)
      if (y & 1) ret = 1ll * ret * x % mod;
    return ret;
  };
  auto S = [&](int n, int m) {
    int ret = 0;
    for (int i = 0; i <= m; i++) {
      int ts = 1ll * C(m, i) * Pow(m - i, n) % mod;
      if ((m - i) & 1)
        (ret += mod - ts) %= mod;
      else
        (ret += ts) %= mod;
    }
    return 1ll * ret * Inv[m] % mod;
  };
  int sx = (S(n, k) + 1ll * (n - 1) * S(n - 1, k) % mod) % mod, sy = 0;
  for (int i = 1, x; i <= n; i++) cin >> x, (sy += x) %= mod;
  cout << 1ll * sx * sy % mod << '\n';
  return 0;
}
