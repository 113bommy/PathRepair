#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target( \
    "avx,avx2,fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
long long MOD = 1e9 + 7;
long long dp[5001][5001];
long long pr[5001];
long long sf[5001];
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0),
      cout << fixed << setprecision(20);
  long long n, a, b, k;
  cin >> n >> a >> b >> k;
  a--, b--;
  dp[0][a] = 1;
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < n; j++) {
      pr[j] = dp[i][j];
      if (j) pr[j] += pr[j - 1];
      pr[j] %= MOD;
    }
    for (int j = n - 1; j > -1; j--) {
      sf[j] = dp[i][j];
      sf[j] += sf[j + 1];
      sf[j] %= MOD;
    }
    for (int j = 0; j < n; j++) {
      long long kek = 0;
      if (j < b && (j + b - 1) / 2 >= j) kek = dp[i][j];
      if (j > b && (j + b) / 2 + 1 <= j) kek = dp[i][j];
      if (j < b) {
        dp[i + 1][j] = (pr[(j + b - 1) / 2] - kek + MOD) % MOD;
      } else {
        if (j > b) dp[i + 1][j] = (sf[(j + b) / 2 + 1] - kek + MOD) % MOD;
      }
    }
  }
  long long sm = 0;
  for (int j = 0; j < n; j++) {
    sm += dp[k][j];
    sm %= MOD;
  }
  cout << sm;
}
