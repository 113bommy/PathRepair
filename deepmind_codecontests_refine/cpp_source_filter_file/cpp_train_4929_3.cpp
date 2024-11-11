#include <bits/stdc++.h>
using namespace std;
int n, m, r;
int w[60][60][60];
int dp[61][60][60];
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m >> r;
  for (int k = 0; k < (int)(m); k++)
    for (int i = 0; i < (int)(n); i++)
      for (int j = 0; j < (int)(n); j++) cin >> w[k][i][j];
  for (int x = 0; x < (int)(m); x++)
    for (int k = 0; k < (int)(n); k++)
      for (int i = 0; i < (int)(n); i++)
        for (int j = 0; j < (int)(n); j++)
          w[x][i][j] = min(w[x][i][j], w[x][i][k] + w[x][k][j]);
  for (int k = 0; k < (int)(61); k++)
    for (int i = 0; i < (int)(60); i++)
      for (int j = 0; j < (int)(60); j++) dp[k][i][j] = 1e9;
  for (int i = 0; i < (int)(n); i++)
    for (int j = 0; j < (int)(n); j++)
      for (int k = 0; k < (int)(m); k++)
        dp[0][i][j] = min(dp[0][i][j], w[k][i][j]);
  for (int t = 0; t < (int)(61); t++)
    for (int i = 0; i < (int)(n); i++)
      for (int j = 0; j < (int)(n); j++)
        for (int k = 0; k < (int)(n); k++)
          dp[t + 1][i][j] = min(dp[t + 1][i][j], dp[t][i][k] + dp[t][k][j]);
  for (int _ = 0; _ < (int)(r); _++) {
    int s, t, k;
    cin >> s >> t >> k;
    cout << dp[min(k, n)][--s][--t] << endl;
  }
  return 0;
}
