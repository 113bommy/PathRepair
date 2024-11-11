#include <bits/stdc++.h>
using namespace std;
struct edge {
  int v, w;
  edge(int v = 0, int w = 0) : v(v), w(w) {}
};
int n, k, dp[100005][2];
int pos[100005];
vector<edge> G[100005];
bool cmp1(int x, int y) { return dp[x][1] > dp[y][1]; }
void dfs(int u, int p) {
  vector<int> kid;
  for (int i = 0; i < G[u].size(); i++) {
    int v = G[u][i].v;
    if (v == p) continue;
    dfs(v, u);
    dp[v][1] += G[u][i].w;
    kid.push_back(v);
  }
  int num = k - (u != 0);
  sort(kid.begin(), kid.end(), cmp1);
  for (int i = 0; i < kid.size(); i++) pos[kid[i]] = i;
  for (int i = 0; i < min((int)kid.size(), num); i++) dp[u][1] += dp[kid[i]][1];
  int sum = dp[u][1];
  for (int i = 0; i < G[u].size(); i++) {
    int v = G[u][i].v;
    if (v == p) continue;
    if (pos[v] < num) {
      int tmp = 0;
      if (kid.size() > num) tmp = dp[kid[num]][1];
      dp[u][0] = max(dp[u][0], sum - dp[v][1] + tmp + dp[v][0] + G[u][i].w);
    } else
      dp[u][0] = max(dp[u][0], sum + dp[v][0] + G[u][i].w);
  }
}
int main() {
  iostream::sync_with_stdio(0);
  cin >> n >> k;
  for (int i = 1; i < n; i++) {
    int x, y, w;
    cin >> x >> y >> w;
    G[x].push_back(edge(y, w));
    G[y].push_back(edge(x, w));
  }
  dfs(0, -1);
  cout << max(dp[0][0], dp[0][1]);
}
