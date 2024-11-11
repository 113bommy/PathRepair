#include <bits/stdc++.h>
using namespace std;
const int MAX_L = 2000;
int T[MAX_L][MAX_L];
int last[MAX_L], z[MAX_L];
;
char s[MAX_L], p[MAX_L];
int main() {
  int Ls, Lp, is, ip, k, i, j, r;
  scanf("%s%s", &s, &p);
  Ls = strlen(s);
  Lp = strlen(p);
  for (i = 0; s[i]; i++) {
    is = i;
    ip = 0;
    while (s[is] && p[ip]) {
      while (s[is] && p[ip] && s[is] != p[ip]) is++;
      if (s[is] == p[ip]) {
        is++;
        ip++;
      }
    }
    if (!p[ip]) {
      last[i] = is - 1;
      z[i] = is - i - Lp;
    } else
      last[i] = -1;
  }
  if (last[0] != -1) T[last[0]][z[0]] = 1;
  for (i = 0; i < Ls - 1; i++)
    for (k = 0; k <= i + 1; k++) {
      j = i + 1;
      T[j][k] = max(T[j][k], T[i][k]);
      T[j][k + 1] = max(T[j][k + 1], T[i][k]);
      if (last[j] != -1) {
        r = last[j];
        T[r][k + z[j]] = max(T[r][k + z[j]], T[i][k] + 1);
      }
    }
  i = Ls - 1;
  for (j = 0; j <= Ls; j++) printf("%d ", T[i][j]);
  return 0;
}
