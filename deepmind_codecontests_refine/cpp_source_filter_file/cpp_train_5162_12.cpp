#include <bits/stdc++.h>
using namespace std;
long long num[200005][6];
int n, k;
int siz[200005];
long long dp[200005];
vector<int> g[200005];
void dfs1(int u, int fa) {
  siz[u] = 1;
  for (int i = 0; i < g[u].size(); i++) {
    int v = g[u][i];
    if (v == fa) continue;
    dfs1(v, u);
    siz[u] += siz[v];
    for (int j = 1; j < k; j++) {
      num[u][j + 1] += num[v][j];
    }
    num[u][0] += num[v][0];
    num[u][0] += num[v][k];
    num[u][1] += num[v][k];
    num[u][1]++;
  }
}
void dfs2(int u, int fa) {
  if (fa == 0) {
    for (int i = 0; i <= k; i++) {
      dp[u] += num[u][i];
    }
  } else {
    int a[10];
    for (int i = 0; i <= k; i++) a[i] = num[fa][i];
    for (int j = 1; j < k; j++) {
      a[j + 1] -= num[u][j];
    }
    a[0] -= num[u][0];
    a[0] -= num[u][k];
    a[1] -= num[u][k];
    a[1]--;
    for (int j = 1; j < k; j++) {
      num[u][j + 1] += a[j];
    }
    num[u][0] += a[0];
    num[u][0] += a[k];
    num[u][1] += a[k];
    num[u][1]++;
    for (int i = 0; i <= k; i++) {
      dp[u] += num[u][i];
    }
  }
  for (int i = 0; i < g[u].size(); i++) {
    int v = g[u][i];
    if (v == fa) continue;
    dfs2(v, u);
  }
}
int main() {
  cin >> n >> k;
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs1(1, 0);
  dfs2(1, 0);
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += dp[i];
  }
  cout << ans / 2 << endl;
  return 0;
}
