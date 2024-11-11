#include <bits/stdc++.h>
using namespace std;
int nbase, bufi;
char buf[2000500], *bs[2050];
int bslen[2050];
int m, sl;
int h[2050];
char s[2050];
int lbuf[26][2000500], *lnext[26][2050];
int gnext[26][2050];
bool hasch[26][2050] = {0};
pair<int, int> dp[2050][2050];
inline void pre() {
  for (int i = 0; i < nbase; i++)
    for (int j = 0; j < bslen[i]; j++) hasch[bs[i][j] - 'a'][i] = 1;
  for (int z = 0; z < 26; z++) gnext[z][m] = m;
  for (int i = m - 1; i >= 0; i--) {
    for (int z = 0; z < 26; z++) {
      if (hasch[z][h[i]])
        gnext[z][i] = i;
      else
        gnext[z][i] = gnext[z][i + 1];
    }
  }
  for (int i = 0; i < nbase; i++) {
    int bl = bslen[i];
    char *str = bs[i];
    for (int z = 0; z < 26; z++) lnext[z][i][bl] = bl;
    for (int j = bl - 1; j >= 0; j--) {
      for (int z = 0; z < 26; z++) lnext[z][i][j] = lnext[z][i][j + 1];
      lnext[str[j] - 'a'][i][j] = j;
    }
  }
}
inline void relax(pair<int, int> &x, pair<int, int> val) {
  if (val < x) x = val;
}
inline int solve() {
  int opt = 0;
  pre();
  for (int i = 0; i <= sl; i++)
    for (int j = 0; j <= i; j++) dp[i][j] = make_pair(m + 1, 0);
  dp[0][0] = make_pair(0, 0);
  for (int i = 0; i < sl; i++) {
    int z = s[i] - 'a';
    for (int j = 0; j <= i; j++) {
      int x = dp[i][j].first;
      int y = dp[i][j].second;
      int xtype = h[x];
      if (x > m) continue;
      opt = max(opt, j);
      int nx = m + 1, ny = 0;
      if (x < m) {
        int loc = lnext[z][xtype][y];
        if (loc < bslen[xtype]) {
          nx = xtype;
          ny = loc + 1;
        } else {
          int glo = gnext[z][x + 1];
          if (glo < m) {
            nx = glo;
            ny = lnext[z][h[nx]][0] + 1;
          }
        }
        relax(dp[i + 1][j + 1], make_pair(nx, ny));
      }
      relax(dp[i + 1][j], dp[i][j]);
    }
  }
  for (int j = 0; j <= sl; j++)
    if (dp[sl][j].first <= m) opt = max(opt, j);
  return opt;
}
int main(void) {
  scanf("%d", &nbase);
  bufi = 0;
  for (int i = 0; i < nbase; i++) {
    scanf("%s", buf + bufi);
    bs[i] = buf + bufi;
    for (int j = 0; j < 26; j++) lnext[j][i] = lbuf[j] + bufi;
    bslen[i] = strlen(buf + bufi);
    bufi += bslen[i] + 1;
  }
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    scanf("%d", h + i);
    h[i]--;
  }
  scanf("%s", s);
  sl = strlen(s);
  printf("%d\n", solve());
  return 0;
}
