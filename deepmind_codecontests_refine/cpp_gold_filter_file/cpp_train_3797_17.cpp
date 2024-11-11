#include <bits/stdc++.h>
using namespace std;
char s[2][55], fr[55], fw[55], to[55][4];
bool pt[2][55][55][30];
int len[2], f[55][55];
int main() {
  for (int i = 0; i <= 1; ++i) {
    scanf("%s", s[i] + 1);
    len[i] = strlen(s[i] + 1);
    for (int j = 1; j <= len[i]; ++j) s[i][j] -= 'a';
  }
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%s", fw);
    fr[i] = fw[0] - 'a';
    to[i][0] = fw[3] - 'a';
    to[i][1] = fw[4] - 'a';
  }
  for (int T = 0; T <= 1; ++T) {
    for (int i = 1; i <= len[T]; ++i) pt[T][i][i][s[T][i]] = 1;
    for (int k = 2; k <= len[T]; ++k) {
      for (int i = 1, j; i + k - 1 <= len[T]; ++i) {
        j = i + k - 1;
        for (int ii = i; ii < j; ++ii) {
          for (int jj = 1; jj <= n; ++jj)
            pt[T][i][j][fr[jj]] |=
                pt[T][i][ii][to[jj][0]] & pt[T][ii + 1][j][to[jj][1]];
        }
      }
    }
  }
  memset(f, 0x3f, sizeof f);
  f[0][0] = 0;
  for (int i = 1; i <= len[0]; ++i) {
    for (int j = 1; j <= len[1]; ++j) {
      for (int ii = 0; ii < i; ++ii) {
        for (int jj = 0; jj < j; ++jj) {
          if (f[ii][jj] == 0x3f3f3f3f) continue;
          for (int ch = 0; ch < 26; ++ch) {
            if (pt[0][ii + 1][i][ch] && pt[1][jj + 1][j][ch])
              f[i][j] = min(f[i][j], f[ii][jj] + 1);
          }
        }
      }
    }
  }
  if (f[len[0]][len[1]] == 0x3f3f3f3f)
    puts("-1");
  else
    printf("%d\n", f[len[0]][len[1]]);
  return 0;
}
