#include <bits/stdc++.h>
using namespace std;
char s[525][525];
int a[525][525];
int b[525][525];
int main() {
  int i, j, h, w;
  cin >> h >> w;
  for (i = 1; i <= h; i++) {
    cin >> s[i] + 1;
    for (j = 1; j <= w; j++) {
      if (s[i][j] == '.' && s[i - 1][j] == '.') a[i][j]++;
      if (s[i][j] == '.' && s[i][j - 1] == '.') b[i][j]++;
      a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
      b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];
    }
  }
  int p;
  cin >> p;
  while (p--) {
    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int ans = a[x2][y2] - a[x1][y2] - a[x2][y1 - 1] + a[x1][y1 - 1] +
              b[x2][y2] - b[x2][y1] - b[x1 - 1][y2] + b[x1 - 1][y1];
    cout << ans;
  }
  return 0;
}
