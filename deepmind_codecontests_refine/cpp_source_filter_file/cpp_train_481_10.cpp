#include <bits/stdc++.h>
using namespace std;
long long const mod = 1e9 + 7;
inline long long add(long long x, long long y) { return (x + y) % mod; }
inline long long mul(long long x, long long y) { return (x * y) % mod; }
struct matrix {
  int sz;
  vector<vector<int>> v;
  matrix(int n, bool identity = false) {
    sz = n;
    v.resize(n, vector<int>(n));
    for (int i = 0; i < n; ++i) v[i][i] = identity;
  }
  matrix operator*(const matrix &other) const {
    matrix res(sz);
    for (int i = 0; i < sz; ++i)
      for (int j = 0; j < sz; ++j)
        for (int k = 0; k < sz; ++k)
          res.v[i][k] = add(res.v[i][k], mul(v[i][j], other.v[j][k]));
    return res;
  }
};
matrix fpow(matrix x, long long y) {
  matrix res(x.sz, true);
  while (y) {
    if (y & 1) res = res * x;
    x = x * x;
    y >>= 1;
  }
  return res;
}
int main() {
  ios ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  map<long long, int> pfx[3];
  set<long long> position;
  long long ans[3] = {0, 1, 0};
  long long n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    long long a, l, r;
    cin >> a >> l >> r;
    pfx[a - 1][l]++;
    pfx[a - 1][r + 1]--;
    position.insert(l - 1);
    position.insert(l);
    position.insert(r);
    position.insert(r + 1);
  }
  position.insert(m);
  int prv = 1;
  for (long long x : position) {
    if (x > m) break;
    matrix base(3);
    for (int i = 0; i < 3; ++i) pfx[i][x] += pfx[i][prv];
    if (pfx[0][x] == 0) base.v[0][0] = base.v[0][1] = 1;
    if (pfx[1][x] == 0) base.v[1][0] = base.v[1][1] = base.v[1][2] = 1;
    if (pfx[2][x] == 0) base.v[2][1] = base.v[2][2] = 1;
    base = fpow(base, x - prv);
    long long tmp[3] = {0, 0, 0};
    for (int i = 0; i < 3; ++i)
      for (int j = 0; j < 3; ++j)
        for (int k = 0; k < 1; ++k)
          tmp[i] = add(tmp[i], mul(base.v[i][j], ans[j]));
    for (int i = 0; i < 3; ++i) ans[i] = tmp[i];
    prv = x;
  }
  cout << ans[1] << '\n';
  return 0;
}
