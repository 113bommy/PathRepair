#include <bits/stdc++.h>
using namespace std;
const int maxi = ~0U >> 1;
const int mn = 100010;
int n, m, tot;
vector<pair<int, int> > mp[mn];
int dp[mn][3];
int vis[mn];
void dpp(int x) {
  vis[x] = 1;
  int max1 = 0, max2 = 0;
  for (int i = 0; i < mp[x].size(); i++) {
    int j = mp[x][i].first;
    int tp = mp[x][i].second;
    if (vis[j])
      continue;
    else
      dpp(j);
    int m0 = tp + dp[j][0];
    dp[x][0] += m0;
    max1 = max(max1, m0 - (dp[j][1] + (1 - tp)));
    max2 = max(max2, max(m0 - (dp[j][2] + tp), m0 - dp[j][1]));
  }
  dp[x][1] = dp[x][0] - max1;
  dp[x][2] = dp[x][0] - max2;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    mp[x].push_back(pair<int, int>(y, 0));
    mp[y].push_back(pair<int, int>(x, 1));
  }
  tot = maxi;
  for (int i = 1; i <= n; i++) {
    memset(vis, 0, sizeof(vis));
    memset(dp, 0, sizeof(dp));
    dpp(i);
    tot = min(tot, min(dp[i][0], min(dp[i][1], dp[i][2])));
  }
  printf("%d\n", tot);
  return 0;
}
