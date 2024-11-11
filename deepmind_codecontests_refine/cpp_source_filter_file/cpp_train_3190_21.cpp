#include <bits/stdc++.h>
using namespace std;
vector<vector<char> > matrix;
void print_matrix() {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      cout << matrix[i][j];
      if (j % 3 == 2) cout << " ";
    }
    cout << endl;
    if (i % 3 == 2) cout << endl;
  }
}
bool check_rect(int num) {
  int x, y;
  if (num == 1) {
    x = 0;
    y = 0;
  }
  if (num == 2) {
    x = 0;
    y = 3;
  }
  if (num == 3) {
    x = 0;
    y = 6;
  }
  if (num == 4) {
    x = 3;
    y = 0;
  }
  if (num == 5) {
    x = 3;
    y = 3;
  }
  if (num == 6) {
    x = 3;
    y = 6;
  }
  if (num == 7) {
    x = 6;
    y = 0;
  }
  if (num == 8) {
    x = 6;
    y = 3;
  }
  if (num == 9) {
    x = 6;
    y = 6;
  }
  bool res = false;
  for (int i = x; i < x + 3; i++) {
    for (int j = y; j < y + 3; j++) {
      if (matrix[i][j] == '.') res = true;
    }
  }
  return res;
}
void color_matrix(bool flag, int num = 0) {
  if (flag) {
    for (int i = 0; i < 9; i++)
      for (int j = 0; j < 9; j++)
        if (matrix[i][j] == '.') matrix[i][j] = '!';
    return;
  }
  int x, y;
  if (num == 1) {
    x = 0;
    y = 0;
  }
  if (num == 2) {
    x = 0;
    y = 3;
  }
  if (num == 3) {
    x = 0;
    y = 6;
  }
  if (num == 4) {
    x = 3;
    y = 0;
  }
  if (num == 5) {
    x = 3;
    y = 3;
  }
  if (num == 6) {
    x = 3;
    y = 6;
  }
  if (num == 7) {
    x = 6;
    y = 0;
  }
  if (num == 8) {
    x = 6;
    y = 3;
  }
  if (num == 9) {
    x = 6;
    y = 6;
  }
  for (int i = x; i < x + 3; i++) {
    for (int j = y; j < y + 3; j++) {
      if (matrix[i][x] == '.') matrix[i][j] = '!';
    }
  }
  return;
}
int get_res_rect(int num, int i, int j) {
  int cnt = 1;
  int x, y;
  if (num == 1) {
    x = 0;
    y = 0;
  }
  if (num == 2) {
    x = 0;
    y = 3;
  }
  if (num == 3) {
    x = 0;
    y = 6;
  }
  if (num == 4) {
    x = 3;
    y = 0;
  }
  if (num == 5) {
    x = 3;
    y = 3;
  }
  if (num == 6) {
    x = 3;
    y = 6;
  }
  if (num == 7) {
    x = 6;
    y = 0;
  }
  if (num == 8) {
    x = 6;
    y = 3;
  }
  if (num == 9) {
    x = 6;
    y = 6;
  }
  for (int k = x; k < x + 3; k++) {
    for (int l = y; l < y + 3; l++) {
      if (k == i - 1 && l == j - 1) return cnt;
      cnt++;
    }
  }
}
int get_num(int i, int j) {
  if (i < 4 && j < 4) return 1;
  if (i < 4 && j > 3 && j < 7) return 2;
  if (i < 4) return 3;
  if (i > 3 && i < 7 && j < 4) return 4;
  if (i > 3 && i < 7 && j < 7) return 5;
  if (i > 3 && i < 7) return 6;
  if (i > 6 && j < 4) return 7;
  if (i > 6 && j < 7) return 8;
  if (i > 6) return 9;
}
int main() {
  matrix.resize(9);
  for (int i = 0; i < 9; i++) matrix[i].resize(9);
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      cin >> matrix[i][j];
    }
  }
  int x, y;
  cin >> x >> y;
  int num = get_num(x, y);
  num = get_res_rect(num, x, y);
  if (check_rect(num)) {
    color_matrix(false, num);
  } else {
    color_matrix(true);
  }
  print_matrix();
  return 0;
}
