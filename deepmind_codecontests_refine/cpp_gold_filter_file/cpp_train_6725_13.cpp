#include <bits/stdc++.h>
using namespace std;
const int N = 60, p = 1e9 + 7;
void update(int &x, int v) {
  x += v;
  if (x >= p) x -= p;
}
int inc(int x, int y) {
  x += y;
  return x >= p ? x - p : x;
}
int mul(int x, int y) { return (long long)x * y % p; }
int n, deg[N], C[N][N], dp[2][N][N][N][N], x = 0, y = 1;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> deg[i];
  for (int i = 0; i <= n; i++) {
    C[i][0] = 1;
    for (int j = 1; j <= i; j++) C[i][j] = inc(C[i - 1][j - 1], C[i - 1][j]);
  }
  int st;
  if (deg[1] == 2)
    dp[x][0][1][0][0] = 1, st = 1;
  else if (deg[2] == 2)
    dp[x][0][1][1][0] = 1, st = 2;
  else
    dp[x][0][1][0][1] = 1, st = 2;
  for (int i = st; i < n; i++, swap(x, y)) {
    memset(dp[y], 0, sizeof dp[y]);
    for (int a = 0; a <= i; a++)
      for (int b = 0; a + b <= i; b++)
        for (int c = 0; a + b + c <= i; c++)
          for (int d = 0; a + b + c + d <= i; d++)
            if (deg[i + 1] == 2) {
              int v = dp[x][a][b][c][d];
              if (!v) continue;
              if (a) update(dp[y][a - 1][b][c + 1][d], mul(v, a));
              if (b) update(dp[y][a + 1][b - 1][c + 1][d], mul(v, b));
              if (a && c) update(dp[y][a - 1][b][c - 1][d], mul(v, a * c));
              if (a && d) update(dp[y][a - 1][b][c + 1][d - 1], mul(v, a * d));
              if (b && c) update(dp[y][a + 1][b - 1][c - 1][d], mul(v, b * c));
              if (b && d)
                update(dp[y][a + 1][b - 1][c + 1][d - 1], mul(v, b * d));
            } else {
              int v = dp[x][a][b][c][d];
              if (!v) continue;
              if (a) update(dp[y][a - 1][b][c][d + 1], mul(v, a));
              if (b) update(dp[y][a + 1][b - 1][c][d + 1], mul(v, b));
              if (a && c) update(dp[y][a - 1][b][c][d], mul(v, a * c));
              if (a && d) update(dp[y][a - 1][b][c + 2][d - 1], mul(v, a * d));
              if (b && c) update(dp[y][a + 1][b - 1][c][d], mul(v, b * c));
              if (b && d)
                update(dp[y][a + 1][b - 1][c + 2][d - 1], mul(v, b * d));
              if (a && c > 1)
                update(dp[y][a - 1][b][c - 2][d], mul(v, a * C[c][2]));
              if (a && c && d)
                update(dp[y][a - 1][b][c][d - 1], mul(v, a * c * d));
              if (a && d > 1)
                update(dp[y][a - 1][b][c + 2][d - 2], mul(v, a * C[d][2]));
              if (b && c > 1)
                update(dp[y][a + 1][b - 1][c - 2][d], mul(v, b * C[c][2]));
              if (b && c && d)
                update(dp[y][a + 1][b - 1][c][d - 1], mul(v, b * c * d));
              if (b && d > 1)
                update(dp[y][a + 1][b - 1][c + 2][d - 2], mul(v, b * C[d][2]));
            }
    for (int c = 0; c <= i + 1; c++)
      for (int d = 0; d <= i + 1; d++)
        if (c || d)
          update(dp[y][c][d][0][0], dp[y][0][0][c][d]), dp[y][0][0][c][d] = 0;
  }
  cout << dp[x][0][0][0][0] << endl;
  return 0;
}
