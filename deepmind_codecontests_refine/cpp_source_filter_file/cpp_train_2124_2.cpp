#include <bits/stdc++.h>
using namespace std;
int main() {
  int k;
  cin >> k;
  if (k % 2 == 1) {
    cout << -1;
    return 0;
  }
  for (int i = 0; i < k; i++) {
    if (i % 2 == 0) {
      for (int j = 0; j < k; j++) {
        for (int l = 0; l < k; l++) {
          if ((l % 4 == 0 && j % 4 == 0) || (l % 4 == 1 && j % 4 == 0) ||
              (l % 4 == 1 && j % 4 == 1) || (l % 4 == 0 && j % 4 == 1) ||
              (l % 4 == 2 && j % 4 == 2) || (l % 4 == 3 && j % 4 == 2) ||
              (l % 4 == 3 && j % 4 == 3) || (j % 4 == 2 && j % 4 == 3))
            cout << 'b';
          else
            cout << 'w';
        }
        cout << endl;
      }
    } else {
      for (int j = 0; j < k; j++) {
        for (int l = 0; l < k; l++) {
          if ((l % 4 == 0 && j % 4 == 0) || (l % 4 == 1 && j % 4 == 0) ||
              (l % 4 == 1 && j % 4 == 1) || (l % 4 == 0 && j % 4 == 1) ||
              (l % 4 == 2 && j % 4 == 2) || (l % 4 == 3 && j % 4 == 2) ||
              (l % 4 == 3 && j % 4 == 3) || (j % 4 == 2 && j % 4 == 3))
            cout << 'w';
          else
            cout << 'b';
        }
        cout << endl;
      }
    }
    cout << endl;
  }
}
