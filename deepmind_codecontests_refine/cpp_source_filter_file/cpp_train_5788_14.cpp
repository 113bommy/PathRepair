#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int n, k, f[N][5], g[N][5];
long long ansc[N], ansp[N], ans;
vector<int> c[N];
void dfs1(int par, int u) {
  for (int i = 0; i < c[u].size(); i++) {
    int v = c[u][i];
    if (v == par) continue;
    dfs1(u, v);
    for (int j = 0; j < k; j++) f[u][j] += f[v][(j - 1 + k) % k];
    ansc[u] += ansc[v] + f[v][0];
  }
  f[u][0]++;
}
void dfs2(int par, int u) {
  g[u][0]++;
  for (int i = 0; i < c[u].size(); i++) {
    int v = c[u][i];
    if (v == par) continue;
    for (int j = 0; j < k; j++)
      g[v][j] = g[u][(j - 1 + k) % k] + f[u][(j - 1 + k) % k] -
                f[v][(j - 2 + 2 * k) % k];
    g[v][1 % k]--;
    ansp[v] = ansp[u] + g[v][1] + ansc[u] - ansc[v] - f[v][0];
    dfs2(u, v);
  }
  ans += ansc[u] + ansp[u];
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> k;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    c[u].push_back(v);
    c[v].push_back(u);
  }
  dfs1(0, 1);
  dfs2(0, 1);
  cout << ans / 2;
  return 0;
}
