#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int t[n + 1];
  for (int i = (int)1; i < (int)n + 1; i++) cin >> t[i];
  int ans = 0;
  for (int i = (int)1; i < (int)n + 1; i++) {
    int vis[n + 1];
    memset(vis, 0, sizeof vis);
    for (int j = (int)0; j < (int)201; j++)
      if (i - j * k >= 1) vis[i - j * k] = 1;
    for (int j = (int)0; j < (int)201; j++)
      if (i + j * k <= n) vis[i + j * k] = 1;
    int a1 = 0, a2 = 0;
    for (int j = (int)1; j < (int)n + 1; j++) {
      if (vis[j]) continue;
      if (t[j] == 1)
        a1++;
      else
        a2++;
    }
    ans = max(ans, abs(a1 - a2));
  }
  cout << ans << '\n';
  return 0;
}
