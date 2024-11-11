#include <bits/stdc++.h>
using namespace std;
int main() {
  char a[3][3];
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> a[i][j];
    }
  }
  int i = 0, j = 0;
  if (a[i][j] == a[i + 2][j + 2] && a[i][j + 1] == a[i + 2][j + 1] &&
      a[i][j + 2] == a[j + 2][i] && a[i + 1][j] == a[i + 1][j + 2])
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
