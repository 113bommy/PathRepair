#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, i, x[100005], h[100005], vis[100005], ans = 0;
  memset(vis, 0, sizeof(vis));
  cin >> n;
  for (i = 0; i < n; i++) cin >> x[i] >> h[i];
  vis[0] = 1;
  vis[n - 1] = 2;
  for (i = 1; i < n - 1; i++) {
    if (h[i] < x[i] - x[i - 1] && vis[i - 1] != 2)
      vis[i] = 1;
    else if (vis[i - 1] == 2 && h[i] + h[i - 1] < x[i] - x[i - 1])
      vis[1] = 1;
    else if (h[i] < x[i + 1] - x[i])
      vis[i] = 2;
  }
  for (i = 0; i < n; i++)
    if (vis[i]) ans++;
  cout << ans << '\n';
  return 0;
}
