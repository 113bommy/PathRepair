#include <bits/stdc++.h>
using namespace std;
long long int A[100001];
long long int power(long long int base, long long int exp, long long int md) {
  if (exp == 0) return 1LL;
  long long int root = power(base, exp / 2, md);
  if (exp & 1LL) return (((root * root) % md) * base) % md;
  return (root * root) % md;
}
bool half = false;
const long long int MOD = 1000000007LL;
long long int term = 1LL;
template <typename T>
class Matrix {
 public:
  int rows, cols;
  vector<vector<T> > _M;
  Matrix(int rows, int cols) : rows(rows), cols(cols) {
    _M = vector<vector<T> >(rows, vector<T>(cols, 0));
    assert(_M.size() == rows);
  }
  Matrix(vector<vector<T> > M) {
    rows = M.size();
    cols = M[0].size();
    _M = M;
  }
  vector<T>& operator[](int rownum) { return _M[rownum]; }
  Matrix operator*(Matrix B) {
    Matrix _ans = Matrix(rows, B.cols);
    assert(cols == B.rows);
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < B.cols; j++) {
        T ans = 0;
        for (int k = 0; k < cols; k++) {
          ans = (ans + (_M[i][k] * B[k][j])) % MOD;
        }
        _ans[i][j] = ans;
      }
    }
    return _ans;
  }
  friend ostream& operator<<(ostream& stream, const Matrix& matrix) {
    for (int i = 0; i < matrix.rows; i++) {
      for (int j = 0; j < matrix.cols; j++) {
        stream << matrix._M[i][j] << " ";
      }
      stream << endl;
    }
    return stream;
  }
  Matrix identity() {
    Matrix __ans(rows, rows);
    for (int i = 0; i < rows; i++) {
      __ans[i][i] = 1;
    }
    return __ans;
  }
};
template <typename T>
T power(T A, long long int exp) {
  if (exp == 0) return A.identity();
  if (exp == 1) return A;
  T root = power(A, exp / 2);
  if (exp % 2 == 0) {
    return root * root;
  } else {
    return A * root * root;
  }
}
int main() {
  int n = []() {
    int x;
    scanf("%d", &x);
    return x;
  }();
  vector<vector<long long int> > V = {{1, 1, 0}, {1, 0, 1}, {0, 1, 1}};
  Matrix<long long int> M(V);
  for (int i = 0; i < n; i++) {
    A[i] = []() {
      long long int x;
      scanf("%lld", &x);
      return x;
    }();
    A[i] = A[i] % (MOD - 1);
    term = (term * A[i]) % (MOD - 1);
    M = power(M, term);
  }
  term = power(2, term, MOD);
  M[1][1] = (M[1][1] * power(2, MOD - 2, MOD)) % MOD;
  cout << M[1][1] << "/";
  term = (term * power(2, MOD - 2, MOD)) % MOD;
  cout << term << endl;
  return 0;
}
