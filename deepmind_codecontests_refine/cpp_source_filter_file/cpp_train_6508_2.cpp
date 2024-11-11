#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
struct Matrix {
  vector<vector<long long int>> a;
  int n;
  Matrix(int n) : n(n) { a.resize(n, vector<long long int>(n)); }
  Matrix operator*(const Matrix &b) {
    Matrix p(n);
    for (int i = 0; i < n; i++) {
      for (int k = 0; k < n; k++) {
        for (int j = 0; j < n; j++) {
          p.a[i][j] += (a[i][k] * b.a[k][j]) % mod;
          p.a[i][j] %= mod;
        }
      }
    }
    return p;
  }
};
int c[15];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, b, k, x;
  cin >> n >> b >> k >> x;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    a %= x;
    c[a]++;
  }
  vector<long long int> dp(x);
  dp[0] = 1ll;
  Matrix ans(x), a(x);
  for (int i = 0; i < x; i++) {
    for (int j = 0; j < x; j++) {
      int llego = (10 * i + j) % x;
      if (llego < 0) llego += x;
      llego %= x;
      a.a[llego][i] += c[j];
    }
  }
  for (int i = 0; i < x; i++) ans.a[i][i] = 1ll;
  while (b) {
    if (b & 1) ans = a * ans;
    b >>= 1;
    a = a * a;
  }
  vector<long long int> new_dp(x);
  for (int i = 0; i < x; i++) {
    for (int j = 0; j < x; j++) {
      int llego = (10 * i + j) % x;
      new_dp[llego] += (dp[i] * ans.a[llego][i]) % mod;
      new_dp[llego] %= mod;
    }
  }
  dp = new_dp;
  cout << dp[k] << '\n';
  return 0;
}
