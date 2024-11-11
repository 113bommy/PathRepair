#include <bits/stdc++.h>
using namespace std;
int n, ans, nxt[55][4], dp[155][55][55][55];
char s[55];
int main() {
  scanf("%d", &n);
  scanf("%s", s + 1);
  nxt[n + 1][0] = nxt[n + 1][1] = nxt[n + 1][2] = n + 1;
  for (int i = n; i >= 1; i--) {
    nxt[i][0] = nxt[i + 1][0];
    nxt[i][1] = nxt[i + 1][1];
    nxt[i][2] = nxt[i + 1][2];
    if (s[i] == 'a') nxt[i][0] = i;
    if (s[i] == 'b') nxt[i][1] = i;
    if (s[i] == 'c') nxt[i][2] = i;
  }
  ans = 0;
  dp[1][0][0][0] = 1;
  int limit = n / 3 + 2;
  for (int i = 1; i <= n; i++)
    for (int a = 0; a <= limit; a++)
      for (int b = 0; b <= limit; b++)
        for (int c = 0; c <= limit; c++) {
          if (abs(a - b) <= 1 && abs(a - c) <= 1 && abs(b - c) <= 1 &&
              (a + b + c == n))
            (ans += dp[i][a][b][c]) %= 51123987;
          if (nxt[i][0] <= n)
            (dp[nxt[i][0]][a + 1][b][c] += dp[i][a][b][c]) %= 51123987;
          if (nxt[i][1] <= n)
            (dp[nxt[i][1]][a][b + 1][c] += dp[i][a][b][c]) %= 51123987;
          if (nxt[i][2] <= n)
            (dp[nxt[i][2]][a][b][c + 1] += dp[i][a][b][c]) %= 51123987;
        }
  printf("%d", ans);
  return 0;
}
