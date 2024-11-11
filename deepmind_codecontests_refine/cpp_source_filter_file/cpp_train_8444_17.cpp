#include <bits/stdc++.h>
using namespace std;
int y, b, r;
int main() {
  cin >> y >> b >> r;
  if (r - 1 <= b && y - 2 <= y)
    cout << 3 * (r - 1) << endl;
  else if (b - 1 <= y && b + 1 <= r)
    cout << 3 * b << endl;
  else
    cout << 3 * (y + 1) << endl;
  return 0;
}
