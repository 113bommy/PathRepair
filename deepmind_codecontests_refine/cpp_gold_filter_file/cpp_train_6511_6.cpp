#include <bits/stdc++.h>
using namespace std;
long long MOD = 1e9 + 7;
struct Matrix {
  long long n, m;
  vector<vector<long long> > mat;
  Matrix(vector<vector<long long> > M) : mat(M), n(M.size()), m(M[0].size()) {}
  static Matrix id(long long n) {
    vector<vector<long long> > I(n, vector<long long>(n, 0));
    for (long long i = 0; i < n; i++) {
      I[i][i] = 1;
    }
    return Matrix(I);
  }
  Matrix operator*(Matrix A) {
    long long N = n;
    long long M = A.m;
    long long O = m;
    vector<vector<long long> > Temp(N, vector<long long>(M, 0));
    for (long long i = 0; i < N; i++) {
      for (long long j = 0; j < M; j++) {
        for (long long k = 0; k < O; k++) {
          Temp[i][j] = (Temp[i][j] + mat[i][k] * A.mat[k][j]) % MOD;
        }
      }
    }
    return Matrix(Temp);
  }
  friend ostream& operator<<(ostream& out, Matrix A);
};
ostream& operator<<(ostream& out, Matrix A) {
  for (long long i = 0; i < A.n; i++) {
    if (i) cout << '\n';
    for (long long j = 0; j < A.m; j++) {
      cout << A.mat[i][j] << " ";
    }
  }
}
Matrix BigMod(long long n, Matrix M) {
  Matrix ret = M.id(M.mat.size());
  while (n) {
    if (n & 1) {
      ret = ret * M;
    }
    n /= 2;
    M = M * M;
  }
  return ret;
}
int32_t main() {
  long long n, k;
  cin >> n >> k;
  vector<long long> a(n);
  vector<vector<long long> > m(n, vector<long long>(n, 0));
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (long long i = 0; i < n; i++)
    for (long long j = 0; j < n; j++)
      m[i][j] = __builtin_popcountll(a[i] ^ a[j]) % 3 == 0;
  Matrix M(m);
  M = BigMod(k - 1, M);
  long long s = 0;
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < n; j++) {
      s = (s + M.mat[i][j]) % MOD;
    }
  }
  cout << s << endl;
}
