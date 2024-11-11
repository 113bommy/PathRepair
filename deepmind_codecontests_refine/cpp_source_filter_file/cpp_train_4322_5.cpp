#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 2005;
double dp[MAX_N][MAX_N][2][2];
int n, h;
double p;
int x[MAX_N], Left[MAX_N], Right[MAX_N];
const int inf = 1e9 + 10;
void prepare() {
  for (int i = 1; i <= n; i++)
    if (x[i] - x[i - 1] >= h)
      Left[i] = i - 1;
    else
      Left[i] = Left[i - 1];
  for (int i = n; i >= 1; i--)
    if (x[i + 1] - x[i] >= h)
      Right[i] = i + 1;
    else
      Right[i] = Right[i + 1];
}
int main() {
  ios ::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> h >> p;
  for (int i = 1; i <= n; i++) cin >> x[i];
  x[0] = -inf;
  x[n + 1] = inf;
  sort(x + 1, x + n + 1);
  double q = 1.0 - p;
  prepare();
  for (int j = 1; j <= n; j++)
    for (int i = j; i >= 1; i--)
      for (int a = 0; a <= 1; a++)
        for (int b = 0; b <= 1; b++) {
          int l = (a ? x[i - 1] + h : x[i - 1]);
          int r = (b ? x[j + 1] : x[j + 1] - h);
          dp[i][j][a][b] += 0.5 * p * ((min(h, x[i] - l)) + dp[i + 1][j][0][b]);
          dp[i][j][a][b] += 0.5 * q * ((min(h, r - x[i])) + dp[i][j - 1][a][1]);
          int k;
          k = Right[i];
          if (k > j) {
            if (k == j + 1 || (k > j + 1 && b))
              dp[i][j][a][b] += 0.5 * q * min(r - x[i], x[j] - x[i] + h);
          } else
            dp[i][j][a][b] += 0.5 * q * (x[k - 1] - x[i] + h + dp[k][j][1][b]);
          k = Left[j];
          if (k < i) {
            if (k == i - 1 || (k < i - 1 && !a))
              dp[i][j][a][b] += 0.5 * p * min(x[j] - l, x[j] - x[i] + h);
          } else
            dp[i][j][a][b] += 0.5 * p * (x[j] - x[k + 1] + h + dp[i][k][a][0]);
        }
  cout << fixed << setprecision(12) << dp[1][n][0][1];
  return 0;
}
