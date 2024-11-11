#include <bits/stdc++.h>
using namespace std;
const int inf = 2e9 + 1e8;
const int maxn = 305;
const int mod = 1e9 + 7;
int n, gcnt;
int arr[maxn], gto[maxn], gsiz[maxn], fact[maxn];
int dp[maxn][maxn];
int c[maxn][maxn];
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  fact[0] = c[0][0] = 1;
  for (int i = 1; i <= n + 1; ++i) {
    fact[i] = (1LL * fact[i - 1] * i) % mod;
    c[i][0] = 1;
    for (int j = 1; j <= i; ++j) {
      c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
    }
  }
  for (int i = 1; i <= n; ++i) cin >> arr[i];
  for (int i = 1; i <= n; ++i)
    if (gto[i] == 0) {
      gto[i] = ++gcnt;
      gsiz[gcnt] = 1;
      for (int j = i + 1; j <= n; ++j) {
        if (gto[j] == 0) {
          long long kv = 1LL * arr[i] * arr[j];
          long long t = sqrt((long double)kv);
          if ((t - 1) * (t - 1) == kv || t * t == kv || (t + 1) * (t + 1) == kv)
            gto[j] = gcnt, gsiz[gcnt] += 1;
          ;
        }
      }
    }
  dp[0][0] = 1;
  int len = 0;
  for (int i = 1; i <= gcnt; ++i) {
    for (int j = 0; j <= max(0, len - 1); ++j) {
      for (int a = 1; a <= min(gsiz[i], len + 1); ++a) {
        for (int b = max(0, a + j - len - 1); b <= min(a, j); ++b) {
          int cnt = (1LL * fact[gsiz[i]] * c[gsiz[i] - 1][a - 1]) % mod;
          cnt = (1LL * cnt * c[j][b]) % mod;
          cnt = (1LL * cnt * c[len + 1 - j][a - b]) % mod;
          dp[i][j - b + gsiz[i] - a] =
              (dp[i][j - b + gsiz[i] - a] + 1LL * cnt * dp[i - 1][j]) % mod;
        }
      }
    }
    len += gsiz[i];
  }
  cout << dp[gcnt][0];
  return 0;
}
