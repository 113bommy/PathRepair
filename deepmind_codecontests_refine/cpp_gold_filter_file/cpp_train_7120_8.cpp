#include <bits/stdc++.h>
using namespace std;
bool a[101], b[101];
char d[101][101];
int main() {
  int n, i, j;
  cin >> n;
  for (i = 0; i < n; ++i) {
    for (j = 0; j < n; ++j) {
      cin >> d[i][j];
      if (d[i][j] == '.') a[i] = b[j] = 1;
    }
  }
  bool b1 = 1, b2 = 1;
  for (i = 0; i < n; ++i) b1 = b1 & a[i];
  for (i = 0; i < n; ++i) b2 = b2 & b[i];
  if ((b1 | b2) == 0) {
    cout << "-1";
    return 0;
  }
  if (b1) {
    for (i = 0; i < n; ++i) {
      for (j = 0; j < n; ++j) {
        if (d[i][j] == '.') {
          cout << i + 1 << " " << j + 1 << endl;
          break;
        }
      }
    }
  } else {
    for (i = 0; i < n; ++i) {
      for (j = 0; j < n; ++j) {
        if (d[j][i] == '.') {
          cout << j + 1 << " " << i + 1 << endl;
          break;
        }
      }
    }
  }
  return 0;
}
