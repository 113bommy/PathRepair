#include <bits/stdc++.h>
using namespace std;
const int N = 80;
const int inf = 1000;
int dp[N][N][N][2];
int X[N], Y[N], Z[N];
void up(int &x, int y) { x = min(x, y); }
int cost(int x, int y) { return max(0, x - y); }
int dist(int x, int y) { return abs(x - y); }
int check(int a[], int n, int pos) {
  int sum = 0;
  for (int i = 1; i <= n; i++)
    if (a[i] > pos) sum++;
  return sum;
}
int main() {
  int n, x = 0, y = 0, z = 0;
  char s[N];
  scanf("%d%s", &n, s + 1);
  for (int i = 1; i <= n; i++) {
    if (s[i] == 'V')
      X[++x] = i;
    else if (s[i] == 'K')
      Y[++y] = i;
    else
      Z[++z] = i;
  }
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      for (int k = 0; k < N; k++)
        for (int r = 0; r < 2; r++) dp[i][j][k][r] = inf;
  dp[0][0][0][0] = 0;
  for (int i = 0; i <= x; i++)
    for (int j = 0; j <= y; j++)
      for (int k = 0; k <= z; k++)
        for (int r = 0; r < 2; r++) {
          if (i < x) {
            int p = X[i + 1] + check(Y, j, X[i + 1]) + check(Z, k, X[i + 1]);
            up(dp[i + 1][j][k][1], dp[i][j][k][r] + dist(p, i + j + k + 1));
          }
          if (j < y && r != 1) {
            int p = Y[j + 1] + check(X, i, Y[j + 1]) + check(Z, k, Y[j + 1]);
            up(dp[i][j + 1][k][0], dp[i][j][k][r] + dist(p, i + j + k + 1));
          }
          if (k < z) {
            int p = Z[k + 1] + check(X, i, Z[k + 1]) + check(Y, j, Z[k + 1]);
            up(dp[i][j][k + 1][0], dp[i][j][k][r] + dist(p, i + j + k + 1));
          }
        }
  cout << min(dp[x][y][z][0], dp[x][y][z][1]) << endl;
  return 0;
}
