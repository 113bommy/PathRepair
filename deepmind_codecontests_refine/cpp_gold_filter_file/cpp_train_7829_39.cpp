#include <bits/stdc++.h>
using namespace std;
int main() {
  char l[3][3];
  int i, j;
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      cin >> l[i][j];
    }
  }
  if (l[0][0] == l[2][2] && l[0][1] == l[2][1] && l[0][2] == l[2][0] &&
      l[1][0] == l[1][2])
    cout << "YES";
  else
    cout << "NO";
}
