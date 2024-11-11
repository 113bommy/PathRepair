#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y;
  cin >> x >> y;
  int turn = 0;
  int ret = -1;
  while (true) {
    if (turn == 0) {
      if (x >= 2 && y >= 2)
        x -= 2, y -= 2;
      else if (x >= 1 && y >= 12)
        x -= 1, y -= 12;
      else if (y >= 22)
        y -= 22;
      else {
        ret = 1;
        break;
      }
    } else {
      if (y >= 22)
        y -= 22;
      else if (x >= 1 && y >= 12)
        x -= 1, y -= 12;
      else if (x >= 2 && y >= 2)
        x -= 2, y -= 2;
      else {
        ret = 0;
        break;
      }
    }
    turn = 1 - turn;
  }
  if (ret == 0)
    cout << "Ciel" << endl;
  else
    cout << "Hanako" << endl;
  return 0;
}
