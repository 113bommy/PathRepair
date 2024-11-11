#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a, b, x, y;
  x = 0;
  y = 0;
  int seven = n / 7;
  int min = 1000000000;
  for (int i = 0; i <= seven; i++) {
    b = i;
    a = (n - 7 * b) / 4;
    if ((4 * a + 7 * b) == n) {
      if ((a + b) < min) {
        min = a + b;
        x = a;
        y = b;
      } else if ((a + b) == min) {
        if (b < y) {
          x = a;
          y = b;
        }
      }
    }
  }
  if ((4 * x + 7 * y) == n) {
    for (int i = 1; i <= x; i++) cout << "4";
    for (int i = 1; i <= y; i++) cout << "7";
  } else
    cout << "-1";
  cout << endl;
  return 0;
}
