#include <bits/stdc++.h>
using namespace std;
const int iinf = 0x3f3f3f3f;
const long long linf = 0x3f3f3f3f3f3f3f3f;
const int N = 5000;
int n, a[N], f[N + 1], lim[N + 1];
const int mod = 998244353;
void fmod(int& first) { first += mod & first >> 31; }
int Pow(int a, int first) {
  int res = 1;
  for (; first; first >>= 1, a = 1ll * a * a % mod)
    if (first & 1) res = 1ll * res * a % mod;
  return res;
}
int fac[N + 1], ifac[N + 1];
void math_init() {
  fac[0] = 1;
  for (int i = (1), iE = (n + 1); i < iE; i++)
    fac[i] = 1ll * fac[i - 1] * i % mod;
  ifac[n] = Pow(fac[n], mod - 2);
  for (int i = (n)-1, iE = (0) - 1; i > iE; i--)
    ifac[i] = 1ll * ifac[i + 1] * (i + 1) % mod;
}
int A(int u, int v) {
  if (u < 0 || v < 0 || v > u) return 0;
  return 1ll * fac[u] * ifac[u - v] % mod;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> n, math_init();
  for (int i = (0), iE = (n); i < iE; i++) cin >> a[i];
  sort(a, a + n);
  for (int i = (0), iE = (n); i < iE; i++) {
    int l = -1, r = i + 1;
    while (r - l > 1) {
      int mid = (l + r) >> 1;
      if (a[mid] * 2 > a[i])
        r = mid;
      else
        l = mid;
    }
    lim[i + 1] = r;
  }
  f[0] = 1, lim[0] = -1;
  for (int i = (1), iE = (n + 1); i < iE; i++)
    for (int j = (0), jE = (lim[i] + 1); j < jE; j++)
      fmod(f[i] +=
           1ll * f[j] * A(n - 2 - lim[j], lim[i] - lim[j] - 1) % mod - mod);
  if (lim[n] == n - 1)
    cout << f[n] << '\n';
  else
    cout << 0 << '\n';
  return 0;
}
