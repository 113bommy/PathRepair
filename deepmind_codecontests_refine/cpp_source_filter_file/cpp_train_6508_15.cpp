#include <bits/stdc++.h>
using namespace std;
struct matrix {
  long long dp[105][105];
};
int n, b, k, x;
matrix multi(matrix a, matrix b) {
  matrix y;
  memset(y.dp, 0, sizeof(y.dp));
  for (int i = 0; i < x; i++)
    for (int j = 0; j < x; j++)
      for (int k = 0; k < x; k++)
        y.dp[i][j] = (y.dp[i][j] + (a.dp[i][k] * b.dp[k][j])) % 100000007;
  return y;
}
matrix pow(matrix A, int b) {
  matrix y;
  memset(y.dp, 0ll, sizeof(y.dp));
  for (int i = 0; i < x; i++) y.dp[i][i] = 1ll;
  while (b) {
    if (b & 1) y = multi(y, A);
    A = multi(A, A);
    b >>= 1;
  }
  return y;
}
int cnt[15];
int main() {
  int num;
  matrix A;
  memset(A.dp, 0, sizeof(A.dp));
  scanf("%d%d%d%d", &n, &b, &k, &x);
  for (int i = 0; i < n; i++) {
    scanf("%d", &num);
    cnt[num]++;
  }
  for (int i = 0; i < x; i++)
    for (int j = 0; j < 10; j++) A.dp[i][(i * 10 + j) % x] += 1ll * cnt[j];
  matrix res = pow(A, b);
  printf("%I64d\n", res.dp[0][k]);
  return 0;
}
