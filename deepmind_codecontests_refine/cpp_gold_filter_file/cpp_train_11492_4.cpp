#include <bits/stdc++.h>
int n, m;
int map[110][110];
int knows[110][110];
int vis[110];
void dfs(int now) {
  vis[now] = true;
  for (int i = 0; i != n; i++)
    if (!vis[i] && map[now][i]) {
      dfs(i);
    }
}
int main() {
  scanf("%d%d", &n, &m);
  int sum = 0;
  for (int i = 0; i != n; i++) {
    int ki;
    scanf("%d", &ki);
    sum += ki;
    int tmp;
    for (int j = 0; j != ki; j++) {
      scanf("%d", &tmp);
      knows[i][tmp] = true;
    }
  }
  for (int i = 0; i != n; i++) {
    for (int j = i + 1; j != n; j++) {
      for (int k = 1; k <= m; k++) {
        if (knows[i][k] && knows[j][k]) map[i][j] = map[j][i] = true;
      }
    }
  }
  int ans = 0;
  for (int i = 0; i != n; i++) {
    if (!vis[i]) {
      ans++;
      dfs(i);
    }
  }
  if (sum) printf("%d\n", ans - 1);
  if (!sum) printf("%d\n", ans);
  return 0;
}
