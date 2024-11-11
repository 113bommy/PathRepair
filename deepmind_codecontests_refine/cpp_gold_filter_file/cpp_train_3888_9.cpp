#include <bits/stdc++.h>
using namespace std;
const int MAXN = 155;
const int MOD = 51123987;
char str[MAXN];
int dp[MAXN][MAXN / 3 + 2][MAXN / 3 + 2][MAXN / 3 + 2];
int sumA[3][MAXN / 3 + 2][MAXN / 3 + 2][MAXN / 3 + 2];
int sumB[3][MAXN / 3 + 2][MAXN / 3 + 2][MAXN / 3 + 2];
int sumC[3][MAXN / 3 + 2][MAXN / 3 + 2][MAXN / 3 + 2];
int main() {
  int N, ans = 0;
  scanf("%d", &N);
  scanf("%s", str + 1);
  int up = min(N, N / 3 + 2);
  int lstpos[3] = {0, 0, 0};
  for (int i = 1; i <= N; i++) {
    for (int a = 0; a <= up; a++)
      for (int b = 0; b <= up; b++)
        for (int c = 0; c <= up; c++) {
          if (str[i] == 'a' && !a) continue;
          if (str[i] == 'b' && !b) continue;
          if (str[i] == 'c' && !c) continue;
          if (str[i] == 'a') {
            (dp[i][a][b][c] += sumA[1][a - 1][b][c]) %= MOD;
            (dp[i][a][b][c] += sumA[2][a - 1][b][c]) %= MOD;
          }
          if (str[i] == 'b') {
            (dp[i][a][b][c] += sumB[0][a][b - 1][c]) %= MOD;
            (dp[i][a][b][c] += sumB[2][a][b - 1][c]) %= MOD;
          }
          if (str[i] == 'c') {
            (dp[i][a][b][c] += sumC[0][a][b][c - 1]) %= MOD;
            (dp[i][a][b][c] += sumC[1][a][b][c - 1]) %= MOD;
          }
        }
    lstpos[str[i] - 'a'] = i;
    if (str[i] == 'a')
      for (int a = 1; a <= up; a++) dp[i][a][0][0] = 1;
    if (str[i] == 'b')
      for (int b = 1; b <= up; b++) dp[i][0][b][0] = 1;
    if (str[i] == 'c')
      for (int c = 1; c <= up; c++) dp[i][0][0][c] = 1;
    for (int a = 0; a <= up; a++)
      for (int b = 0; b <= up; b++) {
        sumC[str[i] - 'a'][a][b][0] = dp[i][a][b][0];
        for (int c = 1; c <= up; c++)
          sumC[str[i] - 'a'][a][b][c] =
              (sumC[str[i] - 'a'][a][b][c - 1] + dp[i][a][b][c]) % MOD;
      }
    for (int a = 0; a <= up; a++)
      for (int c = 0; c <= up; c++) {
        sumB[str[i] - 'a'][a][0][c] = dp[i][a][0][c];
        for (int b = 1; b <= up; b++)
          sumB[str[i] - 'a'][a][b][c] =
              (sumB[str[i] - 'a'][a][b - 1][c] + dp[i][a][b][c]) % MOD;
      }
    for (int b = 0; b <= up; b++)
      for (int c = 0; c <= up; c++) {
        sumA[str[i] - 'a'][0][b][c] = dp[i][0][b][c];
        for (int a = 1; a <= up; a++)
          sumA[str[i] - 'a'][a][b][c] =
              (sumA[str[i] - 'a'][a - 1][b][c] + dp[i][a][b][c]) % MOD;
      }
  }
  for (int a = 0; a <= up; a++)
    for (int b = 0; b <= up; b++)
      for (int c = 0; c <= up; c++)
        for (int t = 0; t < 3; t++)
          if (a + b + c == N && abs(a - b) <= 1 && abs(a - c) <= 1 &&
              abs(b - c) <= 1)
            (ans += dp[lstpos[t]][a][b][c]) %= MOD;
  if (N == 1)
    puts("1");
  else
    cout << ans << '\n';
}
