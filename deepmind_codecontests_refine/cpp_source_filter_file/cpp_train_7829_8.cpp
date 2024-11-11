#include <bits/stdc++.h>
using namespace std;
int main() {
  char b[3][3];
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> b[i][j];
    }
  }
  if (b[0][0] == b[2][2] && b[0][1] == b[2][1] && b[0][3] == b[2][0] &&
      b[1][0] == b[1][2]) {
    return cout << "YES", 0;
  }
  cout << "NO";
}
