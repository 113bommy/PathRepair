#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 103;
long long n;
int m;
int add(int x, int y) {
  x += y;
  return x >= mod ? x - mod : x;
}
int mul(int x, int y) { return (long long)x * y % mod; }
class Matrix {
 public:
  long long n;

 public:
  long long mod;

 public:
  vector<vector<long long> > matrix;

 public:
  Matrix(long long n, long long mod) {
    this->n = n;
    this->mod = mod;
    matrix.resize(n);
    for (long long i = 0; i < n; i++) matrix[i].resize(n, 0);
  }

 public:
  void mult(Matrix m) {
    vector<vector<long long> > ans(n);
    for (long long i = 0; i < n; i++) ans[i].resize(n, 0);
    for (long long i = 0; i < n; i++)
      for (long long j = 0; j < n; j++)
        for (long long k = 0; k < n; k++)
          ans[i][j] = (ans[i][j] + matrix[k][j] * m.matrix[i][k]) % mod;
    swap(matrix, ans);
  }

 public:
  void mult() {
    vector<vector<long long> > ans(n);
    for (long long i = 0; i < n; i++) ans[i].resize(n, 0);
    for (long long i = 0; i < n; i++)
      for (long long j = 0; j < n; j++)
        for (long long k = 0; k < n; k++)
          ans[i][j] = (ans[i][j] + matrix[k][j] * matrix[i][k]) % mod;
    swap(matrix, ans);
  }

 public:
  void binpow(long long p) {
    Matrix tmp = Matrix(n, mod);
    tmp.matrix = matrix;
    for (long long i = 0; i < n; i++)
      for (long long j = 0; j < n; j++) matrix[i][j] = (i == j ? 1 : 0);
    while (p) {
      if (p & 1) mult(tmp);
      tmp.mult();
      p >>= 1;
    }
  }

 public:
  void print() {
    for (long long i = 0; i < n; i++) {
      for (long long j = 0; j < n; j++) cout << matrix[i][j] << " ";
      cout << '\n';
    }
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  if (n < m) {
    cout << 1 << '\n';
    return 0;
  }
  Matrix dp(m, mod);
  dp.matrix[0][0] = 1;
  dp.matrix[0][m - 1] = 1;
  for (int i = 1; i < m; i++) dp.matrix[i][i - 1] = 1;
  dp.binpow(n - m + 1);
  int ans = 0;
  for (int i = 1; i <= m; i++) {
    ans += dp.matrix[0][i];
    if (ans >= mod) ans -= mod;
  }
  cout << ans << '\n';
  return 0;
}
