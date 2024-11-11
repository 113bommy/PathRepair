#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, j;
  cin >> n;
  char arr[n + 1][n + 1];
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      if (i % 2 == 0) {
        if (j % 2 != 0) {
          arr[i][j] = 'W';
        } else
          arr[i][j] = 'B';
      } else {
        if (j % 2 != 0) {
          arr[i][j] = 'B';
        } else
          arr[i][j] = 'W';
      }
    }
  }
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      cout << arr[i][j];
    }
    cout << "\n";
  }
}
