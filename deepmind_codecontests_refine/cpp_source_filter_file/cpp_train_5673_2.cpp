#include <bits/stdc++.h>
using namespace std;
int par[200005];
int visited[200005];
long long ans[200005], dp[200005], dp1[200005];
vector<int> graph[200005];
long long modulo(long long a, long long b, long long c) {
  long long x = 1LL, y = a;
  while (b > 0LL) {
    if (b % 2LL == 1LL) {
      x = (x * y) % c;
    }
    y = (y * y) % c;
    b /= 2LL;
  }
  return x % c;
}
void dfs(int v) {
  visited[v] = 1;
  for (int i = 0; i < graph[v].size(); i++) {
    int u = graph[v][i];
    if (!visited[u]) {
      dfs(u);
      dp[v] = (dp[v] * (dp[u] + 1)) % 1000000007;
    }
  }
}
void dfs1(int v, int p, long long a) {
  dp1[v] = a + 1;
  par[v] = p;
  for (int i = 0; i < graph[v].size(); i++) {
    int u = graph[v][i];
    if (u == p) continue;
    long long ans = 1;
    if (dp[u] + 1 == 1000000007) {
      for (int j = 0; j < graph[v].size(); j++) {
        int l = graph[v][i];
        if (l != par[v] && l != u) ans = (ans * (dp[l] + 1)) % 1000000007;
      }
      ans = (ans * dp1[v]) % 1000000007;
    } else {
      ans = (((dp[v] * dp1[v]) % 1000000007) *
             modulo(dp[u] + 1, 1000000007 - 2, 1000000007)) %
            1000000007;
    }
    dfs1(u, v, ans);
  }
}
int main() {
  int n, a;
  scanf("%d", &n);
  for (int i = 2; i <= n; i++) {
    scanf("%d", &a);
    graph[a].push_back(i);
    graph[i].push_back(a);
  }
  for (int i = 1; i <= n; i++) {
    dp[i] = dp1[i] = 1, par[i] = -1;
  }
  dfs(1);
  dfs1(1, -1, 0);
  for (int i = 1; i <= n; i++) {
    cout << (dp[i] * dp1[i]) % 1000000007 << " ";
  }
  return 0;
}
