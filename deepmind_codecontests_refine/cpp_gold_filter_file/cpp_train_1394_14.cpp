#include <bits/stdc++.h>
using namespace std;
const int MAXN = 55;
long long C[MAXN][MAXN];
long long dp[4 * MAXN][MAXN][MAXN];
int n, k;
inline long long add(long long x, long long y) {
  return (x + y >= 1000000007) ? x + y - 1000000007 : x + y;
}
inline long long mul(long long x, long long y) { return (x * y) % 1000000007; }
int main() {
  scanf("%d%d", &n, &k);
  k /= 50;
  int ones = 0, twos = 0;
  int x;
  for (int i = 0; i < (int)(n); i++) {
    scanf("%d", &x);
    if (x == 50)
      ones++;
    else
      twos++;
  }
  memset(C, 0, sizeof C);
  C[0][0] = C[1][0] = C[1][1] = 1;
  for (int i = 2; i < MAXN; i++) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; j++) C[i][j] = add(C[i - 1][j], C[i - 1][j - 1]);
  }
  memset(dp, 0, sizeof dp);
  dp[0][ones][twos] = 1;
  for (int t = 0; t < 4 * MAXN - 1; t++) {
    for (int i = 0; i <= ones; i++) {
      for (int j = 0; j <= twos; j++) {
        if (dp[t][i][j] == 0) continue;
        if (i == 0 && j == 0 && dp[t][i][j] != 0) {
          printf("%d\n%I64d\n", t, dp[t][i][j]);
          return 0;
        }
        if (t % 2 == 0) {
          for (int ti = 0; ti <= i; ti++) {
            if (k - ti < 0) break;
            for (int tj = 0; tj <= j; tj++) {
              if (k - ti - 2 * tj < 0) break;
              if (ti == 0 && tj == 0) continue;
              dp[t + 1][i - ti][j - tj] =
                  add(dp[t + 1][i - ti][j - tj],
                      mul(mul(dp[t][i][j], C[i][ti]), C[j][tj]));
            }
          }
        } else {
          for (int ti = 0; ti <= ones - i; ti++) {
            if (k - ti < 0) break;
            for (int tj = 0; tj <= twos - j; tj++) {
              if (k - ti - 2 * tj < 0) break;
              if (ti == 0 && tj == 0) continue;
              dp[t + 1][i + ti][j + tj] =
                  add(dp[t + 1][i + ti][j + tj],
                      mul(mul(dp[t][i][j], C[ones - i][ti]), C[twos - j][tj]));
            }
          }
        }
      }
    }
  }
  printf("-1\n0\n");
  return 0;
}
