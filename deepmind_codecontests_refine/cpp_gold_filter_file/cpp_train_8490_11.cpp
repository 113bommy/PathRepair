#include <bits/stdc++.h>
using namespace std;
long long a[200003], h[200003], par[200003][26];
vector<pair<int, int> > g[200003];
long long ans[200003];
void dfs(int v, int p, long long d) {
  par[v][0] = p;
  h[v] = d;
  for (int i = 1; i < 26; i++) {
    if (par[v][i - 1] != -1) par[v][i] = par[par[v][i - 1]][i - 1];
  }
  for (auto u : g[v])
    if (p != u.first) dfs(u.first, v, d + u.second);
}
void dfs(int u, int p) {
  for (auto i : g[u]) {
    if (i.first != p) {
      dfs(i.first, u);
      ans[u] += ans[i.first];
    }
  }
}
int find(int u) {
  long long rem = h[u] - a[u];
  long long cur = u;
  for (int i = 26 - 1; i >= 0; i--) {
    if (par[cur][i] != -1)
      if (h[par[cur][i]] >= rem) cur = par[cur][i];
  }
  return cur;
}
int main() {
  ios_base::sync_with_stdio(0);
  int n, x, y;
  cin >> n;
  for (int i = 1; i < n + 1; i++) cin >> a[i];
  for (int i = 1; i < n; i++) {
    cin >> x >> y;
    g[x].push_back({i + 1, y});
  }
  memset(par, -1, sizeof(par));
  dfs(1, -1, 0);
  for (int i = 1; i < n + 1; i++) {
    int in = find(i);
    ans[par[i][0]]++;
    ans[par[in][0]]--;
  }
  dfs(1, -1);
  for (int i = 1; i < n + 1; i++) cout << ans[i] << " ";
  return 0;
}
