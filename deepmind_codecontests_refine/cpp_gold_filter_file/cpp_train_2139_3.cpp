#include <bits/stdc++.h>
using namespace std;
int ins, del, rep, exc;
string a, b;
int lena, lenb;
int dp[4010][4010];
int posa[4010][30];
int posb[4010][30];
int main() {
  cin >> ins >> del >> rep >> exc;
  cin >> a >> b;
  lena = a.size();
  lenb = b.size();
  a = "." + a;
  b = "." + b;
  for (int k = 0; k < 26; k++) {
    char now = 'a' + k;
    posa[0][k] = posa[0][k] = 0;
    for (int i = 1; i <= lena; i++) {
      if (a[i] == now)
        posa[i][k] = i;
      else
        posa[i][k] = posa[i - 1][k];
    }
    for (int i = 1; i <= lenb; i++) {
      if (b[i] == now)
        posb[i][k] = i;
      else
        posb[i][k] = posb[i - 1][k];
    }
  }
  dp[0][0] = 0;
  for (int i = 1; i <= lena; i++) dp[i][0] = dp[i - 1][0] + del;
  for (int i = 1; i <= lenb; i++) dp[0][i] = dp[0][i - 1] + ins;
  for (int i = 1; i <= lena; i++)
    for (int j = 1; j <= lenb; j++) {
      dp[i][j] = 999999999;
      if (a[i] == b[j]) dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
      dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + rep);
      dp[i][j] = min(dp[i][j], dp[i - 1][j] + del);
      dp[i][j] = min(dp[i][j], dp[i][j - 1] + ins);
      int u = posa[i][b[j] - 'a'];
      int v = posb[j][a[i] - 'a'];
      if (u > 0 && v > 0 && u < i && v < j)
        dp[i][j] = min(dp[i][j], dp[u - 1][v - 1] + exc + (i - u - 1) * del +
                                     (j - v - 1) * ins);
    }
  cout << dp[lena][lenb] << endl;
  return 0;
}
