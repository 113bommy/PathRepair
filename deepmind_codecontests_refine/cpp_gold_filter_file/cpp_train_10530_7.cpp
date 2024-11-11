#include <bits/stdc++.h>
using namespace std;
int n, m, k, N, T, X;
long long mo = 1e9 + 7, ans;
int A[20];
long long B[20][20];
struct matrix {
  long long s[210][210];
  matrix operator*(const matrix a) const {
    matrix b;
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) {
        b.s[i][j] = 0;
        for (int k = 1; k <= N; k++) {
          b.s[i][j] = (b.s[i][j] + s[i][k] * a.s[k][j]) % mo;
        }
      }
    }
    return b;
  }
} C, D;
int main() {
  cin >> n >> k >> m;
  X = (1 << m) - 1;
  for (int i = 1; i < 1 << m; i++) {
    A[i] = A[i >> 1] + (i & 1);
  }
  for (int i = 0; i <= k; i++) {
    for (int j = 0; j < (1 << m); j++) {
      B[i][j] = ++N;
    }
  }
  for (int i = 0; i <= k; i++) {
    for (int j = 0; j < 1 << m; j++) {
      T = (j << 1) & X;
      C.s[B[i][j]][B[i][T]] = 1;
      if (i != k) {
        C.s[B[i][j]][B[i + 1][T | 1]] = A[j] + 1;
      }
    }
  }
  D.s[1][1] = 1;
  while (n) {
    if (n & 1) {
      D = D * C;
    }
    C = C * C;
    n >>= 1;
  }
  for (int i = 0; i < 1 << m; i++) {
    ans = ans + D.s[1][B[k][i]];
  }
  ans = ans % mo;
  cout << ans << endl;
}
