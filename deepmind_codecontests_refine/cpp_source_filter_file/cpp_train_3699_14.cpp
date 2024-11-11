#include <bits/stdc++.h>
using namespace std;
int n;
int d[201][201][201] = {};
char s[205];
int r = 0, g = 0, b = 0;
int main() {
  scanf("%d%s", &n, s);
  for (int i = 0; i < (int)(n); ++i)
    if (s[i] == 'R')
      ++r;
    else if (s[i] == 'G')
      ++g;
    else
      ++b;
  d[1][0][0] = 1;
  d[0][1][0] = 2;
  d[0][0][1] = 4;
  for (int cnt = 0; cnt < (int)(201); ++cnt)
    for (int i = 0; i < (int)(cnt + 1); ++i)
      for (int j = 0; j < (int)(cnt + 1 - i); ++j) {
        int k = cnt - i - j;
        if (i && j) d[i][j][k] |= d[i - 1][j - 1][k + 1];
        if (i && k) d[i][j][k] |= d[i - 1][j + 1][k - 1];
        if (j && k) d[i][j][k] |= d[i + 1][j - 1][k - 1];
        if (i > 1) d[i][j][k] |= d[i - 1][j][k];
        if (j > 1) d[i][j][k] |= d[i][j - 1][k];
        if (k > 1) d[i][j][k] |= d[i][j][k - 1];
      }
  int res = d[r][g][b];
  if (res & 1) printf("R");
  if (res & 2) printf("G");
  if (res & 4) printf("B");
  printf("\n");
  return 0;
}
