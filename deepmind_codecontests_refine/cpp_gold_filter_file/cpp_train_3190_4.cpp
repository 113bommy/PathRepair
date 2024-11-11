#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<vector<char> > a(11);
  for (int i = 0; i < 11; i++) {
    a.at(i).resize(11);
  }
  int x1, y1;
  int i, j;
  for (i = 0; i < 9; i++) {
    for (j = 0; j < 9; j++) {
      cin >> a[i][j];
    }
  }
  cin >> x1 >> y1;
  x1 %= 3;
  if (x1 == 0) x1 = 3;
  y1 %= 3;
  if (y1 == 0) y1 = 3;
  x1 = (x1 - 1) * 3;
  y1 = (y1 - 1) * 3;
  int k = 0;
  for (i = x1; i < x1 + 3; i++) {
    for (j = y1; j < y1 + 3; j++) {
      if (a[i][j] == '.') {
        a[i][j] = '!';
        k++;
      }
    }
  }
  if (k == 0) {
    for (i = 0; i < 9; i++) {
      for (j = 0; j < 9; j++) {
        if (a[i][j] == '.') {
          a[i][j] = '!';
        }
      }
    }
  }
  for (i = 0; i < 9; i++) {
    for (j = 0; j < 9; j++) {
      cout << a[i][j];
      if (j % 3 == 2) cout << ' ';
    }
    if (i % 3 == 2) {
      cout << endl;
    }
    cout << endl;
  }
}
