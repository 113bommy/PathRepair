#include <bits/stdc++.h>
using namespace std;
int a[2005][2005], visit[2][2005], i, n, j, flag;
void dfs(int k) {
  if (visit[flag][k]) return;
  visit[flag][k] = 1;
  for (int i = 1; i <= n; i++)
    if (!flag && a[k][i] || flag && a[i][k]) dfs(i);
}
int main() {
  scanf("%d", &n);
  for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++) scanf("%d", &a[i][j]);
  flag = 0;
  dfs(1);
  flag = 1;
  dfs(1);
  for (i = 1; i <= n; i++)
    if (!visit[0][i] || !visit[1][i]) return puts("NO");
  puts("YES");
}
