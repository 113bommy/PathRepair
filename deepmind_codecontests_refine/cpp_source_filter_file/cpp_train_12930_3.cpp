#include <bits/stdc++.h>
using namespace std;
int gcd(int x, int y) { return (!y ? x : gcd(y, x % y)); }
const int maxn = 2e5 + 10;
const int mod = 998244353;
inline int ad(int x, int y) {
  x += y;
  if (x < mod) return x;
  return x - mod;
}
inline int mu(int x, int y) { return 1LL * x * y % mod; }
inline int bpow(int x, int y) {
  int res = 1;
  while (y) {
    if (y & 1) res = mu(res, x);
    x = mu(x, x);
    y >>= 1;
  }
  return res;
}
int fact[maxn], inv[maxn], f[maxn];
int C(int r, int n) {
  if (r < 0 || r > n || n < 0) return 0;
  return mu(fact[n], mu(inv[r], inv[n - r]));
}
void prep() {
  for (int i = 0; i < maxn; i++) fact[i] = (!i ? 1 : mu(i, fact[i - 1]));
  for (int i = 0; i < maxn; i++) inv[i] = bpow(fact[i], mod - 2);
  f[1] = 1;
  f[2] = 1;
  int In2 = bpow(2, mod - 2);
  for (int i = 3; i < maxn; i++) {
    if (i & 1)
      f[i] = bpow(2, i - 1);
    else {
      f[i] = bpow(2, i) - C(i / 2, i);
      f[i] = mu(f[i], In2);
    }
  }
}
int a[maxn];
int32_t main() {
  ios::sync_with_stdio(0), cin.tie(0);
  prep();
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  a[n] = a[0];
  int ch = 0;
  for (int i = 0; i < n; i++)
    if (a[i] == a[i + 1]) ch++;
  int ans = bpow(k, ch);
  int rem = n - ch;
  if (rem == 0) {
    cout << 0 << '\n';
    return 0;
  }
  int ha = 0;
  for (int i = 1; i <= rem; i++) {
    int z1 = bpow(k - 2, rem - i);
    int z2 = mu(f[i], C(i, rem));
    ha = ad(ha, mu(z1, z2));
  }
  ans = mu(ans, ha);
  cout << ans << '\n';
}
