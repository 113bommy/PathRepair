#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, l[100], s = 0;
  cin >> a;
  if (a % 2 == 0) {
    a = a - 1;
    while (a != 0) {
      if (a % 2 == 1) {
        cout << "I hate that";
      } else {
        cout << " I love that ";
      }
      a--;
    }
    cout << " I love it";
  } else {
    a = a - 1;
    while (a != 0) {
      if (a % 2 == 0) {
        cout << "I hate that";
      } else {
        cout << " I love that ";
      }
      a--;
    }
    cout << "I hate it";
  }
}
