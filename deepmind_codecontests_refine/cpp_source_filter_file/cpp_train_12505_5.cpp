#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, x, i = 0;
  cin >> x;
  if (x > 100 || x < 1) {
    std::cout << "-1" << std::endl;
    exit(0);
  }
  for (b = 1; b <= x; b++) {
    for (c = 2; c < x; c++) {
      a = c * b;
      if (a * b > x && a < x) {
        cout << a << " " << b << endl;
        i++;
      }
      if (i == 1) break;
    }
    if (i == 1) break;
  }
  if (i == 0) std::cout << "-1" << std::endl;
}
