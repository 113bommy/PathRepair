#include <bits/stdc++.h>
using namespace std;
const int MAX = 85;
const int INF = INT_MAX / 3;
vector<vector<pair<int, int>>> G;
int dp[MAX][MAX][MAX][MAX];
int go(int u, int l, int r, int k) {
  if (k == 0) return 0;
  int &res = dp[u][l][r][k];
  if (res == -1) {
    res = INF;
    for (int i = 0; i < G[u].size(); i++) {
      int first = G[u][i].first;
      int c = G[u][i].second;
      if (u == first) continue;
      if (first > l && first < r) {
        if (u < first)
          res = min(res, c + go(first, u, r, k - 1));
        else
          res = min(res, c + go(first, l, u, k - 1));
      }
    }
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  memset(dp, -1, sizeof dp);
  int n, k;
  cin >> n >> k;
  G = vector<vector<pair<int, int>>>(n + 2);
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    G[a].push_back(pair<int, int>(b, c));
  }
  int ans = INF;
  for (int i = 1; i <= n; i++) {
    ans = min(ans, go(i, 0, n + 1, k - 1));
  }
  if (ans >= INF) ans = -1;
  cout << ans;
}
