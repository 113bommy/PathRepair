#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int x, y, u, v, i, j, flag = 0;
  char ttt[11][11];
  for (i = 0; i < 9; i++) {
    for (j = 0; j < 9; j++) {
      cin >> ttt[i][j];
    }
  }
  cin >> x >> y;
  u = ((x - 1) % 3) * 3;
  v = ((y - 1) % 3) * 3;
  for (i = u; i < u + 3; i++) {
    for (j = v; j < v + 3; j++) {
      if (ttt[i][j] == '.') {
        ttt[i][j] = '!';
        flag = 1;
      }
    }
  }
  if (!flag) {
    for (i = 0; i < 9; i++) {
      for (j = 0; j < 9; j++) {
        if (ttt[i][j] == '.') {
          ttt[i][j] = '!';
        }
      }
    }
  }
  for (i = 0; i < 9; i++) {
    for (j = 0; j < 9; j++) {
      if (j != 0 && (j + 1) % 3 == 0)
        cout << ttt[i][j] << " ";
      else
        cout << ttt[i][j];
    }
    if (i != 0 && (i + 1) % 3 == 0)
      cout << "\n\n";
    else
      cout << "\n";
  }
  return 0;
}
