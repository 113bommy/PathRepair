#include <bits/stdc++.h>
using namespace std;
const int MAXN = 300001;
int n, x, y, c[MAXN], red, blue, uncolored, ans;
vector<int> adj[MAXN];
pair<int, int> dfs(int u, int p = -1) {
  int b, r;
  if (c[u] == 2) {
    b = 1;
    r = 0;
  }
  if (c[u] == 1) {
    r = 1;
    b = 0;
  }
  if (c[u] == 0) {
    r = 0;
    b = 0;
  }
  for (int i = 0; i <= int(adj[u].size()) - 1; ++i) {
    int v = adj[u][i];
    if (v != p) {
      pair<int, int> pal = dfs(v, u);
      int b1 = pal.first, r1 = pal.second;
      if (b1 == blue && r1 == 0) ans++;
      if (r1 == red && b1 == 0) ans++;
      b += b1;
      r += r1;
    }
  }
  return {b, r};
}
signed main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> c[i];
    if (c[i] == 2) blue++;
    if (c[i] == 1) red++;
    if (c[i] == 0) uncolored++;
  }
  for (int i = 1; i <= n - 1; ++i) {
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  dfs(1);
  cout << ans;
}
