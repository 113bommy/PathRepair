#include <bits/stdc++.h>
using namespace std;
const int inf = 1000000005;
int n;
vector<int> G[200005];
int dp[200005];
int del[200005];
int m;
void dfs(int v, bool level) {
  for (int i = 0; i < G[v].size(); i++) dfs(G[v][i], !level);
  if (G[v].size() == 0) {
    del[v] = 1;
    dp[v] = 0;
    m++;
    return;
  }
  if (level) {
    dp[v] = inf;
  } else {
    dp[v] = inf;
  }
  int temp = 0;
  for (int i = 0; i < G[v].size(); i++) {
    int &u = G[v][i];
    if (level) {
      if (dp[u] < dp[v]) dp[v] = dp[u], del[v], del[u];
    } else {
      temp += del[u];
    }
  }
  if (!level) {
    for (int i = 0; i < G[v].size(); i++) {
      int &u = G[v][i];
      if (dp[v] > temp - del[u] + dp[u]) {
        dp[v] = temp - del[u] + dp[u];
        del[v] = dp[v] + 1;
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    G[a].push_back(b);
  }
  dfs(1, true);
  printf("%d ", m - dp[1]);
  dfs(1, false);
  printf("%d\n", 1 + dp[1]);
}
