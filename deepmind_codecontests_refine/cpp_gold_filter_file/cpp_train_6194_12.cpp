#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, y;
  cin >> n;
  x = 2;
  while (n--) {
    cin >> y;
    if (y == 1) x = 1;
  }
  if (x == 1)
    cout << -1 << endl;
  else
    cout << 1 << endl;
  return 0;
}
