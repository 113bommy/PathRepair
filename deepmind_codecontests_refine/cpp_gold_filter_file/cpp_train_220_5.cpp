#include <bits/stdc++.h>
using namespace std;
int n, q;
char str[100010];
int des[4][256];
int len[4];
int nxt[100010][26];
int dp[255][255][255];
void update(int &a, int b) {
  if (a == -1)
    a = b;
  else if (b > -1)
    a = min(a, b);
}
int main() {
  memset(dp, -1, sizeof(dp));
  cin >> n >> q;
  scanf("%s", str + 1);
  for (int i = n; i >= 0; i--) {
    for (int j = 0; j < 26; j++) {
      if (i == n) {
        nxt[i][j] = -1;
      } else {
        if (str[i + 1] == j + 'a') {
          nxt[i][j] = i + 1;
        } else {
          nxt[i][j] = nxt[i + 1][j];
        }
      }
    }
  }
  dp[0][0][0] = 0;
  while (q--) {
    char op[2];
    scanf("%s", op);
    int who;
    char ch[2];
    if (op[0] == '+') {
      scanf("%d %s", &who, ch);
      des[who][len[who]++] = ch[0] - 'a';
    } else {
      scanf("%d", &who);
      len[who]--;
    }
    int is = 0, js = 0, ks = 0;
    if (who == 1) is = len[1];
    if (who == 2) js = len[2];
    if (who == 3) ks = len[3];
    int ie = len[1], je = len[2], ke = len[3];
    for (int i = is; i <= ie; i++) {
      for (int j = js; j <= je; j++) {
        for (int k = ks; k <= ke; k++) {
          if (i + j + k > 0) dp[i][j][k] = -1;
          if (i > 0 && dp[i - 1][j][k] >= 0) {
            update(dp[i][j][k], nxt[dp[i - 1][j][k]][des[1][i - 1]]);
          }
          if (j > 0 && dp[i][j - 1][k] >= 0) {
            update(dp[i][j][k], nxt[dp[i][j - 1][k]][des[2][j - 1]]);
          }
          if (k > 0 && dp[i][j][k - 1] >= 0) {
            update(dp[i][j][k], nxt[dp[i][j][k - 1]][des[3][k - 1]]);
          }
        }
      }
    }
    if (dp[len[1]][len[2]][len[3]] >= 0) {
      puts("YES");
    } else {
      puts("NO");
    }
  }
  return 0;
}
