#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:10000000000")
using namespace std;
int L = 17, MAX_P = 10;
int n, m, q;
vector<vector<int> > g;
vector<vector<int> > up;
vector<vector<vector<int> > > dp;
vector<int> tin, tout;
vector<int> ans;
int timer;
void add(vector<int> &a, vector<int> &b) {
  for (int i = 0; i < (int)((b).size()); ++i) a.push_back(b[i]);
  sort((a).begin(), (a).end());
  a.erase(unique((a).begin(), (a).end()), a.end());
  a.resize(min((int)((a).size()), MAX_P));
}
void dfs(int v, int p) {
  tin[v] = ++timer;
  up[v][0] = p;
  for (int i = 1; i <= L; ++i) {
    up[v][i] = up[up[v][i - 1]][i - 1];
    add(dp[v][i], dp[v][i - 1]);
    add(dp[v][i], dp[up[v][i - 1]][i - 1]);
  }
  for (int i = 0; i < (int)((g[v]).size()); ++i) {
    int to = g[v][i];
    if (to != p) dfs(to, v);
  }
  tout[v] = ++timer;
}
bool is_upper(int v, int u) { return tin[v] <= tin[u] && tout[v] >= tout[u]; }
int lca(int v, int u) {
  if (is_upper(v, u)) return v;
  if (is_upper(u, v)) return u;
  for (int i = L; i >= 0; --i)
    if (!is_upper(up[v][i], u)) v = up[v][i];
  return up[v][0];
}
void path(int v, int u) {
  ans.clear();
  int c = lca(v, u);
  int sv = v;
  int su = u;
  for (int i = L; i >= 0; --i) {
    if (!is_upper(up[v][i], u)) {
      add(ans, dp[v][i]);
      v = up[v][i];
    }
  }
  if (sv != c) add(ans, dp[v][0]);
  for (int i = L; i >= 0; --i) {
    if (!is_upper(up[u][i], v)) {
      add(ans, dp[u][i]);
      u = up[u][i];
    }
  }
  if (su != c) add(ans, dp[u][0]);
  add(ans, dp[c][0]);
}
void query(int v, int u, int a) {
  path(v, u);
  int s = min((int)((ans).size()), a);
  printf("%d ", s);
  for (int i = 0; i < s; ++i) printf("%d ", ans[i] + 1);
  printf("\n");
}
signed main() {
  scanf("%d%d%d", &n, &m, &q);
  g.resize(n);
  tin.resize(n);
  tout.resize(n);
  up.assign(n, vector<int>(L + 1));
  dp.assign(n, vector<vector<int> >(L + 1));
  for (int i = 0; i < n - 1; ++i) {
    int v, u;
    scanf("%d%d", &v, &u);
    --v, --u;
    g[v].push_back(u);
    g[u].push_back(v);
  }
  for (int i = 0; i < m; ++i) {
    int c;
    scanf("%d", &c);
    --c;
    dp[c][0].push_back(i);
  }
  for (int i = 0; i < n; ++i) {
    sort((dp[i][0]).begin(), (dp[i][0]).end());
    dp[i][0].resize(min((int)((dp[i][0]).size()), MAX_P));
  }
  dfs(0, 0);
  for (int i = 0; i < q; ++i) {
    int v, u, a;
    scanf("%d%d%d", &v, &u, &a);
    --v, --u;
    query(v, u, a);
  }
  return 0;
}
