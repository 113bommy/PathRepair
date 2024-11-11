#include <bits/stdc++.h>
using namespace std;
int n, a[2222][2222][2], st, cnt;
bool vd[2222][2];
void dfs(int m, int d) {
  vd[m][d] = true;
  for (int j = 0; j < m; j++)
    if (a[m][j][d])
      if (!vd[j][d]) dfs(j, d);
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      scanf("%d", &st);
      if (st > 0) a[i][j][0] = 1, a[j][i][1] = 1;
    }
  for (int i = 0; i < n; i++)
    if (a[i][i][0] == 1) st = i;
  dfs(st, 0);
  dfs(st, 1);
  for (int i = 0; i < n; i++)
    if (vd[i][0] == true)
      if (vd[i][1] == true) cnt++;
  printf("%s\n", cnt == n ? "YES" : "NO");
  return 0;
}
