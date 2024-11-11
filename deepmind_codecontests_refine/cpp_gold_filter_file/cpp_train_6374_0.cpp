#include <bits/stdc++.h>
using namespace std;
const int nax = 1e3 + 1;
int n;
int x[nax + 1][nax + 1], y[nax + 1][nax + 1];
vector<vector<char>> l(nax + 1, vector<char>(nax + 1, ' '));
vector<vector<bool>> vis(nax + 1, vector<bool>(nax + 1, false));
void dfs(int i, int j) {
  vis[i][j] = true;
  if (i + 1 <= n && !vis[i + 1][j] && x[i + 1][j] == x[i][j] &&
      y[i + 1][j] == y[i][j]) {
    l[i + 1][j] = 'U';
    dfs(i + 1, j);
  }
  if (i - 1 >= 1 && !vis[i - 1][j] && x[i - 1][j] == x[i][j] &&
      y[i - 1][j] == y[i][j]) {
    l[i - 1][j] = 'D';
    dfs(i - 1, j);
  }
  if (j + 1 <= n && !vis[i][j + 1] && x[i][j + 1] == x[i][j] &&
      y[i][j + 1] == y[i][j]) {
    l[i][j + 1] = 'L';
    dfs(i, j + 1);
  }
  if (j - 1 >= 1 && !vis[i][j - 1] && x[i][j - 1] == x[i][j] &&
      y[i][j - 1] == y[i][j]) {
    l[i][j - 1] = 'R';
    dfs(i, j - 1);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for (long long i = 1; i < n + 1; i++)
    for (long long j = 1; j < n + 1; j++) cin >> x[i][j] >> y[i][j];
  for (long long i = 1; i < n + 1; i++) {
    for (long long j = 1; j < n + 1; j++) {
      if (!vis[i][j] && x[i][j] == -1) {
        if (i + 1 <= n && x[i + 1][j] == -1)
          l[i][j] = 'D';
        else if (i - 1 >= 1 && x[i - 1][j] == -1)
          l[i][j] = 'U';
        else if (j - 1 >= 1 && x[i][j - 1] == -1)
          l[i][j] = 'L';
        else if (j + 1 <= n && x[i][j + 1] == -1)
          l[i][j] = 'R';
        dfs(i, j);
      }
      if (!vis[i][j] && x[i][j] == i && y[i][j] == j) {
        l[i][j] = 'X';
        dfs(i, j);
      }
    }
  }
  for (long long i = 1; i < n + 1; i++) {
    for (long long j = 1; j < n + 1; j++) {
      if (l[i][j] == ' ') {
        cout << "INVALID";
        return 0;
      }
    }
  }
  cout << "VALID\n";
  for (long long i = 1; i < n + 1; i++) {
    for (long long j = 1; j < n + 1; j++) {
      cout << l[i][j];
    }
    cout << endl;
  }
  return 0;
}
