#include <bits/stdc++.h>
using namespace std;
const int maxn = 200;
char s1[maxn], s2[maxn];
bool ok1[maxn][maxn][maxn], ok2[maxn][maxn][maxn];
int n, l1, l2, dp[maxn][maxn];
vector<pair<int, int> > v[maxn];
int main() {
  scanf("%s%s", s1 + 1, s2 + 1);
  l1 = strlen(s1 + 1);
  l2 = strlen(s2 + 1);
  scanf("%d", &n);
  for (register int i = 1; i <= n; i++) {
    char c1, c2;
    while (!isalpha(c1 = getchar()))
      ;
    while (!isalpha(c2 = getchar()))
      ;
    v[c1].emplace_back(c2, getchar());
  }
  for (register int i = 1; i <= l1; i++) ok1[i][i][s1[i]] = 1;
  for (register int l = 2; l <= l1; l++)
    for (register int i = 1; i <= l1; i++) {
      int j = i + l - 1;
      if (j > l1) break;
      for (register int ch = 'a'; ch <= 'z'; ch++)
        for (register int k = i; k < j; k++)
          for (auto ru : v[ch])
            ok1[i][j][ch] |= ok1[i][k][ru.first] && ok1[k + 1][j][ru.second];
    }
  for (register int i = 1; i <= l2; i++) ok2[i][i][s2[i]] = 1;
  for (register int l = 2; l <= l2; l++)
    for (register int i = 1; i <= l2; i++) {
      int j = i + l - 1;
      if (j > l2) break;
      for (register int ch = 'a'; ch <= 'z'; ch++)
        for (register int k = i; k < j; k++)
          for (auto ru : v[ch])
            ok2[i][j][ch] |= ok2[i][k][ru.first] && ok2[k + 1][j][ru.second];
    }
  memset(dp, 0x3f, sizeof(dp));
  dp[0][0] = 0;
  for (register int i = 1; i <= l1; i++)
    for (register int j = 1; j <= l2; j++)
      for (register int k = 1; k <= i; k++)
        for (register int l = 1; l <= j; l++)
          for (register int ch = 'a'; ch <= 'z'; ch++)
            if (ok1[k][i][ch] && ok2[l][j][ch])
              dp[i][j] = min(dp[i][j], dp[l - 1][k - 1] + 1);
  if (dp[l1][l2] <= 1e9)
    printf("%d", dp[l1][l2]);
  else
    puts("-1");
  return 0;
}
