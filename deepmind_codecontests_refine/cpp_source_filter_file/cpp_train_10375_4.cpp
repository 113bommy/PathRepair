#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> e[N], b;
int n, dep[N], mxd[N], rt;
void dfs(int u, int f, int d) {
  mxd[u] = dep[u] = d;
  for (auto v : e[u])
    if (v != f) {
      dfs(v, u, d + 1);
      mxd[u] = max(mxd[u], mxd[v]);
    }
}
void dfs2(int u, int f, int d) {
  if ((f || n == 1) && e[u].size() == 1) b.push_back(d);
  int s = -1;
  for (auto v : e[u])
    if (v != f) {
      if (s == -1 || mxd[s] < mxd[v]) s = v;
    }
  if (~s) dfs2(s, u, d + 1);
  for (auto v : e[u])
    if (v != f && v != s) dfs2(v, u, 1);
}
int main() {
  cin >> n;
  for (int i = 1; i <= n - 1; ++i) {
    int x, y;
    cin >> x >> y;
    e[x].push_back(y);
    e[y].push_back(x);
  }
  dfs(1, 0, 1);
  for (int i = 1; i <= n; ++i)
    if (dep[rt] < dep[i]) rt = i;
  dfs(rt, 0, 1);
  dfs2(1, 0, 1);
  sort(b.begin(), b.end(), greater<int>());
  int ans = 0;
  cout << 1;
  for (int i = 0; i <= n - 2; ++i) {
    if (i < b.size()) ans += b[i];
    cout << ' ' << ans;
  }
}
