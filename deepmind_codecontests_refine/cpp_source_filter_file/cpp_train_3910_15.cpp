#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1;
vector<int> g[N];
int size[N], par[N];
bool u[N];
void dfs(int v, int dad) {
  size[v] += u[v];
  par[v] = dad;
  for (int i = 0; i < g[v].size(); i++)
    if (g[v][i] != dad) {
      dfs(g[v][i], v);
      size[v] += size[g[v][i]];
    }
}
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < 2 * k; i++) {
    int x;
    cin >> x;
    u[--x] = true;
  }
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(0, -1);
  int ans = 0;
  for (int i = 1; i < n; i++) ans += min(size[i], 2 * k - size[i]);
  cout << ans << endl;
}
