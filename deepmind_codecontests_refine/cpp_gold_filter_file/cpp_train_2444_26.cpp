#include <bits/stdc++.h>
using namespace std;
char mat[55][55];
bool visited[55][55];
bool recstack[55][55];
bool flag = false;
int n, m;
void dfs(int i, int j, int prevx, int prevy) {
  if (visited[i][j] == false) {
    visited[i][j] = true;
    recstack[i][j] = true;
    if (j + 1 < m && mat[i][j] == mat[i][j + 1] && prevy != -1) {
      if (visited[i][j + 1] == true && recstack[i][j + 1] == true) flag = true;
      if (visited[i][j + 1] == false) dfs(i, j + 1, 0, 1);
    }
    if (j - 1 >= 0 && mat[i][j] == mat[i][j - 1] && prevy != 1) {
      ;
      if (visited[i][j - 1] == true && recstack[i][j - 1] == true) flag = true;
      if (visited[i][j - 1] == false) dfs(i, j - 1, 0, -1);
    }
    if (i + 1 < n && mat[i][j] == mat[i + 1][j] && prevx != -1) {
      if (visited[i + 1][j] == true && recstack[i + 1][j] == true) flag = true;
      if (visited[i + 1][j] == false) dfs(i + 1, j, 1, 0);
    }
    if (i - 1 >= 0 && mat[i][j] == mat[i - 1][j] && prevx != 1) {
      if (visited[i - 1][j] == true && recstack[i - 1][j] == true) flag = true;
      if (visited[i - 1][j] == false) dfs(i - 1, j, -1, 0);
    }
    recstack[i][j] = false;
  }
}
int main() {
  int i, j, prevx = 0, prevy = 0;
  cin >> n >> m;
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      cin >> mat[i][j];
      visited[i][j] = false;
      recstack[i][j] = false;
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      prevx = 0;
      prevy = 0;
      if (visited[i][j] == false) {
        dfs(i, j, prevx, prevy);
      }
    }
  }
  if (flag == true)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
