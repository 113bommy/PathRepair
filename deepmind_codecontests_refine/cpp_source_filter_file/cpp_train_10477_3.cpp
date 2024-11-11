#include <bits/stdc++.h>
using namespace std;
int n, m, a[502][502], ok, x, y;
bitset<505> v, ins;
pair<int, int> q[100005];
void dfs(int x) {
  v[x] = 1;
  ins[x] = 1;
  for (int i = 1; i <= n && !ok; ++i) {
    if (a[x][i] && !v[i]) {
      dfs(i);
      continue;
    }
    if (a[x][i] && ins[i]) {
      ok++;
    }
  }
  ins[x] = 0;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    cin >> x >> y, a[x][y] = 1;
  }
  for (int i = 1; i <= n; ++i) {
    ok = 0;
    v = 0;
    dfs(i);
    for (int j = 1; j <= n; ++j)
      if (!v[i]) dfs(j);
    if (ok < 2) {
      cout << "Yes";
      return 0;
    }
  }
  cout << "No";
  return 0;
}
