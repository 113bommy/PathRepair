#include <bits/stdc++.h>
using namespace std;
int testnum;
int dp[100][26][101];
char s[111];
int arr[111];
int K;
int m;
int bonus[26][26];
int n;
void preprocess() {}
void solve() {
  for (int k = 0; k < 100; k++)
    for (int i = 0; i < 26; i++)
      for (int j = 0; j < 101; j++) dp[i][j][k] = -10000000;
  for (int i = 0; i < 26; i++) {
    if (i == arr[0])
      dp[0][i][0] = 0;
    else
      dp[0][i][1] = 0;
  }
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < 26; j++) {
      if (j == arr[i])
        for (int k = 0; k < 101; k++) {
          for (int l = 0; l < 26; l++)
            dp[i][j][k] = max(dp[i][j][k], dp[i - 1][l][k] + bonus[l][j]);
        }
      else
        for (int k = 0; k < 100; k++) {
          for (int l = 0; l < 26; l++)
            dp[i][j][k + 1] =
                max(dp[i][j][k + 1], dp[i - 1][l][k] + bonus[l][j]);
        }
    }
  }
  int ans = -1000000;
  for (int j = 0; j < 26; j++)
    for (int k = 0; k <= K; k++) ans = max(ans, dp[n - 1][j][k]);
  printf("%d\n", ans);
}
bool input() {
  scanf("%s", s);
  n = strlen(s);
  for (int i = 0; i < n; i++) arr[i] = s[i] - 'a';
  scanf("%d", &K);
  scanf("%d", &m);
  memset(bonus, 0, sizeof bonus);
  char a, b;
  int x;
  for (int i = 0; i < m; i++) {
    cin >> a >> b >> x;
    bonus[a - 'a'][b - 'a'] = x;
  }
  return true;
}
int main() {
  preprocess();
  int T = 1;
  for (testnum = 1; testnum <= T; testnum++) {
    if (!input()) break;
    solve();
  }
}
