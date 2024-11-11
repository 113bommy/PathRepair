#include <bits/stdc++.h>
using namespace std;
const int maxn = 205;
int n, m, a, b, c;
char s[maxn][maxn];
inline void nxt(int &x, int &y) {
  ++y;
  if (y == m) ++x, y = 0;
  return;
}
inline void printTop(int p) {
  if (!p)
    printf("..");
  else if (p == 1)
    printf("##");
  else if (p == 2)
    printf("#/");
  else if (p == 3)
    printf("\\#");
  else if (p == 4)
    printf("\\.");
  else
    printf("./");
  return;
}
inline void printBottom(int p) {
  if (p == 0)
    printf("..");
  else if (p == 1)
    printf("##");
  else if (p == 2)
    printf("/.");
  else if (p == 3)
    printf(".\\");
  else if (p == 4)
    printf("#\\");
  else
    printf("/#");
  return;
}
int main() {
  scanf("%d%d%d%d%d", &n, &m, &a, &b, &c);
  memset(s, -1, sizeof(s));
  int x = 0, y = 0;
  for (; a; --a) {
    s[x][y] = 1;
    nxt(x, y);
  }
  for (int i = (y); i < (m); ++i) {
    if ((i - y) & 1)
      s[x][i] = 3;
    else
      s[x][i] = 2;
  }
  for (int i = (0); i < (y); ++i) {
    if ((y - i) & 1)
      s[x + 1][i] = 2;
    else
      s[x + 1][i] = 3;
  }
  for (int i = (0); i < (m); ++i) nxt(x, y);
  for (; b; --b) {
    s[x][y] = 0;
    nxt(x, y);
  }
  for (int i = (x); i < (n); ++i)
    for (int j = (y); j < (m); ++j) {
      if ((m - j) & 1) {
        if ((i - x) & 1)
          s[i][j] = 2;
        else
          s[i][j] = 4;
      } else {
        if ((i - x) & 1)
          s[i][j] = 3;
        else
          s[i][j] = 5;
      }
    }
  for (int i = (x + 1); i < (n); ++i)
    for (int j = (0); j < (y); ++j) {
      if ((y - j) & 1) {
        if ((i - x - 1) & 1)
          s[i][j] = 2;
        else
          s[i][j] = 4;
      } else {
        if ((i - x - 1) & 1)
          s[i][j] = 3;
        else
          s[i][j] = 5;
      }
    }
  for (int i = (0); i < (n); ++i) {
    for (int j = (0); j < (m); ++j) printTop(s[i][j]);
    puts("");
    for (int j = (0); j < (m); ++j) printBottom(s[i][j]);
    puts("");
  }
  return 0;
}
