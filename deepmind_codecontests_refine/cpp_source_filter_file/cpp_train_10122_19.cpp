#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  for (int i = 0; i < T; i++) {
    long a, b;
    cin >> a >> b;
    int steps = 0;
    if (a == b)
      cout << steps << endl;
    else if (a > b) {
      if ((a - b) % 2 == 0)
        cout << (steps + 1) << endl;
      else
        cout << (steps + 2) << endl;
    } else {
      if ((b - a) == 1)
        cout << (steps + 1) << endl;
      else
        cout << (steps + 2) << endl;
    }
  }
  return 0;
}
