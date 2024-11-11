#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, n, a, x = 0, y = 0, z = 0;
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> a;
    if (i % 3 == 1)
      x = x + a;
    else if (i % 3 == 2)
      y = y + a;
    else
      z = z + a;
  }
  if (x >= y) {
    if (x > z)
      cout << "chest";
    else
      cout << "back";
  } else {
    if (y > z)
      cout << "biceps";
    else
      cout << "back";
  }
  return 0;
}
