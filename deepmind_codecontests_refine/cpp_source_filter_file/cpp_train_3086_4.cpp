#include <bits/stdc++.h>
using namespace std;
const int N = 205;
template <typename T>
inline void read(T &AKNOI) {
  T x = 0, flag = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') flag = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  AKNOI = flag * x;
}
namespace ModCalculator {
long long MOD;
inline void Inc(long long &x, long long y) {
  x += y;
  if (x >= MOD) x -= MOD;
}
inline void Dec(long long &x, long long y) {
  x -= y;
  if (x < 0) x += MOD;
}
inline long long Add(long long x, long long y) {
  Inc(x, y);
  return x;
}
inline long long Sub(long long x, long long y) {
  Dec(x, y);
  return x;
}
inline int Mul(long long x, long long y) { return x * y % MOD; }
}  // namespace ModCalculator
using namespace ModCalculator;
int n, d;
long long C[N][N], dp[N][N], sum[N], ans;
void init() {
  read(n);
  read(d);
  read(MOD);
  for (int i = 0; i <= n; ++i) {
    C[i][0] = 1;
    for (int j = 1; j <= i; ++j) {
      C[i][j] = Add(C[i - 1][j], C[i - 1][j - 1]);
    }
  }
}
void solve() {
  dp[1][0] = sum[1] = 1;
  for (int i = 2; i <= n; ++i) {
    for (int j = 1; j <= d; ++j) {
      for (int k = 1; k < i; ++k) {
        Inc(dp[i][j], Mul(C[i - 2][k - 1], Mul(sum[k], dp[i - k][j - 1])));
      }
      if (j < d) Inc(sum[i], dp[i][j]);
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= d; ++j) {
      for (int k = 0; k + j <= d; ++k) {
        if (k == 1) continue;
        Inc(ans, Mul(dp[i][j], dp[n - i + 1][k]));
      }
    }
  }
  printf("%lld\n", Mul(ans, 2LL * n * (n - 1)));
}
int main() {
  init();
  solve();
  return 0;
}
