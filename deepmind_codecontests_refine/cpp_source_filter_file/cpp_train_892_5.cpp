#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const int maxn = 1e5;
vector<int> dp[maxn + 5];
int next1[maxn + 5][26];
char s1[maxn + 5], s2[maxn + 5];
int nxt[maxn + 5];
int n, m;
set<int> s[maxn + 5];
void calc_next() {
  nxt[1] = 0;
  int j = 0;
  for (int i = 2; i <= m; i++) {
    while (j > 0 && s2[i] != s2[j + 1]) j = nxt[j];
    if (s2[i] == s2[j + 1]) j++;
    nxt[i] = j;
  }
}
int main() {
  scanf("%s", s1 + 1);
  scanf("%s", s2 + 1);
  n = strlen(s1 + 1);
  m = strlen(s2 + 1);
  if (n > m) {
    printf("0\n");
    return 0;
  }
  calc_next();
  for (int i = 0; i <= m; i++) {
    int j0 = i;
    do {
      if (j0 != m)
        next1[i][s2[j0 + 1] - 'a'] = max(next1[i][s2[j0 + 1] - 'a'], j0 + 1);
      j0 = nxt[j0];
    } while (j0 > 0);
    next1[i][s2[1] - 'a'] = max(1, next1[i][s2[1] - 'a']);
  }
  for (int i = 0; i <= m; i++)
    for (int j = 0; j < 26; j++) s[i].insert(next1[i][j]);
  for (int i = 0; i <= n; i++) dp[i].resize(m + 1);
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= m; j++) dp[i][j] = -INF;
  dp[0][0] = 0;
  int p;
  for (int i = 0; i < n; i++)
    for (int j = 0; j <= m; j++)
      if (dp[i][j] >= 0) {
        if (s1[i + 1] != '?') {
          p = next1[j][s1[i + 1] - 'a'];
          dp[i + 1][p] = max(dp[i + 1][p], dp[i][j] + (p == m));
        } else {
          for (auto k : s[j]) {
            dp[i + 1][k] = max(dp[i + 1][k], dp[i][j] + (k == m));
          }
        }
      }
  int ans = 0;
  for (int j = 0; j <= m; j++) ans = max(ans, dp[n][j]);
  printf("%d\n", ans);
  return 0;
}
