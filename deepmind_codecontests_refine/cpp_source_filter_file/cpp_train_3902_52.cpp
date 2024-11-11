#include <bits/stdc++.h>
using namespace std;
char mat[50][50];
void FillEmpty() {
  for (int i = 0; i < 50; i++) {
    for (int j = 0; j < 50; j++) {
      mat[i][j] = '.';
    }
  }
}
void FillRow(int row, int m) {
  for (int i = 0; i < m; i++) {
    mat[row][i] = '#';
  }
}
void PrintMat(int n, int m) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << mat[i][j];
    }
    cout << "\n";
  }
}
int main() {
  int n, m;
  cin >> n >> m;
  bool switcher = true;
  FillEmpty();
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0) {
      FillRow(i, m);
    } else {
      if (switcher) {
        mat[i][0] = '#';
        switcher = false;
      } else {
        mat[i][m - 1] = '#';
        switcher = true;
      }
    }
  }
  PrintMat(n, m);
  return 0;
}
