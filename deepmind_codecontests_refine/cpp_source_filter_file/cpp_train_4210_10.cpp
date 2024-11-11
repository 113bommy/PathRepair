#include <bits/stdc++.h>
using namespace std;
const long long maxn = 100, mod = 1e9 + 7;
long long A[maxn][maxn], B[maxn][maxn], T[maxn][maxn], I[maxn], C[maxn][maxn],
    P[maxn];
long long n, k;
void init() {
  C[0][0] = 1;
  for (int i = 1; i <= k; i++)
    for (int j = 0; j <= i; j++) {
      if (j == 0 || j == i)
        C[i][j] = 1;
      else {
        C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        C[i][j] %= mod;
      }
    }
  for (int i = 0; i <= k; i++) {
    P[i] = (1 << i) % mod;
  }
}
void pre() {
  memset(I, 0, sizeof(I));
  for (int i = k + 2; i <= 2 * k + 3; i++) {
    I[i] = 1;
  }
  I[1] = 1;
  memset(A, 0, sizeof(A));
  for (int i = 1; i <= k + 1; i++) {
    A[i][k + 1 + i] = 1;
  }
  for (int i = 1; i <= k + 1; i++) {
    for (int j = 1; j <= i; j++) {
      A[i + k + 1][j] = P[i - j] * C[i - 1][j - 1] % mod;
    }
    for (int j = 1; j <= i; j++) {
      A[i + k + 1][j + k + 1] = C[i - 1][j - 1] % mod;
    }
  }
  A[2 * k + 3][2 * k + 2] = A[2 * k + 3][2 * k + 3] = 1;
  memset(B, 0, sizeof(B));
  for (int i = 1; i <= 2 * k + 3; i++) {
    B[i][i] = 1;
  }
}
int main() {
  scanf("%lld %lld", &n, &k);
  init();
  pre();
  while (n) {
    if (n & 1) {
      memset(T, 0, sizeof(T));
      for (int i = 1; i <= 2 * k + 3; i++)
        for (int j = 1; j <= 2 * k + 3; j++)
          for (int m = 1; m <= 2 * k + 3; m++) {
            T[i][j] += B[i][m] * A[m][j] % mod;
            T[i][j] %= mod;
          }
      for (int i = 1; i <= 2 * k + 3; i++)
        for (int j = 1; j <= 2 * k + 3; j++) {
          B[i][j] = T[i][j];
        }
    }
    memset(T, 0, sizeof(T));
    for (int i = 1; i <= 2 * k + 3; i++)
      for (int j = 1; j <= 2 * k + 3; j++) {
        for (int m = 1; m <= 2 * k + 3; m++) {
          T[i][j] += A[i][m] * A[m][j] % mod;
          T[i][j] %= mod;
        }
      }
    for (int i = 1; i <= 2 * k + 3; i++)
      for (int j = 1; j <= 2 * k + 3; j++) {
        A[i][j] = T[i][j];
      }
    n >>= 1;
  }
  long long ans = 0;
  for (int i = 1; i <= 2 * k + 3; i++) {
    ans += B[2 * k + 3][i] * I[i] % mod;
    ans %= mod;
  }
  ans = (ans - 1 + mod) % mod;
  printf("%lld", ans);
  return 0;
}
