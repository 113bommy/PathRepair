#include <bits/stdc++.h>
using namespace std;
const int maxn = (int)2e5 + 321;
int n;
int a[maxn];
int x, y;
vector<int> g[maxn];
int dp[maxn], gp[maxn], pr[maxn];
void dfs(int v, int p) {
  for (int i : g[v]) {
    if (i == p) {
      continue;
    }
    pr[i] = v;
    dfs(i, v);
    dp[v] += max(0, dp[i]);
  }
}
void dfs2(int v, int p, int mx) {
  gp[v] = mx + dp[v];
  for (int i : g[v]) {
    if (i == p) {
      continue;
    }
    dfs2(i, v, max(0, dp[v] + mx - max(0, dp[i])));
  }
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] == 0) {
      dp[i] = -1;
    } else {
      dp[i] = 1;
    }
  }
  for (int i = 1; i < n; i++) {
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(1, 1);
  dfs2(1, 1, 0);
  for (int i = 1; i <= n; i++) {
    cout << gp[i] << " ";
  }
}
