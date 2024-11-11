#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O2,no-stack-protector,unroll-loops,fast-math")
const long long maxn = 1e5 + 400, maxm = 3e3 + 10, lg = 61, mod = 998244353,
                inf = 1e18;
long long pwm(long long a, long long b) {
  if (b == 0) return 1;
  if (b % 2) return a * pwm(a, b - 1) % mod;
  long long ret = pwm(a, b / 2);
  return ret * ret % mod;
}
long long n, m, sg, sb, eg, eb, w[maxn], cc[maxm * 2];
bool mashti[maxn];
long long dp[maxm][maxm];
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> mashti[i];
  for (int i = 0; i < n; i++) cin >> w[i], (mashti[i] ? sg : sb) += w[i];
  for (int i = -m; i <= m; i++)
    if (sg + sb + i >= 0) cc[i + maxm] = pwm(sg + sb + i, mod - 2);
  dp[0][0] = 1;
  for (int i = 0; i <= m; i++)
    for (int j = 0; j <= m; j++) {
      dp[i + 1][j] += (dp[i][j] * (sg + i) % mod) * cc[i - j + maxm] % mod,
          dp[i + 1][j] %= mod;
      dp[i][j + 1] += (dp[i][j] * (sb - j) % mod) * cc[i - j + maxm] % mod,
          dp[i][j + 1] %= mod;
    }
  eg = sg;
  for (int i = 0; i <= m; i++) eg += dp[i][m - i] * i % mod, eg %= mod;
  eb = sb;
  for (int i = 0; i <= m; i++)
    eb -= dp[m - i][i] * i % mod, eb += mod, eb %= mod;
  long long isg = pwm(sg, mod - 2), isb = pwm(sb, mod - 2);
  for (int i = 0; i < n; i++) {
    if (mashti[i])
      cout << (eg * w[i] % mod) * isg % mod << endl;
    else
      cout << (eb * w[i] % mod) * isb % mod << endl;
  }
  return 0;
}
