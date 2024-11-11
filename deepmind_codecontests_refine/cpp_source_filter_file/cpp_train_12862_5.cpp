#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, j;
  cin >> n;
  char a[n][5];
  for (i = 0; i < n; i++) {
    for (j = 0; j < 5; j++) {
      cin >> a[i][j];
    }
  }
  bool flag = false;
  for (i = 0; i < n; i++) {
    for (j = 0; j < 5; j++) {
      if (a[i][j] == 'O' && a[i][j + 1] == 'O') {
        a[i][j] = '+';
        a[i][j + 1] = '+';
        flag = true;
        break;
      }
    }
    if (flag) {
      break;
    }
  }
  if (flag) {
    cout << "YES" << endl;
    for (i = 0; i < n; i++) {
      for (j = 0; j < 5; j++) {
        cout << a[i][j];
      }
      cout << endl;
    }
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
