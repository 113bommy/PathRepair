#include <bits/stdc++.h>
using namespace std;
char a[10][10];
int row[3][1000], col[3][1000];
bool okie1(int cs) {
  for (int i = 1; i <= row[1][cs] - 1; i++)
    if (a[i][col[1][cs]] != '.') return false;
  return true;
}
bool okie2(int cs) {
  for (int i = row[2][cs] + 1; i <= 8; i++)
    if (a[i][col[2][cs]] != '.') return false;
  return true;
}
int main() {
  int m1 = 1000, m2 = 1000;
  int dem1 = 0, dem2 = 0;
  for (int i = 1; i <= 8; i++)
    for (int j = 1; j <= 8; j++) {
      cin >> a[i][j];
      if (a[i][j] == 'W') {
        ++dem1;
        row[1][dem1] = i, col[1][dem1] = j;
      } else if (a[i][j] == 'B') {
        ++dem2;
        row[2][dem2] = i, col[2][dem2] = j;
      }
    }
  for (int u = 1; u <= dem1; u++) {
    if (okie1(u)) m1 = min(m1, row[1][u] - 1);
  }
  for (int v = 1; v <= dem2; v++) {
    if (okie2(v)) m2 = min(m2, 8 - row[2][v]);
  }
  if (m1 <= m2)
    cout << "A";
  else
    cout << "B";
  return 0;
}
