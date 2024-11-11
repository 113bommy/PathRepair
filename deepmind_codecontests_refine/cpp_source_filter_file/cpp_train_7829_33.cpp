#include <bits/stdc++.h>
using namespace std;
int main() {
  char a[3][3];
  int i, j;
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      cin >> a[i][j];
    }
  }
  if (a[0][0] == a[2][2] && a[0][1] == a[2][2] && a[0][2] == a[2][0] &&
      a[1][0] == a[1][2])
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
