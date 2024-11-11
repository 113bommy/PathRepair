#include <bits/stdc++.h>
using namespace std;
char s[2][55];
bool f_sub[2][55][55][26];
int transx[26][55], transy[26][55], trans1[26], f[55][55], len[2];
int main() {
  scanf("%s", s[0] + 1);
  scanf("%s", s[1] + 1);
  len[0] = strlen(s[0] + 1);
  len[1] = strlen(s[1] + 1);
  for (int i = 1; i <= len[0]; ++i) s[0][i] -= 'a';
  for (int i = 1; i <= len[1]; ++i) s[1][i] -= 'a';
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    char ch1, ch2, ch3;
    scanf(" %c->%c%c", &ch1, &ch2, &ch3);
    ch1 -= 'a';
    ch2 -= 'a';
    ch3 -= 'a';
    ++trans1[ch1];
    transx[ch1][trans1[ch1]] = ch2;
    transy[ch1][trans1[ch1]] = ch3;
  }
  for (int i1 = 0; i1 <= 1; ++i1) {
    for (int i = 1; i <= len[i1]; ++i) f_sub[i1][i][i][s[i1][i]] = 1;
    for (int delta = 1; delta <= len[i1]; ++delta)
      for (char ch = 0; ch < 26; ++ch)
        for (int i = 1; i + delta <= len[i1]; ++i) {
          int j = i + delta;
          bool &c = f_sub[i1][i][j][ch];
          for (int I = 1; I <= trans1[ch]; ++I) {
            char ch1 = transx[ch][I], ch2 = transy[ch][I];
            for (int k = i; k < j; ++k)
              if (f_sub[i1][i][k][ch1] && f_sub[i1][k + 1][j][ch2]) {
                c = 1;
                goto end;
              }
          }
        end:;
        }
  }
  memset(f, 23, sizeof(f));
  f[0][0] = 0;
  for (int i = 1; i <= len[0]; ++i)
    for (int j = 1; j <= len[1]; ++j)
      for (int i1 = 0; i1 < i; ++i1)
        for (int j1 = 0; j1 < j; ++j1) {
          bool can = 0;
          for (int k = 0; k < 26; ++k)
            can |= f_sub[0][i1 + 1][i][k] && f_sub[1][j1 + 1][j][k];
          if (!can) continue;
          f[i][j] = min(f[i][j], f[i1][j1] + 1);
        }
  if (f[len[0]][len[1]] < (1 << 20))
    printf("%d\n", f[len[0]][len[1]]);
  else
    printf("-1\n");
  return 0;
}
