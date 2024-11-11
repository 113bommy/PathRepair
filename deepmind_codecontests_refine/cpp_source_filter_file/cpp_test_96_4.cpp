#include <bits/stdc++.h>
using namespace std;
inline void in(long long& x) { scanf("%lld", &x); }
inline void in(int& x) { scanf("%d", &x); }
inline void in(double& x) { scanf("%lf", &x); }
inline void in(char& x) { x = getchar(); }
inline void in(char* x) { scanf("%s", x); }
inline void in() {}
template <class T, class... U>
inline void in(T& a, U&... b) {
  in(a);
  in(b...);
}
inline void out(const long long x) { printf("%lld", x); }
inline void out(const int x) { printf("%d", x); }
inline void out(const char x) { putchar(x); }
inline void out(const char* x) { printf("%s", x); }
inline void out() {}
template <class T, class... U>
inline void out(const T a, const U... b) {
  out(a);
  out(b...);
}
template <class... U>
inline void outl(const U... b) {
  out(b...);
  putchar('\n');
}
const long long INF = 0x3f3f3f3f3f3f3f3f;
const long long MOD = 998244353;
const long long N = 500 + 10;
long long n, x, dp[N][N], c[N][N];
long long qpow(long long a, long long b) {
  long long ans = 1;
  while (b > 0) {
    if (b & 1) (ans *= a) %= MOD;
    b >>= 1;
    (a *= a) %= MOD;
  }
  return ans;
}
int solve(long long T) {
  cin >> n >> x;
  dp[n][0] = 1;
  for (long long i = n; i >= 2; --i) {
    for (long long j = 0; j <= x - 1; ++j) {
      if (dp[i][j] <= 0) continue;
      long long nj = min(x, j + i - 1);
      for (long long k = 0; k <= i; ++k) {
        (dp[k][nj] +=
         (dp[i][j] * (c[i][k] * qpow(nj - j, i - k)) % MOD) % MOD) %= MOD;
      }
    }
  }
  long long ans = 0;
  for (long long i = 0; i <= x; ++i) (ans += dp[0][i]) %= MOD;
  outl(ans);
  return 0;
}
int main() {
  for (long long i = 0; i <= N - 1; ++i) {
    c[i][0] = c[i][i] = 1;
    for (long long j = 1; j <= i - 1; ++j) {
      c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
    }
  }
  solve(0);
  return 0;
}
