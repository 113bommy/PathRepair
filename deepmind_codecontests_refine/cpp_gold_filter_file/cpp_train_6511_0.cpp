#include <bits/stdc++.h>
const int MAX_N = (int)3e6 + 5;
const int mod = (int)1e9 + 7;
using namespace std;
int n;
long long len;
long long a[105];
inline void add(int &a, const int &b) {
  a += b;
  if (a >= mod) a -= mod;
}
struct matrix {
  int n, m, a[105][105];
  matrix() {}
  matrix(int _n, int _m) {
    n = _n, m = _m;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) a[i][j] = 0;
  }
  void apply() {
    assert(n == m);
    for (int i = 0; i < n; i++) a[i][i] = 1;
  }
  matrix operator*(const matrix &b) {
    assert(m == b.n);
    matrix res = matrix(n, b.m);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < b.m; j++)
        for (int k = 0; k < m; k++)
          add(res.a[i][j], 1ll * a[i][k] * b.a[k][j] % mod);
    return res;
  }
};
int dp[105][105];
int main() {
  ios_base ::sync_with_stdio(NULL), cin.tie(NULL), cout.tie(NULL);
  cin >> n >> len;
  for (int i = 0; i < n; i++) cin >> a[i];
  matrix first = matrix(1, n);
  for (int i = 0; i < n; i++) first.a[0][i] = 1;
  len--;
  matrix second = matrix(n, n);
  second.apply();
  matrix t = matrix(n, n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (__builtin_popcountll(a[i] ^ a[j]) % 3 == 0) t.a[i][j] = 1;
  while (len) {
    if (len & 1) second = second * t;
    t = t * t;
    len >>= 1;
  }
  first = first * second;
  int ans = 0;
  for (int i = 0; i < n; i++) add(ans, first.a[0][i]);
  cout << ans;
  return 0;
}
