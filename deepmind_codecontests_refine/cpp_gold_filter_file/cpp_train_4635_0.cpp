#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int h, w;
  cin >> h >> w;
  string s[h];
  int a[h][w], b[w][h];
  for (int i = 0; i < h; i++) {
    cin >> s[i];
    a[i][0] = 0;
    for (int j = 1; j < w; j++) {
      if (s[i][j] == '.' && s[i][j - 1] == '.')
        a[i][j] = a[i][j - 1] + 1;
      else
        a[i][j] = a[i][j - 1];
    }
  }
  for (int i = 0; i < w; i++) {
    b[i][0] = 0;
    for (int j = 1; j < h; j++) {
      if (s[j][i] == '.' && s[j - 1][i] == '.')
        b[i][j] = b[i][j - 1] + 1;
      else
        b[i][j] = b[i][j - 1];
    }
  }
  int q;
  cin >> q;
  while (q--) {
    int xi, xf, ci, cf, ans = 0;
    cin >> xi >> ci >> xf >> cf;
    for (int i = xi - 1; i < xf; i++) ans += a[i][cf - 1] - a[i][ci - 1];
    for (int i = ci - 1; i < cf; i++) ans += b[i][xf - 1] - b[i][xi - 1];
    cout << ans << endl;
  }
  return 0;
}
