#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  char c[100][12];
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> c[i];
  }
  bool g[6] = {false};
  int t2 = t;
  for (int i = 0; i < t2; i++) {
    memset(g, 0, sizeof g);
    for (int j = 0; j < 12; j++)
      if (c[i][j] == 'X') {
        g[0] = true;
        break;
      }
    for (int j = 0; j < 6; j++)
      if (c[i][j] == 'X' && c[i][j + 6] == 'X') {
        g[1] = true;
        break;
      }
    for (int j = 0; j < 4; j++)
      if (c[i][j] == c[i][j + 4] && c[i][j] == c[i][j + 8] && c[i][j] == 'X') {
        g[2] = true;
        break;
      }
    for (int j = 0; j < 3; j++)
      if (c[i][j] == c[i][j + 3] && c[i][j] == c[i][j + 6] &&
          c[i][j] == c[i][j + 9] && c[i][j] == 'X') {
        g[3] = true;
        break;
      }
    for (int j = 0; j < 2; j++)
      if (c[i][j] == c[i][j + 2] && c[i][j] == c[i][j + 4] &&
          c[i][j] == c[i][j + 6] && c[i][j] == c[i][j + 8] &&
          c[i][j] == c[i][j + 10] && c[i][j] == 'X') {
        g[4] = true;
        break;
      }
    g[5] = true;
    for (int j = 0; j < 12; j++) {
      if (c[i][j] == '0') {
        g[5] = false;
        break;
      }
    }
    t = 0;
    for (int j = 0; j < 6; t += g[j++])
      ;
    cout << t;
    if (g[0])
      cout << " "
           << "1X12";
    if (g[1])
      cout << " "
           << "2X6";
    if (g[2])
      cout << " "
           << "3X4";
    if (g[3])
      cout << " "
           << "4X3";
    if (g[4])
      cout << " "
           << "6X2";
    if (g[5])
      cout << " "
           << "12X1";
    cout << endl;
  }
}
