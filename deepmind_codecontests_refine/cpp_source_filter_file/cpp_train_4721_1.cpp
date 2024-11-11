#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline T sqr(const T& a) {
  return a * a;
}
template <typename T>
inline int sign(const T& a) {
  return a < 0 ? -1 : a > 0;
}
void task();
int main() {
  task();
  return 0;
}
int n;
int k;
vector<pair<int, int> > g[int(1e5) + 10];
int add[int(1e5) + 10];
int sub[int(1e5) + 10];
int ans[int(1e5) + 10];
int par[int(1e5) + 10][25];
int tin[int(1e5) + 10];
int tout[int(1e5) + 10];
int used[int(1e5) + 10];
int dasndkjwqndkj = 0;
void dfs(int v, int p) {
  used[v] = 1;
  tin[v] = dasndkjwqndkj++;
  par[v][0] = p;
  for (int i = 1; i < 25; ++i) par[v][i] = par[par[v][i - 1]][i - 1];
  for (auto x : g[v])
    if (!used[x.first]) dfs(x.first, v);
  tout[v] = dasndkjwqndkj++;
}
int is_upper(int a, int b) { return tin[a] <= tin[b] && tout[b] <= tout[a]; }
int lca(int a, int b) {
  if (is_upper(a, b)) return a;
  if (is_upper(b, a)) return b;
  for (int i = 25; i >= 0; --i)
    if (!is_upper(par[a][i], b)) a = par[a][i];
  return par[a][0];
}
int dfs2(int v) {
  used[v] = 1;
  int ret = 0;
  for (auto p : g[v])
    if (!used[p.first]) {
      int res = dfs2(p.first);
      ans[p.second] = res;
      ret += res;
    }
  ret += add[v];
  ret -= sub[v];
  return ret;
}
void task() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g[a].push_back({b, i});
    g[b].push_back({a, i});
  }
  dfs(0, 0);
  int k;
  cin >> k;
  for (int i = 0; i < k; ++i) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    add[a]++;
    add[b]++;
    sub[lca(a, b)] += 2;
  }
  (void(1));
  (void(1));
  fill(used, used + n, 0);
  dfs2(0);
  for (int i = 0; i < n - 1; ++i) cout << ans[i] << ' ';
}
