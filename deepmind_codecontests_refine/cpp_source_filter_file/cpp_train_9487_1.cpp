#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1, ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
inline void write(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) write(x / 10);
  putchar(x % 10 + '0');
}
inline void writeln(long long x) {
  write(x);
  puts("");
}
const long long mod = 1e9 + 7, N = 4e7, M = 1e4 + 5;
long long ans = 1, n, m, cnt, dp[M][100], inv[100];
inline void init() {
  n = read();
  m = read();
  inv[0] = inv[1] = 1;
  for (long long i = 2; i < 100; i++)
    inv[i] = (mod - mod / i) * inv[mod % i] % mod;
}
inline void calc(long long x, long long tot) {
  x %= mod;
  for (long long i = 0; i <= m; i++) {
    for (long long j = 0; j <= tot; j++) {
      dp[i][j] = 0;
    }
  }
  dp[0][tot] = 1;
  for (long long i = 0; i < m; i++) {
    for (long long j = 0; j <= tot; j++) {
      for (long long k = 0; k <= j; k++) {
        dp[i + 1][k] = (dp[i + 1][k] + dp[i][j] * inv[j + 1] % mod) % mod;
      }
    }
  }
  long long sum = 0;
  for (long long i = 0, j = 1; i <= tot; i++) {
    sum = (sum + dp[m][i] * j % mod) % mod;
    j = j * x % mod;
  }
  ans = ans * sum % mod;
}
inline void solve() {
  for (long long i = 2; i * i < n; i++) {
    if (n % i == 0) {
      long long cnt = 0;
      while (n % i == 0) cnt++, n /= i;
      calc(i, cnt);
    }
  }
  if (n) calc(n, 1);
  writeln(ans);
}
signed main() {
  init();
  solve();
  return 0;
}
