#include <bits/stdc++.h>
using namespace std;
char a[105][105];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (a[i][j] == '#' && a[i - 1][j] == '#' && a[i][j - 1] == '#' &&
          a[i][j + 1] == '#' && a[i + 1][j] == '#') {
        a[i][j] = 0;
        a[i - 1][j] = 0;
        a[i][j - 1] = 0;
        a[i][j + 1] = 0;
        a[i + 1][j] = 0;
      }
    }
  }
  bool s = true;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (a[i][j] == '#') {
        s = false;
      }
    }
  }
  if (s) {
    cout << "YES";
  } else {
    cout << "NO";
  }
}
