#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
const int mod = 1e9 + 7;
int qpow(int base, int p) {
  int ans = 1;
  while (p) {
    if (p & 1) ans = 1ll * ans * base % mod;
    base = 1ll * base * base % mod;
    p >>= 1;
  }
  return ans;
}
int inv(int a, int p) { return qpow(a, p - 2); }
int fac[N + 5], inv_fac[N + 5];
void init() {
  fac[0] = inv_fac[0] = 1;
  for (int i = 1; i <= N; i++) fac[i] = 1ll * fac[i - 1] * i % mod;
  inv_fac[N] = inv(fac[N], mod);
  for (int i = N - 1; i >= 1; i--)
    inv_fac[i] = 1ll * inv_fac[i + 1] * (i + 1) % mod;
}
int pre[N + 5], suf[N + 5];
int sqx_lagrange(const vector<int> &x, const vector<int> &y, int k) {
  int n = x.size();
  int a = x[0];
  int b = x[n - 1];
  pre[0] = suf[n - 1] = 1;
  for (int i = 1; i < n; i++) pre[i] = 1ll * pre[i - 1] * (k - x[i - 1]) % mod;
  for (int i = n - 2; i >= 0; i--)
    suf[i] = 1ll * suf[i + 1] * (k - x[i + 1]) % mod;
  int ans = 0;
  for (int i = 0, j = a; i < n; i++, j++) {
    int pro = 1ll * y[i] * pre[i] % mod * suf[i] % mod;
    pro = 1ll * pro * inv_fac[j - a] % mod * inv_fac[b - j] % mod;
    if ((b - j) & 1) pro = -pro;
    ans = (ans + pro) % mod;
  }
  return (ans + mod) % mod;
}
int solve(int n, int k) {
  vector<int> x, y;
  x.push_back(1);
  y.push_back(1);
  for (int i = 1; i <= k + 1; i++) {
    x.push_back(i + 1);
    y.push_back((y[i - 1] + qpow(i + 1, k)) % mod);
  }
  return sqx_lagrange(x, y, n);
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cout.setf(ios::fixed), cout.precision(3);
  init();
  int n, k;
  cin >> n >> k;
  cout << solve(n, k) << '\n';
  return 0;
}
