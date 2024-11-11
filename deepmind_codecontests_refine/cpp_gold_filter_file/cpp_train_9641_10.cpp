#include <bits/stdc++.h>
using namespace std;
const int MAXN = 15;
const int MAXM = 250;
const int MOD = 1000000007;
char a[MAXM + 5][MAXM + 5];
char b[MAXM + 5][MAXM + 5];
int dp[2][(1 << MAXN) + 5][MAXN + 5][2][2];
void rot(int& n, int& m) {
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) b[j][i] = a[i][j];
  swap(n, m);
  memcpy(a, b, sizeof(b));
}
int add(int x, int y) {
  x += y;
  if (x >= MOD) x -= MOD;
  return x;
}
void adn(int& x, int y) {
  x += y;
  if (x >= MOD) x -= MOD;
}
int main() {
  int n, m;
  scanf("%d%d ", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%s", a[i] + 1);
  if (n > m) rot(n, m);
  dp[0][0][n][0][0] = 1;
  int ns = (1 << n);
  for (int i = 1; i <= m; ++i) {
    int w = (i & 1);
    int l = w ^ 1;
    memset(dp[w], 0, sizeof(dp[w]));
    for (int j = 0; j < ns; ++j)
      for (int k = 0; k < 2; ++k) {
        dp[w][j][0][0][k] = add(dp[l][j][n][0][k], dp[l][j][n][1][k]);
        dp[w][j][0][1][k] = 0;
      }
    for (int j = 0; j < n; ++j)
      for (int s = 0; s < ns; ++s) {
        if (a[j + 1][i] == 'x') {
          int s1 = ((s | (1 << j)) ^ (1 << j));
          adn(dp[w][s1][j + 1][0][0],
              add(dp[w][s][j][0][0], dp[w][s][j][1][0]));
          adn(dp[w][s1][j + 1][0][1],
              add(dp[w][s][j][0][1], dp[w][s][j][1][1]));
          adn(dp[w][s1][j + 1][1][0], 0);
          adn(dp[w][s1][j + 1][1][1], 0);
        } else {
          if (s & (1 << j)) {
            adn(dp[w][s][j + 1][0][0], dp[w][s][j][0][0]);
            adn(dp[w][s][j + 1][0][1], dp[w][s][j][0][1]);
            adn(dp[w][s][j + 1][1][0],
                add(dp[w][s][j][0][0],
                    add(dp[w][s][j][1][0], dp[w][s][j][1][0])));
            adn(dp[w][s][j + 1][1][1],
                add(dp[w][s][j][0][1],
                    add(dp[w][s][j][1][1], dp[w][s][j][1][1])));
          } else {
            int s1 = (s ^ (1 << j));
            adn(dp[w][s][j + 1][0][0], 0);
            adn(dp[w][s][j + 1][0][1], dp[w][s][j][0][0]);
            adn(dp[w][s][j + 1][1][0], dp[w][s][j][1][0]);
            adn(dp[w][s][j + 1][1][1], dp[w][s][j][1][1]);
            adn(dp[w][s1][j + 1][0][0], 0);
            adn(dp[w][s1][j + 1][0][1], 0);
            adn(dp[w][s1][j + 1][1][0],
                add(dp[w][s][j][0][0], dp[w][s][j][1][0]));
            adn(dp[w][s1][j + 1][1][1],
                add(dp[w][s][j][0][1], dp[w][s][j][1][1]));
          }
        }
      }
  }
  int ans = 0, w = (m & 1);
  for (int i = 0; i < ns; ++i)
    adn(ans, add(add(dp[w][i][n][0][0], dp[w][i][n][0][1]),
                 add(dp[w][i][n][1][0], dp[w][i][n][1][1])));
  printf("%d\n", ans);
  return 0;
}
