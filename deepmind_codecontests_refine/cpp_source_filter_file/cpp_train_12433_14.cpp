#include <bits/stdc++.h>
using namespace std;
int main() {
  const int n = 3;
  char c[n][n];
  vector<char> v;
  int countX = 0, countO = 0, countD = 0;
  for (int i = 0; i < n; i++) {
    int X = 0, O = 0;
    for (int j = 0; j < n; j++) {
      cin >> c[i][j];
      if (c[i][j] == 'X') {
        countX++;
        X++;
      } else if (c[i][j] == '0') {
        countO++;
        O++;
      } else
        countD++;
    }
    if (X == 3)
      v.push_back('X');
    else if (O == 3)
      v.push_back('0');
  }
  for (int i = 0; i < n; i++) {
    char tmp = '-';
    bool b = true;
    for (int j = 0; j < n; j++) {
      if (j == 0)
        tmp = c[j][i];
      else {
        if (c[j][i] != tmp) b = false;
      }
    }
    if (b == true) v.push_back(tmp);
  }
  if (c[0][0] == c[1][1] && c[1][1] == c[2][2]) {
    if (c[0][0] == 'X')
      v.push_back('X');
    else if (c[0][0] == '0')
      v.push_back('0');
  }
  if (c[0][2] == c[1][1] && c[1][1] == c[2][0]) {
    if (c[0][0] == 'X')
      v.push_back('X');
    else if (c[0][0] == '0')
      v.push_back('0');
  }
  int diff = countX - countO;
  if (diff >= 2 || diff < 0)
    cout << "illegal" << endl;
  else {
    if (diff == 0) {
      if (countX <= 2)
        cout << "first" << endl;
      else {
        if (find(v.begin(), v.end(), 'X') != v.end())
          cout << "illegal" << endl;
        else {
          if (find(v.begin(), v.end(), '0') != v.end())
            cout << "the second player won" << endl;
          else
            cout << "first" << endl;
        }
      }
    } else {
      if (countX <= 2)
        cout << "second" << endl;
      else {
        if (find(v.begin(), v.end(), '0') != v.end())
          cout << "illegal" << endl;
        else {
          if (find(v.begin(), v.end(), 'X') != v.end())
            cout << "the first player won" << endl;
          else {
            if (countD == 0)
              cout << "draw" << endl;
            else
              cout << "second" << endl;
          }
        }
      }
    }
  }
}
