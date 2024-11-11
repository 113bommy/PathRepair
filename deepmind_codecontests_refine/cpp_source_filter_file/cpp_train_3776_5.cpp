#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O2,no-stack-protector,unroll-loops,fast-math")
const long long maxn = 3e5 + 10, maxm = 1e5 + 10, lg = 21, mod = 998244353,
                inf = 1e18;
long long pwm(long long a, long long b) {
  if (b == 0) return 1;
  if (b % 2) return a * pwm(a, b - 1) % mod;
  return pwm(a * a % mod, b / 2);
}
long long n, m, l[maxn], r[maxn], ad[maxn], a[maxn], b[maxn], hh[maxn][lg],
    nw[lg], fac[maxn], inv[maxn];
long long C(long long n, long long r) {
  if (n < 0 || r < 0 || r > n) return 0;
  return fac[n] * inv[r] % mod * inv[n - r] % mod;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  fac[0] = inv[0] = 1;
  for (int i = 1; i < maxn; i++)
    fac[i] = fac[i - 1] * i % mod, inv[i] = pwm(fac[i], mod - 2);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> l[i] >> r[i];
    ad[l[i]]++, ad[r[i] + 1]--;
  }
  for (int i = 0; i < m; i++) cin >> a[i] >> b[i];
  for (int msk = 0; msk < (1 << m); msk++) {
    set<long long> ss;
    for (int i = 0; i < m; i++)
      if (msk >> i & 1) ss.insert(a[i]), ss.insert(b[i]);
    long long L = 1, R = n;
    for (auto x : ss) L = max(L, l[x]), R = min(R, r[x]);
    if (L <= R) {
      if ((__builtin_popcount(msk)) % 2 == 0)
        hh[L][(long long)(ss.size())]++, hh[R + 1][(long long)(ss.size())]--;
      else
        hh[L][(long long)(ss.size())]--, hh[R + 1][(long long)(ss.size())]++;
    }
  }
  long long sum = 0, tt = 0;
  for (int i = 1; i <= n; i++) {
    tt += ad[i];
    for (int j = 0; j < lg; j++) {
      nw[j] += hh[i][j];
      sum += nw[j] * C(tt - j, i - j) % mod;
      (sum += mod) %= mod;
    }
  }
  cout << sum;
  return 0;
}
