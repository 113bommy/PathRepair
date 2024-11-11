#include <bits/stdc++.h>
using namespace std;
int main() {
  char O[3][3];
  bool vv = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> O[i][j];
    }
  }
  if (O[0][0] == O[2][2]) {
    if (O[1][0] == O[1][2]) {
      if (O[2][0] == O[0][2]) {
        if (O[0][1] == O[2][1]) {
          vv = 1;
        }
      }
    }
  }
  if (vv) {
    cout << "YES";
  } else
    cout << "NO";
  return 0;
}
