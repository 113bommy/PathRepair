#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, x = -1, y = -1, res = 0;
  cin >> n >> k;
  char** a = new char*[n];
  for (int i = 0; i < n; i++) a[i] = new char[k];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 0; i < k; i++) {
    if (a[n - 1][i] != '.') {
      x = i;
      break;
    }
  }
  for (int i = k - 1; i > -1; i--) {
    if (a[n - 1][i] != '.') {
      y = i;
      break;
    }
  }
  if (x == -1 or y == -1) {
    cout << 0 << endl;
  } else {
    for (int i = x + 1; i < y + 1; i++) {
      if (a[n - 1][i - 1] == 'B' && a[n - 1][i] == '.') {
        res += 1;
      }
    }
    cout << res + 1 << endl;
  }
  return 0;
}
