#include <bits/stdc++.h>
using namespace std;
const int MAX = 1005;
char mm[MAX][MAX];
int ff[MAX][MAX];
int n, m;
bool qw(int i, int j) {
  return 0 <= i && i < n && 0 <= j && j < m && ff[i][j] == 0 && mm[i][j] == 'w';
}
bool qb(int i, int j) {
  return 0 <= i && i < n && 0 <= j && j < m && ff[i][j] == 0 && mm[i][j] == 'b';
}
int an[6];
int check(int i, int j, int dir) {
  memset(an, 0, sizeof(an));
  if (dir == 0) {
    if (j - 1 >= 0) an[ff[i][j - 1]] = 1;
    if (j + 3 < m) an[ff[i][j + 3]] = 1;
    int i1 = i - 1, i2 = i + 1;
    for (int k = 0; k < 3; k++) {
      if (i1 >= 0) an[ff[i1][j + k]] = 1;
      if (i2 < n) an[ff[i2][j + k]] = 1;
    }
    for (int k = 2; k <= 5; k++) {
      if (an[k] == 0) return k;
    }
  } else {
    if (i - 1 >= 0) an[ff[i - 1][j]] = 1;
    if (i + 3 < n) an[ff[i + 3][j]] = 1;
    int j1 = j - 1, j2 = j + 1;
    for (int k = 0; k < 3; k++) {
      if (j1 >= 0) an[ff[i + k][j1]] = 1;
      if (j2 < m) an[ff[i + k][j2]] = 1;
    }
    for (int k = 2; k <= 5; k++) {
      if (an[k] == 0) return k;
    }
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%s", mm + i);
  }
  bool ok = true;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (mm[i][j] == '.') {
        ff[i][j] = 1;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (ff[i][j] == 0) {
        if (mm[i][j] == 'b') {
          ok = false;
          break;
        } else if (!qb(i, j + 1)) {
          if (!qb(i + 1, j) || !qw(i + 2, j)) {
            ok = false;
            break;
          } else {
            int re = check(i, j, 1);
            for (int k = 0; k < 3; k++) {
              ff[i + k][j] = re;
            }
          }
        } else if (!qw(i, j + 2)) {
          ok = false;
          break;
        } else {
          int re = check(i, j, 0);
          for (int k = 0; k < 3; k++) {
            ff[i][j + k] = re;
          }
        }
      }
    }
    if (!ok) break;
  }
  if (!ok)
    printf("NO\n");
  else {
    printf("YES\n");
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (ff[i][j] == 1)
          putchar('.');
        else
          putchar('a' + ff[i][j] - 2);
      }
      putchar('\n');
    }
  }
  return 0;
}
