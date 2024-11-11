#include <bits/stdc++.h>
using namespace std;
const int N = 51;
const long long mod = 1e9 + 7;
int n, k, n1 = 0, n2 = 0;
long long dp[202][N][N][2], C[N][N];
int main() {
  int x;
  scanf("%d%d", &n, &k);
  k /= 50;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &x);
    if (x == 50)
      n1++;
    else
      n2++;
  }
  for (int i = 0; i <= n; i++) C[i][0] = 1, C[i][i] = 1;
  for (int i = 2; i <= n; i++)
    for (int j = 1; j < i; j++) {
      C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
    }
  dp[0][n1][n2][0] = 1;
  for (int st = 0; st <= 200; st++) {
    if (dp[st][0][0][1]) {
      printf("%d\n%I64d\n", st, dp[st][0][0][1]);
      return 0;
    }
    for (int a1 = 0; a1 <= n1; a1++) {
      for (int a2 = 0; a2 <= n2; a2++) {
        if (dp[st][a1][a2][0]) {
          for (int u = 0; u <= a1; u++) {
            if (u > k) break;
            for (int v = 0; v <= a2; v++) {
              if (u + v * 2 > k) break;
              if (u + v == 0) continue;
              dp[st + 1][a1 - u][a2 - v][1] +=
                  (C[a2][v] * (dp[st][a1][a2][0] * C[a1][u]) % mod) % mod;
              dp[st + 1][a1 - u][a2 - v][1] %= mod;
            }
          }
        }
        if (dp[st][a1][a2][1]) {
          for (int u = 0; u <= n1 - a1; u++) {
            if (u > k) break;
            for (int v = 0; v <= n2 - a2; v++) {
              if (u + v * 2 > k) break;
              if (u + v == 0) continue;
              dp[st + 1][a1 + u][a2 + v][0] +=
                  (C[n2 - a2][v] * (dp[st][a1][a2][1] * C[n1 - a1][u]) % mod) %
                  mod;
              dp[st + 1][a1 + u][a2 + v][0] %= mod;
            }
          }
        }
      }
    }
  }
  printf("-1\n0\n");
  return 0;
}
