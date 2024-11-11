#include <bits/stdc++.h>
using namespace std;
const int MODULO = (int)(1e9 + 7);
vector<int> adj[222222];
vector<int> suffix[222222], prefix[222222];
int ans[222222];
int dp[222222];
void mult(int &a, long long b) {
  long long c = a * 1LL * b;
  if (c >= MODULO) c %= MODULO;
  a = (int)c;
}
void dfs1(int v = 0) {
  dp[v] = 1;
  for (int u : adj[v]) {
    dfs1(u);
    mult(dp[v], (long long)dp[u] + 1);
  }
  int cur_prefix = 1;
  int cur_suffix = 1;
  for (int i = 0; i < ((int)(adj[v]).size()); i++) {
    int u = adj[v][i];
    int ru = adj[v][((int)(adj[v]).size()) - i - 1];
    prefix[v].push_back(cur_prefix);
    mult(cur_prefix, (long long)dp[u] + 1);
    suffix[v].push_back(cur_suffix);
    mult(cur_suffix, (long long)dp[u] + 1);
  }
}
void dfs2(int v = 0, int p = -1) {
  ans[v] = dp[v];
  reverse((suffix[v]).begin(), (suffix[v]).end());
  for (int i = 0; i < ((int)(adj[v]).size()); i++) {
    int u = adj[v][i];
    int dp_v = dp[v];
    dp[v] = 1;
    mult(dp[v], (long long)prefix[v][i] * (long long)suffix[v][i]);
    if (p != -1) mult(dp[v], (long long)dp[p] + 1);
    int dp_u = dp[u];
    mult(dp[u], (long long)dp[v] + 1);
    dfs2(u, v);
    dp[v] = dp_v;
    dp[u] = dp_u;
  }
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) {
    int x;
    scanf("%d", &x);
    adj[--x].push_back(i + 1);
  }
  dfs1();
  dfs2();
  for (int i = 0; i < n; i++) printf("%d ", ans[i]);
  puts("");
  return 0;
}
