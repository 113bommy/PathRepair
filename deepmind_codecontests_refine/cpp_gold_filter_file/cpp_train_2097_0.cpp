#include <bits/stdc++.h>
using namespace std;
const long long N = 3005, mod = 1e9 + 7;
typedef vector<vector<long long>> mat;
mat mult(mat &a, mat &b, long long siz) {
  mat prod(siz, vector<long long>(siz, 0));
  for (long long i = 0; i < siz; i++) {
    for (long long j = 0; j < siz; j++) {
      for (long long k = 0; k < siz; k++) {
        prod[i][k] += (a[i][j] * b[j][k]) % mod;
        prod[i][k] %= mod;
      }
    }
  }
  return prod;
}
mat binpow(long long n, long long siz, mat &res, mat &a) {
  while (n > 0) {
    if (n & 1) res = mult(res, a, siz);
    a = mult(a, a, siz);
    n /= 2;
  }
  return res;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, m;
  cin >> n >> m;
  if (m > n) {
    cout << 1;
  } else {
    mat res(m, vector<long long>(m, 0));
    mat a(m, vector<long long>(m, 0));
    res[0][0] = 1;
    res[0][m - 1] = 1;
    for (long long i = 1; i < m; i++) {
      res[i][i - 1] = 1;
    }
    for (long long i = 0; i < m; i++) {
      for (long long j = 0; j < m; j++) a[i][j] = res[i][j];
    }
    mat ress = binpow(n - m, m, res, a);
    long long an = 0;
    for (long long i = 0; i < m; i++) {
      an += res[0][i];
      an %= mod;
    }
    cout << an;
  }
  return 0;
}
