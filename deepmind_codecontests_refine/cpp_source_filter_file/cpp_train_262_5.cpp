#include <bits/stdc++.h>
int mod = 1000000007;
using namespace std;
using namespace std;
vector<vector<int> > adj(400005);
int dp[400005];
int parent[400005];
int half;
int cntr = -1;
int n;
int v1 = -1, v2 = -1;
int ans[400005];
void dfs1(int v, int p, int n) {
  dp[v] = 1;
  bool dcn = true;
  vector<int>::iterator it = adj[v].begin();
  for (; it != adj[v].end(); it++) {
    if (*it == p) continue;
    parent[*it] = v;
    dfs1(*it, v, n);
    dp[v] += dp[*it];
    if (dp[*it] > half) dcn = false;
  }
  if (n - dp[v] > half) {
    dcn = false;
  }
  if (dcn && cntr == -1) {
    cntr = v;
  }
}
void dfs2(int v, int val, int p, int n) {
  dp[v] = 1;
  vector<int>::iterator it = adj[v].begin();
  for (; it != adj[v].end(); it++) {
    if (*it == p) continue;
    dfs2(*it, val, v, n);
    dp[v] += dp[*it];
  }
  if (val == half) {
    ans[v] = 1;
    return;
  }
  if (val == v1)
    val = v2;
  else
    val = v1;
  if (n - dp[v] - val <= half) {
    ans[v] = 1;
  }
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  ;
  int n;
  cin >> n;
  half = n / 2;
  memset(ans, 0, sizeof(ans));
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  parent[1] = 0;
  dfs1(1, 0, n);
  vector<int>::iterator it = adj[cntr].begin();
  dp[parent[cntr]] = n - dp[cntr];
  vector<pair<int, int> > v;
  ans[cntr] = 1;
  for (; it != adj[cntr].end(); it++) {
    v.push_back(make_pair(*it, dp[*it]));
    if (dp[*it] >= v1) {
      v2 = v1;
      v1 = dp[*it];
    } else if (dp[*it] > v2) {
      v2 = dp[*it];
    }
  }
  vector<pair<int, int> >::iterator itt = v.begin();
  for (; itt != v.end(); itt++) {
    int u = (*itt).first;
    int val = (*itt).second;
    dfs2(u, val, cntr, n);
  }
  for (int i = 1; i <= n; i++) cout << ans[i] << " ";
}
