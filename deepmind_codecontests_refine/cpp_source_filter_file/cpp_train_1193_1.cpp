#include <bits/stdc++.h>
using namespace std;
class Matrix {
 public:
  int m[31][31];
  int N;
  Matrix(int N) {
    this->N = N;
    memset(m, 0, sizeof(m));
    for (int i = 0; i < N; i++) m[i][i] = 1;
  }
  Matrix* operator*(Matrix b);
} * M[71][31];
Matrix* Matrix::operator*(Matrix b) {
  int i, j, k;
  Matrix* ret = new Matrix(N);
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      long long int cans = 0;
      for (k = 0; k < N; k++) {
        cans += m[i][k] * ((long long int)b.m[k][j]);
        cans %= 1000000007;
      }
      ret->m[i][j] = cans;
    }
  }
  return ret;
}
long long int kp[100];
int main() {
  int i, j, k, l;
  long long int n;
  cin >> n >> k;
  for (i = 0; i < k; i++) {
    M[0][i] = new Matrix(k + 1);
    for (j = 0; j <= k; j++) {
      M[0][i]->m[i][j] = 1;
    }
  }
  kp[0] = 1;
  kp[1] = k;
  int lg = 2;
  while (kp[lg - 1] <= n) {
    kp[lg] = kp[lg - 1] * k;
    lg++;
  }
  for (i = 1; i < lg; i++) {
    M[i][0] = new Matrix(k + 1);
    for (j = 1; j < k; j++) {
      M[i][j] = *M[i - 1][j - 1] * *M[i][j - 1];
    }
    Matrix* cpro = new Matrix(k + 1);
    for (j = k - 1; j >= 0; j--) {
      cpro = *cpro * *M[i - 1][j];
      M[i][j] = *M[i][j] * *cpro;
    }
  }
  Matrix* ans = new Matrix(k + 1);
  int cc = 0;
  for (i = lg - 1; i >= 0; i--) {
    while (kp[i] <= n) {
      n -= kp[i];
      ans = *M[i][cc] * *ans;
      cc++;
      cc %= k;
    }
  }
  long long int ret = 0;
  for (i = 0; i <= k; i++) {
    ret += ans->m[i][k];
    ret %= 1000000007;
  }
  cout << ret << endl;
  return 0;
}
