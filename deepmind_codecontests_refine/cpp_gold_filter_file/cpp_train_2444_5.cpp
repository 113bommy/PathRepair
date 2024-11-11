#include <bits/stdc++.h>
using namespace std;
int di[5] = {0, 0, 1, 0, -1};
int dj[5] = {0, 1, 0, -1, 0};
int u, v, m, n, thien, t, used[1001][1001];
char a[1001][1001], truoc;
void dfs(int u, int v) {
  int i, j;
  t++;
  used[u][v] = t;
  truoc = a[u][v];
  for (int k = 1; k <= 4; k++) {
    i = di[k] + u;
    j = dj[k] + v;
    if (i > 0 && j > 0 && i <= n && j <= m && a[i][j] == truoc) {
      if (used[i][j] == 0)
        dfs(i, j);
      else if (abs(used[i][j] - used[u][v]) > 1)
        thien = 1;
    }
  }
  t--;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++)
      if (used[i][j] == 0) {
        dfs(i, j);
        if (thien == 1) {
          break;
        }
      }
    if (thien == 1) break;
  }
  if (thien == 0)
    cout << "No";
  else
    cout << "Yes";
}
