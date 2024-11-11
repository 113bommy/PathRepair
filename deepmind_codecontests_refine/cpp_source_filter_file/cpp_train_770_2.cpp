#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, i, y, s;
  bool flag;
  cin >> a;
  if (a == 0) {
    cout << 1;
  } else {
    i = 1;
    y = a - 1;
    s = 1;
    flag = false;
    while (y > 0) {
      if (y * y + i * i <= a * a) {
        s++;
        i++;
        flag = false;
      } else {
        if (flag == true) {
          i--;
          flag = false;
        } else {
          y--;
          flag = true;
        }
      };
    }
    cout << s * 4;
  }
}
