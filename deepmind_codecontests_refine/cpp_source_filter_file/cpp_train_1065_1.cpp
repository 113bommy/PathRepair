#include <bits/stdc++.h>
using namespace std;
long long n, m, ans, cont;
bool rw, cw;
bool vis[1005][1005];
char mat[1005][1005];
void dfs(int x, int y) {
  vis[x][y] = true;
  if (x > 0 && vis[x - 1][y] == false && mat[x - 1][y] == '#') {
    dfs(x - 1, y);
  }
  if (x + 1 < m && vis[x + 1][y] == false && mat[x + 1][y] == '#') {
    dfs(x + 1, y);
  }
  if (y > 0 && vis[x][y - 1] == false && mat[x][y - 1] == '#') {
    dfs(x, y - 1);
  }
  if (y + 1 < n && vis[x][y + 1] == false && mat[x][y + 1] == '#') {
    dfs(x, y + 1);
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> mat[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    cont = 0;
    for (int j = 0; j < m; j++) {
      if (j > 0 && mat[i][j] == '#' && mat[i][j - 1] == '.' && cont > 0) {
        cout << "-1\n";
        return 0;
      }
      if (mat[i][j] == '#') cont++;
    }
    if (cont == m) rw = true;
  }
  for (int i = 0; i < m; i++) {
    cont = 0;
    for (int j = 0; j < n; j++) {
      if (j > 0 && mat[j][i] == '#' && mat[j - 1][i] == '.' && cont > 0) {
        cout << "-1\n";
        return 0;
      }
      if (mat[j][i] == '#') cont++;
    }
    if (cont == n) cw = true;
  }
  if (rw != cw) {
    cout << "-1\n";
    return 0;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (vis[i][j] == false && mat[i][j] == '#') {
        ans++;
        dfs(i, j);
      }
    }
  }
  cout << ans << "\n";
  return 0;
}
