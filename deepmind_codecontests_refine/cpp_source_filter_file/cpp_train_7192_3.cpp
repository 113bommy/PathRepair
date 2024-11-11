#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int MAXS = 205;
const int MAXN = 205;
char s[MAXS];
int fail[MAXS], trans[MAXS][2], f[MAXN][MAXS][105][2];
int n;
void init() {
  fail[1] = 0;
  for (int i = 2; i <= n; i++) {
    fail[i] = 0;
    for (int j = i - 1; j > 0; j--) {
      bool ch = 1;
      for (int k = 0; k < j; k++) ch &= (s[i - k] == s[j - k]);
      if (ch) {
        fail[i] = j;
        break;
      }
    }
  }
  if (s[1] == '(')
    trans[0][0] = 1, trans[0][1] = 0;
  else
    trans[0][0] = 0, trans[0][1] = 1;
  for (int i = 1; i <= n; i++) {
    if (s[i + 1] == '(')
      trans[i][0] = i + 1;
    else
      trans[i][0] = trans[fail[i]][0];
    if (s[i + 1] == ')')
      trans[i][1] = i + 1;
    else
      trans[i][1] = trans[fail[i]][1];
  }
}
int main() {
  scanf("%d", &n);
  scanf("%s", s + 1);
  int m = strlen(s + 1);
  init();
  memset(f, 0, sizeof(f));
  f[0][0][0][0] = 1;
  for (int i = 0; i < 2 * n; i++) {
    for (int j = 0; j <= m; j++) {
      for (int p = 0; p <= n; p++) {
        for (int k = 0; k < 2; k++) {
          if (f[i][j][p][k]) {
            int t = trans[j][0];
            f[i + 1][t][p + 1][k | (t == m)] += f[i][j][p][k];
            f[i + 1][t][p + 1][k | (t == m)] %= MOD;
            t = trans[j][1];
            if (p > 0) {
              f[i + 1][t][p - 1][k | (t == m)] += f[i][j][p][k];
              f[i + 1][t][p - 1][k | (t == m)] %= MOD;
            }
          }
        }
      }
    }
  }
  int res = 0;
  for (int j = 0; j <= m; j++) res += f[2 * n][j][0][1], res %= MOD;
  printf("%d\n", res);
  return 0;
}
