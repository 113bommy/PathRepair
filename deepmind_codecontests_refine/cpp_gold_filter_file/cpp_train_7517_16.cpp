#include <bits/stdc++.h>
int x, y, p = 0, st = 0;
char s[10][10];
bool a[10][10], b[10][10];
void people() {
  bool ta[10][10];
  memcpy(ta, a, sizeof a);
  for (int i = 1; i <= 8; i++)
    for (int j = 1; j <= 8; j++)
      if (a[i][j]) {
        for (int k = -1; k <= 1; k++)
          if (i + k && i + k <= 8)
            for (int l = -1; l <= 1; l++)
              if (j + l && j + l <= 8) {
                if (!b[i + k][j + l] && !ta[i + k][j + l]) p++;
                if (!b[i + k][j + l]) ta[i + k][j + l] = true;
              }
      }
  memcpy(a, ta, sizeof ta);
}
void stone() {
  bool tb[10][10];
  memset(tb, 0, sizeof tb);
  for (int i = 1; i < 8; i++)
    for (int j = 1; j <= 8; j++)
      if (b[i][j]) {
        tb[i + 1][j] = true;
        if (a[i + 1][j]) p--;
        a[i + 1][j] = false;
      }
  memcpy(b, tb, sizeof tb);
}
int main() {
  memset(a, 0, sizeof a);
  memset(b, 0, sizeof b);
  for (int i = 1; i <= 8; i++) scanf("%s", s[i] + 1);
  for (int i = 1; i <= 8; i++)
    for (int j = 1; j <= 8; j++) {
      if (s[i][j] == 'A') x = i, y = j;
      if (s[i][j] == 'M') a[i][j] = true;
      if (s[i][j] == 'S') b[i][j] = true;
    }
  p = 1;
  while (!a[x][y] && p && st < 16) {
    if (~st & 1)
      people();
    else
      stone();
    st++;
  }
  if (p)
    puts("WIN");
  else
    puts("LOSE");
}
