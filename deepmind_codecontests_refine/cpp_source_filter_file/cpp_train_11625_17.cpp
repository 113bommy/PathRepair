#include <bits/stdc++.h>
using namespace std;
const int N = 300005;
int fa[N], f[N], g[N], sn[N], id[N], n, u, v;
vector<int> s[N], e[N], tmp[N];
long long ans, sum;
int clk;
int dfs(int u) {
  int mx = 1;
  id[++clk] = u;
  for (auto v : e[u])
    if (v != fa[u]) {
      fa[v] = u;
      mx = max(mx, dfs(v) + 1);
      ++sn[u];
    }
  ans += mx;
  return mx;
}
void up(int u, int now) {
  if (now <= g[u]) return;
  sum += now - g[u], g[u] = now;
  if (fa[u]) up(fa[u], now);
}
int cnt[N];
long long solve(int k) {
  for (auto u : s[k]) f[u] = n, cnt[u] = 0, tmp[u].clear();
  for (auto u : s[k]) {
    if (cnt[u] < sn[u])
      f[u] = 2;
    else {
      sort(tmp[u].begin(), tmp[u].end(), greater<int>());
      f[u] = tmp[u][k - 1];
    }
    if (fa[u]) tmp[fa[u]].push_back(f[u] + 1), cnt[fa[u]]++;
  }
  long long res = n - s[k].size();
  for (auto u : s[k]) up(u, f[u]);
  return sum;
}
int main() {
  cin >> n;
  for (int i = (1); i <= (n - 1); i++) {
    cin >> u >> v;
    e[u].push_back(v);
    e[v].push_back(u);
  }
  dfs(1);
  for (int i = (n); i >= (1); i--) {
    int u = id[i];
    for (int j = (1); j <= (sn[u]); j++) s[j].push_back(u);
  }
  for (int i = (1); i <= (n); i++) g[i] = 1, sum++;
  for (int i = (n); i >= (2); i--) ans += solve(i);
  cout << ans << endl;
  return 0;
}
