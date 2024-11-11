#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const double eps = 1e-11;
void fastIO() {
  std::ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
struct Matrix {
  long long mat[16][16];
  Matrix(int diagnoal = 0) {
    for (int i = 0; i < 16; i++)
      for (int j = 0; j < 16; j++) mat[i][j] = i == j ? diagnoal : 0;
  }
  Matrix operator*(const Matrix &b) const {
    Matrix c;
    for (int i = 0; i < 16; i++)
      for (int j = 0; j < 16; j++)
        for (int k = 0; k < 16; k++) {
          c.mat[i][j] =
              (c.mat[i][j] + (mat[i][k]) * (b.mat[k][j])) % 1000000007;
        }
    return c;
  }
  Matrix power(long long pw) {
    auto cur = *this;
    Matrix R(1);
    while (pw) {
      if (pw & 1ll) R = R * cur;
      pw >>= 1;
      cur = cur * cur;
    }
    return R;
  }
};
Matrix MAT[16];
Matrix RES[101];
int n;
int main() {
  fastIO();
  for (int c = 0; c < 16; c++) {
    MAT[c] = Matrix();
    for (int i = 0; i <= c; i++) {
      for (int j = 0; j <= c; j++) {
        MAT[c].mat[i][j] = (abs(j - i) <= 1);
      }
    }
  }
  long long a, b, k;
  int n, c;
  cin >> n >> k;
  Matrix cur;
  vector<long long> v(16, 0);
  v[0] = 1;
  for (int i = 0; i < n; i++) {
    cin >> a >> b >> c;
    b = min(b, k);
    cur = MAT[c].power(b - a);
    vector<long long> w(16, 0);
    for (int x = 0; x < 16; x++) {
      for (int y = 0; y < 16; y++) {
        w[x] = (w[x] + (cur.mat[x][y] * v[y])) % 1000000007;
      }
    }
    v = w;
  }
  cout << v[0] << endl;
  return 0;
}
