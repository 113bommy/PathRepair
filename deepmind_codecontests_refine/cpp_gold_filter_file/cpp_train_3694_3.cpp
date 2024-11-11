#include <bits/stdc++.h>
using namespace std;
const int N = 200 + 10;
const int P = 10007;
struct Matrix {
  static const int N = 400 + 10;
  int a[N][N];
  int n;
  Matrix() {}
  Matrix(int _n, int _x = 0) : n(_n) {
    memset(a, 0, sizeof a);
    for (int i = 0; i < n; ++i) {
      a[i][i] = _x;
    }
  }
  Matrix operator*(const Matrix &matrix) const {
    Matrix ret(n);
    for (int i = 0; i < n; ++i) {
      for (int k = i; k < n; ++k) {
        for (int j = i; j < n; ++j) {
          (ret.a[i][j] += a[i][k] * matrix.a[k][j]) %= P;
        }
      }
    }
    return ret;
  }
  Matrix operator^(int k) const {
    Matrix ret(n, 1), matrix(*this);
    for (; k > 0; k >>= 1) {
      if (k & 1) {
        ret = ret * matrix;
      }
      matrix = matrix * matrix;
    }
    return ret;
  }
};
char s[N];
int f[N][N][N], g[N], h[N];
int n;
int ans;
void dp(char *s) {
  int n = strlen(s + 1);
  f[1][n][0] = 1;
  for (int d = 0; d <= n; ++d) {
    for (int l = 1; l <= n; ++l) {
      for (int r = n; r >= l; --r) {
        if (f[l][r][d] == 0) {
          continue;
        }
        if (s[l] == s[r]) {
          (f[l + 1][r - 1][d] += f[l][r][d]) %= P;
        } else {
          (f[l + 1][r][d + 1] += f[l][r][d]) %= P;
          (f[l][r - 1][d + 1] += f[l][r][d]) %= P;
        }
      }
    }
  }
  for (int i = 0; i <= n; ++i) {
    for (int l = 1; l <= n + 1; ++l) {
      if (l > 1) {
        (g[i] += f[l][l - 2][i]) %= P;
      }
      (g[i] += f[l][l - 1][i]) %= P;
      (h[i] += f[l][l - 1][i]) %= P;
    }
  }
}
void combinatorics(int n, int m) {
  Matrix mat(n + (n + 1) / 2 * 2);
  for (int i = 0; i < n; ++i) {
    mat.a[i][i] = 24;
    mat.a[i][i + 1] = 1;
  }
  for (int i = n; i < n + (n + 1) / 2; ++i) {
    mat.a[i][i] = 25;
    if (i + 1 < n + (n + 1) / 2) {
      mat.a[i][i + 1] = 1;
    }
    mat.a[i][i + (n + 1) / 2] = 1;
  }
  for (int i = n + (n + 1) / 2; i < n + (n + 1) / 2 * 2; ++i) {
    mat.a[i][i] = 26;
  }
  Matrix ret = mat ^ ((n + m + 1) / 2);
  for (int i = 0; i <= n; ++i) {
    int n24 = i, n25 = (n - n24 + 1) / 2;
    int from = n - i, to = n - 1 + n25 + (n + 1) / 2;
    (ans += ret.a[from][to] * g[i]) %= P;
  }
  if ((n + m) & 1) {
    ret = mat ^ ((n + m) / 2);
    for (int i = 0; i <= n; ++i) {
      if ((n - i) % 2 == 0) {
        int n24 = i, n25 = (n - n24 + 1) / 2;
        int from = n - i, to = n - 1 + n25;
        ans -= ret.a[from][to] * h[i];
        ans %= P;
        ans += P;
        ans %= P;
      }
    }
  }
}
int main() {
  scanf("%s", s + 1);
  scanf("%d", &n);
  dp(s);
  combinatorics(strlen(s + 1), n);
  printf("%d\n", ans);
  return 0;
}
