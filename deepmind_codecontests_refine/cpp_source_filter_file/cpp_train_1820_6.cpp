#include <bits/stdc++.h>
struct matrix {
  long long a[102][102];
} I = {0}, A = {0}, B = {0};
int dp[102] = {0};
int visit[102] = {0};
int cnt[102] = {0};
int n, x;
using namespace std;
void open() {
  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);
}
void close() {
  fclose(stdin);
  fclose(stdout);
}
int dfs(int i) {
  if (i < 0) return 0;
  if (i == 0) return 1;
  if (visit[i] == 1) return dp[i];
  for (int j = 1, END = 100; j <= END; j++)
    dp[i] = (dp[i] + cnt[j] * dfs(i - j)) % 1000000007;
  visit[i] = 1;
  return dp[i];
}
void init() {
  for (int i = 1, END = 101; i <= END; i++) I.a[i][i] = 1;
  scanf("%d", &n);
  scanf("%d", &x);
  int d;
  for (int i = 1, END = n; i <= END; i++) {
    scanf("%d", &d);
    cnt[d]++;
  }
  dp[0] = visit[0] = 1;
  for (int i = 100, END = 0; i >= END; i--)
    if (visit[i] == 0) dp[i] = dfs(i);
  for (int i = 1, END = 99; i <= END; i++) B.a[i + 1][i] = 1;
  B.a[101][101] = 1;
  for (int i = 1, END = 100; i <= END; i++)
    B.a[101 - i][100] = B.a[101 - i][101] = cnt[i];
  A.a[1][101] = dp[0];
  for (int i = 1, END = 100; i <= END; i++)
    A.a[1][i] = dp[i], A.a[1][101] = (A.a[1][101] + dp[i]) % 1000000007;
}
matrix mul(matrix A, matrix B) {
  matrix C = {0};
  for (int i = 1, END = 101; i <= END; i++)
    for (int j = 1, END = 101; j <= END; j++)
      for (int k = 1, END = 101; k <= END; k++)
        C.a[i][j] =
            (C.a[i][j] + (long long)(A.a[i][k] * B.a[k][j]) % 1000000007) %
            1000000007;
  return C;
}
matrix power(matrix A, int k) {
  matrix X = A;
  matrix O = I;
  while (k) {
    if (k & 1) O = mul(O, X);
    X = mul(X, X);
    k >>= 1;
  }
  return O;
}
int main() {
  init();
  if (x > 100) {
    B = power(B, x - 100);
    A = mul(A, B);
    printf("%I64d\n", A.a[1][101]);
  } else {
    int ans = 0;
    for (int i = 0, END = x; i <= END; i++) ans = (ans + dp[i]) % 1000000007;
    printf("%d\n", ans);
  }
  close();
  return 0;
}
