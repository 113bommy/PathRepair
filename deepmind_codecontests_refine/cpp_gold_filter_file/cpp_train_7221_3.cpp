#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[5][5] = {0};
  int x = 0, y = 0;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      int no;
      cin >> no;
      if (no == 1) {
        x = i;
        y = j;
      }
    }
  }
  x -= 2;
  y -= 2;
  if (x <= 0 && y >= 0)
    cout << -1 * x + y;
  else if (x >= 0 && y <= 0)
    cout << -1 * y + x;
  else if (x <= 0 && y <= 0)
    cout << (-1 * x) + (-1 * y);
  else
    cout << x + y;
  return 0;
}
