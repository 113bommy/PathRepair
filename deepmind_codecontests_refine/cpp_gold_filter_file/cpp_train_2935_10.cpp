#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, j;
  cin >> n;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      if (i % 2 != 0) {
        if (j % 2 != 0) {
          if (j != n)
            cout << "W";
          else
            cout << "W" << endl;
        } else {
          if (j != n)
            cout << "B";
          else
            cout << "B" << endl;
        }
      } else {
        if (j % 2 == 0) {
          if (j != n)
            cout << "W";
          else
            cout << "W" << endl;
        } else {
          if (j != n)
            cout << "B";
          else
            cout << "B" << endl;
        }
      }
    }
  }
  return 0;
}
