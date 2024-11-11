#include <bits/stdc++.h>
using namespace std;
char a[15][15];
int main() {
  for (int i = 1; i <= 9; i++) {
    for (int j = 1; j <= 9; j++) cin >> a[i][j];
  }
  int x, y;
  cin >> x >> y;
  int aa, b;
  int cnt = 0;
  aa = x % 3;
  if (aa == 0) aa = 3;
  b = y % 3;
  if (b == 0) b = 3;
  for (int i = 3 * (aa - 1) + 1; i <= 3 * aa; i++) {
    for (int j = 3 * (b - 1) + 1; j <= 3 * b; j++) {
      if (a[i][j] == '.') {
        a[i][j] = '!';
        cnt++;
      }
    }
  }
  if (cnt == 0) {
    for (int i = 1; i <= 9; i++) {
      for (int j = 1; j <= 9; j++) {
        if (a[i][j] == '.') a[i][j] = '!';
      }
    }
  }
  for (int i = 1; i <= 9; i++) {
    for (int j = 1; j <= 9; j++) {
      cout << a[i][j];
      if (j == 3 || j == 6) cout << " ";
    }
    if (i == 3 || i == 6) cout << endl;
    cout << endl;
  }
  return 0;
}
