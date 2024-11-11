#include <bits/stdc++.h>
using namespace std;

int n, a[1025][1025], z;
bool vis[1025], flag;
bool ok() {
  for (int i = 1; i <= n; i++)
    if (a[i][0] != n) return 0;
  return 1;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n - 1; ++j) cin >> a[i][j];
    a[i][0] = 1;
  }
  while (1) {
    if (ok()) {
      cout << z << '\n';
      return 0;
    }
    flag = 0;
    z++;
    memset(vis, 0, sizeof vis);
    for (int i = 1; i <= n; i++) {
      if (vis[i] || a[i][0] == n) continue;
      int x = a[i][a[i][0]];
      if (a[x][a[x][0]] == i && !vis[i] && !vis[x]) {
        a[i][0]++;
        a[x][0]++;
        vis[i] = vis[x] = 1;
        flag = 1;
      }
    }
    if (!flag) {
      cout << -1 << '\n';
      return 0;
    }
  }
  return 0;
}
