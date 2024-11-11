#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, i;
  cin >> a >> b;
  for (i = 1;; i++) {
    if (i % 2 == 1) {
      if (a >= 2 && b >= 2) {
        a = a - 2;
        b = b - 2;
      } else if (a >= 1 && b >= 12) {
        a = a - 1;
        b = b - 12;
      } else if (a >= 0 && b >= 22) {
        b = b - 22;
      } else
        break;
    } else {
      if (a > 0 && b >= 22) {
        b = b - 22;
      } else if (a >= 1 && b >= 12) {
        a = a - 1;
        b = b - 12;
      } else if (a >= 2 && b >= 2) {
        b = b - 2;
        a = a - 2;
      } else
        break;
    }
  }
  if (i % 2 == 1)
    cout << "Hanako" << endl;
  else
    cout << "Ciel" << endl;
  return 0;
}
