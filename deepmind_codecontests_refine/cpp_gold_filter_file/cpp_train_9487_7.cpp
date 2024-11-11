#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 4;
const int MOD = 1e9 + 7;
const int K = 100;
int dp[N][K];
int vis[N][K], visid;
long long inv[K], pw[K];
long long p;
int k;
long long power(long long a, long long b) {
  long long x = 1, y = a;
  while (b > 0) {
    if (b & 1) {
      x = (x * y);
      if (x > MOD) x %= MOD;
    }
    y = y * y;
    if (y > MOD) y %= MOD;
    b >>= 1;
  }
  return x;
}
int solve(int idx, int j) {
  int &ret = dp[idx][j];
  if (vis[idx][j] == visid) return ret;
  vis[idx][j] = visid;
  if (idx == k) return ret = pw[j];
  ret = 0;
  for (int i = 0; i <= j; i++) {
    ret += solve(idx + 1, j - i) * inv[j + 1] % MOD;
    if (ret >= MOD) ret -= MOD;
  }
  return ret;
}
int main() {
  pw[0] = 1;
  for (int i = 1; i < K; i++) inv[i] = power(i, MOD - 2) % MOD;
  long long ans = 1;
  long long n;
  cin >> n >> k;
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      visid++;
      p = i;
      int cnt = 0;
      while (n % i == 0) {
        cnt++;
        n /= i;
      }
      for (int j = 1; j <= cnt; j++) pw[j] = 1LL * pw[j - 1] * i % MOD;
      ans = ans * solve(0, cnt) % MOD;
    }
  }
  if (n != 1) {
    p = n;
    pw[1] = n % MOD;
    visid++;
    ans = ans * solve(0, 1) % MOD;
  }
  cout << ans << "\n";
  return 0;
}
