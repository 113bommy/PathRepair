#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:36777216")
using namespace std;
const int MAX_N = 200500;
vector<int> g[MAX_N];
int d[MAX_N];
bool univ[MAX_N];
int dfs(int v, int p) {
  if (univ[v]) {
    ++d[v];
  }
  for (int u : g[v]) {
    if (u == p) {
      continue;
    }
    d[v] += dfs(u, v);
  }
  return d[v];
}
long long ans = 0;
int n, k;
void dfs2(int v, int p) {
  for (int u : g[v]) {
    if (u == p) {
      continue;
    }
    ans += min(d[u], 2 * k - d[u]);
    dfs2(u, v);
  }
}
int main() {
  cin >> n >> k;
  for (int i = 0; i < 2 * k; ++i) {
    int u;
    cin >> u;
    --u;
    univ[u] = true;
  }
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(0, -1);
  dfs2(0, -1);
  cout << ans << endl;
  return 0;
}
