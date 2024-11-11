#include <bits/stdc++.h>
using namespace std;
long long m, n, mod = 1000000009;
vector<vector<long long>> multiply(vector<vector<long long>> a,
                                   vector<vector<long long>> b) {
  vector<vector<long long>> q(m);
  for (int i = 0; i < m; i++) {
    q[i].resize(m);
    for (int j = 0; j < m; j++)
      for (int k = 0; k < m; k++) q[i][j] = (q[i][j] + a[i][k] * b[k][j]) % mod;
  }
  return q;
}
vector<vector<long long>> ex(vector<vector<long long>> x, long long b) {
  vector<vector<long long>> res(m);
  for (int i = 0; i < m; i++) {
    res[i].resize(m);
    res[i][i] = 1;
  }
  while (b > 0) {
    if (b & 1) res = multiply(res, x);
    x = multiply(x, x);
    b >>= 1;
  }
  return res;
}
int main() {
  cin >> n >> m;
  vector<vector<long long>> c(m), d;
  c[0].resize(m);
  c[0][0] = c[0][m - 1] = 1;
  for (int i = 1; i < m; i++) {
    c[i].resize(m);
    c[i][i - 1] = 1;
  }
  c = ex(c, n - m + 1);
  long long ans = 0;
  for (int i = 0; i < m; i++) ans = (ans + c[0][i]) % mod;
  cout << ans;
}
