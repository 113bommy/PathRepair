#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, n, x, y;
  cin >> n;
  if (n >= 0)
    cout << n << endl;
  else {
    if (n <= -10) {
      i = n % 10;
      n = n / 10;
      j = n % 10;
      n = n / 10;
      x = n * 10 + i;
      y = n * 10 + j;
    }
    if (x < y)
      cout << y << endl;
    else
      cout << x << endl;
  }
  return 0;
}
