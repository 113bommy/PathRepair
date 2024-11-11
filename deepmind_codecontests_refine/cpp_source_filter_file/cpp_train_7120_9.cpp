#include <bits/stdc++.h>
using namespace std;
char a[101][101];
int main() {
  int n, r = 1, c = 1;
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) cin >> a[i][j];
  for (int i = 0; i < n; i++) {
    int b = 0;
    for (int j = 0; j < n; j++) {
      if (a[i][j] == 'E') b++;
    }
    if (b == n) r = 0;
  }
  for (int i = 0; i < n; i++) {
    int b = 0;
    for (int j = 0; j < n; j++) {
      if (a[j][i] == 'E') b++;
    }
    if (b == n) c = 0;
  }
  if (r == 0 && c == 0)
    cout << -1;
  else if (r == 1) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (a[i][j] == '.') {
          cout << i + 1 << ' ' << j + 1 << endl;
          break;
        }
      }
    }
  } else {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (a[j][i] == '.') {
          cout << i + 1 << ' ' << j + 1 << endl;
          break;
        }
      }
    }
  }
  return 0;
}
