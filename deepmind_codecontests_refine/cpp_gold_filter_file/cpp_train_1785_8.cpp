#include <bits/stdc++.h>
using namespace std;
inline int in() {
  int x;
  scanf("%d", &x);
  return x;
}
const int N = 1000 + 10;
const int MOD = 1e9 + 7;
const long double eps = 1e-12;
int n, m, l;
int fact[N * N], inv[N * N];
long long dp[N][N];
int power(int n, int f) {
  if (f == 0) return 1;
  if (f == 1) return n;
  long long x = power(n, f >> 1);
  x %= MOD;
  x = x * x;
  x %= MOD;
  if (f & 1) {
    long long s = x * n;
    s %= MOD;
    return s;
  }
  return (1LL * x) % MOD;
}
int choose(int n, int f) {
  if (f > n) cout << n << " :: " << f << endl;
  if (f == 0) return 1;
  if (n == f) return 1;
  long long iv = (1LL * inv[f] * inv[n - f]) % MOD;
  return (1LL * fact[n] * iv) % MOD;
}
int main() {
  fact[0] = 1;
  for (int i = 1; i < N * N; i++)
    fact[i] = (1LL * fact[i - 1] * i) % MOD, inv[i] = power(fact[i], MOD - 2);
  n = in(), m = in(), l = in();
  dp[1][1] = 1;
  for (int i = 2; i < N; i++)
    for (int j = 1; j <= i; j++)
      dp[i][j] = 1LL * j * (1LL * dp[i - 1][j - 1] + 1LL * dp[i - 1][j]),
      dp[i][j] %= MOD;
  if (m == 1) {
    cout << power(l, n) << endl;
    return 0;
  }
  if (m == 2) {
    long long ans = 0;
    for (int i = 1; i <= min(l, n); i++) {
      long long s = 0;
      s = (1LL * dp[n][i] * dp[n][i]);
      s %= MOD;
      s *= choose(l, i);
      s %= MOD;
      s *= choose(l, i);
      s %= MOD;
      ans = (ans + s) % MOD;
    }
    cout << ans;
    return 0;
  }
  long long ans = 0;
  for (int x = 1; x <= min(l, n); x++)
    for (int k = 0; k <= x; k++) {
      if (2 * x - k > l) continue;
      long long second = 1;
      second = 1LL * second * choose(l, x);
      second = 1LL * second * choose(x, k);
      second %= MOD;
      second = 1LL * second * choose(l - x, x - k);
      second %= MOD;
      second = 1LL * second * power(k, n * (m - 2));
      second %= MOD;
      second = 1LL * second * dp[n][x];
      second %= MOD;
      second = 1LL * second * dp[n][x];
      second %= MOD;
      ans += second;
      ans %= MOD;
    }
  cout << ans;
  return 0;
}
