#include <bits/stdc++.h>
using namespace std;
const int N = 60;
const long long MOD = 1000000007;
int m, k;
long long n;
struct Matrix {
  long long m[N][N];
};
Matrix matrix;
Matrix matrix_multi(Matrix a, Matrix b) {
  Matrix c;
  for (int i = 0; i < m; i++)
    for (int j = 0; j < m; j++) {
      long long sum = 0;
      for (int k = 0; k < m; k++) {
        sum += a.m[i][k] * b.m[k][j];
        sum %= MOD;
      }
      c.m[i][j] = sum;
    }
  return c;
}
Matrix matrix_Pow(Matrix M, long long n) {
  if (n == 0) {
    Matrix ans;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) ans.m[i][j] = i == j;
    return ans;
  }
  if (n == 1) return M;
  if (n % 2 == 0) {
    Matrix ret = matrix_Pow(M, n / 2);
    return matrix_multi(ret, ret);
  } else {
    n--;
    Matrix ret = matrix_Pow(M, n / 2);
    return matrix_multi(M, matrix_multi(ret, ret));
  }
}
int change(char c) {
  if (c >= 'a' && c <= 'z') return c - 'a';
  return c - 'A' + 26;
}
int main() {
  char a, b;
  while (cin >> n >> m >> k) {
    for (int i = 0; i < m; i++)
      for (int j = 0; j < m; j++) matrix.m[i][j] = 1;
    for (int i = 0; i < k; i++) {
      cin >> a >> b;
      matrix.m[change(a)][change(b)] = 0;
    }
    n--;
    Matrix ans = matrix_Pow(matrix, n);
    long long cnt = 0;
    for (int i = 0; i < m; i++)
      for (int j = 0; j < m; j++) cnt = (cnt + ans.m[i][j]) % MOD;
    cout << cnt << endl;
  }
}
