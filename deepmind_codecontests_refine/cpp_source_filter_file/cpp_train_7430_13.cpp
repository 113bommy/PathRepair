#include <bits/stdc++.h>
using namespace std;
const int MAXN = 160;
const int PP = 10000007;
int n, m;
long long a[MAXN][MAXN][MAXN], b[MAXN][MAXN][MAXN], c[MAXN][MAXN][MAXN],
    d[MAXN][MAXN][MAXN];
long long A[MAXN][MAXN][MAXN], B[MAXN][MAXN][MAXN], C[MAXN][MAXN][MAXN],
    D[MAXN][MAXN][MAXN];
void Updata(int i) {
  for (int l = 1; l <= n; l++)
    for (int r = 1; r <= n; r++) {
      A[i][l][r] = A[i][l][r - 1] + a[i][l][r];
      B[i][l][r] = B[i][l][r - 1] + b[i][l][r];
      C[i][l][r] = C[i][l][r - 1] + c[i][l][r];
      D[i][l][r] = D[i][l][r - 1] + d[i][l][r];
      A[i][l][r] = A[i][l][r] % PP;
      B[i][l][r] = B[i][l][r] % PP;
      C[i][l][r] = C[i][l][r] % PP;
      D[i][l][r] = D[i][l][r] % PP;
    }
  for (int l = 1; l <= n; l++)
    for (int r = 1; r <= n; r++) {
      A[i][l][r] += A[i][l - 1][r];
      B[i][l][r] += B[i][l - 1][r];
      C[i][l][r] += C[i][l - 1][r];
      D[i][l][r] += D[i][l - 1][r];
      A[i][l][r] = A[i][l][r] % PP;
      B[i][l][r] = B[i][l][r] % PP;
      C[i][l][r] = C[i][l][r] % PP;
      D[i][l][r] = D[i][l][r] % PP;
    }
}
void Init() {
  cin >> n >> m;
  if (n > m) swap(n, m);
  memset(A, 0, sizeof(A));
  ;
  memset(B, 0, sizeof(B));
  ;
  memset(C, 0, sizeof(C));
  ;
  memset(D, 0, sizeof(D));
  ;
  memset(a, 0, sizeof(a));
  ;
  memset(b, 0, sizeof(b));
  ;
  memset(c, 0, sizeof(c));
  ;
  memset(d, 0, sizeof(d));
  ;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (i <= j) a[1][i][j] = 1;
  Updata(1);
}
void Work() {
  for (int i = 2; i <= m; i++) {
    for (int l = 1; l <= n; l++)
      for (int r = 1; r <= n; r++)
        if (l <= r) {
          a[i][l][r] = A[i - 1][r][r] + A[i - 1][l - 1][l - 1] -
                       A[i - 1][r][l - 1] - A[i - 1][l - 1][r] + 1;
          b[i][l][r] = A[i - 1][l - 1][r] - A[i - 1][l - 1][l - 1] +
                       B[i - 1][l][r] - B[i - 1][l][l - 1];
          c[i][l][r] = A[i - 1][r][n] + A[i - 1][l - 1][r] -
                       A[i - 1][l - 1][n] - A[i - 1][r][r] + C[i - 1][r][n] +
                       C[i - 1][l - 1][r - 1] - C[i - 1][l - 1][n] -
                       C[i - 1][r][r - 1];
          d[i][l][r] = D[i - 1][l][n] - D[i - 1][l][r - 1] +
                       A[i - 1][l - 1][n] - A[i - 1][l - 1][r] +
                       B[i - 1][l][n] - B[i - 1][l][r] + C[i - 1][l - 1][n] -
                       C[i - 1][l - 1][r - 1];
          a[i][l][r] = a[i][l][r] % PP;
          b[i][l][r] = b[i][l][r] % PP;
          c[i][l][r] = c[i][l][r] % PP;
          d[i][l][r] = d[i][l][r] % PP;
          if (a[i][l][r] < 0) a[i][l][r] += PP;
          if (b[i][l][r] < 0) b[i][l][r] += PP;
          if (c[i][l][r] < 0) c[i][l][r] += PP;
          if (d[i][l][r] < 0) d[i][l][r] += PP;
        }
    Updata(i);
  }
  for (int i = 1; i <= m; i++)
    for (int l = 1; l <= n; l++)
      for (int r = 1; r <= n; r++) {
      }
  int ans = 0;
  for (int i = 1; i <= m; i++) {
    ans += A[i][n][n];
    if (ans > PP) ans -= PP;
    ans += B[i][n][n];
    if (ans > PP) ans -= PP;
    ans += C[i][n][n];
    if (ans > PP) ans -= PP;
    ans += D[i][n][n];
    if (ans > PP) ans -= PP;
  }
  cout << ans;
}
int main() {
  Init();
  Work();
}
