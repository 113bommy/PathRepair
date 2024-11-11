#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
bool used[MAXN];
vector<int> g[MAXN];
int dp[MAXN];
void dfs(int v) {
  if ((int)g[v].size() <= 2) {
    used[v] = 1;
    for (int j = 0; j < (int)g[v].size(); j++) {
      int to = g[v][j];
      if (!used[to]) {
        dfs(to);
      }
    }
  }
}
void solve() {
  int n;
  cin >> n;
  int v, to;
  for (int i = 1; i < n; i++) {
    scanf("%d%d", &v, &to);
    g[v].push_back(to);
    g[to].push_back(v);
  }
  for (int i = 1; i <= n; i++) {
    if ((int)g[i].size() == 1 && !used[i]) {
      dfs(i);
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < (int)g[i].size(); j++) {
      int to = g[i][j];
      if (used[to]) {
        dp[to] = min(2, dp[to] + 1);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    if (used[i]) continue;
    int cur = 0;
    for (int j = 0; j < (int)g[i].size(); j++) {
      int to = g[i][j];
      if (!used[i] && (int)g[to].size() - dp[to] > 1) {
        cur++;
      }
    }
    if (cur > 2) {
      printf("No");
      return;
    }
  }
  printf("Yes");
}
int main() {
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
