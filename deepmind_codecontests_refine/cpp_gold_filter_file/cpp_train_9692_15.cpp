#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, t = 0, u = 0, m, k, l, j, i, a = 0, b = 0, e = 0, c, d;
  scanf("%d %d", &n, &m);
  char s[116][116];
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      cin >> s[i][j];
    }
  }
  for (k = 0; k < n; k++) {
    for (l = 0; l < m; l++) {
      if (s[k][l] == 'B') {
        a = 1;
        e = k + 1;
        b = l + 1;
        break;
      }
      if (a == 1) break;
    }
    if (a == 1) break;
  }
  for (k = 0; k < n; k++) {
    for (l = 0; l < m; l++) {
      if (s[k][l] == 'B') {
        t = k + 1;
        u = l + 1;
      }
    }
  }
  cout << (e + t) / 2 << " " << (b + u) / 2 << endl;
  return 0;
}
