#include <bits/stdc++.h>
using namespace std;
char ss[400000];
vector<int> g[400000];
int deg[400000];
int ou[400000];
int dp[400000][26];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  scanf("%s", ss);
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    g[u].push_back(v);
    deg[v]++;
    ou[u]++;
  }
  queue<int> q;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (deg[i] == 0) {
      dp[i][ss[i - 1] - 'a']++;
      q.push(i);
      ans++;
    }
  }
  int max1 = 1;
  while (!q.empty()) {
    int f = q.front();
    q.pop();
    for (int i = 0; i < g[f].size(); i++) {
      int u = g[f][i];
      for (int k = 0; k < 26; k++) {
        dp[u][k] = max(dp[f][k] + (ss[u - 1] - 'a' == k), dp[u][k]);
      }
      deg[u]--;
      if (!deg[u]) {
        q.push(u);
        ans++;
      }
    }
  }
  if (ans != n)
    printf("-1\n");
  else {
    for (int i = 1; i <= n; i++)
      for (int j = 0; j < 26; j++) {
        max1 = max(max1, dp[i][j]);
      }
    printf("%d\n", max1);
  }
}
