#include <bits/stdc++.h>
using namespace std;
ifstream fin("in.in");
ofstream fout("out.out");
const int N = 1e6 + 10;
int n;
long long t1, t2, mod, a[N], x, y;
inline void mul(long long x[2][2], long long y[2][2], long long r[2][2]) {
  long long ret[2][2] = {0, 0, 0, 0};
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++)
      for (int k = 0; k < 2; k++) {
        ret[i][j] += (x[i][k] * y[k][j]) % mod;
        ret[i][j] %= mod;
      }
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++) r[i][j] = ret[i][j];
}
inline void calc(long long t, long long mat[2][2], long long res[2][2]) {
  res[0][0] = res[1][1] = 1;
  res[1][0] = res[0][1] = 0;
  while (t) {
    if (t & 1) mul(res, mat, res);
    t >>= 1;
    mul(mat, mat, mat);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> t1 >> t2 >> mod;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (!i || i == n - 1)
      x = (x + a[i]) % mod;
    else
      y = (y + a[i]) % mod;
  }
  if (n == 1) return (cout << a[0] % mod), 0;
  long long mat[2][2] = {{3, 0}, {-1, 1}}, res[2][2];
  calc(t1, mat, res);
  long long s = (x + y) * res[0][0] % mod;
  s = (s + x * res[1][0]) % mod, s = (s + mod) % mod;
  mat[0][0] = mat[0][1] = mat[1][0] = 1;
  mat[1][1] = 0;
  calc(t1, mat, res);
  x = (a[0] + (a[n - 2] * res[1][0] % mod) + (a[n - 1] * res[0][0] % mod)) %
      mod;
  y = (s - x + mod) % mod;
  mat[0][0] = +3, mat[0][1] = 0;
  mat[1][0] = -1, mat[1][1] = 1;
  calc(t2, mat, res);
  s = (x + y) * res[0][0] % mod;
  s = (s + x * res[1][0]) % mod, s = (s + mod) % mod;
  cout << s << endl;
  return 0;
}
