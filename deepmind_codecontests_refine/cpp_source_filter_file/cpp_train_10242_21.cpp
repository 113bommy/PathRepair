#include <bits/stdc++.h>
using namespace std;
int main() {
  int m[5][5];
  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 5; j++) m[i][j] = 0;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++) cin >> m[i + 1][j + 1];
  int n[3][3];
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++) {
      int sum = m[i + 2][j + 1] + m[i + 1][j + 1] + m[i + 1][j + 2] +
                m[i][j + 1] + m[i + 1][j];
      n[i][j] = 1 - sum % 2;
    }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) cout << n[i][j] << " ";
    cout << endl;
  }
  return 0;
}
