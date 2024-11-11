#include <bits/stdc++.h>
using namespace std;
int k, i, j, c[400000][5], b[111110], m, n;
int main() {
  cin >> n >> m;
  for (i = 1; i <= m; i++)
    for (j = 1; j <= 3; j++) cin >> c[i][j];
  for (i = 1; i <= m; i++)
    if ((b[c[i][1]] == 0) && (b[c[i][2]] == 0) && (b[c[i][3]] == 0)) {
      b[c[i][1]] = 1;
      b[c[i][2]] = 2;
      b[c[i][3]] = 3;
    } else if (b[c[i][1]] != 0) {
      k = b[c[i][1]];
      k++;
      if (k > 3) k = k - 3;
      b[c[i][2]] = k;
      k++;
      if (k > 3) k = k - 3;
      b[c[i][3]] = k;
    } else if (b[c[i][2]] != 0) {
      k = b[c[i][2]];
      k++;
      if (k > 3) k = k - 3;
      b[c[i][3]] = k;
      k++;
      if (k > 3) k = k - 3;
      b[c[i][1]] = k;
    } else if (b[c[i][3]] != 0) {
      k = b[c[i][3]];
      k++;
      if (k > 3) k = k - 3;
      b[c[i][1]] = k;
      k++;
      if (k > 3) k = k - 3;
      b[c[i][2]] = k;
    }
  for (i = 1; i <= n; i++) {
    cout << b[i] << " ";
  }
}
