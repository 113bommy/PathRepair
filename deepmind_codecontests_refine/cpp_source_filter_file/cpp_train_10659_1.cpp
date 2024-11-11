#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1000000000")
using namespace std;
int a[1000];
bool was[1000];
int level[1000];
int color[1000];
int c[1000];
int cnt = 0;
void dfs(int u) {
  was[u] = true;
  if (a[u] != 0) {
    if (was[a[u]] == false) dfs(a[u] - 1);
    level[u] = level[a[u] - 1] + 1;
    color[u] = color[a[u] - 1];
    c[color[u]] = u;
  } else {
    level[u] = 1, color[u] = cnt++;
    c[color[u]] = u;
  }
}
int main() {
  int n, x;
  cin >> n >> x;
  bool dp[1001];
  for (int i = 0; i < n; i++) cin >> a[i], was[i] = false, dp[i] = false;
  dp[n] = false;
  for (int i = 0; i < n; i++)
    if (was[i] == false) dfs(i);
  int y = level[x - 1];
  vector<int> knapsack;
  for (int i = 0; i < cnt; i++) {
    if (color[x - 1] == i) continue;
    knapsack.push_back(level[c[i]]);
  }
  dp[0] = true;
  for (int i = 0; i < knapsack.size(); i++) {
    for (int j = n; j >= 0; j--)
      if (j + knapsack[i] <= n) dp[j + knapsack[i]] |= dp[j];
  }
  for (int i = 0; i <= n; i++)
    if (dp[i]) cout << i + y << endl;
  y = y;
  return 0;
}
