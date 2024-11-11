#include <bits/stdc++.h>
using namespace std;
inline int R() {
  int rt;
  scanf("%d", &rt);
  return rt;
}
const int MAXN = 1e5 + 7, MAXL = 257;
int dp[MAXL][MAXL][MAXL], len[3];
vector<char> w[5];
char s[MAXN];
int nxt[MAXN][27], lst[27];
int main() {
  int n = R(), q = R();
  scanf("%s", s + 1);
  w[1].push_back(0), w[2].push_back(0), w[3].push_back(0);
  for (int i = 0; i < 26; ++i) lst[i] = n + 1, nxt[n + 1][i] = n + 1;
  for (int i = n; i >= 0; --i) {
    for (int j = 0; j < 26; ++j) nxt[i][j] = lst[j];
    if (i) lst[s[i] - 'a'] = i;
  }
  for (int i = 0; i <= 250; ++i)
    for (int j = 0; j <= 250; ++j)
      for (int k = 0; k <= 250; ++k) dp[i][j][k] = n + 1;
  dp[0][0][0] = 0;
  for (; q; --q) {
    char ch = getchar();
    while (ch != '+' && ch != '-') ch = getchar();
    if (ch == '+') {
      int x = R();
      while (ch < 'a' || ch > 'z') ch = getchar();
      ++len[x], w[x].push_back(ch);
      if (x == 1)
        for (int i = 0; i <= len[2]; ++i)
          for (int j = 0; j <= len[3]; ++j) {
            if (len[x])
              dp[len[x]][i][j] =
                  min(dp[len[x]][i][j],
                      nxt[dp[len[x] - 1][i][j]][w[x][len[x]] - 'a']);
            if (i)
              dp[len[x]][i][j] = min(dp[len[x]][i][j],
                                     nxt[dp[len[x]][i - 1][j]][w[2][i] - 'a']);
            if (j)
              dp[len[x]][i][j] = min(dp[len[x]][i][j],
                                     nxt[dp[len[x]][i][j - 1]][w[3][j] - 'a']);
          }
      if (x == 2)
        for (int i = 0; i <= len[1]; ++i)
          for (int j = 0; j <= len[3]; ++j) {
            if (i)
              dp[i][len[x]][j] = min(dp[i][len[x]][j],
                                     nxt[dp[i - 1][len[x]][j]][w[1][i] - 'a']);
            if (len[x])
              dp[i][len[x]][j] =
                  min(dp[i][len[x]][j],
                      nxt[dp[i][len[x] - 1][j]][w[x][len[x]] - 'a']);
            if (j)
              dp[i][len[x]][j] = min(dp[i][len[x]][j],
                                     nxt[dp[i][len[x]][j - 1]][w[3][j] - 'a']);
          }
      if (x == 3)
        for (int i = 0; i <= len[1]; ++i)
          for (int j = 0; j <= len[2]; ++j) {
            if (i)
              dp[i][j][len[x]] = min(dp[i][j][len[x]],
                                     nxt[dp[i - 1][j][len[x]]][w[1][i] - 'a']);
            if (j)
              dp[i][j][len[x]] = min(dp[i][j][len[x]],
                                     nxt[dp[i][j - 1][len[x]]][w[2][j] - 'a']);
            if (len[x])
              dp[i][j][len[x]] =
                  min(dp[i][j][len[x]],
                      nxt[dp[i][j][len[x] - 1]][w[x][len[x]] - 'a']);
          }
    } else {
      int x = R();
      if (x == 1)
        for (int i = 0; i <= len[2]; ++i)
          for (int j = 0; j <= len[3]; ++j) dp[len[x]][i][j] = n + 1;
      if (x == 2)
        for (int i = 0; i <= len[1]; ++i)
          for (int j = 0; j <= len[3]; ++j) dp[i][len[x]][j] = n + 1;
      if (x == 3)
        for (int i = 0; i <= len[1]; ++i)
          for (int j = 0; j <= len[2]; ++j) dp[i][j][len[x]] = n + 1;
      --len[x], w[x].pop_back();
    }
    puts((dp[len[1]][len[2]][len[3]] == (n + 1)) ? "NO" : "YES");
  }
  return 0;
}
