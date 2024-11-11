#include <bits/stdc++.h>
using namespace std;
const int MOD(1000000007);
const int INF((1 << 30) - 1);
const int MAXN(2005);
int n, row[MAXN], col[MAXN];
double dp[MAXN][MAXN];
double DP(int i, int j) {
  if (i >= n && j >= n) return 0.0;
  if (dp[i][j] != -1.0) return dp[i][j];
  double res = DP(i + 1, j) * (n - i) * j + DP(i, j + 1) * i * (n - j) +
               DP(i + 1, j + 1) * (n - i) * (n - j) + n * n;
  res /= (n * n - i * j);
  return dp[i][j] = res;
}
int main() {
  int m;
  scanf("%d%d", &n, &m);
  int r = 0, c = 0;
  for (int i = 0; i < m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (!row[x]) {
      row[x] = 1;
      r++;
    }
    if (!col[y]) {
      col[y] = 1;
      c++;
    }
  }
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= n; j++) dp[i][j] = -1.0;
  printf("%lf", DP(r, c));
}
