#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O2,no-stack-protector,unroll-loops,fast-math")
const long long maxn = 1e6 + 10, maxm = 2e7 + 10, lg = 61, mod = 1e9 + 7,
                inf = 1e18;
long long n, k, d[maxn];
int C[maxm][2], cnt[maxm], ts = 1, wer[maxn], rew[maxn];
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> k;
  wer[1] = rew[1] = 1;
  for (int i = 2; i <= n; i++) {
    wer[i] = rew[i] = 1;
    long long p, w;
    cin >> p >> w;
    d[i] = d[p] ^ w;
  }
  long long ans = 0;
  for (int j = lg; j >= 0; j--) {
    for (int i = 1; i <= n; i++) {
      bool bj = d[i] >> j & 1;
      if (!C[wer[i]][bj]) {
        C[wer[i]][bj] = ++ts = 0;
        cnt[ts] = C[ts][0] = C[ts][1] = 0;
        if (ts == maxm - 10) ts = 0;
      }
      ++cnt[wer[i] = C[wer[i]][bj]];
    }
    long long tot = 0;
    for (int i = 1; i <= n; i++) tot += cnt[C[rew[i]][d[i] >> j & 1]];
    for (int i = 1; i <= n; i++)
      rew[i] = C[rew[i]][(d[i] >> j & 1) ^ (tot < k)];
    if (tot < k) ans ^= (1ll << j), k -= tot;
  }
  cout << ans;
  return 0;
}
