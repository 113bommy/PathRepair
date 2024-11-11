#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  char b;
  cin >> b;
  int x, y;
  x = (b - 'a');
  cin >> b;
  y = (b - '1');
  if (x > 0 && y > 0 && x < 7 && y < 7) {
    cout << 8;
  } else if ((x == 0 && y == 0) || (x == 7 && y == 0) || (x == 0 && y == 7) ||
             (x == 7 && y == 7)) {
    cout << 5;
  } else {
    cout << 3;
  }
  return 0;
}
