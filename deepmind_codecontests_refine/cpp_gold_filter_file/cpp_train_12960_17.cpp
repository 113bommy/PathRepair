#include <bits/stdc++.h>
using namespace std;
const int maxn = 100 + 10;
int dp[maxn][maxn][2];
int main() {
  int n;
  scanf("%d", &n);
  vector<pair<int, int> > seg;
  for (int i = 1; i <= n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    seg.push_back({x, y});
  }
  seg.push_back({-0x3f3f3f3f, 0});
  sort(seg.begin(), seg.end());
  n++;
  int res = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int p = 0; p < 2; p++) {
        res = max(res, dp[i][j][p]);
        int right = seg[j].first + p * seg[j].second, mx = -0x3f3f3f3f, x, y;
        for (int k = i + 1; k < n; k++) {
          for (int q = 0; q < 2; q++) {
            int newRight = seg[k].first + q * seg[k].second;
            if (newRight > mx) mx = newRight, x = k, y = q;
            dp[k][x][y] =
                max(dp[k][x][y], dp[i][j][p] +
                                     min(seg[k].second, newRight - right) + mx -
                                     newRight);
          }
        }
      }
    }
  }
  printf("%d\n", res);
  return 0;
}
