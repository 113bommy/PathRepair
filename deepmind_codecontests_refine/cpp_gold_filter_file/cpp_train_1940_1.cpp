#include <bits/stdc++.h>
const long long MAX_N = 500 + 100;
const long long MOD = 1e9 + 7;
using namespace std;
int n, m;
bool mat[MAX_N][MAX_N];
long long dp[MAX_N][MAX_N];
long long e[MAX_N][MAX_N];
int main() {
  cin >> n;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) cin >> mat[i][j];
  for (int i = 0; i < n; ++i)
    dp[i][1] = e[i][1] = mat[i][(i + 1) % n], dp[i][0] = e[i][0] = 1;
  for (int i = 2; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int u = j;
      int v = (j + i) % n;
      int w = (j + 1) % n;
      int cn = 1;
      while (w != v) {
        if (mat[u][w]) {
          dp[u][i] += e[u][cn] * dp[w][i - cn];
          dp[u][i] %= MOD;
        }
        w++;
        w %= n;
        cn++;
      }
      for (int k = 0; k < i; ++k) {
        e[u][i] += dp[u][k] * dp[(u + k + 1) % n][i - k - 1];
        e[u][i] %= MOD;
      }
      if (!mat[u][v]) e[u][i] = 0;
      dp[u][i] += e[u][i];
      dp[u][i] %= MOD;
    }
  }
  cout << dp[0][n - 1];
  return 0;
}
