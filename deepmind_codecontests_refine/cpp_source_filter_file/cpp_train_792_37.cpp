#include <bits/stdc++.h>
using namespace std;
int main() {
  int row, col;
  while (cin >> col >> row) {
    string s[100];
    for (int i = 0; i < row; i++) cin >> s[i];
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        bool flag = true;
        for (int c = 0; c < col; c++)
          if (c != j && s[i][j] == s[i][c]) {
            flag = false;
            break;
          }
        for (int r = 0; r < row; r++)
          if (r != i && s[i][j] == s[r][j]) {
            flag = false;
            break;
          }
        if (flag) cout << s[i][j];
      }
    }
    cout << "\n";
  }
  return 0;
}
