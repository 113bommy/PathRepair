#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int x = b * c;
  int y = a * c;
  if (y <= x) {
    cout << 0;
    return 0;
  }
  if ((y - x) <= b)
    cout << (y - x);
  else {
    if ((y - x) % b == 0)
      cout << (y - x) / b;
    else
      cout << ((y - x) / b) + 1;
  }
  return 0;
}
