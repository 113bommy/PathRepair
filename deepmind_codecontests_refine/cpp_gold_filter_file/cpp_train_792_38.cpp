#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  char s[n][m];
  bool bl = false;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cin >> s[i][j];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      bl = false;
      for (int a = 0; a < m; a++) {
        if (s[i][j] == s[i][a] && j != a) {
          bl = true;
          break;
        }
      }
      for (int a = 0; a < n; a++) {
        if (s[i][j] == s[a][j] && i != a) {
          bl = true;
          break;
        }
      }
      if (!bl) cout << s[i][j];
    }
  }
  return 0;
}
