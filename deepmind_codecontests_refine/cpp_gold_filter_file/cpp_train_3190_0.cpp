#include <bits/stdc++.h>
using namespace std;
static void print(vector<vector<char> > vec) {
  for (int i = 0; i < 9; i++) {
    if ((i % 3 == 0) && i > 0) cout << endl;
    for (int j = 0; j < 9; j++) {
      if ((j % 3 == 0) && j > 0) cout << ' ';
      cout << vec[i][j];
    }
    cout << endl;
  }
}
int main() {
  vector<vector<char> > board(9, vector<char>(9));
  for (int i = 0; i < 9; i++) {
    for (int t = 0; t < 3; t++) {
      string s;
      cin >> s;
      for (int j = 0; j < 3; j++) board[i][j + t + t + t] = s[j];
    }
  }
  int x, y;
  cin >> y >> x;
  x--;
  y--;
  int i = y % 3;
  int j = x % 3;
  bool check = true;
  for (int Y = 0; Y < 3; Y++)
    for (int X = 0; X < 3; X++)
      if (board[i + i + i + Y][j + j + j + X] == '.') check = false;
  if (check) {
    for (int i = 0; i < 9; i++)
      for (int j = 0; j < 9; j++)
        if (board[i][j] == '.') board[i][j] = '!';
  } else {
    for (int Y = 0; Y < 3; Y++)
      for (int X = 0; X < 3; X++)
        if (board[i + i + i + Y][j + j + j + X] == '.')
          board[i + i + i + Y][j + j + j + X] = '!';
  }
  print(board);
}
