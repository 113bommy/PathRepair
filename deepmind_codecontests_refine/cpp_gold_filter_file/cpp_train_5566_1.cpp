#include <bits/stdc++.h>
using namespace std;
const int NMax = 5100;
const long long INF = 1000000007;
int ceil(int a) {
  if (a % 2) return a / 2 + 1;
  return a / 2;
}
int N, A, B, K, nn, X;
long long dp[2][NMax], sum[NMax];
int main() {
  scanf("%d%d%d%d", &N, &A, &B, &K);
  if (A < B) {
    nn = B;
    X = B - A + 1;
  } else {
    nn = N - B + 1;
    X = A - B + 1;
  }
  int p = 0;
  dp[0][X] = 1;
  for (int j = 1; j <= nn; j++) sum[j] = (sum[j - 1] + dp[p][j]) % INF;
  for (int i = 1; i <= K; i++) {
    p = 1 - p;
    for (int j = 2; j <= nn; j++)
      dp[p][j] =
          ((sum[nn] - sum[ceil(j)] + INF) % INF - dp[1 - p][j] + INF) % INF;
    memset(sum, 0, sizeof(sum));
    for (int j = 1; j <= nn; j++) sum[j] = (sum[j - 1] + dp[p][j]) % INF;
    memset(dp[1 - p], 0, sizeof(dp[1 - p]));
  }
  printf("%I64d\n", sum[nn]);
  getchar();
  getchar();
  return 0;
}
