#include <bits/stdc++.h>
using namespace std;
char n[102][102];
int main() {
  int x, i, j, f;
  cin >> x;
  for (i = 1; i <= x; i++) cin >> n[i];
  for (i = 1; i <= x; i++) {
    for (j = 1; j <= x; j++) {
      if (n[i][j] == '#' && n[i - 1][j] == '#' && n[i + 1][j] == '#' &&
          n[i][j - 1] == '#' && n[i][j + 1] == '#') {
        n[i][j] = '.';
        n[i - 1][j] = '.';
        n[i + 1][j] = '.';
        n[i][j - 1] = '.';
        n[i][j + 1] = '.';
      }
    }
  }
  for (i = 1; i <= x; i++) {
    for (j = 1; j <= x; j++) {
      if (n[i][j] == '#') {
        cout << "NO\n";
        return 0;
      }
    }
  }
  cout << "YES\n";
}
