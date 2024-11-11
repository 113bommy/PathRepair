#include <bits/stdc++.h>
using namespace std;
const char el = '\n';
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  cin.ignore();
  int maxm = 0, maxn = 0, maxk = 0;
  vector<vector<int>> queries(T);
  for (int t = 0; t < T; ++t) {
    int m, n, k;
    cin >> m >> n >> k;
    cin.ignore();
    maxm = max(maxm, m);
    maxn = max(maxn, n);
    maxk = max(maxk, k);
    queries[t] = {m, n, k};
  }
  vector<vector<vector<int>>> dp(
      maxm + 1, vector<vector<int>>(maxn + 1, vector<int>(maxk + 1, 0)));
  for (int a = 1; a <= maxm; ++a) {
    for (int b = 1; b <= maxn; ++b) {
      for (int k = 1; k <= min(maxk, a * b); ++k) {
        if (a * b == k) {
          dp[a][b][k] = 0;
          continue;
        }
        int vertcand = INT_MAX, horcand = INT_MAX;
        for (int j = 1; j <= b / 2; ++j) {
          if (a * j >= k) {
            vertcand = min(vertcand, a * a + dp[a][j][k]);
          } else {
            vertcand = min(vertcand, a * a + dp[a][b - j][k - a * j]);
          }
        }
        for (int i = 1; i <= a / 2; ++i) {
          if (i * b >= k) {
            horcand = min(horcand, b * b + dp[i][b][k]);
          } else {
            horcand = min(horcand, b * b + dp[a - i][b][k - i * b]);
          }
        }
        dp[a][b][k] = min(vertcand, horcand);
      }
    }
  }
  for (auto& v : queries) {
    int m = v[0], n = v[1], k = v[2];
    cout << dp[m][n][k] << el;
  }
}
