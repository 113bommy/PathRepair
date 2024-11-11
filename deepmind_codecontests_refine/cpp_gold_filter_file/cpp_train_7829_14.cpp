#include <bits/stdc++.h>
using namespace std;
int main() {
  char matrix[3][3];
  for (int i = 0; i <= 2; i++) {
    for (int j = 0; j <= 2; j++) {
      cin >> matrix[i][j];
    }
  }
  for (int i = 0; i <= 2; i++) {
    for (int j = 0; j <= 2; j++) {
      if (matrix[i][j] != matrix[2 * 1 - i][2 * 1 - j]) {
        cout << "NO";
        return 0;
      }
      if (i == 1 && j == 1) {
        cout << "YES";
        return 0;
      }
    }
  }
  return 0;
}
