#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5, maxk = (1 << 20), inf = 1e9;
int dp[maxk][2];
int ind[20];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  string a, b;
  cin >> a >> b;
  int c = 0, d = 0;
  for (int i = 0; i < k; i++) {
    if (a[i] == '1') {
      c += (1 << i);
    }
    if (b[i] == '1') {
      d += (1 << i);
    }
  }
  for (int i = 0; i < maxk; i++) {
    dp[i][0] = inf;
    dp[i][1] = -inf;
  }
  dp[c][0] = 0;
  dp[d][1] = 0;
  int x, y;
  int c1, d1;
  for (int i = 0; i < k; i++) {
    ind[i] = i;
  }
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    x--;
    y--;
    swap(ind[x], ind[y]);
    c1 = 0;
    d1 = 0;
    for (int j = 0; j < k; j++) {
      c1 += (1 << ind[j]) * (((1 << j) & c) > 0);
      d1 += (1 << ind[j]) * (((1 << j) & d) > 0);
    }
    if (dp[c1][0] == inf) {
      dp[c1][0] = i + 1;
    }
    dp[d1][1] = i + 1;
  }
  int uk = __builtin_popcount(c) + __builtin_popcount(d);
  int sol = 0;
  pair<int, int> range = {1, 1};
  for (int i = (1 << k) - 1; i > -1; i--) {
    if (dp[i][1] - dp[i][0] >= m) {
      if (sol < k + __builtin_popcount(i) * 2 - uk) {
        sol = k + __builtin_popcount(i) * 2 - uk;
        range = {dp[i][0] + 1, dp[i][1]};
      }
    }
    for (int j = 0; j < k; j++) {
      if (i & (1 << j)) {
        dp[i ^ (1 << j)][0] = min(dp[i ^ (1 << j)][0], dp[i][0]);
        dp[i ^ (1 << j)][1] = max(dp[i ^ (1 << j)][1], dp[i][1]);
      }
    }
  }
  cout << sol << '\n';
  cout << range.first << ' ' << range.second << '\n';
  return 0;
}
