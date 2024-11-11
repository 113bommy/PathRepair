#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
struct Matrix {
  long long c[105][105];
};
int cnt[105];
long long dp[105], sum[105];
Matrix Mul(Matrix A, Matrix B) {
  Matrix res;
  for (int i = 0; i <= 100; i++) {
    for (int j = 0; j <= 100; j++) {
      res.c[i][j] = 0;
      for (int k = 0; k <= 100; k++) {
        res.c[i][j] = (res.c[i][j] + A.c[i][k] * B.c[k][j]) % M;
      }
    }
  }
  return res;
}
Matrix Solve(Matrix A, int n) {
  Matrix tmp;
  memset(tmp.c, 0, sizeof(tmp.c));
  for (int i = 0; i < 99; i++) {
    tmp.c[i][i + 1] = 1;
  }
  for (int i = 0; i < 100; i++) {
    tmp.c[99][i] = cnt[100 - i];
    tmp.c[100][i] = cnt[100 - i];
  }
  tmp.c[100][100] = 1;
  while (n) {
    if (n & 1) {
      A = Mul(tmp, A);
    }
    tmp = Mul(tmp, tmp);
    n >>= 1;
  }
  return A;
}
int main() {
  int n, x;
  scanf("%d%d", &n, &x);
  for (int i = 0; i < n; i++) {
    int k;
    scanf("%d", &k);
    cnt[k]++;
  }
  dp[0] = 1;
  sum[0] = 1;
  for (int i = 1; i <= 100; i++) {
    for (int j = 0; j <= i; j++) {
      dp[i] += dp[i - j] * cnt[j];
      dp[i] %= M;
    }
    sum[i] += sum[i - 1] + dp[i];
    sum[i] %= M;
  }
  if (x <= 100) {
    printf("%I64d\n", sum[x]);
    return 0;
  }
  Matrix res;
  for (int i = 0; i < 100; i++) {
    res.c[i][0] = dp[i + 1];
  }
  res.c[100][0] = sum[100];
  res = Solve(res, x - 100);
  printf("%I64d\n", res.c[100][0]);
}
