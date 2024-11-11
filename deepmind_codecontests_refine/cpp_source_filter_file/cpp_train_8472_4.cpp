#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y, c;
  cin >> x >> y;
  if (x % 2 == 1)
    c = x / 2 + 1;
  else
    c = x / 2;
  if (y <= c)
    cout << (2 * y) - 1 << endl;
  else
    cout << (y - c) * 2 << endl;
}
