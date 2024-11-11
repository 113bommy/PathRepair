#include <bits/stdc++.h>
using namespace std;
stringstream ss;
int dx[9] = {0, -1, 0, 1, 0, 1, 1, -1, -1};
int dy[9] = {0, 0, -1, 0, 1, 1, -1, 1, -1};
template <class T>
int pyfind(const vector<T> &vect, const T &targ) {
  for (int i = 0; i < vect.size(); i++) {
    if (vect[i] == targ) return i;
  }
  return -1;
}
void remove(vector<int> &vect, int x) {
  vector<int>::iterator itr;
  itr = vect.begin();
  for (int i = 0; i < x; i++) {
    itr++;
  }
  vect.erase(itr);
}
vector<string> downSs(vector<string> board) {
  bool empty = false;
  for (int i = (int)(0); i < (int)(8); i++) {
    for (int j = (int)(0); j < (int)(8); j++) {
      int y = 7 - i;
      int x = j;
      if (board[y][x] == 'S') {
        empty = true;
        if (y == 7) {
          board[y][x] = '.';
        } else {
          if (board[y + 1][x] == 'M') {
            board[0][0] = '*';
            return board;
          }
          board[y + 1][x] = 'S';
          board[y][x] = '.';
        }
      }
    }
  }
  if (not empty) {
    board[0][0] = 'W';
    return board;
  }
  return board;
}
void showboard(vector<string> board) {
  for (int i = (int)(0); i < (int)(8); i++) {
    cout << board[i] << endl;
  }
}
bool dfs(vector<string> board, int x, int y, int depth) {
  int tx, ty;
  for (int i = (int)(0); i < (int)(9); i++) {
    tx = x + dx[i];
    ty = y + dy[i];
    if (tx > 7 or ty > 7 or tx < 1 or ty < 1) continue;
    if (board[ty][tx] == 'S') continue;
    if (board[ty][tx] == 'A') {
      return true;
    }
    vector<string> tmp = board;
    tmp[y][x] = '.';
    tmp[ty][tx] = 'M';
    tmp = downSs(tmp);
    if (tmp[0][0] == '*') {
      continue;
    } else if (tmp[0][0] == 'W') {
      return true;
    }
    if (dfs(tmp, tx, ty, depth + 1)) {
      return true;
    }
  }
  return false;
}
int main() {
  string tmp;
  vector<string> board;
  for (int i = (int)(0); i < (int)(8); i++) {
    cin >> tmp;
    board.push_back(tmp);
  }
  if (dfs(board, 0, 7, 1)) {
    cout << "WIN" << endl;
  } else {
    cout << "LOSE" << endl;
  }
}
