#include <bits/stdc++.h>
using namespace std;
int n, m;
char mat[55][55];
int w[55][3];
bool vis[55];
int ans;
void DFS(int cur, int cnt) {
  if (cur == 3) {
    ans = min(ans, cnt);
    return;
  }
  if (cnt >= ans) return;
  for (int i = 1; i <= n; i++)
    if (!vis[i]) {
      vis[i] = true;
      DFS(cur + 1, cnt + w[i][cur]);
      vis[i] = false;
    }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%s", mat[i]);
    w[i][0] = w[i][1] = w[i][2] = 0x3f3f3f3f;
    for (int j = 0; j < m; j++)
      if (isdigit(mat[i][j]))
        w[i][0] = min(w[i][0], min(j, m - j));
      else if (isalpha(mat[i][j]))
        w[i][1] = min(w[i][1], min(j, m - j));
      else
        w[i][2] = min(w[i][2], min(j, m - j));
  }
  ans = 0x3f3f3f3f;
  DFS(0, 0);
  printf("%d\n", ans);
  return 0;
}
