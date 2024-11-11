#include <bits/stdc++.h>
using namespace std;
vector<int> v[400005];
map<int, int> mp[400005];
vector<pair<int, int> > edg;
int dp[400005];
int dis[400005];
bool vis[400005];
int h[400005];
int col[400005];
int cntr = 0;
int a, b;
int dp2[400005];
vector<int> ans;
void dfs(int x, int p) {
  col[x] = 3 - col[p];
  h[x] = 1;
  vis[x] = 1;
  int cnt = 0, cnt2 = 0;
  bool flag = 0;
  for (auto j : v[x]) {
    if (vis[j]) {
      if (j != p && h[j] == 1) {
        if (col[x] == col[j]) {
          dp2[x]++;
          cntr++;
          a = x;
          b = j;
        }
        cnt++;
      } else if (j != p) {
        if (col[x] == col[j]) {
          dp2[x]--;
        }
        cnt2++;
      }
      continue;
    }
    flag = 1;
    dfs(j, x);
    dp2[x] += dp2[j];
    dp[x] += dp[j];
  }
  dp[x] += -cnt2 + cnt;
  h[x] = 0;
}
void dfs2(int x, int p) {
  h[x] = 1;
  vis[x] = 1;
  for (auto j : v[x]) {
    if (!vis[j]) {
      if (dp2[j] == cntr && dp[j] == cntr) {
        ans.push_back(mp[x][j]);
      }
      dfs2(j, x);
    }
  }
  h[x] = 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int n, m;
  cin >> n >> m;
  for (int i = 1; i < m + 1; i++) {
    int x, y;
    cin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
    mp[x][y] = mp[y][x] = i;
  }
  col[0] = 1;
  for (int i = 1; i < n + 1; i++) {
    if (!vis[i]) dfs(i, 0);
  }
  if (cntr == 1) {
    ans.push_back(mp[a][b]);
  }
  if (cntr == 0) {
    cout << m << '\n';
    for (int i = 1; i < m + 1; i++) {
      cout << i << " ";
    }
    return 0;
  }
  for (int i = 1; i < n + 1; i++) {
    vis[i] = 0;
  }
  for (int i = 1; i < n + 1; i++) {
    dfs2(i, 0);
  }
  cout << ans.size() << '\n';
  sort(ans.begin(), ans.end());
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
}
