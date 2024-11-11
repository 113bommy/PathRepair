#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 100;
bool mark[MAXN];
vector<int> adj[MAXN];
int dp[MAXN], dp2[MAXN]{-1};
void dfs(int v, int par) {
  dp[v] = -1;
  if (mark[v]) dp[v] = 0;
  for (auto i : adj[v])
    if (i != par) {
      dfs(i, v);
      if (~dp[i]) dp[v] = max(dp[v], dp[i] + 1);
    }
}
void dfs2(int v, int par) {
  int mx1 = -1, mx2 = -1;
  for (auto i : adj[v])
    if (i != par) {
      if (dp[i] > mx1) {
        mx2 = mx1;
        mx1 = dp[i];
      } else if (dp[i] > mx2)
        mx2 = dp[i];
    }
  for (auto i : adj[v])
    if (i != par) {
      int dis;
      if (dp[i] == mx1)
        dis = mx2;
      else
        dis = mx1;
      if (~dis) dis += 2;
      dp2[i] = dis;
      if (~dp2[v]) dp2[i] = max(dp2[i], dp2[v] + 1);
      if (mark[i]) dp2[i] = max(dp2[i], -1);
      dfs2(i, v);
    }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  memset(dp, -1, sizeof dp);
  memset(dp2, -1, sizeof dp2);
  int n, m, d;
  cin >> n >> m >> d;
  for (int i = 0, a; i < m; i++) cin >> a, mark[--a] = true;
  for (int i = 0, a, b; i < n - 1; i++) {
    cin >> a >> b;
    a--;
    b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dfs(0, -1);
  if (mark[0]) dp2[0] = 0;
  dfs2(0, -1);
  int ans = 0;
  for (int i = 0; i < n; i++)
    if (dp[i] <= d && dp2[i] <= d) ans++;
  cout << ans << endl;
}
