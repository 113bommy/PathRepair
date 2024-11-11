#include <bits/stdc++.h>
using namespace std;
int n, flag, r, c, ans, Left, Right;
char s[200][200];
int d[1000000][2], f[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int main() {
  while (~scanf("%d%d", &r, &c)) {
    for (int i = 0; i < r; ++i) scanf("%s", &s[i]);
    ans = 0;
    for (int i = 0; i < r; ++i)
      for (int j = 0; j < c; ++j)
        if (s[i][j] == 'B') {
          ++ans;
          s[i][j] = '.';
          Left = Right = 0;
          d[0][0] = i;
          d[0][1] = j;
          while (Left <= Right) {
            for (int k = 0; k < 4; ++k)
              if (d[Left][0] + f[k][0] >= 0 && d[Left][0] + f[k][0] < r &&
                  d[Left][1] + f[k][1] >= 0 && d[Left][1] + f[k][1] < c &&
                  s[d[Left][0] + f[k][0]][d[Left][1] + f[k][1]] == 'B') {
                ++Right;
                ;
                d[Right][0] = d[Left][0] + f[k][0];
                d[Right][1] = d[Left][1] + f[k][1];
                s[d[Left][0] + f[k][0]][d[Left][1] + f[k][1]] = '.';
              }
            ++Left;
          }
        }
    cout << ans << endl;
  }
}
