#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5;
const int MAXM = 110000;
const long long INF = 1LL << 60;
int n, m;
int X[MAXN][MAXM], Y[MAXN][MAXM];
long long sumX[1 << MAXN], sumY[1 << MAXN];
long long dp[1 << MAXN][2];
long long ans = INF;
int STA;
int main() {
  scanf("%d %d", &n, &m);
  STA = 1 << n;
  for (int j = 1; j < m; j++)
    for (int i = 0; i < n; i++) scanf("%d", &X[i][j]);
  for (int j = 1; j <= m; j++)
    for (int i = 0; i < n; i++) scanf("%d", &Y[i][j]);
  for (int i = 0; i < STA; i++)
    for (int j = 0; j < 2; j++) dp[i][j] = INF;
  dp[0][1] = 0;
  for (int j = 1; j < m; j++) {
    memset(sumX, 0, sizeof(sumX));
    memset(sumY, 0, sizeof(sumY));
    for (int a = 0; a < STA; a++) {
      dp[a][j + 1 & 1] = INF;
      for (int i = 0; i < n; i++) {
        bool f1 = a & 1 << i;
        bool f2 = a & 1 << (i + 1) % n;
        if (f1 != f2) sumY[a] += Y[i][j];
        if (f1) sumX[a] += X[i][j];
      }
    }
    for (int a = 0; a < STA; a++) {
      for (int b = 0; b < STA; b++) {
        while ((a & b) > 0) b += a & b;
        if (b >= STA) break;
        dp[a | b][j + 1 & 1] =
            min(dp[a | b][j + 1 & 1], dp[a][j & 1] + sumX[b] + sumY[a]);
        if ((a | b) == STA - 1) ans = min(ans, dp[a | b][j + 1 & 1]);
      }
    }
  }
  cout << ans << endl;
  return 0;
}
