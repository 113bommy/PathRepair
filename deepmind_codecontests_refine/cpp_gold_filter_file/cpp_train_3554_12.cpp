#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
const int ma = 15e4 + 10;
int a[N], vis[N], st[N], ok[N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, k;
  while (cin >> n >> k) {
    memset(vis, 0, sizeof(vis));
    memset(ok, 0, sizeof(ok));
    memset(st, 0, sizeof(st));
    int ans = 0;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int up = k;
    int cur = 0, la = 0;
    for (int i = 1; i <= ma + 1; i++) {
      la = 0;
      int p = int((cur * 100.0 / n) + 0.5);
      for (int j = 1; j <= min(up, n); j++) {
        if (!vis[j]) {
          if (i - st[j] == p && !ok[j]) {
            ans++;
            ok[j] = 1;
          }
        }
      }
      for (int j = 1; j <= min(up, n); j++) {
        if (i - st[j] == a[j]) {
          vis[j] = 1;
          la++;
        }
      }
      cur += la;
      up += la;
      for (int j = 1; j <= min(up, n); j++)
        if (!st[j] && j > k) st[j] = i;
    }
    cout << ans << endl;
  }
  return 0;
}
