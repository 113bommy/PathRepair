#include <bits/stdc++.h>
using namespace std;
const int maxn = 305;
long long dp[maxn][maxn][6];
int n, x[maxn], y[maxn];
vector<pair<double, pair<int, int>>> seg;
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < 6; k++) dp[i][j][k] = 0;
      if (i == j) dp[i][j][0] = 1;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i != j) {
        int xx = x[i] - x[j], yy = y[i] - y[j];
        seg.push_back({atan2(xx, yy), {i, j}});
      }
    }
  }
  sort(seg.begin(), seg.end());
  int m = seg.size();
  for (int cc = 0; cc < m; cc++) {
    int i = seg[cc].second.first, j = seg[cc].second.second;
    for (int k = 0; k < n; k++)
      for (int f = 0; f < 5; f++) dp[k][j][f + 1] += dp[k][i][f];
  }
  int ret = 0;
  for (int i = 0; i < n; i++) ret += dp[i][i][5];
  cout << ret << endl;
  return 0;
}
