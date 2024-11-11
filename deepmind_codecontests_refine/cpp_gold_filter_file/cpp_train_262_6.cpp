#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const int MAXN = 5 * 1e5 + 1, MODM = 1e9 + 7;
int n;
vector<int> g[MAXN];
int sz[MAXN];
int pr[MAXN];
int ans[MAXN];
int m1, m2;
int now;
int root = -1;
void dfs(int v, int p = -1) {
  sz[v] = 1;
  pr[v] = p;
  for (auto to : g[v]) {
    if (to != p) {
      dfs(to, v);
      sz[v] += sz[to];
    }
  }
}
void dfs2(int v, int p = -1) {
  int k = m1;
  if (sz[now] == m1) k = m2;
  ans[v] |= (n - sz[v] - k <= (n / 2));
  ans[v] |= (n - sz[now] <= (n / 2));
  for (auto it : g[v])
    if (it != p) dfs2(it, v);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs(1);
  for (int v = 1; v <= n; v++) {
    int cnt = 0;
    for (auto to : g[v])
      if (to != pr[v]) cnt += (sz[to] <= (n / 2));
    if (v != 1) cnt += (n - sz[v] <= (n / 2));
    ans[v] = (cnt >= g[v].size());
    if (ans[v]) root = v;
  }
  if (root == -1) {
    for (int i = 0; i < n; i++) cout << 0 << " ";
    return 0;
  }
  fill(sz, sz + MAXN, 0);
  dfs(root);
  for (auto it : g[root]) {
    if (sz[it] > m1) {
      m2 = m1;
      m1 = sz[it];
    } else
      m2 = max(m2, sz[it]);
  }
  for (auto it : g[root]) {
    now = it;
    dfs2(it, root);
  }
  for (int i = 0; i < n; i++) cout << ans[i + 1] << " ";
  return 0;
}
