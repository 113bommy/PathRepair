#include <bits/stdc++.h>
using namespace std;
template <class T>
inline int chkmax(T &a, T b) {
  return a < b ? a = b, 1 : 0;
}
template <class T>
inline int chkmin(T &a, T b) {
  return a > b ? a = b, 1 : 0;
}
const int INF = (int)1e9;
const long long LINF = (long long)1e18;
const int maxn = 100 + 15;
const int MOD = 1000000007;
struct Matrix {
  int n, m, a[16][16];
  Matrix(int n = 0, int m = 0) : n(n), m(m) { memset(a, 0, sizeof(a)); }
  Matrix baseMatrix() {
    Matrix ret = Matrix(n, m);
    for (int i = (0), _b = (n - 1); i <= _b; ++i)
      for (int j = (0), _b = (m - 1); j <= _b; ++j) ret.a[i][j] = i == j;
    return ret;
  }
  Matrix operator*(const Matrix &other) const {
    Matrix ret = Matrix(n, other.m);
    for (int i = (0), _b = (n - 1); i <= _b; ++i)
      for (int j = (0), _b = (other.m - 1); j <= _b; ++j)
        for (int k = (0), _b = (m - 1); k <= _b; ++k)
          ret.a[i][j] =
              (ret.a[i][j] + (1LL * a[i][k] * other.a[k][j]) % MOD) % MOD;
    return ret;
  }
};
int n, c[maxn];
long long a[maxn], b[maxn], k;
Matrix operator^(Matrix n, long long k) {
  Matrix ret = n.baseMatrix();
  while (k) {
    if (k & 1LL) ret = ret * n;
    n = n * n;
    k >>= 1LL;
  }
  return ret;
}
bool check(int x, int b) { return 0 <= x && x <= b; }
void debug(Matrix mat) {
  for (int i = (0), _b = (mat.n - 1); i <= _b; ++i)
    for (int j = (0), _b = (mat.m - 1); j <= _b; ++j)
      cout << mat.a[i][j] << " \n"[j == mat.m - 1];
  cout << "zzz" << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  Matrix ans = Matrix(1, 16);
  ans.a[0][0] = 1;
  for (int i = (1), _b = (n); i <= _b; ++i) {
    cin >> a[i] >> b[i] >> c[i];
    chkmin(b[i], k);
    Matrix unit = Matrix(16, 16);
    for (int j = (0), _b = (c[i]); j <= _b; ++j) {
      if (check(j - 1, c[i])) unit.a[j][j - 1] = 1;
      if (check(j, c[i])) unit.a[j][j] = 1;
      if (check(j + 1, c[i])) unit.a[j][j + 1] = 1;
    }
    unit = unit ^ (b[i] - a[i]);
    ans = ans * unit;
  }
  cout << ans.a[0][0];
  return 0;
}
