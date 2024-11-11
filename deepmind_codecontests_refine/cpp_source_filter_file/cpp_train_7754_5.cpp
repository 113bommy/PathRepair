#include <bits/stdc++.h>
using namespace std;
int vis[1005];
int main() {
  std::ios::sync_with_stdio(false);
  memset(vis, 0, sizeof(vis));
  int n;
  cin >> n;
  int k = 0;
  while (1) {
    int now = 1 + ((1 + k) * k / 2) % n;
    if (vis[now])
      break;
    else
      vis[now] = 1;
  }
  for (int i = 1; i < n + 1; i++)
    if (!vis[i]) return 0 * puts("NO");
  return 0 * puts("YES");
}
