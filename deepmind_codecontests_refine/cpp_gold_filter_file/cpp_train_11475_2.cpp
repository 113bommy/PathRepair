#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
static inline void amin(T &x, U y) {
  if (y < x) x = y;
}
template <typename T, typename U>
static inline void amax(T &x, U y) {
  if (y > x) x = y;
}
const long long int mod = (1000000007);
vector<int> g[2020];
int par[2010], cost[2010];
vector<int> al[2010];
int ans[2010], che = 0;
bool comp(int a, int b) { return (ans[a] < ans[b]); }
void dfs(int nn) {
  int pre = 0;
  if (che != 0) return;
  for (int i = 0; i < g[nn].size(); i++) {
    if (g[nn][i] == par[nn]) continue;
    dfs(g[nn][i]);
    int u = g[nn][i], nm = 0;
    for (int j = 0; j < al[u].size(); j++) {
      al[nn].push_back(al[u][j]);
      ans[al[u][j]] += pre;
    }
    if (nm == 0) al[nn].push_back(u);
    ans[u] += pre;
    pre += al[u].size() + 20000;
  }
  sort(al[nn].begin(), al[nn].end(), comp);
  if (cost[nn] > al[nn].size()) {
    che = 1;
    return;
  }
  if (cost[nn] == 0) {
    ans[nn] = 1;
  } else {
    int cq = ans[al[nn][cost[nn] - 1]];
    ans[nn] = cq + 1;
  }
  for (int i = cost[nn]; i < al[nn].size(); i++) ans[al[nn][i]]++;
}
void solve() {
  int root, n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> par[i] >> cost[i];
    int x = par[i], y = i;
    if (par[i] == 0) {
      root = i;
      continue;
    }
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(root);
  if (che != 0) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  for (int i = 1; i <= n; i++) cout << ans[i] << " ";
}
int main() {
  clock_t tt;
  tt = clock();
  int t = 1;
  for (int i = 1; i <= t; i++) {
    solve();
  }
  tt = clock() - tt;
  double time_taken = ((double)tt) / CLOCKS_PER_SEC;
  return 0;
}
