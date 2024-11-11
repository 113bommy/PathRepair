#include <bits/stdc++.h>
using namespace std;
int main() {
  int m, d;
  cin >> m >> d;
  switch (m) {
    case 2:
      if (d != 1)
        cout << 5;
      else
        cout << 4;
      break;
    case 4:
      if (d == 7)
        cout << 6;
      else
        cout << 5;
      break;
    case 6:
      if (d > 6)
        cout << 6;
      else
        cout << 5;
      break;
    case 9:
      if (d > 5)
        cout << 6;
      else
        cout << 5;
      break;
    case 11:
      if (d > 6)
        cout << 6;
      else
        cout << 5;
      break;
    default:
      if (d > 5)
        cout << 6;
      else
        cout << 5;
      break;
  }
  return 0;
}
