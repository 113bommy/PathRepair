#include <bits/stdc++.h>
const int MAXN = 50 + 10;
const int MOD = 1e9 + 7;
long long n;
int k;
namespace {
inline int add(int x) { return x >= MOD ? x - MOD : x; }
inline int sub(int x) { return x < 0 ? x + MOD : x; }
inline int mul(int x, int y) { return (long long)x * y % MOD; }
}  // namespace
namespace solver1 {
struct Matrix {
  int a[MAXN][MAXN];
  int n;
  void init() { memset(a, 0, sizeof a); }
  void set() {
    init();
    for (int i = 1; i <= n; i++) {
      a[i][i] = 1;
    }
  }
  Matrix operator*(const Matrix &rhs) const {
    Matrix ans;
    ans.n = n;
    static long long tmp[MAXN][MAXN];
    static const long long MODLL = (long long)MOD * MOD;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        tmp[i][j] = 0;
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int k = 1; k <= n; k++) {
        for (int j = 1; j <= n; j++) {
          tmp[i][j] += (long long)a[i][k] * rhs.a[k][j];
          if (tmp[i][j] >= MODLL) tmp[i][j] -= MODLL;
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        ans.a[i][j] = tmp[i][j] % MOD;
      }
    }
    return ans;
  }
};
Matrix f[80][MAXN], sump[80][MAXN], sums[80][MAXN];
void main() {
  static int num[MAXN], cnt = 0;
  while (n) {
    num[++cnt] = n % k;
    n /= k;
  }
  for (int i = 0; i < k; i++) {
    f[0][i].n = k + 1;
    f[0][i].init();
    for (int j = 1; j <= k + 1; j++) {
      f[0][i].a[j][j] = 1;
      f[0][i].a[i + 1][j] = 1;
    }
  }
  sump[0][0] = f[0][0];
  sums[0][k - 1] = f[0][k - 1];
  for (int i = 1; i < k; i++) {
    sump[0][i] = f[0][i] * sump[0][i - 1];
  }
  for (int i = k - 2; i >= 0; i--) {
    sums[0][i] = sums[0][i + 1] * f[0][i];
  }
  for (int i = 1; i < cnt; i++) {
    for (int j = 0; j < k; j++) {
      f[i][j] = j == 0 ? sums[i - 1][j] : sump[i - 1][j - 1] * sums[i - 1][j];
    }
    sump[i][0] = f[i][0];
    sums[i][k - 1] = f[i][k - 1];
    for (int j = 1; j < k; j++) {
      sump[i][j] = f[i][j] * sump[i][j - 1];
    }
    for (int j = k - 2; j >= 0; j--) {
      sums[i][j] = sums[i][j + 1] * f[i][j];
    }
  }
  Matrix ans;
  ans.n = k + 1;
  ans.set();
  int sum = 0;
  for (int i = cnt; i >= 1; i--) {
    for (int j = 0; j < num[i]; j++) {
      ans = f[i - 1][(sum + j) % k] * ans;
    }
    sum += num[i];
    sum %= k;
  }
  int res = 0;
  for (int i = 1; i <= k + 1; i++) {
    res = add(res + ans.a[i][k + 1]);
  }
  printf("%d\n", res);
}
}  // namespace solver1
int main() {
  scanf("%lld%d", &n, &k);
  solver1::main();
}
