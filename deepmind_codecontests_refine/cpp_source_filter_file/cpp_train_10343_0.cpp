#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, i, r;
  cin >> x;
  if (x == 1) {
    cout << 1;
    return 0;
  }
  if (x == 3) {
    cout << 3;
    return 0;
  }
  int st = 0;
  for (int i = 1; i < 10; ++i) {
    for (int j = 0; j < i; ++j) {
      st += 4;
      if (st + 1 >= x) {
        cout << (2 * i + 1);
        return 0;
      }
    }
  }
  return 0;
}
