#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 55;
int n, m, q, dp[N][N], a[N], b[N], c[N];
int ok1[N][N][N], ok2[N][N][N];
string s1, s2, s3;
inline int read() {
  int f = 1, x = 0;
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return f * x;
}
int main() {
  cin >> s1 >> s2;
  n = s1.length(), m = s2.length();
  q = read();
  for (int i = 1; i <= q; i++) {
    cin >> s3;
    a[i] = s3[0] - 'a';
    b[i] = s3[3] - 'a';
    c[i] = s3[4] - 'a';
  }
  for (int i = 0; i < n; i++) ok1[i + 1][i + 1][s1[i] - 'a'] = 1;
  for (int i = 0; i < m; i++) ok2[i + 1][i + 1][s2[i] - 'a'] = 1;
  for (int i = n; i >= 1; i--)
    for (int j = i + 1; j <= n; j++)
      for (int k = i; k < j; k++)
        for (int w = 1; w <= n; w++)
          if (ok1[i][k][b[w]] == 1 && ok1[k + 1][j][c[w]] == 1)
            ok1[i][j][a[w]] = 1;
  for (int i = m; i >= 1; i--)
    for (int j = i + 1; j <= m; j++)
      for (int k = i; k < j; k++)
        for (int w = 0; w < 26; w++)
          if (ok2[i][k][b[w]] == 1 && ok2[k + 1][j][c[w]] == 1)
            ok2[i][j][a[w]] = 1;
  memset(dp, INF, sizeof(dp));
  dp[0][0] = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      for (int k = 1; k <= i; k++)
        for (int l = 1; l <= j; l++)
          for (int w = 0; w < 26; w++)
            if (ok1[k][i][w] && ok2[l][j][w])
              dp[i][j] = min(dp[i][j], dp[k - 1][l - 1] + 1);
  if (dp[n][m] == INF)
    printf("-1");
  else
    printf("%d", dp[n][m]);
  return 0;
}
