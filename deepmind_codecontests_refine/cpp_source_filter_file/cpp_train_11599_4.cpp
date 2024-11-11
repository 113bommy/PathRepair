#include <bits/stdc++.h>
using namespace std;
int main() {
  int x;
  cin >> x;
  int temp;
  int x1 = 0;
  int x2 = 0;
  bool flag = true;
  while (x != 0) {
    temp = x % 10;
    x = x / 10;
    if ((temp == 4) && (x1 == 0)) {
      x1 = 1;
      x2 = 1;
    } else if ((temp == 1)) {
      x1 = 0;
      x2 = 0;
    } else if ((temp == 4) && (x2 == 1)) {
      x2 = 2;
    } else if ((temp == 4) && (x2 == 2)) {
      x2 = 0;
    } else if (temp == 1) {
    } else {
      flag = false;
      break;
    }
    if ((temp == 4) && (x == 0)) {
      flag = false;
      break;
    }
  }
  if (flag)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
