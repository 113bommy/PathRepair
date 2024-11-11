#include <bits/stdc++.h>
using namespace std;
int edj[20] = {0};
pair<int, pair<int, int> > par[200];
int dp[(1 << 15)][20];
int main() {
  int n, m, q;
  cin >> n >> m >> q;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    edj[x] |= (1 << y);
    edj[y] |= (1 << x);
  }
  for (int i = 0; i < q; i++)
    cin >> par[i].second.first >> par[i].second.second >> par[i].first,
        par[i].second.first--, par[i].second.second--, par[i].first--;
  for (int i = 1; i < (1 << n); i++) {
    for (int j = 0; j < n; j++) {
      if ((i & (1 << j)) == 0) continue;
      int fuck = i ^ (1 << j);
      int rightmostbit = fuck & (-fuck);
      if (fuck == 0)
        dp[i][j] = 1;
      else {
        for (int cur = fuck; cur > 0; cur = (cur - 1) & fuck) {
          if ((cur & rightmostbit) == 0) continue;
          bool shit = false;
          for (int w = 0; w < q; w++) {
            bool s1 = (cur & (1 << par[w].first));
            bool s2 = (cur & (1 << par[w].second.second));
            bool s3 = (cur & (1 << par[w].second.first));
            if (s1 && (!s2 || !s3)) {
              shit = true;
              break;
            }
            if (!s1 && s2 && s3) {
              shit = true;
              break;
            }
          }
          if (shit) continue;
          for (int w = 0; w < n; w++) {
            if ((cur & (1 << w)) == 0) continue;
            if (((cur | (1 << j)) & edj[w]) != edj[w]) continue;
            dp[i][j] += dp[i ^ cur][j] * dp[cur][w];
          }
        }
      }
    }
  }
  cout << dp[(1 << n) - 1][0] << endl;
}
