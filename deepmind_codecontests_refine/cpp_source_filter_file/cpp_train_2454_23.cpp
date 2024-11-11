#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c;
  while (cin >> a >> b >> c) {
    int sum = 0;
    while (1) {
      if (a == 0) break;
      if (a * 2 < b)
        if (a * 4 < c) {
          sum = a + (a * 2) + (a * 4);
          break;
        }
      a--;
    }
    cout << sum << endl;
  }
  return 0;
}
