#include <bits/stdc++.h>
using namespace std;
const int N = 13 * 17, Mod = 1e9 + 7;
struct Matrix {
  int n, m, A[N][N];
  inline Matrix(int _n, int _m) : n(_n), m(_m) { memset(A, 0, sizeof(A)); }
  inline Matrix operator*(Matrix &X) {
    Matrix R(n, X.m);
    for (int i = 0; i < n; i++)
      for (int k = i; k < m; k++)
        for (int j = k; j < X.m; j++)
          R[i][j] = (R[i][j] + 1LL * A[i][k] * X[k][j]) % Mod;
    return R;
  }
  inline Matrix operator^(long long pw) {
    Matrix R(n, n), T = *this;
    for (int i = 0; i < n; i++) R.A[i][i] = 1;
    for (; pw; pw >>= 1, T = T * T)
      if (pw & 1) R = R * T;
    return R;
  }
  inline int *operator[](int id) { return A[id]; }
};
long long int n;
int m;
int k;
const long long int MOD2 = 4LL * 1000000007LL * 1000000007LL;
int dp[14][1 << 4];
int tmp[14][1 << 14];
int mxt;
inline int id(int a, int b) {
  mxt = max(mxt, (a << m) + b + 1);
  return (a << m) + b;
}
int main() {
  cin >> n >> k >> m;
  Matrix bt((k + 1) << m, (k + 1) << m);
  for (int i2 = n; i2 >= n; i2--) {
    int cnt = 0;
    for (int i = 0; i <= k; i++) {
      for (int j = 0; j < (1 << m); j++) {
        int ava = 0;
        for (int k = 0; k < m; k++) {
          if ((j >> k) & 1) {
            ava++;
          }
        }
        ava++;
        int wa = ((j << 1) & ((1 << m) - 1));
        bt[id(i, wa)][id(i, j)] = 1;
        wa++;
        if (i + 1 <= k) {
          bt[id(i + 1, wa)][id(i, j)] = ava;
        }
      }
    }
  }
  bt = bt ^ n;
  long long int ans = 0;
  for (int j = 0; j < (1 << m); j++) {
    ans += bt[id(k, j)][0];
    if (ans >= MOD2) ans -= MOD2;
  }
  ans %= 1000000007LL;
  printf("%lld\n", ans);
  return 0;
}
