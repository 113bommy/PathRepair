#include <bits/stdc++.h>
using namespace std;
char sa[52];
char sb[52];
char sc[52];
int na[52];
int nb[52];
int ga[52];
int gb[52];
int gc[52];
int lenA;
int lenB;
int n;
int maskA[52][52];
int maskB[52][52];
int dp[52][52];
int main() {
  scanf("%s%s%d", sa + 1, sb + 1, &n);
  lenA = strlen(sa + 1);
  lenB = strlen(sb + 1);
  for (int i = 1; i <= lenA; i++) na[i] = sa[i] - 'a';
  for (int i = 1; i <= lenB; i++) nb[i] = sb[i] - 'a';
  for (int i = 1; i <= n; i++) {
    scanf("%s", sc);
    ga[i] = 1 << (sc[0] - 'a');
    gb[i] = 1 << (sc[3] - 'a');
    gc[i] = 1 << (sc[4] - 'a');
  }
  memset(maskA, 0, sizeof(maskA));
  memset(maskB, 0, sizeof(maskB));
  for (int i = 1; i <= lenA; i++) maskA[i][i] |= 1 << na[i];
  for (int i = 1; i <= lenB; i++) maskB[i][i] |= 1 << nb[i];
  for (int len = 1; len < lenA; len++)
    for (int l = 1; l + len <= lenA; l++) {
      int r = l + len;
      for (int mid = l; mid < r; mid++)
        for (int c = 1; c <= n; c++)
          if (maskA[l][mid] & gb[c] && maskA[mid + 1][l + len] & gc[c])
            maskA[l][r] |= ga[c];
    }
  for (int len = 1; len < lenB; len++)
    for (int l = 1; l + l <= lenB; l++) {
      int r = l + len;
      for (int mid = l; mid < r; mid++)
        for (int c = 1; c <= n; c++)
          if (maskB[l][mid] & gb[c] && maskB[mid + 1][r] & gc[c])
            maskB[l][r] |= ga[c];
    }
  memset(dp, 1, sizeof(dp));
  dp[0][0] = 0;
  for (int i = 1; i <= lenA; i++)
    for (int j = 1; j <= lenB; j++)
      for (int a = 1; a <= i; a++)
        for (int b = 1; b <= j; b++)
          if (maskA[a][i] & maskB[b][j])
            dp[i][j] = min(dp[i][j], 1 + dp[a - 1][b - 1]);
  if (dp[lenA][lenB] > 50)
    cout << "-1" << endl;
  else
    cout << dp[lenA][lenB] << endl;
  return 0;
}
