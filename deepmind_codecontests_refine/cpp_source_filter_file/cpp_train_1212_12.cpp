#include <bits/stdc++.h>
using namespace std;
long long int mod = 1e9 + 9;
const double error = 1e-7;
const double PI = acos(-1);
mt19937 rng(
    (unsigned int)chrono::system_clock::now().time_since_epoch().count());
inline long long int MOD(long long int x, long long int m = mod) {
  long long int y = x % m;
  return (y >= 0) ? y : y + m;
}
const int inf = 1e9 + 2;
const long long int infl = 1e18 + 1;
const int nmax = 256;
void MatMult(vector<vector<long long int> > &A,
             vector<vector<long long int> > &B,
             vector<vector<long long int> > &C) {
  int p = A.size(), q = B.size(), r = B[0].size();
  vector<vector<long long int> > tmp(p, vector<long long int>(r, 0));
  for (int i = 0; i < p; i++)
    for (int j = 0; j < r; j++)
      for (int k = 0; k < q; k++)
        tmp[i][j] = ((A[i][k] * B[k][j]) + tmp[i][j]) % mod;
  swap(C, tmp);
  return;
}
vector<vector<long long int> > I(16, vector<long long int>(16, 0));
vector<vector<long long int> > powsum(vector<vector<long long int> > X,
                                      long long int n) {
  if (n == 0) return I;
  vector<vector<long long int> > X2;
  MatMult(X, X, X2);
  vector<vector<long long int> > Y = powsum(X2, (n - 1) >> 1);
  vector<vector<long long int> > Xp1(X);
  for (int i = 0; i < Xp1.size(); i++) Xp1[i][i] += 1;
  MatMult(Xp1, Y, Y);
  if (!(n & 1)) {
    MatMult(X, Y, Y);
    for (int i = 0; i < Y.size(); i++) Y[i][i] += 1;
    return Y;
  }
  return Y;
}
vector<vector<long long int> > base(16, vector<long long int>(16, 0));
vector<vector<long long int> > two(16, vector<long long int>(1, 0));
long long int getans(long long int l, long long int r) {
  if (l > r) return 0;
  long long int ret = 0;
  if (l < 2) {
    l = 2;
    ret += 4;
  }
  if (r < l) return ret;
  if (l == 2) {
    vector<vector<long long int> > A = powsum(base, r - 2);
    MatMult(A, two, A);
    for (int i = 0; i < 16; i++) ret += A[i][0];
  } else {
    vector<vector<long long int> > A = powsum(base, r - 2);
    vector<vector<long long int> > B = powsum(base, l - 3);
    MatMult(A, two, A);
    MatMult(B, two, B);
    for (int i = 0; i < 16; i++) ret += A[i][0] - B[i][0];
  }
  return ret;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  for (int i = 0; i < 16; i++)
    for (int j = 0; j < 16; j++) {
      if (((i) / 4) != ((j) % 4)) continue;
      if ((((i) / 4) & 1) == (((i) % 4) & 1)) continue;
      if (j == 6 && i == 11) continue;
      if (j == 14 && i == 9) continue;
      base[i][j] = 1;
    }
  for (int i = 0; i < 16; i++) {
    I[i][i] = 1;
    if (((i) / 4) == ((i) % 4)) continue;
    if ((((i) / 4) & 1) == (((i) % 4) & 1)) continue;
    two[i][0] = 1;
  }
  long long int l, r;
  cin >> l >> r;
  long long int ans = 0;
  ans += getans(l, r) + getans(l / 2 + 1, (r - 1) / 2 + 1);
  ans = MOD(ans);
  long long int inv2 = (mod + 1) / 2;
  ans *= inv2;
  ans %= mod;
  cout << ans;
}
