#include <bits/stdc++.h>
using namespace std;
const int maxn = 100 + 5;
const int mod = 1e9 + 7;
const int inf = 8e18;
const int del = 728729;
const int K = 1000 + 10;
long long poww(long long a, long long b, long long md) {
  return (!b ? 1
             : (b & 1 ? a * poww(a * a % md, b / 2, md) % md
                      : poww(a * a % md, b / 2, md) % md));
}
long long n;
long long m;
long long r;
long long dist[maxn][maxn][maxn];
long long dp[maxn][maxn][maxn];
long long x;
long long y;
long long k;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> r;
  for (int k = 0; k < m; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> dist[k][i][j];
      }
    }
  }
  for (int k = 0; k < m; k++) {
    for (int t = 0; t < n; t++) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          dist[k][i][j] = min(dist[k][i][j], dist[k][i][t] + dist[k][t][j]);
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      dp[1][i][j] = dist[0][i][j];
      for (int k = 1; k < m; k++) {
        dp[1][i][j] = min(dp[1][i][j], dist[k][i][j]);
      }
    }
  }
  for (int k = 2; k < 75; k++)
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) {
        dp[k][i][j] = dp[k - 1][i][j];
        for (int t = 0; t < n; t++) {
          dp[k][i][j] = min(dp[k][i][j], dp[1][i][t] + dp[k - 1][t][j]);
        }
      }
  for (int i = 0; i < r; i++) {
    cin >> x >> y >> k;
    k = min(k, n);
    x--, y--;
    cout << dp[k + 1][x][y] << "\n";
  }
}
