#include <bits/stdc++.h>
using namespace std;
bool vis[55][5555];
int ans[55];
int go(int i, int sum = 0) {
  if (vis[i][sum]) return 0;
  vis[i][sum] = 1;
  if (!i) return 1;
  return go(i - 1, sum + 1) + go(i - 1, sum + 5) + go(i - 1, sum + 10) +
         go(i - 1, sum + 50);
}
int main() {
  for (int i = 1; i <= 50; i++) {
    memset(vis, 0, sizeof vis);
    ans[i] = go(i);
  }
  int n;
  scanf("%d", &n);
  if (n <= 12)
    cout << ans[n] << endl;
  else
    cout << ans[12] + 1ll * (n - 12) * 49 << endl;
  return 0;
}
