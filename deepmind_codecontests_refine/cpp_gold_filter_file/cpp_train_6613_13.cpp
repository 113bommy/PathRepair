#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
char s[10];
int df[1 << 19];
char a[1 << 19][6][6];
void parse(int m) {
  int mm = m;
  m <<= 1;
  for (int i = (0); i < (3); i++) a[mm][4][4 - i] = (m >>= 1) & 1;
  for (int i = (0); i < (4); i++) a[mm][3][4 - i] = (m >>= 1) & 1;
  for (int i = (0); i < (5); i++) a[mm][2][4 - i] = (m >>= 1) & 1;
  for (int i = (0); i < (4); i++) a[mm][1][3 - i] = (m >>= 1) & 1;
  for (int i = (0); i < (3); i++) a[mm][0][2 - i] = (m >>= 1) & 1;
}
int pos(int r, int c) {
  if (r == 4) return 4 - c;
  if (r == 3) return 4 - c + 3;
  if (r == 2) return 4 - c + 7;
  if (r == 1) return 3 - c + 12;
  if (r == 0) return 2 - c + 16;
  while (1)
    ;
}
int f(int mask);
void go(int i, int j, int di, int dj, int m, int &res) {
  int ni = i;
  int nj = j;
  int nm = m;
  while (a[m][ni][nj]) {
    nm ^= 1 << pos(ni, nj);
    res = min(res, f(nm));
    ni += di;
    nj += dj;
  }
}
int f(int mask) {
  if (mask == 0) return 0;
  if (df[mask] != -1) return df[mask];
  int res = 1;
  parse(mask);
  for (int i = (0); i < (5); i++) {
    for (int j = (0); j < (5); j++)
      if (a[mask][i][j]) {
        go(i, j, 1, 0, mask, res);
        go(i, j, 0, 1, mask, res);
        go(i, j, 1, 1, mask, res);
        if (res == 0) goto m1;
      }
  }
m1:;
  res = 1 - res;
  return df[mask] = res;
}
int main() {
  memset(df, -1, sizeof(df));
  int m = 0;
  for (int i = (0); i < (19); i++) {
    scanf("%s", s);
    if (s[0] == 'O')
      m = m * 2 + 1;
    else
      m = m * 2;
  }
  if (f(m))
    printf("Karlsson\n");
  else
    printf("Lillebror\n");
  return 0;
}
