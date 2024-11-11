#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int u[2001], v[2001], d[2001];
int dp[81][81][81][81];
int solve(int cur, int mi, int ma, int lef) {
  int& ret = dp[cur][mi][ma][lef];
  if (ret != -1) return ret;
  if (lef == 0) return ret = 0;
  ret = 1e9;
  for (int i = 0; i < m; i++) {
    if (u[i] == cur) {
      if (mi <= v[i] && v[i] <= ma) {
        if (v[i] < cur) {
          ret = min(ret, solve(v[i], mi, cur - 1, lef - 1) + d[i]);
        } else {
          ret = min(ret, solve(v[i], cur + 1, ma, lef - 1) + d[i]);
        }
      }
    }
  }
  return ret;
}
int main() {
  for (int i = 0; i < 81; i++)
    for (int j = 0; j < 81; j++)
      for (int k = 0; k < 81; k++)
        for (int l = 0; l < 81; l++) dp[i][j][k][l] = -1;
  cin >> n >> k;
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> u[i] >> v[i] >> d[i];
  }
  int ret = 1e9;
  for (int i = 1; i <= n; i++) {
    ret = min(ret, solve(i, 1, n, k - 1));
  }
  if (ret < 1e9)
    cout << ret << endl;
  else
    cout << -1 << endl;
  return 0;
}
