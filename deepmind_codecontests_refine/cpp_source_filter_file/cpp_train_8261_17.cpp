#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const int inf = 10000000;
int res[1001][2][32][32][32];
int main() {
  int n, h, na, nb, nc;
  cin >> n >> h;
  res[0][1][0][0][0] = 1;
  for (int i = (0); i < (n); i++)
    for (int a = 0; a < (h); a++)
      for (int b = 0; b < (h); b++)
        for (int c = 0; c < (h); c++)
          for (int l = 0; l < (2); l++) {
            int &ans = res[i][l][a][b][c];
            na = ((a == 0 || a == h - 1) ? 0 : a + 1);
            nb = ((b == 0 || b == h - 1) ? 0 : b + 1);
            nc = ((c == 0 || c == h - 1) ? 0 : c + 1);
            res[i + 1][l][na][nb][nc] += ans;
            if (res[i + 1][l][na][nb][nc] >= 1000000009)
              res[i + 1][l][na][nb][nc] -= 1000000009;
            res[i + 1][a > 0 || i < h][l][nb][nc] += ans;
            if (res[i + 1][a > 0 || i < h][l][nb][nc] >= 1000000009)
              res[i + 1][a > 0 || i < h][l][nb][nc] -= 1000000009;
            res[i + 1][b > 0 || i < h][na][l][nc] += ans;
            if (res[i + 1][b > 0 || i < h][na][l][nc] >= 1000000009)
              res[i + 1][b > 0 || i < h][na][l][nc] -= 1000000009;
            res[i + 1][c > 0 || i < h][na][nb][l] += ans;
            if (res[i + 1][c > 0 || i < h][na][nb][l] >= 1000000009)
              res[i + 1][c > 0 || i < h][na][nb][l] -= 1000000009;
          }
  int ans = 0;
  for (int a = 0; a < (h); a++)
    for (int b = 0; b < (h); b++)
      for (int c = 0; c < (h); c++) {
        ans += res[n][1][a][b][c];
        if (ans >= 1000000009) ans -= 1000000009;
        if (a || b || c) {
          ans += res[n][0][a][b][c];
          if (ans >= 1000000009) ans -= 1000000009;
        }
      }
  cout << ans << endl;
  return 0;
}
