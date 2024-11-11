#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, c = 0;
  cin >> x;
  if (x == 2 || x == 1)
    cout << 1 << endl << 1;
  else if (x == 3)
    cout << 2 << endl << "1 3";
  else {
    cout << x << endl;
    for (int i = x; i >= 1; i--) {
      if (i % 2 != 0) cout << i << ' ';
    }
    for (int i = x; i >= 1; i--) {
      if (i % 2 == 0) cout << i << ' ';
    }
  }
  return 0;
}
