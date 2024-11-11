#include <bits/stdc++.h>
using namespace std;
short int dp[120][65][20][20];
short int pre[120][65][20][20];
int ans[10000000], cnt = 0;
void output(int a, int b, int c, int d) {
  if (!pre[a][b][c][d]) return;
  ans[++cnt] = pre[a][b][c][d];
  int x = pre[a][b][c][d];
  output(a + x / 2 + x / 4 + x / 8, b + x / 3 + x / 9, c + x / 5, d + x / 7);
}
int main() {
  int a = 0, b = 0, c = 0, d = 0;
  int n;
  char s[35];
  scanf("%d", &n);
  scanf("%s", s);
  for (int i = 0; s[i]; i++) {
    int x = s[i] - '0';
    a += x / 2 + x / 4 + x / 8;
    b += x / 3 + x / 9;
    c += x / 5;
    d += x / 7;
  }
  memset(dp, -1, sizeof(dp));
  dp[a][b][c][d] = 0;
  for (int i = a; i >= 0; i--)
    for (int j = b; j >= 0; j--)
      for (int k = c; k >= 0; k--)
        for (int r = d; r >= 0; r--)
          if (dp[i][j][k][r] == -1)
            continue;
          else {
            for (int x = 2; x < 10; x++) {
              int aa = i - x / 2 - x / 4 - x / 8;
              int bb = j - x / 3 - x / 9;
              int cc = k - x / 5;
              int dd = r - x / 7;
              if (aa >= 0 && bb >= 0 && cc >= 0 && dd >= 0 &&
                  dp[aa][bb][cc][dd] < dp[i][j][k][r] + 1) {
                dp[aa][bb][cc][dd] = dp[i][j][k][r] + 1;
                pre[aa][bb][cc][dd] = x;
              }
            }
          }
  assert(dp[0][0][0][0] != -1);
  output(0, 0, 0, 0);
  sort(ans + 1, ans + cnt + 1);
  for (int i = cnt; i >= 1; i--) printf("%d", ans[i]);
  printf("\n");
  return 0;
}
