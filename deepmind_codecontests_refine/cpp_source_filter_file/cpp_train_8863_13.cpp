#include <bits/stdc++.h>
using namespace std;
class DebugStream {
} LOG;
template <typename T>
DebugStream &operator<<(DebugStream &s, const T &) {
  return s;
}
const int maxN = 2e3 + 9, maxV = 1e6 + 9, MOD = 998244353, SQ = 335, lg = 20,
          bs = 29;
int n, k;
long long l, fac[maxN][2], flr[3], exi[3], poly[maxN * 2], inve[maxN * 2];
long long fastPow(long long a, long long b) {
  long long ret = 1;
  while (b) {
    if (b & 1) ret = ret * a % MOD;
    b >>= 1;
    a = a * a % MOD;
  }
  return ret;
}
long long tmp[maxN * 2];
void polMul(long long *ans, long long *one, long long *two, int os, int ts) {
  for (int u = 0; u <= os; u++)
    for (int i = 0; i <= ts; i++)
      ans[i + u] = (ans[i + u] + one[u] * two[i]) % MOD;
}
void polDiv(long long *ans, long long *one) {
  long long mgc, ot, cnst = fastPow(flr[2], MOD - 2);
  for (int i = n * 2; i >= 2; i--) {
    ot = one[i] * cnst % MOD;
    mgc = MOD - ot;
    if (mgc >= MOD) mgc -= MOD;
    for (int j = 0, nm = i - 2; j <= 2; j++) {
      one[nm + j] = (one[nm + j] + mgc * flr[j]) % MOD;
      ans[nm + j] = (ans[nm + j] + ot * exi[j]) % MOD;
    }
  }
}
long long integ(long long *poly) {
  long long ret = 0, pot = l;
  for (int i = 0; i <= n * 2; i++, pot = pot * l % MOD)
    ret = (ret + poly[i] * inve[i + 1] % MOD * pot) % MOD;
  return ret;
}
long long ncr(int n, int k) {
  if (k > n) return 0;
  return fac[n][0] * fac[k][1] % MOD * fac[n - k][1] % MOD;
}
long long bse[maxN * 2];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  clock_t begi = clock();
  cin >> n >> k >> l;
  fac[0][0] = fac[0][1] = 1;
  for (long long i = 1; i <= n; i++) {
    fac[i][0] = fac[i - 1][0] * i % MOD;
    fac[i][1] = fastPow(fac[i][0], MOD - 2) % MOD;
  }
  for (int i = 0; i <= n * 2 + 2; i++) inve[i] = fastPow(i, MOD - 2);
  flr[0] = 1;
  exi[1] = 2 * fastPow(l, MOD - 2) % MOD;
  flr[1] = exi[1] * (MOD - 1) % MOD;
  flr[2] = exi[1] * fastPow(l, MOD - 2) % MOD;
  exi[2] = flr[2] * (MOD - 1) % MOD;
  poly[0] = 1;
  for (int i = 0; i < 3; i++) bse[i] = flr[i];
  for (int i = 0, sz = 0; (1 << i) <= n; i++) {
    if (1 << i & n) {
      memset(tmp, 0, sizeof tmp);
      polMul(tmp, poly, bse, sz, 2 * (1 << i));
      memcpy(poly, tmp, sizeof poly);
      sz += 2 * (1 << i);
    }
    memset(tmp, 0, sizeof tmp);
    polMul(tmp, bse, bse, 2 * (1 << i), 2 * (1 << i));
    memcpy(bse, tmp, sizeof poly);
  }
  long long ans = 0;
  for (int i = 0; i <= n; i++) {
    if (i >= k) ans = (ans + integ(poly) * ncr(n, i)) % MOD;
    memset(tmp, 0, sizeof tmp);
    polDiv(tmp, poly);
    memcpy(poly, tmp, sizeof poly);
  }
  cout << ans << '\n';
  LOG << double(clock() - begi) / CLOCKS_PER_SEC << '\n';
}
