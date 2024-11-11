#include <bits/stdc++.h>
using namespace std;
int n, m, x, y;
int tf = 0;
char a[1009][1009];
bool vis[10009][1009];
int d1[] = {1, -1, 0, 0}, d2[] = {0, 0, 1, -1};
void dfs(int i, int j, char c, int cnt, int fx, int fy) {
  if (i >= n || i < 0 || j < 0 || j >= m) return;
  if (a[i][j] != c) return;
  if (vis[i][j] == 1) {
    if (cnt >= 4 && i == fx && j == fy) {
      tf++;
      return;
    } else
      return;
  }
  vis[i][j] = 1;
  for (int l = 0; l < 4; l++) {
    dfs(i + d1[l], j + d2[l], c, cnt + 1, fx, fy);
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  memset(vis, 0, sizeof vis);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      memset(vis, 0, sizeof vis);
      x = i;
      y = j;
      dfs(i, j, a[i][j], 0, x, y);
    }
  }
  if (tf > 0) {
    cout << "yes" << endl;
  } else
    cout << "no" << endl;
  return 0;
}
