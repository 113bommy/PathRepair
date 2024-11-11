#include <bits/stdc++.h>
using namespace std;
int mx[4] = {1, 0, -1, 0};
int my[4] = {0, 1, 0, -1};
void dfs(int x, int y, vector<vector<char> > &b, vector<vector<int> > &val,
         int &c, int &v) {
  v++;
  val[x][y] = c;
  for (int i = 0; i < 4; i++) {
    int xt = x + mx[i];
    int yt = y + my[i];
    if (xt >= 0 && xt < b.size() && yt >= 0 && yt < b[0].size() &&
        b[xt][yt] == '.' && val[xt][yt] == 0) {
      dfs(xt, yt, b, val, c, v);
    }
  }
}
int main() {
  int n, m;
  while (cin >> n >> m) {
    vector<vector<char> > board(n, vector<char>(m, '.'));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) cin >> board[i][j];
    }
    vector<vector<int> > values(n, vector<int>(m, 0));
    int color = 1;
    vector<int> colors(n * m, 0);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (board[i][j] == '.' && values[i][j] == 0) {
          int val = 0;
          dfs(i, j, board, values, color, val);
          colors[color] = val;
          color++;
        }
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (board[i][j] == '.') {
          cout << '.';
          continue;
        } else {
          int acu = 0;
          set<int> valA;
          for (int k = 0; k < 4; k++) {
            int xt = i + mx[k];
            int yt = j + my[k];
            if (xt >= 0 && xt < board.size() && yt >= 0 &&
                yt < board[0].size() && !valA.count(values[xt][yt])) {
              acu += colors[values[xt][yt]];
              valA.insert(values[xt][yt]);
            }
          }
          cout << (acu + 1) % 10;
        }
      }
      cout << endl;
    }
  }
}
