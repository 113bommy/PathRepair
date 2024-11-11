#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
long long a[24][26], f1[1 << 12][26], f2[1 << 12][26], f[1 << 23], ans[1 << 23],
    dp[30], n;
long long ans2[1 << 23], d1, d2;
void phantap() {
  memset(f1, -1, sizeof f1);
  memset(f2, -1, sizeof f2);
  d1 = n >> 1, d2 = n - d1;
  for (long long i = 0; i < (1 << d1); i++) {
    vector<long long> tmp;
    for (long long j = 0; j < d1; j++)
      if ((i >> j) & 1) tmp.emplace_back(j);
    for (long long j : tmp)
      for (long long k = 0; k < 26; k++)
        f1[i][k] = (f1[i][k] == -1 ? a[j + 1][k] : min(f1[i][k], a[j + 1][k]));
  }
  for (long long i = 1; i < (1 << d1); i++)
    for (long long j = 0; j < 26; j++)
      if (f1[i][j] == -1) f1[i][j] = 0;
  for (long long i = 0; i < (1 << d2); i++) {
    vector<long long> tmp;
    for (long long j = 0; j < d2; j++)
      if ((i >> j) & 1) tmp.emplace_back(j);
    for (long long j : tmp)
      for (long long k = 0; k < 26; k++)
        f2[i][k] = (f2[i][k] == -1 ? a[j + d1 + 1][k]
                                   : min(f2[i][k], a[j + d1 + 1][k]));
  }
  for (long long i = 1; i < (1 << d2); i++)
    for (long long j = 0; j < 26; j++)
      if (f2[i][j] == -1) f2[i][j] = 0;
  for (long long i = 0; i < 26; i++) f1[0][i] = f2[0][i] = 1e9;
}
long long calc(long long m1, long long m2) {
  if (m1 == 0 && m2 == 0) return 0;
  vector<long long> tmp(26);
  memset(dp, 0, sizeof dp);
  for (long long i = 0; i < 26; i++) tmp[i] = min(f1[m1][i], f2[m2][i]);
  long long ans = 0, cnt = 0;
  dp[0] = 1ll;
  for (long long i = 0; i < 26; i++) {
    if (tmp[i]) {
      long long k = tmp[i];
      cnt++;
      dp[cnt] = ((k + 1) * dp[cnt - 1]) % mod;
    }
  }
  if (dp[cnt] < 0) dp[cnt] += mod;
  if ((__builtin_popcount(m1) + __builtin_popcount(m2)) & 1)
    return dp[cnt];
  else
    return (mod - dp[cnt]) % mod;
}
void ghep() {
  for (long long i = 0; i < (1 << n); i++) {
    long long mask2 = i >> d1, mask1 = i % (1 << d1);
    f[i] = calc(mask1, mask2);
  }
}
void SOS() {
  for (long long i = 0; i < (1 << n); i++) ans[i] = f[i];
  ans[0] = 0;
  for (long long i = 0; i < n; i++)
    for (long long mask = 0; mask < (1 << n); mask++) {
      if ((mask >> i) & 1) ans[mask] += ans[mask ^ (1 << i)];
      if (ans[mask] >= mod) ans[mask] -= mod;
    }
  long long res = 0;
  for (long long i = 0; i < (1 << n); i++) {
    long long k = __builtin_popcount(i), tmp = k;
    for (long long j = 0; j < n; j++)
      if ((i >> j) & 1) tmp += j;
    ans2[i] = ans[i] * k * tmp;
    res ^= ans2[i];
  }
  cout << res;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    string s;
    cin >> s;
    for (char c : s) a[i][c - 'a']++;
  }
  phantap();
  ghep();
  SOS();
}
