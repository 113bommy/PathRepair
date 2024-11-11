#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, l[100], s = 0;
  cin >> a;
  if (a % 2 == 0) {
    a = a - 1;
    while (a != 0) {
      if (a % 2 == 1) {
        cout << "i hate that";
      } else {
        cout << " i love that ";
      }
      a--;
    }
    cout << " i love it";
  } else {
    a = a - 1;
    while (a != 0) {
      if (a % 2 == 0) {
        cout << "i hate that";
      } else {
        cout << " i love that ";
      }
      a--;
    }
    cout << " i hate it";
  }
}
