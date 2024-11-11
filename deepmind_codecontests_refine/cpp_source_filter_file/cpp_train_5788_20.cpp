#include <bits/stdc++.h>
using namespace std;
const double sn = 1e-6;
const int siz = 200005;
int n, k;
long long ans;
vector<int> adj[siz];
vector<int> child[siz];
bool vis[siz];
struct cost {
  int n, moves;
};
cost dp[siz][6];
void makerooted(int i) {
  vis[i] = true;
  int sz = adj[i].size();
  for (int j = 0; j < sz; j++) {
    if (!vis[adj[i][j]]) {
      child[i].push_back(adj[i][j]);
      makerooted(adj[i][j]);
    }
  }
}
void dfs(int i) {
  dp[i][0] = {1, 0};
  int sz = child[i].size();
  for (int j = 0; j < sz; j++) {
    int ch = child[i][j];
    dfs(ch);
    for (int l = 0; l < k; l++) {
      dp[i][(l + 1) % k].n += dp[ch][l].n;
      dp[i][(l + 1) % k].moves += dp[ch][l].moves;
      if ((l + 1) % k == 0) dp[i][0].moves += dp[ch][l].n;
    }
  }
}
void solve(int i, int p) {
  if (p != 0) {
    cost arr[6] = {};
    for (int j = 0; j < k; j++) {
      arr[(j + 1) % k] = dp[i][j];
      if ((j + 1) % k == 0) arr[0].moves += dp[i][j].n;
    }
    for (int j = 0; j < k; j++) {
      arr[j].n = dp[p][j].n - arr[j].n;
      arr[j].moves = dp[p][j].moves - arr[j].moves;
    }
    for (int j = 0; j < k; j++) {
      dp[p][j] = arr[j];
    }
    arr[0].n--;
    for (int j = 0; j < k; j++) {
      dp[i][(j + 1) % k].n += arr[j].n;
      dp[i][(j + 1) % k].moves += arr[j].moves;
      if ((j + 1) % k == 0) dp[i][0].moves += arr[j].n;
    }
  }
  for (int j = 0; j < k; j++) {
    ans += dp[i][j].moves + (bool)j * dp[i][j].n;
  }
  int sz = child[i].size();
  for (int j = 0; j < sz; j++) {
    solve(child[i][j], i);
  }
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  makerooted(1);
  dfs(1);
  solve(1, 0);
  printf("%I64d\n", ans);
  return 0;
}
