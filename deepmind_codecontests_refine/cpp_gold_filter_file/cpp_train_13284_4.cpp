#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
long long jc[500], inv[500];
long long fpow(long long di, long long top) {
  long long ret = 1;
  while (top) {
    if (top % 2) ret = ret * di % mod;
    di = di * di % mod, top /= 2;
  }
  return ret;
}
void init() {
  jc[0] = inv[0] = 1;
  for (long long i = 1; i <= 400; ++i) jc[i] = jc[i - 1] * i % mod;
  inv[400] = fpow(jc[400], mod - 2);
  for (long long i = 399; i >= 1; --i) inv[i] = inv[i + 1] * (i + 1) % mod;
}
long long C(long long k, long long fro) {
  long long ret = jc[fro] % mod * inv[fro - k] % mod;
  return ret * inv[k] % mod;
}
vector<long long> sth[500];
bool vis[500];
long long siz[500], cnt, n, num[500];
long long dp[510][510];
bool iss(long long a) {
  long long nw = sqrt(a);
  return 1ll * nw * nw == a;
}
long long tot[500];
signed main() {
  cin >> n;
  init();
  for (long long i = 1; i <= n; ++i) cin >> num[i];
  for (long long i = 1; i <= n; ++i) {
    if (!vis[i]) {
      sth[++cnt].push_back(num[i]), vis[i] = 1;
      for (long long j = 1; j <= n; ++j) {
        if (!vis[j] && iss(1ll * num[j] * num[i])) {
          sth[cnt].push_back(num[j]), vis[j] = 1;
        }
      }
    }
  }
  for (long long i = 1; i <= cnt; ++i) siz[i] = sth[i].size();
  dp[0][0] = 1;
  long long tot = 0;
  for (long long i = 1; i <= cnt; ++i) {
    for (long long j = 0; j <= tot; ++j) {
      dp[i - 1][j] %= mod;
      if (dp[i - 1][j] == 0) continue;
      for (long long k = 1; k <= min(siz[i], tot + 1); ++k) {
        for (long long t = 0; t <= min(k, j); ++t) {
          long long ndel = 1ll * dp[i - 1][j] * C(t, j) % mod;
          ndel = ndel * C(k - 1, siz[i] - 1) % mod;
          ndel = ndel * C(k - t, tot + 1 - j) % mod;
          dp[i][j - t + siz[i] - k] += ndel % mod;
        }
      }
    }
    tot += siz[i];
  }
  long long ans = dp[cnt][0] % mod;
  for (long long i = 1; i <= cnt; ++i) ans = ans * jc[siz[i]] % mod;
  if (ans < 0) cout << dp[cnt][0];
  cout << ans;
  return 0;
}
