#include <bits/stdc++.h>
using namespace std;
const int N = 109;
char s[N][N];
int len[N][N];
int main() {
  int n, m, i, j, x, y, k;
  while (~scanf("%d%d", &n, &m)) {
    int mi = min(n, m);
    memset(s, 0, sizeof(s));
    memset(len, -1, sizeof(-1));
    for (i = 1; i <= mi; ++i) {
      for (j = 1; j <= mi; ++j) {
        s[i][j] = 'A';
        len[i][j] = mi;
      }
    }
    int x1, y1;
    for (i = 1; i <= n; ++i) {
      for (j = 1; j <= m; ++j) {
        if (s[i][j]) {
          continue;
        }
        bool f = false;
        for (s[i][j] = 'A';; ++s[i][j]) {
          bool cur = true;
          if (s[i][j] != s[i - 1][j] && s[i][j] != s[i][j + 1]) {
            if (s[i][j] != s[i][j - 1]) {
              len[i][j] = 1;
              f = true;
            } else {
              x1 = i + len[i][j - 1];
              y1 = j - len[i][j - 1] - 1;
              if (i + len[i][j - 1] <= n && s[x1][y1] != s[i][j]) {
                len[i][j] = len[i][j - 1] + 1;
                f = true;
                x = i;
                y = j;
                for (k = 1; k <= len[i][j - 1]; ++k) {
                  ++x;
                  s[x][y] = s[i][j];
                  len[x][y] = len[i][j - 1] + 1;
                }
                for (k = 1; k <= len[i][j - 1]; ++k) {
                  --y;
                  s[x][y] = s[i][j];
                  len[x][y] = len[i][j - 1] + 1;
                }
              }
            }
          }
          if (f) {
            break;
          }
        }
      }
    }
    for (i = 1; i <= n; ++i) {
      puts(s[i] + 1);
    }
  }
  return 0;
}
