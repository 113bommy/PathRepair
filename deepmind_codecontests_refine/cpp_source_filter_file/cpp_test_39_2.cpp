#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int n, a[N], b[N], pos, lst[N], cnt, last, Last, ans[N];
bool vis[N];
int main() {
  ios::sync_with_stdio(0);
  cin >> n;
  for (int i = n; i >= 1; --i) {
    if (vis[i]) continue;
    cnt = 1;
    pos = i;
    while (pos) {
      cnt++;
      if (cnt == n + 1) {
        cout << "! ";
        for (int i = 1; i <= n; ++i) cout << i << " ";
        cout << endl;
        return 0;
      }
      Last = pos;
      cout << "? ";
      for (int j = 1; j < i; ++j) cout << cnt << " ";
      cout << 1 << " ";
      for (int j = i + 1; j <= n; ++j) cout << cnt << " ";
      cout << endl;
      cout.flush();
      cin >> pos;
      if (pos == i) {
        lst[last] = pos;
        break;
      } else if (pos != 0)
        lst[pos] = Last;
      vis[pos] = 1;
    }
    last = i;
  }
  int tmp = 0;
  memset(vis, 0, sizeof(vis));
  for (int i = 1; i <= n; ++i) vis[lst[i]] = 1;
  for (int i = 1; i <= n; ++i)
    if (!vis[i]) {
      tmp = i;
      break;
    }
  for (int i = 1; i <= n; ++i) ans[tmp] = i, tmp = lst[tmp];
  cout << "! ";
  for (int i = 1; i <= n; ++i) cout << ans[i] << " ";
  cout << endl;
  return 0;
}
