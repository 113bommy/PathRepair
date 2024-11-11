#include <bits/stdc++.h>
using namespace std;
const long long MXN = 5e3 + 10;
const long long Mod = 998244353;
long long power(long long a, long long b) {
  return (!b ? 1 : power(a * a % Mod, b / 2) * (b & 1LL ? a : 1) % Mod);
}
long long inv(long long x) { return power(x, Mod - 2); }
void mkay(long long& x) {
  if (x >= Mod) x -= Mod;
}
long long n, ans, now;
long long F[MXN], I[MXN], dp[MXN][MXN];
long long nCr(long long n, long long r) {
  if (r < 0 || r > n) return 0;
  return F[n] * I[r] % Mod * I[n - r] % Mod;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  F[0] = I[0] = 1;
  for (int i = 1; i < MXN; i++) F[i] = F[i - 1] * i % Mod;
  I[MXN - 1] = inv(F[MXN - 1]);
  for (int i = MXN - 2; i; i--) I[i] = I[i + 1] * (i + 1) % Mod;
  cin >> n;
  dp[0][0] = 1;
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= n; j++) {
      dp[i][j] = j * dp[i - 1][j] + (i - j + 1) * dp[i - 1][j - 1];
      dp[i][j] %= Mod;
    }
  }
  for (int i = 1; i <= n; i++) {
    ans = 0;
    for (int y = i; y <= n; y++) {
      ans += dp[y][i] * I[y] % Mod;
      mkay(ans);
    }
    ans = F[n] * ans % Mod;
    cout << ans << ' ';
  }
  return 0;
}
