#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y;
  int count = 0;
  cin >> x >> y;
  while ((y > 1 && x > 1) || (y > 21) || (y > 11 && x == 1)) {
    if ((count & 1) == 0) {
      if (x > 1) {
        y -= 2;
        x -= 2;
      } else if (x == 1) {
        y -= 12;
        x--;
      } else
        y -= 22;
    } else {
      if (y > 21)
        y -= 22;
      else if (y > 11) {
        y -= 12;
        x--;
      } else {
        x -= 2;
        y -= 2;
      }
    }
    count++;
  }
  if ((count & 1) == 0)
    cout << "Hanako" << endl;
  else
    cout << "Ciel" << endl;
  return 0;
}
