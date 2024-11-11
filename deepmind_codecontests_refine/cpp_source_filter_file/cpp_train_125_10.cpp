#include <bits/stdc++.h>
using namespace std;
int BP;
int DP = 2;
int CP = 1;
int col = 1;
int row = 1;
int mat[52][52];
int m;
long long n;
void up() {
  while (mat[row - 1][col] == BP) {
    row--;
  }
}
void down() {
  while (mat[row + 1][col] == BP) {
    row++;
  }
}
void left() {
  while (mat[row][col - 1] == BP) {
    col--;
  }
}
void right() {
  while (mat[row][col + 1] == BP) {
    col++;
  }
}
void move() {
  BP = mat[row][col];
  int trow = row, tcol = col;
  switch (DP) {
    case 0:
      left();
      if (CP)
        down();
      else
        up();
      col--;
      break;
    case 1:
      up();
      if (CP)
        left();
      else
        right();
      row--;
      break;
    case 2:
      right();
      if (CP)
        up();
      else
        down();
      col++;
      break;
    case 3:
      down();
      if (CP)
        right();
      else
        left();
      row++;
  }
  if (mat[row][col] <= 0) {
    row = trow;
    col = tcol;
    if (CP) {
      CP = 0;
    } else {
      CP = 1;
      DP = (DP + 1) % 4;
    }
  }
}
int main() {
  cin >> m >> n;
  memset(mat, -1, sizeof(mat));
  for (int i = 1; i <= m; i++) {
    string s;
    cin >> s;
    for (int j = 1; j <= s.size(); j++) mat[i][j] = s[j - 1] - '0';
  }
  map<pair<pair<int, int>, pair<int, int>>, int> mymap;
  row = 1;
  col = 1;
  DP = 2;
  CP = 1;
  bool find = true;
  for (int i = 0; i < n; i++) {
    move();
    pair<pair<int, int>, pair<int, int>> a =
        make_pair(make_pair(row, col), make_pair(DP, CP));
    if (find) {
      if (mymap.find(a) != mymap.end()) {
        find = false;
        i += ((n - i) / (i - mymap[a])) * (i - mymap[a]);
      } else
        mymap[a] = i;
    }
  }
  cout << mat[row][col] << endl;
  return 0;
}
