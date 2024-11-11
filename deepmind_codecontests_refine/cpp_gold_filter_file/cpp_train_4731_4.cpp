#include <bits/stdc++.h>
using namespace std;
int a[26];
int n;
bool vis[26];
bool dfs(int pre, int val, int child) {
  if (pre == n) return true;
  if (val + 1 == a[pre]) {
    if (child != 1 && dfs(pre + 1, 0, 0)) return true;
    return false;
  }
  int tot = 0;
  for (int i = 0; i < n; i++) {
    if (!vis[i] && val + a[i] < a[pre] && tot != a[i]) {
      tot = a[i];
      vis[i] = true;
      if (dfs(pre, val + a[i], child + 1)) return true;
      vis[i] = false;
    }
  }
  return false;
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  memset(vis, false, sizeof(vis));
  if (a[n - 1] == n && dfs(0, 0, 0))
    puts("YES");
  else
    puts("NO");
  return 0;
}
