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
const int N = 1 << 18, mod = 998244353;
int Pow(int x, int y) {
  int ret = 1;
  x = (x + mod) % mod;
  for (; y; y >>= 1, x = 1ll * x * x % mod)
    if (y & 1) ret = 1ll * ret * x % mod;
  return ret;
}
void fwt(int *a, int n) {
  for (int i = 1; i < n; i <<= 1)
    for (int j = 0; j < n; j += i << 1)
      for (int k = 0; k < i; k++) {
        int tx = a[j + k], ty = a[i + j + k];
        a[j + k] = (tx + ty) % mod, a[i + j + k] = (tx - ty + mod) % mod;
      }
}
int main() {
  ios::sync_with_stdio(false);
  int n, K, tx, ty, tz, tmp = 0;
  cin >> n >> K >> tx >> ty >> tz;
  static int a[N], b[N], c[N], ans[N];
  for (int i = 1; i <= n; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    y ^= x, z ^= x, tmp ^= x;
    a[y]++, b[z]++, c[y ^ z]++;
  }
  int m = 1 << K;
  fwt(a, m), fwt(b, m), fwt(c, m);
  for (int i = 0; i < 1 << K; i++) {
    int A = a[i], B = b[i], C = c[i];
    int a0 =
        1ll * ((n + A) % mod + (B + C) % mod) % mod * Pow(4, mod - 2) % mod;
    int a1 = 1ll * (n + A - 2 * a0) % mod * Pow(2, mod - 2) % mod;
    int a2 = 1ll * (n + B - 2 * a0) % mod * Pow(2, mod - 2) % mod;
    int a3 = 1ll * (n + C - 2 * a0) % mod * Pow(2, mod - 2) % mod;
    ans[i] = 1ll * Pow((tx + ty) % mod + tz, a0) * Pow(tx + ty - tz, a1) % mod;
    ans[i] = 1ll * ans[i] * Pow(tx - ty + tz, a2) % mod *
             Pow((tx - ty + mod) % mod - tz, a3) % mod;
  }
  fwt(ans, m);
  int inv = Pow(m, mod - 2);
  for (int i = 0; i < m; i++) cout << 1ll * ans[i ^ tmp] * inv % mod << ' ';
  cout << '\n';
  return 0;
}
