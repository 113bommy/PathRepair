#include <bits/stdc++.h>
const double pi = acos(-1);
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;
const int MAXN = 1e2 + 5;
const double eps = 1e-9;
using namespace std;
char x[MAXN], y[MAXN], tmp[MAXN];
int A[MAXN], B[MAXN], C[MAXN];
int dp[MAXN][MAXN], dpX[MAXN][MAXN], dpY[MAXN][MAXN];
int main() {
  scanf("%s %s", x, y);
  int n = strlen(x), m = strlen(y);
  int q;
  scanf("%d", &(q));
  for (int i = 0; i < q; i++) {
    scanf("%s", tmp);
    A[i] = 1ll << (tmp[0] - 'a');
    B[i] = 1ll << (tmp[3] - 'a');
    C[i] = 1ll << (tmp[4] - 'a');
  }
  for (int i = 0; i < n; i++) dpX[i + 1][i + 1] = (1ll << (x[i] - 'a'));
  for (int i = 0; i < m; i++) dpY[i + 1][i + 1] = (1ll << (y[i] - 'a'));
  for (int i = 1; i < n; i++)
    for (int l = 1; l + i <= n; l++)
      for (int mi = l; mi < l + i; mi++)
        for (int j = 0; j < q; j++)
          if ((dpX[l][mi] & B[j]) && (dpX[mi + 1][l + i] & C[j]))
            dpX[l][l + i] |= A[j];
  for (int i = 1; i < m; i++)
    for (int l = 1; l + i <= m; l++)
      for (int mi = l; mi < l + i; mi++)
        for (int j = 0; j < q; j++)
          if ((dpY[l][mi] & B[j]) && (dpY[mi + 1][l + i] & C[j]))
            dpY[l][l + i] |= A[j];
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= m; j++) dp[i][j] = INF;
  dp[0][0] = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      for (int a = 1; a <= i; a++)
        for (int b = 1; b <= j; b++)
          if (dpX[a][i] & dpY[b][j])
            dp[i][j] = min(dp[i][j], dp[a - 1][b - 1] + 1);
  if (dp[n][m] > 50) return !printf("%d\n", (-1));
  return !printf("%d\n", (dp[n][m]));
}
