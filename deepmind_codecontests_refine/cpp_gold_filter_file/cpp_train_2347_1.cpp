#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return a * (b / gcd(a, b)); }
int n, m;
vector<vector<int> > g;
vector<int> stk;
vector<int> v;
vector<int> vis;
vector<int> in;
void dfs(int u, int p = -1) {
  vis[u] = 1;
  for (int i = 0; i < g[u].size(); ++i)
    if (!vis[g[u][i]]) dfs(g[u][i], u);
  stk.push_back(u);
}
void dfs2(int u, int w, int p = -1) {
  if (v[u] != -1) {
    return;
  }
  v[u] = w;
  for (int i = 0; i < g[u].size(); ++i)
    if (g[u][i] != p) dfs2(g[u][i], w, u);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m;
  g.assign(n + 1, vector<int>());
  for (int i = 0; i < m; ++i) {
    int p, q;
    cin >> p >> q;
    p--, q--;
    g[p].push_back(q);
  }
  in.assign(n, 0);
  vector<int> A;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    a--;
    A.push_back(a);
    in[a] = 1;
  }
  vis.assign(n, 0);
  for (int i = 0; i < n; ++i) {
    if (!vis[i]) {
      dfs(i);
    }
  }
  vector<int> ans;
  v.assign(n, -1);
  for (int i = 0; i < stk.size(); ++i) {
    if (in[stk[i]]) {
      dfs2(stk[i], stk[i]);
      ans.push_back(stk[i]);
    }
  }
  for (int i = 0; i < n; ++i) {
    if (A[i] != v[i]) {
      printf("-1\n");
      return 0;
    }
  }
  printf("%d\n", (int)ans.size());
  for (int i = 0; i < ans.size(); ++i) {
    printf("%d\n", ans[i] + 1);
  }
  return 0;
}
