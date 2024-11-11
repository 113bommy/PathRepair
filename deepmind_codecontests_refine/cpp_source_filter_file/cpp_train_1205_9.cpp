#include <bits/stdc++.h>
using namespace std;
void flip(vector<string> &board, int r, int c, vector<pair<int, int>> &ans) {
  if (board[r][c + 1] == 'U') {
    board[r + 0][c + 0] = 'L';
    board[r + 0][c + 1] = 'R';
    board[r + 1][c + 0] = 'L';
    board[r + 1][c + 1] = 'R';
    ans.emplace_back(r, c);
    return;
  }
  if (board[r][c + 1] == 'L') {
    if (board[r + 1][c + 1] == 'L') {
      ans.emplace_back(r, c + 1);
      ans.emplace_back(r, c);
      board[r + 0][c + 0] = 'L';
      board[r + 0][c + 1] = 'R';
      board[r + 0][c + 2] = 'U';
      board[r + 0][c + 0] = 'L';
      board[r + 0][c + 1] = 'R';
      board[r + 0][c + 2] = 'U';
      return;
    } else {
      flip(board, r + 1, c + 1, ans);
      flip(board, r, c, ans);
    }
  }
}
char transchar(char a) {
  if (a == 'U') return 'L';
  if (a == 'D') return 'R';
  if (a == 'L') return 'U';
  if (a == 'R') return 'D';
  return a;
}
vector<pair<int, int>> solve(vector<string> board) {
  vector<pair<int, int>> ans;
  int n = board.size(), m = board[0].size();
  if (m % 2) {
    vector<string> rot(m, string(n, 0));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        rot[j][i] = transchar(board[i][j]);
      }
    }
    vector<pair<int, int>> rotsol = solve(rot);
    for (const auto &p : rotsol) {
      ans.emplace_back(p.second, p.first);
    }
    return ans;
  }
  for (int c = 0; c < m; c += 2) {
    for (int r = 0; r < n; r++) {
      if (board[r][c] == 'U') {
        flip(board, r, c, ans);
      }
    }
  }
  return ans;
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  vector<string> board1, board2;
  for (int i = 0; i < n; i++) {
    char line[64];
    scanf("%s", line);
    board1.emplace_back(line);
  }
  for (int i = 0; i < n; i++) {
    char line[64];
    scanf("%s", line);
    board2.emplace_back(line);
  }
  vector<pair<int, int>> sol1 = solve(board1);
  vector<pair<int, int>> sol2 = solve(board2);
  vector<pair<int, int>> merged = sol1;
  for (int i = sol2.size(); i != 0;) {
    i--;
    merged.emplace_back(sol2[i]);
  }
  printf("%d\n", (int)merged.size());
  for (const auto &p : merged) {
    printf("%d %d\n", p.first + 1, p.second + 1);
  }
  return 0;
}
