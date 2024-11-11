#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > V[1005];
int dp[105][105][105][2];
int n, m, k;
bool vis[105][105][105][2];
int rec(int l, int r, int p, int dir) {
  if (p == k) return 0;
  if (l >= r) return 1000000000;
  if (vis[l][r][p][dir]) return dp[l][r][p][dir];
  vis[l][r][p][dir] = 1;
  int ans = 1000000000;
  if (dir == 0) {
    for (int i = 0; i < V[l].size(); ++i) {
      if (V[l][i].first > r || V[l][i].first <= l) continue;
      ans = min(ans, V[l][i].second + rec(l + 1, V[l][i].first, p + 1, 1));
      ans = min(ans, V[l][i].second + rec(V[l][i].first, r, p + 1, 0));
    }
  } else {
    for (int i = 0; i < V[r].size(); ++i) {
      if (V[r][i].first < l || V[r][i].first >= r) continue;
      ans = min(ans, V[r][i].second + rec(V[r][i].first, r - 1, p + 1, 0));
      ans = min(ans, V[r][i].second + rec(l, V[r][i].first, p + 1, 1));
    }
  }
  dp[l][r][p][dir] = ans;
  return ans;
}
int main() {
  ;
  cin >> n >> k;
  ;
  cin >> m;
  --k;
  for (int i = 1; i <= m; ++i) {
    int u, v, c;
    scanf("%d %d %d", &u, &v, &c);
    V[u].push_back(make_pair(v, c));
  }
  int ans = 1000000000;
  if (n == 1 && k == 0) {
    cout << "0" << endl;
    return 0;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      ans = min(ans, rec(i, j, 0, 0));
      ans = min(ans, rec(i, j, 0, 1));
    }
  }
  if (ans == 1000000000)
    cout << "-1" << endl;
  else
    cout << ans << endl;
  return 0;
}
