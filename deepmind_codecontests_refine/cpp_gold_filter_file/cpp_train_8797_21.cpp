#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, n = 0;
  cin >> x;
  while (x) {
    if (x >= 5)
      x -= 5;
    else if (x >= 4)
      x -= 4;
    else if (x >= 3)
      x -= 3;
    else if (x >= 2)
      x -= 2;
    else if (x >= 1)
      x -= 1;
    n++;
  }
  cout << n;
  return 0;
}
