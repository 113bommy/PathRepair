#include <bits/stdc++.h>
using namespace std;
const int MAXN = 130;
const int N = MAXN;
struct Matrix {
  double a[MAXN][MAXN];
  int row, col;
  Matrix() {
    row = col = MAXN;
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < row; j++) {
        a[i][j] = 0;
      }
    }
  }
  Matrix(int n) {
    row = col = n;
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < row; j++) {
        a[i][j] = 0;
      }
    }
  }
  Matrix operator*(const Matrix &mat) {
    Matrix ans;
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < row; j++) {
        for (int k = 0; k < row; k++) {
          ans.a[i][j] = (ans.a[i][j] + a[i][k] * mat.a[k][j]);
        }
      }
    }
    return ans;
  }
  Matrix operator^(long long k) {
    Matrix ans;
    ans.setOnes();
    Matrix tmp = *this;
    while (k > 0) {
      if (k & 1) {
        ans = ans * tmp;
      }
      k >>= 1;
      tmp = tmp * tmp;
    }
    return ans;
  }
  void setOnes() {
    for (int i = 0; i < row; i++) {
      a[i][i] = 1;
    }
  }
  void print() {
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < row; j++) {
        printf("%f ", a[i][j]);
      }
      cout << endl;
    }
    cout << endl;
  }
};
int n, x;
double p[N];
int main() {
  scanf("%d%d", &n, &x);
  for (int i = 0; i < N; i++) {
    p[i] = 0;
  }
  for (int i = 0; i <= x; i++) {
    scanf("%lf", &p[i]);
  }
  Matrix mat(N);
  for (int i = 0; i <= x; i++) {
    for (int j = 0; j <= x; j++) {
      mat.a[i][j] = p[i ^ j];
    }
  }
  Matrix A(N);
  for (int i = 0; i <= x; i++) {
    A.a[0][i] = p[i];
  }
  mat = mat ^ (n - 1);
  A = A * mat;
  printf("%.8f\n", 1 - A.a[0][0]);
}
