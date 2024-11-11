#include <bits/stdc++.h>
using namespace std;
const int maxM = 21;
const int maxN = (1 << maxM);
const long long INF = 1e18;
int n, m, b[maxM];
long long MOD, T;
int dp[maxN][maxM];
int C[maxM][maxM];
struct Matrix {
  int A[maxM][maxM];
  int a, b;
  Matrix(int x, int y) {
    a = x;
    b = y;
    memset(A, 0, sizeof A);
  }
  int *operator[](int i) { return A[i]; }
  Matrix operator*(const Matrix &X) {
    Matrix res(a, X.b);
    for (int i = 0; i < a; i++)
      for (int k = 0; k < b; k++)
        for (int j = 0; j < X.b; j++)
          res.A[i][j] = (res.A[i][j] + (1ll * A[i][k] * X.A[k][j]) % MOD) % MOD;
    return res;
  }
  Matrix operator^(const long long &t) {
    Matrix res(a, a);
    Matrix T = *this;
    for (int i = 0; i < a; i++) res[i][i] = 1;
    for (long long pw = t; pw; pw >>= 1, T = T * T)
      if (pw & 1) res = res * T;
    return res;
  }
};
int main() {
  time_t START = clock();
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  scanf("%d%lld%lld", &m, &T, &MOD);
  n = (1 << m);
  for (int i = 0; i < n; i++) {
    scanf("%d", &dp[i][0]);
    dp[i][0] %= MOD;
  }
  for (int i = 0; i <= m; i++) {
    scanf("%d", b + i);
    b[i] %= MOD;
  }
  for (int i = 0; i <= m; i++) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; j++)
      C[i][j] = (0ll + C[i - 1][j - 1] + C[i - 1][j]) % MOD;
  }
  for (int i = 0; i <= m; i++)
    for (int j = i + 1; j > -1; j--)
      for (int mask = 0; mask < n; mask++)
        dp[mask][j] = (0ll + dp[mask][j] + dp[mask ^ (1 << i)][j - 1]) % MOD;
  Matrix M(m + 1, m + 1);
  for (int i = 0; i <= m; i++)
    for (int x = 0; x <= i; x++)
      for (int j = x; i + j - x <= m; j++)
        M[i][j] = (0ll + M[i][j] +
                   ((1ll * C[j][x] * C[m - j][i - x]) % MOD * b[i + j - 2 * x] %
                    MOD) %
                       MOD) %
                  MOD;
  M = M ^ T;
  for (int mask = 0; mask < n; mask++) {
    long long ans = 0;
    for (int diff = 0; diff <= m; diff++)
      ans = (ans + (1ll * M[0][diff] * dp[mask][diff]) % MOD) % MOD;
    printf("%lld\n", ans);
  }
  time_t FINISH = clock();
  cerr << "Execution time: "
       << (long double)(FINISH - START) / CLOCKS_PER_SEC * 1000.0
       << " milliseconds.\n";
  return 0;
}
