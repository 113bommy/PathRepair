#include <bits/stdc++.h>
using namespace std;
int main() {
  int in[5][5];
  for (int i = 1; i <= 4; i++) {
    for (int j = 1; j <= 4; j++) {
      cin >> in[i][j];
    }
  }
  if (in[1][4] == 1) {
    if (in[1][1] + in[1][2] + in[1][3] + in[2][1] + in[3][2] + in[4][1] > 0) {
      cout << "YES";
      return 0;
    }
  }
  if (in[2][4] == 1) {
    if (in[2][1] + in[2][2] + in[2][3] + in[1][3] + in[3][1] + in[4][2] > 0) {
      cout << "YES";
      return 0;
    }
  }
  if (in[3][4] == 1) {
    if (in[3][1] + in[3][2] + in[3][3] + in[1][2] + in[2][3] + in[4][1] > 0) {
      cout << "YES";
      return 0;
    }
  }
  if (in[4][4] == 1) {
    if (in[4][1] + in[4][2] + in[4][3] + in[1][1] + in[2][2] + in[3][3] > 0) {
      cout << "YES";
      return 0;
    }
  }
  cout << "NO";
  return 0;
}
