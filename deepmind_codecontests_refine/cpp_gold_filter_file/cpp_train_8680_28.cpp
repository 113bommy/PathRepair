#include <bits/stdc++.h>
using namespace std;
int n, m, K, Ans;
int C[105][105], Dp[105 / 2][105 / 2][105 / 2][105];
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch <= '9' && ch >= '0') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
void Prepare() {
  C[1][0] = C[1][1] = C[0][0] = 1;
  for (int i = 2; i <= 100; i++) {
    C[i][0] = 1;
    for (int j = 1; j <= i; j++)
      C[i][j] = min(C[i - 1][j] + C[i - 1][j - 1], 105);
  }
}
int main() {
  n = read();
  m = read();
  K = read();
  Prepare();
  n /= 2;
  for (int i = 1; i <= n; i++) Dp[1][i][i][1] = 1;
  for (int i = 1; i <= m && i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      for (int k = 1; k <= n; k++) {
        for (int w = 1; w <= K; w++) {
          Ans = Ans + Dp[i][j][k][w] * (m - i) % 1000000007;
          Ans %= 1000000007;
          for (int t = 1; t <= n - k; t++) {
            int qwer = w * C[t + j - 1][j - 1];
            if (qwer > K) continue;
            Dp[i + 1][t][t + k][qwer] =
                (Dp[i + 1][t][t + k][qwer] + Dp[i][j][k][w]) % 1000000007;
          }
        }
      }
    }
  }
  cout << Ans << endl;
  return 0;
}
