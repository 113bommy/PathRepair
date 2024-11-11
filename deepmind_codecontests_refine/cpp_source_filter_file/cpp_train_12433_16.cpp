#include <bits/stdc++.h>
using namespace std;
int main(int argc, char* argv[]) {
  char a[3][3];
  int cross = 0, null = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> a[i][j];
      if (a[i][j] == 'X') cross++;
      if (a[i][j] == '0') null++;
    }
  }
  int delta = cross - null;
  if ((delta < 0) || (delta > 1)) {
    cout << "illegal" << endl;
  } else {
    string win = "";
    if ((a[0][0] == a[0][1]) && (a[0][1] == a[0][2]) && (a[0][0] != '.'))
      win += a[0][0];
    if ((a[1][0] == a[0][1]) && (a[1][1] == a[1][2]) && (a[1][0] != '.'))
      win += a[1][0];
    if ((a[2][0] == a[0][1]) && (a[2][1] == a[2][2]) && (a[2][0] != '.'))
      win += a[2][0];
    if ((a[0][0] == a[1][0]) && (a[1][0] == a[2][0]) && (a[0][0] != '.'))
      win += a[0][0];
    if ((a[0][1] == a[1][1]) && (a[1][1] == a[2][1]) && (a[0][1] != '.'))
      win += a[0][1];
    if ((a[0][2] == a[1][2]) && (a[1][2] == a[2][2]) && (a[0][2] != '.'))
      win += a[0][2];
    if ((a[0][0] == a[1][1]) && (a[1][1] == a[2][2]) && (a[0][0] != '.'))
      win += a[0][0];
    if ((a[0][2] == a[1][1]) && (a[1][1] == a[2][0]) && (a[0][2] != '.'))
      win += a[0][2];
    if (!win.empty()) {
      bool winX = (win.find('X') != string::npos);
      bool winO = (win.find('0') != string::npos);
      if (winX && !winO && (delta == 1))
        cout << "the first player won" << endl;
      else if (winO && !winX && (delta == 0))
        cout << "the second player won" << endl;
      else
        cout << "illegal" << endl;
    } else {
      if (cross + null == 9)
        cout << "draw" << endl;
      else if (delta == 0)
        cout << "first" << endl;
      else if (delta == 1)
        cout << "second" << endl;
    }
  }
  return 0;
}
