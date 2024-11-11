#include <bits/stdc++.h>
using namespace std;
const int Mod = 1e9 + 7;
inline int FIX(long long a) { return (a % Mod + Mod) % Mod; }
int c[100 + 5];
long long dp[100 + 5];
struct Matrix {
  int n;
  long long a[150][150];
  Matrix(int _n) {
    n = _n;
    memset(a, 0, sizeof(a));
  }
  void init() {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (j != i)
          a[i][j] = 0;
        else
          a[i][j] = 1;
      }
    }
    return;
  }
  void clear() { memset(a, 0, sizeof(a)); }
  void assign(int i, int j, long long v) {
    a[i][j] = v % Mod;
    return;
  }
  Matrix operator*(const Matrix &T) {
    Matrix tmp(T.n);
    tmp.clear();
    for (int k = 1; k <= n; k++) {
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
          tmp.a[i][j] += a[i][k] * T.a[k][j];
          tmp.a[i][j] %= Mod;
        }
      }
    }
    return tmp;
  }
};
Matrix MatrixPowMod(Matrix &M, int n) {
  int nn = M.n;
  Matrix ret(nn);
  ret.init();
  while (n > 0) {
    if (n & 1) ret = ret * M;
    M = M * M;
    n >>= 1;
  }
  return ret;
}
int main() {
  int n, x;
  scanf("%d %d", &n, &x);
  for (int i = 1; i <= n; i++) {
    int tmp;
    scanf("%d", &tmp);
    c[tmp]++;
  }
  if (x <= 100) {
    dp[0] = 1;
    for (int i = 1; i <= x; i++) {
      for (int j = 1; j <= i; j++) {
        (dp[i] += dp[i - j] * c[j] % Mod) %= Mod;
      }
    }
    long long ret = 0;
    for (int i = 0; i <= x; i++) (ret += dp[i]) %= Mod;
    cout << ret << endl;
  } else {
    dp[0] = 1;
    long long sum = 1;
    for (int i = 1; i <= 100; i++) {
      for (int j = 1; j <= i; j++) {
        (dp[i] += dp[i - j] * c[j] % Mod) %= Mod;
      }
      (sum += dp[i]) %= Mod;
    }
    long long vec[105];
    for (int i = 1; i <= 100; i++) vec[i] = dp[i];
    vec[101] = sum;
    Matrix t(101);
    for (int i = 1; i < 100; i++) {
      t.assign(i + 1, i, 1);
    }
    for (int i = 1; i <= 100; i++) {
      t.assign(i, 100, c[101 - i]);
    }
    for (int i = 1; i < 101; i++) {
      t.assign(1, 101, c[101 - i]);
    }
    t.assign(101, 101, 1);
    Matrix ret = MatrixPowMod(t, x - 100);
    long long ans = 0;
    for (int i = 1; i <= 101; i++) {
      ans = ans + ret.a[i][101] * vec[i] % Mod;
      ans %= Mod;
    }
    cout << ans << endl;
  }
  return 0;
}
