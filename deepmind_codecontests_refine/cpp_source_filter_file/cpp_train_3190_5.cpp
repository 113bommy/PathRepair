#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios::sync_with_stdio(false);
  string arr[9];
  string second = "";
  for (int i = 0; i < 9; i++) {
    string second = "";
    string h;
    for (int i = 0; i < 3; i++) {
      cin >> h;
      second += h;
    }
    arr[i] = second;
  }
  int x, y;
  cin >> x >> y;
  x--, y--;
  int r = x % 3, c = y % 3;
  int str = 3 * r, stc = 3 * c;
  for (int i = str; i < str + 3; i++) {
    for (int j = stc; j < stc + 3; j++) {
      if (arr[str][stc] == '.') {
        for (int c = str; c < str + 3; c++) {
          for (int d = stc; d < stc + 3; d++) {
            if (arr[c][d] == '.') arr[c][d] = '!';
          }
        }
        for (int i = 0; i < 9; i++) {
          for (int j = 0; j < 9; j++) {
            if (j == 3 || j == 6) cout << " ";
            cout << arr[i][j];
          }
          cout << "\n";
          if (i == 2 || i == 5 || i == 8) cout << "\n";
        }
        return 0;
      }
    }
  }
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      if (j == 3 || j == 6) cout << " ";
      if (arr[i][j] == '.')
        cout << "!";
      else
        cout << arr[i][j];
    }
    cout << "\n";
    if (i == 2 || i == 5 || i == 8) cout << "\n";
  }
  return 0;
}
