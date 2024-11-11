#include <bits/stdc++.h>
using namespace std;
class Matrix {
 public:
  vector<vector<long double>> mat;
  unsigned int rows, cols;
  Matrix(vector<vector<long double>> mat) {
    this->mat = mat;
    rows = mat.size();
    cols = mat[0].size();
  }
  Matrix operator*(Matrix &other) {
    vector<vector<long double>> ret(rows, vector<long double>(other.cols));
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < other.cols; j++) {
        long double sum = 0;
        for (int k = 0; k < cols; k++) {
          sum = (sum + mat[i][k] * other.mat[k][j]);
        }
        ret[i][j] = sum;
      }
    }
    return Matrix(ret);
  }
  static Matrix identity_matrix(int n) {
    vector<vector<long double>> ret(n, vector<long double>(n));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i == j)
          ret[i][j] = 1;
        else
          ret[i][j] = 0;
      }
    }
    return Matrix(ret);
  }
  static Matrix fast_exponentiation(Matrix m, long long power) {
    Matrix ret = Matrix::identity_matrix(m.rows);
    while (power) {
      if (power & 1) ret = ret * m;
      m = m * m;
      power >>= 1;
    }
    return ret;
  }
};
int x;
vector<long double> pr;
vector<vector<long double>> v;
void pre1() {
  v.clear();
  v.push_back(vector<long double>());
  for (int i = 0; i < (1 << 7); i++) {
    if (i <= x)
      v.back().push_back(pr[i]);
    else
      v.back().push_back(0);
  }
}
void pre2() {
  v.clear();
  for (int i = 0; i < (1 << 7); i++) {
    v.push_back(vector<long double>());
    for (int j = 0; j < (1 << 7); j++) {
      int dif = (i ^ j);
      if (dif <= x)
        v.back().push_back(pr[dif]);
      else
        v.back().push_back(0);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  cin >> n >> x;
  for (int i = 0; i <= x; i++) {
    long double a;
    cin >> a;
    pr.push_back(a);
  }
  pre1();
  Matrix mat1(v);
  pre2();
  Matrix mat2(v);
  Matrix mat3 = Matrix::fast_exponentiation(mat2, n - 1);
  mat3 = mat1 * mat2;
  long double sol = 0;
  for (int i = 1; i < (1 << 7); i++) sol += mat3.mat[0][i];
  cout << fixed << setprecision(8) << sol;
  return 0;
}
