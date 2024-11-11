#include <bits/stdc++.h>
using namespace std;
const int P = 998244353;
using ll = long long;
int n, kk, c;
ll dp[17][(1 << 16) + 1], fc[(1 << 16) + 1], a[100005], fac[105], ifac[105];
ll qpow(ll a, ll b) {
  ll ret = 1;
  while (b) {
    if (b & 1) ret = ret * a % P;
    a = a * a % P;
    b >>= 1;
  }
  return ret;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> kk >> c;
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + n + 1,
       [](int a, int b) { return ((a - kk) ^ a) < ((b - kk) ^ b); });
  dp[0][0] = 1;
  fac[0] = 1;
  for (int i = 1; i <= kk; i++) fac[i] = fac[i - 1] * i % P;
  ifac[kk] = qpow(fac[kk], P - 2);
  for (int i = kk; i > 0; --i) ifac[i - 1] = ifac[i] * i % P;
  int cc = 1, cur = 0;
  for (int i = 1; i <= n; i++) {
    while (cc <= ((a[i] - kk) ^ a[i])) cc <<= 1;
    int nc = cur ^ (cur & (cc - 1));
    for (int i1 = kk; i1 >= 0; --i1) {
      for (int j = 0; j < cc; j++) {
        int nj = nc + j;
        fc[nj] = dp[i1][nj];
        dp[i1][nj] = 0;
      }
      for (int j = 0; j < cc; j++)
        if (fc[nc + j]) {
          int nj = nc + j;
          for (int j1 = 0; i1 + j1 <= kk; j1++)
            dp[i1 + j1][nj ^ (a[i] - j1)] =
                (dp[i1 + j1][nj ^ (a[i] - j1)] + fc[nj] * ifac[j1]) % P;
        }
    }
    cur ^= a[i];
  }
  ll inv = qpow(n, P - 1 - kk);
  for (int i = 0; i < (1 << c); i++)
    cout << dp[kk][i] * fac[kk] % P * inv % P << ' ';
  return 0;
}
