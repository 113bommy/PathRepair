#include <bits/stdc++.h>
using namespace std;
inline long long Getint() {
  char ch = getchar();
  long long x = 0, fh = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') fh = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    (x *= 10) += ch ^ 48;
    ch = getchar();
  }
  return x * fh;
}
const long long Mod = 998244353;
const int N = 4025;
int K, n, l;
long long f[N][N], fc[N], fiv[N], inv[N];
inline long long Ksm(long long x, long long y) {
  long long tmp = 1;
  while (y) {
    if (y & 1) tmp = tmp * x % Mod;
    y >>= 1;
    if (y) x = x * x % Mod;
  }
  return tmp;
}
int main() {
  n = Getint();
  K = Getint();
  l = Getint();
  fc[0] = fc[1] = fiv[0] = fiv[1] = inv[0] = inv[1] = 1;
  for (int i = 2; i <= N - 1; i++) {
    fc[i] = fc[i - 1] * i % Mod;
    inv[i] = (Mod - Mod / i) * inv[Mod % i] % Mod;
    fiv[i] = fiv[i - 1] * inv[i] % Mod;
  }
  f[0][0] = 1;
  for (int i = 0; i <= 2 * n - 1; i++)
    for (int j = 0; j <= 2 * i; j++) {
      long long val = f[i][j];
      if (!val) continue;
      if (j > 0) (f[i + 1][j - 1] += val * j) %= Mod;
      (f[i + 1][j + 1] += val) %= Mod;
    }
  long long Ans = 0;
  for (int i = 2; i <= 2 * n; i++)
    for (int k = K; k <= 2 * n; k++)
      (Ans += i * f[2 * n - i + 1][k] % Mod * f[i - 1][k] % Mod * fc[k]) %= Mod;
  for (int i = 1; i <= 2 * n - 1; i++)
    for (int k = K; k <= 2 * n; k++)
      (Ans -= i * f[i][k] % Mod * f[2 * n - i][k] % Mod * fc[k]) %= Mod;
  Ans = Ans * inv[2 * n + 1] % Mod * Ksm(f[2 * n][0], Mod - 2) % Mod * l % Mod;
  cout << (Ans % Mod + Mod) % Mod << '\n';
  return 0;
}
