#include <bits/stdc++.h>
using namespace std;
int main() {
  long int x, y;
  cin >> x >> y;
  long int e = 0;
  int f = 0;
  while (f != 1) {
    if (e % 2 == 0) {
      if (x >= 2 && y >= 2) {
        x = x - 2;
        y = y - 2;
      } else if (x == 1 && y >= 12) {
        x = x - 1;
        y = y - 12;
      } else if (x == 0 && y >= 12) {
        y = y - 12;
      } else {
        f = 1;
        break;
      }
    } else {
      if (y >= 22) {
        y = y - 22;
      } else if (y >= 12 && x >= 1) {
        x = x - 1;
        y = y - 12;
      } else if (y >= 2 && x >= 2) {
        y = y - 2;
        x = x - 2;
      } else {
        f = 1;
        break;
      }
    }
    e += 1;
  }
  if (e % 2 == 0)
    cout << "Ciel";
  else
    cout << "Hanako";
}
