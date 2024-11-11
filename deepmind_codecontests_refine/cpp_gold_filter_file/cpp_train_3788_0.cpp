#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> a[110];
int p[110], f[110];
bool g[110][110], ok;
bool dfs(int bg, int u, int ed) {
  g[bg][u] = true;
  if (u == ed) return true;
  int len = a[u].size();
  int v;
  for (int i = 0; i < len; i++) {
    v = a[u][i];
    if (!g[bg][v]) {
      if (dfs(bg, v, ed)) return true;
    }
  }
  return false;
}
int main() {
  memset(g, 0, sizeof(g));
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> p[i];
  for (int i = 1; i <= n; i++) {
    cin >> f[i];
    if (i + f[i] <= n) {
      a[i].push_back(i + f[i]);
      a[i + f[i]].push_back(i);
    }
    if (i - f[i] >= 1) {
      a[i].push_back(i - f[i]);
      a[i - f[i]].push_back(i);
    }
  }
  ok = true;
  for (int i = 1; i <= n; i++) {
    if (!dfs(i, i, p[i])) {
      ok = false;
      break;
    }
  }
  if (ok)
    cout << "YES\n";
  else
    cout << "NO\n";
  return 0;
}
