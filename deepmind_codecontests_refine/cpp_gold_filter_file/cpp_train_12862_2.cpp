#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  char a[n][5];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 5; j++) {
      cin >> a[i][j];
    }
  }
  int c = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 5; j += 3) {
      if (a[i][j] == 'O' && a[i][j + 1] == 'O') {
        cout << "YES" << endl;
        a[i][j] = '+';
        a[i][j + 1] = '+';
        c++;
        break;
      }
    }
    if (c == 1) break;
  }
  if (c == 0)
    cout << "NO" << endl;
  else {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 5; j++) {
        cout << a[i][j];
      }
      cout << endl;
    }
  }
}
