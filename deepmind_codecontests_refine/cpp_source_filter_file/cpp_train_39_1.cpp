#include <bits/stdc++.h>
using namespace std;
bool chk[64] = {false};
int comb[64][8];
char s[128];
int dp[16][128];
char ans[8][16];
int main() {
  for (int p = 0; p <= 6; p++)
    for (int q = 0; p + q <= 6; q++) {
      int r = 6 - p - q;
      int v = q * 4 + r * 7;
      chk[v] = true;
      for (int i = 0; i < p; i++) comb[v][i] = 0;
      for (int i = p; i < p + q; i++) comb[v][i] = 4;
      for (int i = p + q; i < p + q + r; i++) comb[v][i] = 7;
    }
  int T;
  scanf("%d", &T);
  while (T--) {
    s[0] = '0';
    scanf("%s", s + 1);
    int l = strlen(s);
    memset(dp, -1, sizeof(dp));
    dp[0][0] = -2;
    for (int i = 1; i < l; i++)
      for (int j = 0; j < 10; j++)
        if (dp[j][i - 1] != -1) {
          int v = 10 * j + (s[i] - '0');
          for (int k = 0; k < 64; k++)
            if (chk[k] && v >= k && v - k < 10) dp[v - k][i] = k;
        }
    if (dp[0][l - 1] == -1)
      printf("-1\n");
    else {
      int cv = 0;
      for (int j = 0; j < 6; j++) {
        ans[j][0] = '0';
        ans[j][l] = '\0';
      }
      for (int i = l - 1; i > 0; i--) {
        int w = dp[cv][i];
        for (int j = 0; j < 6; j++) ans[j][i] = '0' + comb[w][j];
        cv += w;
        cv /= 10;
      }
      for (int j = 0; j < 6; j++) {
        long long pans;
        sscanf(ans[j], "%lld", &pans);
        printf(" %lld" + !j, pans);
      }
      printf("\n");
    }
  }
  return 0;
}
