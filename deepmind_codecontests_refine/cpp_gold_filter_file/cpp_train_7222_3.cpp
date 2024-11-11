#include <bits/stdc++.h>
using namespace std;
int main() {
  int x[4][4];
  char c;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      cin >> c;
      x[i][j] = (c == '#' ? 1 : 0);
    }
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      int check = x[i][j] + x[i][j + 1] + x[i + 1][j] + x[i + 1][j + 1];
      if (check == 4 || check == 0 || check % 2) {
        cout << "YES" << endl;
        return 0;
      }
    }
  }
  cout << "NO" << endl;
  return 0;
}
