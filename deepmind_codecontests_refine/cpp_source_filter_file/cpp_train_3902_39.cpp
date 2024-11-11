#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, n, i, j, m;
  cin >> n >> m;
  for (j = 0; j < n; j++) {
    for (i = 0; i < m; i++) {
      if ((j % 2) == 0)
        cout << '#';
      else {
        if ((j + 1 % 4) == 0) {
          if (i == 0)
            cout << '#';
          else
            cout << '.';
        } else {
          if (i == m - 1)
            cout << '#';
          else
            cout << '.';
        }
      }
    }
    cout << endl;
  }
  return 0;
}
