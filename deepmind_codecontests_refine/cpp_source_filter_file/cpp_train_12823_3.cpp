#include <bits/stdc++.h>
using namespace std;
int n, m, a[15][4000], aa[15][15], b[4000], c[4000];
int dp[13][1 << 13], dpt[1 << 13];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(10);
  int ttt;
  cin >> ttt;
  for (int tt = 0; tt < ttt; tt++) {
    cin >> n >> m;
    for (int i = 0; i < min(n, m) + 1; i++)
      for (int j = 0; j < (1 << n); j++) dp[i][j] = dpt[j] = 0;
    for (int j = 0; j < m; j++) b[j] = 0;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) cin >> a[i][j], b[j] = max(b[j], a[i][j]);
    for (int i = 0; i < m; i++) c[i] = i;
    sort(c, c + m, [&](int i, int j) { return b[i] > b[j]; });
    m = min(n, m);
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++) aa[i][j] = a[j][c[i]];
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        for (int b = 0; b < (1 << n); b++) dpt[b] = dp[i][b];
        for (int k = 0; k < n; k++)
          for (int b = 0; b < (1 << n); b++)
            if (!(b & (1 << k)))
              dpt[b | (1 << k)] = max(dpt[b | (1 << k)], dpt[b] + aa[i][k]);
        for (int b = 0; b < (1 << n); b++)
          dp[i + 1][b] = max(dp[i + 1][b], dpt[b]);
        int tmp = aa[i][0];
        for (int k = 1; k < n; k++) aa[i][k - 1] = aa[i][k];
        aa[i][n - 1] = tmp;
      }
    }
    cout << dp[n][(1 << n) - 1] << "\n";
  }
}
