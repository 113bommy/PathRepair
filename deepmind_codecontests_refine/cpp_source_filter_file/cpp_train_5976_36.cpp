#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10, maxm = 2e6 + 10;
const long long INF = 0x3f3f3f3f, mod = 1e9 + 7;
int casn, n, m, k;
namespace graph {
vector<int> g[maxn];
int all, sz[maxn], root, maxt;
bool vis[maxn];
int dfs_root(int now, int fa) {
  int cnt = 1;
  for (auto to : g[now]) {
    if (to == fa || vis[to]) continue;
    cnt += dfs_root(to, now);
  }
  int tmp = max(cnt - 1, all - cnt);
  if (maxt > tmp) maxt = tmp, root = now;
  return sz[now] = cnt;
}
int ans[maxn];
void dfs_col(int now, int fa, int c) {
  ans[now] = c;
  for (auto to : g[now])
    if (to != fa && !vis[to]) dfs_col(to, now, c);
}
void dfs_dv(int now, int d = 0) {
  vis[now] = 1;
  dfs_col(now, now, d);
  for (auto to : g[now]) {
    if (vis[to]) continue;
    maxt = root = n + 1;
    all = sz[to];
    dfs_root(to, now);
    dfs_dv(to, d + 1);
  }
}
void solve(int n) {
  all = maxt = root = n + 1;
  dfs_root(1, 1);
  all -= maxt;
  dfs_dv(root);
}
}  // namespace graph
using namespace graph;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 2; i <= n; ++i) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  solve(n);
  for (int i = 1; i <= n; ++i) cout << char(ans[i] + 'A') << ' ';
}
