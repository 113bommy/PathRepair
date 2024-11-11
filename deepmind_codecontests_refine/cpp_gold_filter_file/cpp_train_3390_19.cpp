#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y;
  cin >> x >> y;
  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) {
      char a, b;
      cin >> a >> b;
      if (a == 'C' || a == 'M' || a == 'Y' || b == 'C' || b == 'M' ||
          b == 'Y') {
        cout << "#Color";
        return 0;
      }
    }
  }
  cout << "#Black&White";
  return 0;
}
