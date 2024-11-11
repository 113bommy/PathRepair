#include <bits/stdc++.h>
using namespace std;
const int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int n, m, k, a[60][60], b[60][60][4][4];
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    m = (int)s.length();
    for (int j = 0; j < m; ++j) a[i + 1][j + 1] = s[j] - '0';
  }
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      for (int l = 0; l < 4; ++l)
        for (int p = 0; p < 4; ++p) b[i][j][l][p] = -1;
  int pi = 1, pj = 1, dp = 0, cp = 3, cnt = 1;
  b[pi][pj][dp][cp] = 0;
  while (cnt <= k) {
    while (a[pi][pj] == a[pi + d[dp][0]][pj + d[dp][1]]) {
      pi += d[dp][0];
      pj += d[dp][1];
    }
    while (a[pi][pj] == a[pi + d[cp][0]][pj + d[cp][1]]) {
      pi += d[cp][0];
      pj += d[cp][1];
    }
    if (a[pi + d[dp][0]][pj + d[dp][1]]) {
      pi += d[dp][0];
      pj += d[dp][1];
      while (a[pi][pj] == a[pi][pj - 1]) --pj;
      while (a[pi][pj] == a[pi - 1][pj]) --pi;
    } else {
      if (((dp + 1) & 3) == cp) {
        dp = (dp + 1) & 3;
        cp = (dp + 3) & 3;
      } else
        cp = (dp + 1) & 3;
    }
    if (b[pi][pj][dp][cp] != -1) break;
    b[pi][pj][dp][cp] = cnt++;
  }
  if (k == cnt)
    k = 0;
  else
    k = (k - b[pi][pj][dp][cp]) % (cnt - b[pi][pj][dp][cp] + 1);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      for (int l = 0; l < 4; ++l)
        for (int p = 0; p < 4; ++p)
          if (b[i][j][l][p] == b[pi][pj][dp][cp] + k) {
            cout << a[i][j];
            return 0;
          }
  return 0;
}
