#include <bits/stdc++.h>
using namespace std;
const int maxn = 200;
bool vis[maxn];
int ans[maxn], a[maxn];
int n;
void dfs(int i, int t, int temp) {
  vis[i] = 1;
  if (a[i] == temp) {
    t += 1;
    for (int i = 1; i <= n; i++) {
      if (vis[i]) ans[i] = t;
    }
    return;
  }
  dfs(a[i], t + 1, temp);
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    memset(ans, 0, sizeof(ans));
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) {
      int tmp = i;
      if (!ans[i]) {
        memset(vis, 0, sizeof(vis));
        dfs(i, 0, tmp);
      }
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << endl;
  }
}
