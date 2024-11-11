#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int c1 = 0, c2 = 0;
  char x[3][3];
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++) {
      cin >> x[i][j];
      if (x[i][j] == 'X')
        c1++;
      else if (x[i][j] == '0')
        c2++;
    }
  if (c2 > c1 || c2 + 1 < c1) {
    cout << "illegal";
    return 0;
  }
  int y1 = 0, y2 = 0, w1 = 0, w2 = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (x[i][j] == 'X')
        y1++;
      else if (x[i][j] == '0')
        y2++;
    }
    if (y1 == 3) {
      w1++;
    } else if (y2 == 3) {
      w2++;
    }
    y1 = 0;
    y2 = 0;
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (x[j][i] == 'X')
        y1++;
      else if (x[j][i] == '0')
        y2++;
    }
    if (y1 == 3) {
      w1++;
    } else if (y2 == 3) {
      w2++;
    }
    y1 = 0;
    y2 = 0;
  }
  if (x[0][0] == x[1][1] && x[1][1] == x[2][2] && x[2][2] == 'X') w1++;
  if (x[0][0] == x[1][1] && x[1][1] == x[2][2] && x[2][2] == '0') w2++;
  if (x[2][0] == x[1][1] && x[1][1] == x[0][2] && x[0][2] == 'X') w1++;
  if (x[2][0] == x[1][1] && x[1][1] == x[0][2] && x[0][2] == '0') w2++;
  if (w1 >= 1 && w2 == 0 && c1 > c2)
    cout << "the first player won";
  else if (w1 == 0 && w2 >= 1 && c2 == c1)
    cout << "the second player won";
  else if (w1 >= 1 && w2 >= 1 || (w1 >= 1 && w2 == 0 && c1 <= c2) ||
           (w1 == 0 && w2 >= 1 && c2 != c1))
    cout << "illegal";
  else if (c2 == 4 && c1 == 5)
    cout << "draw";
  else if (c2 == c1)
    cout << "first";
  else if (c2 < c1)
    cout << "second";
  return 0;
}
