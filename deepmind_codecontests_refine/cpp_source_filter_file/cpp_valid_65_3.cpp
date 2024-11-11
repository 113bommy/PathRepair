#include <bits/stdc++.h>
using namespace std;
int xm[4] = {-1, 1, 0, 0};
int ym[4] = {0, 0, -1, 1};
const int MOD = 998244353;
const int MAXN = 1e5 + 5;
const long long POW = 9973;
int main() {
  long long n, m;
  cin >> n >> m;
  long long l[n], r[n];
  for (int i = 0; i < n; i++) cin >> l[i] >> r[i];
  vector<long long> dp(m + 1, 0);
  for (int i = m; i >= 1; i--) {
    long long mn = 0;
    long long ar[n];
    long long ava;
    vector<vector<long long>> tdp;
    for (int j = 0; j < n; j++) {
      long long tmp;
      if (l[j] % i == 0) {
        tmp = l[j];
        mn += l[j];
      } else {
        tmp = l[j] - l[j] % i;
        tmp += i;
        if (tmp > r[j]) goto skip;
        mn += tmp;
      }
      ar[j] = (r[j] - tmp) / i;
    }
    ava = (m - mn) / i;
    if (ava < 0) goto skip;
    tdp = vector<vector<long long>>(n, vector<long long>(ava + 1, 0));
    for (int j = 0; j < n; j++) {
      if (j == 0) {
        for (int l = 0; l <= ar[j]; l++) {
          if (l > ava) break;
          tdp[0][l] = 1;
        }
        continue;
      }
      vector<long long> pref(ava + 1, 0);
      for (int l = 0; l <= ava; l++) {
        pref[l] += tdp[j - 1][l];
        pref[l] %= MOD;
        if (l + ar[j] + 1 <= ava) {
          pref[l + ar[j] + 1] =
              (pref[l + ar[j] + 1] + MOD - tdp[j - 1][l]) % MOD;
        }
      }
      long long tot = 0;
      for (int l = 0; l <= ava; l++) {
        tot += pref[l];
        tot %= MOD;
        tdp[j][l] = tot;
      }
    }
    for (int l = 0; l <= ava; l++) {
      dp[i] += tdp[n - 1][l];
      dp[i] %= MOD;
    }
    for (int j = i * 2; j <= m; j += i) dp[i] = (dp[i] + MOD - dp[j]) % MOD;
  skip:;
  }
  cout << dp[1] << "\n";
}
