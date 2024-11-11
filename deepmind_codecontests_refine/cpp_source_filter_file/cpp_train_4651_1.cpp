#include <bits/stdc++.h>
int f[1000005];
bool vis[1000005];
int dfs(int x) {
  if (!vis[x]) return 0;
  vis[x] = false;
  return dfs(f[x]) + 1;
}
int main() {
  int n;
  scanf("%d", &n);
  int i, j;
  for (i = 1; i <= n; i++) scanf("%d", &f[i]);
  memset(vis, true, sizeof(vis));
  int sum = 0;
  for (i = 1; i <= n; i++) {
    if (vis[i]) sum = dfs(i) - 1;
  }
  if (sum % 2 == n % 2)
    printf("Petr\n");
  else
    printf("Um_nik\n");
}
