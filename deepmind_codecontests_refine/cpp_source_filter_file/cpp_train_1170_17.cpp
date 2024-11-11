#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, x, y, i, j, d = 0, star = 0, cn = 0;
    cin >> n >> m >> x >> y;
    char s[n][m];
    for (i = 0; i < n; i++) {
      for (j = 0; j < m - 1; j++) {
        cin >> s[i][j];
        if (s[i][j] == '.')
          d++;
        else
          star++;
      }
    }
    if (y >= 2 * x) {
      cout << d * x << endl;
    } else {
      for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
          if (s[i][j] == '.' && s[i][j + 1] == '.') {
            j++;
            cn++;
          }
        }
      }
      cout << cn * y + (d - 2 * cn) * x << endl;
    }
  }
  return 0;
}
