#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  getline(cin, s);
  string s1 = s.substr(0, 2);
  string s2 = s.substr(3, 2);
  string s3 = s.substr(6, 2);
  string s4 = s.substr(9, 2);
  long x1, x2, x3, x4, y1, y2, y3, y4;
  x1 = s1[0] - 'a' + 1;
  x2 = s2[0] - 'a' + 1;
  x3 = s3[0] - 'a' + 1;
  x4 = s4[0] - 'a' + 1;
  y1 = s1[1] - '1' + 1;
  y2 = s2[1] - '1' + 1;
  y3 = s3[1] - '1' + 1;
  y4 = s4[1] - '1' + 1;
  long mas[10][10];
  memset(mas, 0, sizeof(mas));
  for (int i = 0; i < 10; i++) {
    mas[0][i] = 1;
    mas[9][i] = 1;
    mas[i][0] = 1;
    mas[i][9] = 1;
  }
  for (int i = x1 + 1; i < 10; i++) {
    mas[i][y1] = 1;
    if (i == x2 && y1 == y2 || i == x3 && y1 == y3) break;
  }
  for (int i = x1 - 1; i > 0; i--) {
    mas[i][y1] = 1;
    if (i == x2 && y1 == y2 || i == x3 && y1 == y3) break;
  }
  for (int i = x2 + 1; i < 10; i++) {
    mas[i][y2] = 1;
    if (i == x1 && y2 == y1 || i == x3 && y2 == y3) break;
  }
  for (int i = x2 - 1; i > 0; i--) {
    mas[i][y2] = 1;
    if (i == x1 && y2 == y1 || i == x3 && y2 == y3) break;
  }
  for (int j = y1 + 1; j < 10; j++) {
    mas[x1][j] = 1;
    if (j == y2 && x1 == x2 || j == y3 && x1 == x3) break;
  }
  for (int j = y1 - 1; j > 10; j--) {
    mas[x1][j] = 1;
    if (j == y2 && x1 == x2 || j == y3 && x1 == x3) break;
  }
  for (int j = y2 + 1; j < 10; j++) {
    mas[x2][j] = 1;
    if (j == y1 && x2 == x1 || j == y3 && x2 == x3) break;
  }
  for (int j = y2 + 1; j < 10; j++) {
    mas[x2][j] = 1;
    if (j == y1 && x2 == x1 || j == y3 && x2 == x3) break;
  }
  mas[x3 + 1][y3 + 1] = 1;
  mas[x3 - 1][y3 + 1] = 1;
  mas[x3 + 1][y3 - 1] = 1;
  mas[x3 - 1][y3 - 1] = 1;
  mas[x3 + 1][y3] = 1;
  mas[x3][y3 + 1] = 1;
  mas[x3 - 1][y3] = 1;
  mas[x3][y3 - 1] = 1;
  if (mas[x4][y4] == 1 && mas[x4 + 1][y4 + 1] == 1 && mas[x4 + 1][y4] == 1 &&
      mas[x4 + 1][y4 - 1] == 1 && mas[x4][y4 + 1] == 1 &&
      mas[x4][y4 - 1] == 1 && mas[x4 - 1][y4 + 1] == 1 &&
      mas[x4 - 1][y4] == 1 && mas[x4 - 1][y4 - 1] == 1) {
    cout << "CHECKMATE" << endl;
  } else {
    cout << "OTHER" << endl;
  }
  return 0;
}
