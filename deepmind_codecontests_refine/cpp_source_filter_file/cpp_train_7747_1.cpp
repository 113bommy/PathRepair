#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 1;
int n[4];
int root[4], h[N], cnt[N];
long long f[N], maxF[4], sum[4];
vector<int> adj[N];
void dfs1(int u, int p) {
  f[u] = 0;
  cnt[u] = 1;
  for (int v : adj[u])
    if (v != p) {
      h[v] = h[u] + 1;
      dfs1(v, u);
      f[u] += f[v] + cnt[v];
      cnt[u] += cnt[v];
    }
}
void dfs2(int u, int p, int treeSize) {
  for (int v : adj[u])
    if (v != p) {
      f[v] = f[u] + treeSize - 2 * cnt[v];
      dfs2(v, u, treeSize);
    }
}
long long a, b, c, dp[N][2];
long long calc(int u, int p) {
  long long res = f[u] * a + f[u] * b;
  dp[u][0] = a * f[u] + c * h[u];
  dp[u][1] = b * f[u] + c * h[u];
  for (int v : adj[u])
    if (v != p) {
      res = max(res, calc(v, u));
      res = max(res, dp[u][0] + dp[v][1] - 2 * c * h[u]);
      res = max(res, dp[u][1] + dp[v][0] - 2 * c * h[u]);
      dp[u][0] = max(dp[u][0], dp[v][0]);
      dp[u][1] = max(dp[u][1], dp[v][1]);
    }
  return res;
}
long long solve(int id1, int id2, int id3) {
  a = n[id2];
  b = n[id3];
  c = (long long)n[id2] * n[id3];
  return calc(root[id1], -1) + maxF[id2] * n[id1] + maxF[id3] * n[id1] +
         maxF[id2] * n[id3] + maxF[id3] * n[id2] + (long long)n[id1] * n[id2] +
         (long long)n[id1] * n[id3] + (long long)2 * n[id2] * n[id3];
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  root[0] = 1;
  for (int i = 1; i <= 3; i++) {
    cin >> n[i];
    root[i] = root[i - 1] + n[i - 1];
  }
  for (int i = 1; i <= 3; i++)
    for (int j = 1; j < n[i]; j++) {
      int u, v;
      cin >> u >> v;
      u += root[i] - 1;
      v += root[i] - 1;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
  for (int i = 1; i <= 3; i++) {
    dfs1(root[i], -1);
    dfs2(root[i], -1, n[i]);
    maxF[i] = *max_element(f + root[i], f + root[i] + n[i]);
    sum[i] = accumulate(f + root[i], f + root[i] + n[i], 0) / 2;
  }
  long long res = 0;
  res = max(res, solve(1, 2, 3));
  res = max(res, solve(2, 3, 1));
  res = max(res, solve(3, 1, 2));
  cout << res + sum[1] + sum[2] + sum[3];
  return 0;
}
