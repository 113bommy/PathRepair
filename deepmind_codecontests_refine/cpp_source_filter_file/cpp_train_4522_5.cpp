#include <bits/stdc++.h>
using namespace std;
int main() {
  char w, x, y, z;
  cin >> w >> x;
  cin >> y >> z;
  int i, length = max(abs(w - y), abs(x - z));
  cout << length;
  if ((w >= y) and (x >= z)) {
    for (i = 1; i <= min(abs(w - y), abs(x - z)); i++) cout << endl << "LD";
    if (abs(w - y) < abs(x - z))
      for (i = min(abs(w - y), abs(x - z)); i < max(abs(w - y), abs(x - z));
           i++)
        cout << endl << "D";
    if (abs(w - y) > abs(x - z))
      for (i = min(abs(w - y), abs(x - z)); i <= max(abs(w - y), abs(x - z));
           i++)
        cout << endl << "L";
  }
  if ((w >= y) and (x < z)) {
    for (i = 1; i <= min(abs(w - y), abs(x - z)); i++) cout << endl << "LU";
    if (abs(w - y) < abs(x - z))
      for (i = min(abs(w - y), abs(x - z)); i < max(abs(w - y), abs(x - z));
           i++)
        cout << endl << "U";
    if (abs(w - y) > abs(x - z))
      for (i = min(abs(w - y), abs(x - z)); i <= max(abs(w - y), abs(x - z));
           i++)
        cout << endl << "L";
  }
  if ((w < y) and (x < z)) {
    for (i = 1; i <= min(abs(w - y), abs(x - z)); i++) cout << endl << "RU";
    if (abs(w - y) < abs(x - z))
      for (i = min(abs(w - y), abs(x - z)); i < max(abs(w - y), abs(x - z));
           i++)
        cout << endl << "U";
    if (abs(w - y) > abs(x - z))
      for (i = min(abs(w - y), abs(x - z)); i <= max(abs(w - y), abs(x - z));
           i++)
        cout << endl << "R";
  }
  if ((w < y) and (x >= z)) {
    for (i = 1; i <= min(abs(w - y), abs(x - z)); i++) cout << endl << "RD";
    if (abs(w - y) < abs(x - z))
      for (i = min(abs(w - y), abs(x - z)); i < max(abs(w - y), abs(x - z));
           i++)
        cout << endl << "D";
    if (abs(w - y) > abs(x - z))
      for (i = min(abs(w - y), abs(x - z)); i <= max(abs(w - y), abs(x - z));
           i++)
        cout << endl << "R";
  }
  return 0;
}
