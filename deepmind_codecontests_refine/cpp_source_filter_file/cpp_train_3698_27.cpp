#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  int n;
  int x = 0, y = 0, z = 0, i;
  cin >> n;
  cin >> s;
  for (i = 0; i < n; i++) {
    if (s[i] == 'R')
      x++;
    else if (s[i] == 'B')
      y++;
    else
      z++;
  }
  if (x == 0 && y == 0)
    cout << "G" << endl;
  else if (y == 0 && z == 0)
    cout << "R" << endl;
  else if (z == 0 && x == 0)
    cout << "B" << endl;
  else if (x == 0) {
    if (y == 1 && z == 1)
      cout << "R" << endl;
    else if (y == 1)
      cout << "BR" << endl;
    else if (z == 1)
      cout << "GR" << endl;
    else
      cout << "BGR" << endl;
  } else if (y == 0) {
    if (x == 1 && z == 1)
      cout << "R" << endl;
    else if (x == 1)
      cout << "BR" << endl;
    else if (z == 1)
      cout << "BG" << endl;
    else
      cout << "BGR" << endl;
  } else if (z == 0) {
    if (x == 1 && y == 1)
      cout << "G" << endl;
    else if (x == 1)
      cout << "GR" << endl;
    else if (y == 1)
      cout << "BG" << endl;
    else
      cout << "BGR" << endl;
  } else
    cout << "BGR" << endl;
  return 0;
}
