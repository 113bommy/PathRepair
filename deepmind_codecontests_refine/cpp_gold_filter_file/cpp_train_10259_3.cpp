#include <bits/stdc++.h>
using namespace std;
int MOD = 1e9 + 7;
long long a, b, x, n;
struct matrix {
  long long m[3][3];
  int r, c;
  matrix(int r_, int c_) { r = r_, c = c_; }
};
void mul(const matrix &a, const matrix &b, matrix &c) {
  for (int i = 0; i < a.r; i++)
    for (int j = 0; j < b.c; j++) {
      c.m[i][j] = 0;
      for (int k = 0; k < a.c; k++)
        c.m[i][j] += ((a.m[i][k] % MOD) * (b.m[k][j] % MOD)) % MOD,
            c.m[i][j] %= MOD;
    }
  c.r = a.r;
  c.c = b.c;
}
void mp(const matrix &a, const long long &p, matrix &res) {
  int x = log(p) / log(2) + 1 + 1e-9;
  matrix t(a.r, a.c), *t2 = &t, *t1 = &res;
  res.r = res.c = a.r;
  for (int i = 0; i < res.c; i++)
    for (int j = 0; j < res.c; j++) res.m[i][j] = i == j;
  for (; x >= 0; x--) {
    mul(*t1, *t1, *t2);
    swap(t1, t2);
    if (p & (1ll << x)) {
      mul(*t1, a, *t2);
      swap(t1, t2);
    }
  }
  res = *t1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  cin >> a >> b >> n >> x;
  matrix init(2, 2), trans(2, 2);
  init.m[0][0] = x;
  init.m[0][1] = 1;
  trans.m[0][0] = a;
  trans.m[0][1] = 0;
  trans.m[1][0] = b;
  trans.m[1][1] = 1;
  matrix ret(2, 2);
  mp(trans, n, ret);
  matrix ans(2, 2);
  mul(init, ret, ans);
  cout << ans.m[0][0] << endl;
}
