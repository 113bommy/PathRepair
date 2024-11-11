#include <bits/stdc++.h>
using namespace std;
const int MX = 505;
char board[MX][MX];
int adj[MX][MX];
bool vis[MX][MX];
int mx[] = {1, 0, -1, 0};
int my[] = {0, 1, 0, -1};
int n, m;
void dfs(int x, int y, vector<pair<int, int> > &ans) {
  vis[x][y] = true;
  for (int k = 0; k < 4; k++) {
    int tx = x + mx[k];
    int ty = y + my[k];
    if (tx >= 0 && tx < n && ty >= 0 && ty < m && !vis[tx][ty] &&
        board[tx][ty] == 'B') {
      dfs(tx, ty, ans);
    }
  }
  board[x][y] = 'R';
  ans.push_back(make_pair(x, y));
}
int main() {
  while (cin >> n >> m) {
    memset(adj, 0, sizeof adj);
    vector<pair<int, int> > B, R;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> board[i][j];
        if (board[i][j] == '.') {
          B.push_back(make_pair(i + 1, j + 1));
          board[i][j] = 'B';
        }
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (vis[i][j] || board[i][j] == '#') continue;
        dfs(i, j, R);
        board[R[R.size() - 1].first][R[R.size() - 1].second] = 'B';
        R.pop_back();
      }
    }
    cout << B.size() + R.size() * 2 << '\n';
    for (int i = 0; i < B.size(); i++) {
      cout << "B " << B[i].first << " " << B[i].second << '\n';
    }
    for (int i = 0; i < R.size(); i++) {
      cout << "D " << R[i].first + 1 << " " << R[i].second + 1 << '\n';
      cout << "R " << R[i].first + 1 << " " << R[i].second + 1 << '\n';
    }
  }
}
