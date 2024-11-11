#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
vector<int> dg;
vector<int> colors;
bool cycle = false;
void dfs(int v, int c, int from = 0) {
  if (colors[v] == 0) {
    colors[v] = c;
    for (auto it = g[v].cbegin(); it != g[v].cend(); ++it)
      if (*it != from) dfs(*it, c, v);
  } else if (colors[v] == c)
    cycle = true;
}
int main() {
  if (fopen("input.txt", "r")) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  }
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  g.resize(n + 1);
  dg.resize(n + 1);
  colors.resize(n + 1);
  for (int i = 0; i != m; ++i) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
    ++dg[u];
    ++dg[v];
  }
  bool dg2 = true;
  for (int i = 1; i <= n; ++i)
    if (dg[i] != 2) {
      dg2 = false;
      break;
    }
  for (int v = 1; v <= n; ++v) dfs(v, v);
  bool connected = true;
  for (int i = 1; i <= n; ++i)
    if (colors[i] != 1) {
      connected = false;
      break;
    }
  if (dg2 && connected) {
    cout << "YES\n0";
    return 0;
  }
  bool flag = false;
  for (int i = 1; i <= n; ++i)
    if (dg[i] > 2) {
      flag = true;
      break;
    }
  if (m >= n || cycle || flag) {
    cout << "NO";
    return 0;
  }
  cout << "YES\n" << n - m;
  int i = 1;
  while (true) {
    bool changed = false;
    while (i <= n && dg[i] == 2) ++i;
    if (i > n) break;
    for (int j = i + 1; j <= n; ++j)
      if (dg[j] < 2 && colors[i] != colors[j]) {
        changed = true;
        cout << '\n' << i << ' ' << j;
        ++dg[i];
        ++dg[j];
        ++m;
        int c = colors[j];
        for (int k = 1; k <= n; ++k)
          if (colors[k] == c) colors[k] = colors[i];
        break;
      }
    if (!changed) ++i;
  }
  for (i = 1; i <= n; ++i)
    if (dg[i] < 2) break;
  int j;
  for (j = n; j >= i; --j)
    if (dg[j] < 2) break;
  cout << '\n' << i << ' ' << j;
  return 0;
}
