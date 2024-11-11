#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<string> board(11);
  for (int i = 0; i < 11; i++) getline(cin, board[i]);
  board.erase(board.begin() + 7);
  board.erase(board.begin() + 3);
  for (int i = 0; i < 9; i++) {
    board[i].erase(board[i].begin() + 7);
    board[i].erase(board[i].begin() + 3);
  }
  int n, m;
  cin >> n >> m;
  int sideY = (n - 1) % 3, sideX = (m - 1) % 3;
  bool flag = false;
  for (int i = sideY * 3; i < (sideY + 1) * 3; i++)
    for (int j = sideX * 3; j < (sideX + 1) * 3; j++)
      if (board[i][j] == '.') {
        board[i][j] = '!';
        flag = true;
      }
  if (!flag)
    for (int i = 0; i < 9; i++)
      for (int j = 0; j < 9; j++)
        if (board[i][j] == '.') board[i][j] = '!';
  for (int i = 0; i < 9; i++) {
    board[i].insert(board[i].begin() + 3, ' ');
    board[i].insert(board[i].begin() + 7, ' ');
  }
  board.insert(board.begin() + 3, "\n");
  board.insert(board.begin() + 7, "\n");
  for (int i = 0; i < 10; i++) cout << board[i] << endl;
  cout << board[10];
  return 0;
}
