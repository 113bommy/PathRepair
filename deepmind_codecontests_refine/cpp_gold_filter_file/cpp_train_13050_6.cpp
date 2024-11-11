#include <bits/stdc++.h>
using namespace std;
int n, a[55][55], c, i, j, k, m;
int b[1220], s[1220][4];
int main() {
  cin >> n;
  for (i = 0; i < n; i++) cin >> b[i];
  for (i = 0; i < n; i++) {
    for (j = 0; j < b[i]; j++) cin >> a[i][j];
    c += b[i];
  }
  int t = 0, y = 0, x = 0;
  for (k = 1; k <= c; k++) {
    if (a[x][y] != k)
      for (i = 0; i < n; i++)
        for (j = 0; j < b[i]; j++)
          if (a[i][j] == k) {
            s[t][0] = i + 1;
            s[t][1] = j + 1;
            s[t][2] = x + 1;
            s[t++][3] = y + 1;
            swap(a[x][y], a[i][j]);
          }
    y++;
    if (y == b[x]) {
      x++;
      y = 0;
    }
  }
  cout << t << endl;
  for (i = 0; i < t; i++)
    printf("%d %d %d %d\n", s[i][0], s[i][1], s[i][2], s[i][3]);
  return 0;
}
