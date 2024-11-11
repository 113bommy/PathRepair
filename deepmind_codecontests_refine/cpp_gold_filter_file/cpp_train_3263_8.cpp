#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0);
  std::ios::sync_with_stdio(false);
  long long x, y;
  cin >> x;
  while (x--) {
    cin >> y;
    if (y % 2 == 0)
      cout << y * 4 + 1 << endl;
    else if (y % 4 == 0)
      cout << y * 2 + 1 << endl;
    else {
      if ((y - 1) % 4)
        cout << y + 1 << endl;
      else
        cout << y * 2 + 1 << endl;
    }
  }
  return 0;
}
