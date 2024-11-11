#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
struct edges {
  int to, next;
};
edges edge[100010];
int head[100010], num;
int n, color[100010];
long long dp[100010][3];
void add(int u, int v) {
  num++;
  edge[num].to = v;
  edge[num].next = head[u];
  head[u] = num;
}
void dfs(int u) {
  int i;
  for (i = head[u]; i != 0; i = edge[i].next) {
    int v;
    v = edge[i].to;
    dfs(v);
    dp[u][1] =
        (dp[u][1] * (dp[v][1] + dp[v][0]) % mod + dp[u][0] * dp[v][1] % mod) %
        mod;
    dp[u][0] = dp[u][0] * (dp[v][1] + dp[v][0]) % mod;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  int i, j;
  cin >> n;
  for (i = 0; i < n - 1; i++) {
    int v;
    cin >> v;
    add(v, i + 1);
  }
  for (i = 0; i < n; i++) {
    cin >> color[i];
    dp[i][color[i]] = 1;
  }
  dfs(0);
  cout << dp[0][1];
  return 0;
}
