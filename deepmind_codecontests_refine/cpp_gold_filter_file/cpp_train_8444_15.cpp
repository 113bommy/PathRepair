#include <bits/stdc++.h>
using namespace std;
int main() {
  int y, b, r;
  cin >> y >> b >> r;
  if (((y + 2) <= (b + 1)) && ((y + 2) <= r)) {
    cout << (y + y + 1 + y + 2);
  } else if (((b + 1) <= (y + 2)) && ((b + 1) <= r)) {
    cout << (b - 1 + b + b + 1);
  } else {
    cout << (r - 2 + r - 1 + r);
  }
  return 0;
}
