#include <bits/stdc++.h>
using namespace std;
char a[4][100][100];
int c[6];
int check(int le, int s, char st) {
  int ct = 0;
  for (int i = 0; i < s; i++) {
    for (int j = 0; j < s; j++) {
      if ((i - (s - 1) / 2 + j - (s - 1) / 2) % 2 == 0 && a[le][i][j] != st) {
        ct++;
      } else if ((i - (s - 1) / 2 + j - (s - 1) / 2) % 2 != 0 &&
                 a[le][i][j] == st) {
        ct++;
      }
    }
  }
  return ct;
}
int main() {
  int si;
  scanf("%d", &si);
  getchar();
  for (int k = 0; k < 4; k++) {
    for (int i = 0; i < si; i++) {
      char s[101];
      scanf("%s", &s);
      for (int r = 0; r < si; r++) a[k][i][r] = s[r];
      getchar();
    }
    if (k != 3) getchar();
  }
  c[0] = check(0, si, '1') + check(1, si, '1') + check(2, si, '0') +
         check(3, si, '0');
  c[1] = check(0, si, '1') + check(1, si, '0') + check(2, si, '1') +
         check(3, si, '0');
  c[2] = check(0, si, '1') + check(1, si, '0') + check(2, si, '0') +
         check(3, si, '1');
  c[3] = check(0, si, '0') + check(1, si, '1') + check(2, si, '1') +
         check(3, si, '0');
  c[4] = check(0, si, '0') + check(1, si, '1') + check(2, si, '0') +
         check(3, si, '1');
  c[5] = check(0, si, '0') + check(1, si, '0') + check(2, si, '1') +
         check(3, si, '1');
  int ans = 40000;
  for (int i = 0; i < 6; i++) {
    ans = min(c[i], ans);
  }
  printf("%d\n", ans);
  return 0;
}
