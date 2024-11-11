#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> g[300010];
int u[300010];
bool dfs(int i, int co, int *x, int *y) {
  if (u[i] != 0) return u[i] == co;
  u[i] = co;
  (*x)++;
  for (int j : g[i])
    if (!dfs(j, -co, y, x)) return 0;
  return 1;
}
int p2[300010];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  p2[0] = 1;
  for (int i = 1; i <= 300000; ++i) p2[i] = p2[i - 1] * 2 % 998244353;
  int T;
  cin >> T;
  while (T--) {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) g[i].clear();
    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    for (int i = 1; i <= n; ++i) u[i] = 0;
    bool ok = 1;
    long long ans = 0;
    for (int i = 1; i <= n; ++i)
      if (u[i] == 0) {
        int x = 0, y = 0;
        if (!dfs(i, 1, &x, &y)) {
          ok = 0;
          break;
        }
        ans = (ans + p2[x] + p2[y]) % 998244353;
      }
    if (!ok)
      cout << 0 << '\n';
    else
      cout << ans << '\n';
  }
}
