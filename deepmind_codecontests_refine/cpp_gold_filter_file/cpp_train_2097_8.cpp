#include <bits/stdc++.h>
using namespace std;
void solve();
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int t = 1;
  while (t--) solve();
  return 0;
}
const long long mod = 1e9 + 7;
long long n, m;
struct matrix {
  long long a[105][105], w, h;
  matrix operator*(matrix y) {
    matrix ret(w, h);
    for (int i = 1; i <= w; ++i) {
      for (int j = 1; j <= h; ++j) {
        ret.a[i][j] = 0;
        for (int k = 1; k <= h; ++k) {
          ret.a[i][j] = (ret.a[i][j] + (a[i][k] * y.a[k][j])) % mod;
        }
      }
    }
    return ret;
  }
  matrix(long long w, long long h) : w(w), h(h) {
    for (int i = 1; i <= w; ++i)
      for (int j = 1; j <= h; ++j) a[i][j] = 0;
  }
};
void init(matrix &s) {
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= m; ++j) {
      s.a[i][j] = 0;
      if (i == j + 1) s.a[i][j] = 1;
    }
  }
  s.a[1][m] = 1;
  s.a[m][m] = 1;
}
matrix binpow(long long st) {
  if (st == 0) {
    matrix eh(m, m);
    for (int i = 1; i <= m; ++i) {
      eh.a[i][i] = 1;
    }
    return eh;
  }
  matrix eh = binpow(st / 2);
  if (st % 2 == 0) return eh * eh;
  matrix ehs(m, m);
  init(ehs);
  return ehs * (eh * eh);
}
void solve() {
  cin >> n >> m;
  if (n < m) {
    cout << 1 << '\n';
    return;
  }
  matrix vec(1, m);
  for (int i = 1; i <= m; ++i) vec.a[1][i] = 1;
  matrix _new = binpow(max((long long)0, n - m + 1));
  matrix ans = vec * _new;
  cout << ans.a[1][m] << '\n';
}
