#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
inline void smin(T &a, U b) {
  if (a > b) a = b;
}
template <typename T, typename U>
inline void smax(T &a, U b) {
  if (a < b) a = b;
}
vector<int> adj[100100];
int dp[100100];
bool dfs(int u, int fa = 0) {
  int c[6] = {
      0,
  };
  for (int i = adj[u].size(); i--;) {
    int v = adj[u][i];
    if (v == fa) continue;
    if (!dfs(v, u)) return false;
    c[dp[v]]++;
  }
  if (!c[1] && !c[2] && !c[3] && !c[4] && !c[5]) {
    if (c[0] <= 1)
      dp[u] = 0;
    else if (c[0] == 2)
      dp[u] = 1;
    else
      dp[u] = 2;
  } else {
    if (c[5] || c[2] > 2 || c[3] > 1 || c[3] && (c[1] + c[2] || c[0] > 2) ||
        c[4] && (c[0] + c[1] + c[2] + c[3]) > 1)
      return false;
    if (c[3] && (c[0] + c[1] + c[2]) >= 2 ||
        c[4] && (c[0] + c[1] + c[2] + c[3]))
      dp[u] = 5;
    else if (c[3] && c[0] + c[1] + c[2] || c[4])
      dp[u] = 4;
    else if (c[2] > 1 || c[3])
      dp[u] = 3;
    else
      dp[u] = 2;
  }
  return true;
}
int main() {
  int n, u, v;
  cin >> n;
  for (int i = 1; i < n; i++) {
    scanf("%d %d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int t = 99, ans = 0;
  while (t--) {
    if (dfs(rand() % n + 1)) ans++;
  }
  puts(ans >= 33 ? "Yes" : "No");
  return 0;
}
