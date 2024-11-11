#include <bits/stdc++.h>
using namespace std;
int c[305][3005];
int s[305][3005];
int b[3005], a[3005];
int main() {
  int i, j, n, m, p, f, qq;
  cin >> n;
  for (i = 1; i <= n; i++) {
    scanf("%d", &b[i]);
    if (i == 1) {
      m = (b[i] - 1) / 9;
      c[i][0] = b[i] - 9 * m;
      s[i][0] = c[i][0];
      for (j = 1; j <= m; j++) {
        c[i][j] = 9;
        s[i][j] = s[i][j - 1] + 9;
      }
      a[i] = m + 1;
    } else {
      p = a[i - 1];
      for (j = 1; j <= 3001; j++) {
        if (j <= p - 1) {
          qq = 0;
          for (int u = 1; u <= 9; u++) {
            if (s[i - 1][p - 1 - j] + c[i - 1][p - j] + u <= b[i] &&
                9 * (j - 1) + s[i - 1][p - 1 - j] + c[i - 1][p - j] + u >=
                    b[i] &&
                c[i - 1][p - j] + u <= 9) {
              for (f = 0; f <= p - j - 1; f++) {
                c[i][f] = c[i - 1][f];
                s[i][f] = s[i - 1][f];
              }
              c[i][p - j] = c[i - 1][p - j] + u;
              s[i][p - j] = s[i][p - j - 1] + c[i][p - j];
              m = b[i] - s[i][p - j];
              int w = m;
              if (m != 0) m = (m - 1) / 9;
              for (f = p - j + 1; f < p - m - 1; f++) {
                c[i][f] = 0;
                s[i][f] = s[i][f - 1];
              }
              if (p - m - 1 > p - j) {
                c[i][p - m - 1] = w - 9 * m;
                s[i][p - m - 1] = s[i][p - m - 2] + c[i][p - m - 1];
              }
              for (f = p - m; f <= p - 1; f++) {
                c[i][f] = 9;
                s[i][f] = s[i][f - 1] + 9;
              }
              a[i] = p;
              qq = 1;
              break;
            }
          }
          if (qq) break;
        } else if (j == p) {
          qq = 0;
          for (int u = 1; u <= 9; u++) {
            if (c[i - 1][0] + u <= 9 && c[i - 1][0] + u <= b[i] &&
                c[i - 1][0] + u + (p - 1) * 9 >= b[i]) {
              c[i][0] = c[i - 1][0] + u;
              s[i][0] = c[i][0];
              m = b[i] - c[i][0];
              int w = m;
              if (m != 0) m = (m - 1) / 9;
              for (f = 1; f < p - m - 1; f++) {
                c[i][f] = 0;
                s[i][f] = s[i][f - 1];
              }
              if (p - m - 1 > p - j) {
                c[i][p - m - 1] = w - 9 * m;
                s[i][p - m - 1] = s[i][p - m - 2] + c[i][p - m - 1];
              }
              for (f = p - m; f < p; f++) {
                c[i][f] = 9;
                s[i][f] = s[i][f - 1] + 9;
              }
              a[i] = p;
              qq = 1;
              break;
            }
          }
          if (qq) break;
        } else {
          if (9 * j >= b[i]) {
            for (f = 1; f <= 9; f++) {
              if (f + (j - 1) * 9 >= b[i]) {
                c[i][0] = f;
                s[i][0] = f;
                m = (b[i] - f);
                int w = m;
                if (m != 0) m = (m - 1) / 9;
                for (int u = 1; u < (j - m - 1); u++) {
                  c[i][u] = 0;
                  s[i][u] = s[i][u - 1];
                }
                if (j - m - 1 > 0) {
                  c[i][j - m - 1] = w - 9 * m;
                  s[i][j - m - 1] = s[i][j - m - 2] + c[i][j - m - 1];
                }
                for (int u = j - m; u < j; u++) {
                  c[i][u] = 9;
                  s[i][u] = s[i][u - 1] + c[i][u];
                }
                break;
              }
            }
            a[i] = j;
            break;
          }
        }
      }
    }
  }
  for (i = 1; i <= n; i++) {
    for (j = 0; j < a[i]; j++) printf("%d", c[i][j]);
    printf("\n");
  }
}
