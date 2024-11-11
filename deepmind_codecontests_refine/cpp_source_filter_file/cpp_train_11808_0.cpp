#include <bits/stdc++.h>
using namespace std;
int p[3010], maxp[3010];
int vis[3010][3010];
int n, k, cnt = 0;
void dfs(int a, int b, int t) {
  if (vis[a][b]) return;
  vis[a][b] = 1;
  cnt++;
  if (t == k || b >= n) return;
  if (p[a]) {
    if (maxp[b + 1]) dfs(b + 1, b + 2, t + 1);
    if (maxp[b] != 100) dfs(a, b + 1, t + 1);
  }
  if (p[a] != 100 && maxp[b] != 0) dfs(b, b + 1, t + 1);
}
int main() {
  int i, j;
  while (scanf("%d %d", &n, &k) != EOF) {
    memset(maxp, 0, sizeof(maxp));
    memset(vis, 0, sizeof(vis));
    cnt = 0;
    for (i = 0; i < n; i++) scanf("%d", &p[i]);
    for (i = n - 1; i >= 0; i--) maxp[i] = max(maxp[i + 1], p[i]);
    dfs(0, 1, 0);
    printf("%d\n", cnt);
  }
  return 0;
}
