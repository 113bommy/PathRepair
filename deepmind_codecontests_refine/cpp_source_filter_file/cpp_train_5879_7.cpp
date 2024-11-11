#include <bits/stdc++.h>
using namespace std;
int n, m, A, B, C;
char str[205][205];
int cp[105], tmp[2][105], ans[105][105];
int main() {
  cin >> n >> m >> A >> B >> C;
  int tl = 0, ci = 1, cj = 1;
  for (int T = (1), Tend = (A); T <= Tend; ++T) {
    cp[cj] = ci, tl = cj, ans[ci][cj] = 1;
    cj == m ? ci++, cj = 1 : cj++;
  }
  for (int j = (tl), jend = (1); j >= jend; --j)
    ans[cp[j] + 1][j] = (tl - j) & 1 ? 3 : 6;
  for (int j = (tl + 1), jend = (m); j <= jend; ++j)
    ans[cp[j] + 1][j] = (j - tl) & 1 ? 6 : 3;
  ci++;
  for (int T = (1), Tend = (B); T <= Tend; ++T) {
    ans[ci][cj] = 2;
    cj == m ? ci++, cj = 1 : cj++;
  }
  for (int j = (1), jend = (cj - 1); j <= jend; ++j)
    tmp[0][j] = (cj - j) & 1 ? 6 : 3, tmp[1][j] = (cj - j) & 1 ? 5 : 4;
  for (int j = (cj), jend = (m); j <= jend; ++j)
    tmp[0][j] = ans[ci][j] = (j - cj) & 1 ? 5 : 4,
    tmp[2][j] = (j - cj) & 1 ? 6 : 3;
  for (int i = (ci + 1), iend = (n); i <= iend; ++i)
    for (int j = (1), jend = (m); j <= jend; ++j)
      ans[i][j] = tmp[(i - ci) & 1][j];
  for (int i = (1), iend = (n); i <= iend; ++i)
    for (int j = (1), jend = (m); j <= jend; ++j) {
      char &c1 = str[(i - 1) * 2 + 1][(j - 1) * 2 + 1],
           &c2 = str[(i - 1) * 2 + 1][j * 2], &c3 = str[i * 2][(j - 1) * 2 + 1],
           &c4 = str[i * 2][j * 2];
      int t = ans[i][j];
      if (t == 1) c1 = c2 = c3 = c4 = '#';
      if (t == 2) c1 = c2 = c3 = c4 = '.';
      if (t == 3) c1 = c4 = '\\', c2 = '#', c3 = '.';
      if (t == 4) c2 = c3 = '/', c1 = '.', c4 = '#';
      if (t == 5) c1 = c4 = '\\', c2 = '.', c3 = '#';
      if (t == 6) c2 = c3 = '/', c1 = '#', c4 = '.';
    }
  for (int i = (1), iend = (n * 2); i <= iend; ++i) {
    for (int j = (1), jend = (m * 2); j <= jend; ++j) putchar(str[i][j]);
    puts("");
  }
  return 0;
}
