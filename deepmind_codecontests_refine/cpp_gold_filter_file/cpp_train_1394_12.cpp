#include <bits/stdc++.h>
using namespace std;
long long dp[210][55][55], comb[51][51], mod = 1e9 + 7;
int n, K, a[3], t, left50, left100, n50, n100;
void add(long long &x, long long y) {
  x += y;
  if (x >= mod) x -= mod;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> K;
  K /= 50;
  for (int i = 0; i <= n; ++i) {
    comb[i][i] = 1;
    comb[i][1] = i;
    comb[i][0] = 1;
  }
  for (int i = 3; i <= n; ++i)
    for (int j = 2; j < i; ++j)
      comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % mod;
  for (int i = 0; i < n; ++i) {
    cin >> t;
    if (t == 50)
      ++a[1];
    else
      ++a[2];
  }
  dp[0][a[1]][a[2]] = 1;
  for (int i = 1; i <= 205; ++i) {
    for (int j = 0; j <= a[1]; ++j)
      for (int k = 0; k <= a[2]; ++k) {
        if (dp[i - 1][0][0]) {
          cout << i - 1 << endl << dp[i - 1][0][0] << endl;
          return 0;
        }
        left50 = (i & 1) ? j : a[1] - j;
        left100 = (i & 1) ? k : a[2] - k;
        for (int o = 0; o <= left50; ++o)
          for (int u = 0; u <= left100; ++u) {
            if (o + u == 0) continue;
            if (o + 2 * u > K) break;
            if (i & 1) {
              n50 = j - o;
              n100 = k - u;
            } else {
              n50 = j + o;
              n100 = k + u;
            }
            long long nw = (dp[i - 1][j][k] * comb[left50][o]) % mod;
            nw = (nw * comb[left100][u]) % mod;
            add(dp[i][n50][n100], nw);
          }
      }
  }
  cout << -1 << endl << 0 << endl;
}
