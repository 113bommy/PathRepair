#include <bits/stdc++.h>
using namespace std;
const int Max = 3.6e3 + 5, Mod = 998244353;
int w, h, n, dp[Max][Max];
long long Fact[Max], invFact[Max], rr[Max], cc[Max];
bool r[Max], c[Max];
long long fp(long long x, long long p) {
  if (!p) return 1;
  long long y = fp(x, p >> 1);
  y = y * y % Mod;
  if (p & 1) y = y * x % Mod;
  return y;
}
long long C(long long N, long long K) {
  if (N < 0 || N - K < 0 || K < 0) return 0;
  return Fact[N] * invFact[N - K] % Mod * invFact[K] % Mod;
}
int main() {
  Fact[0] = invFact[0] = 1;
  for (int i = 1; i < Max; i++) {
    Fact[i] = i * Fact[i - 1] % Mod;
    invFact[i] = fp(Fact[i], Mod - 2);
  }
  cin >> h >> w >> n;
  for (int i = 0; i < 2 * n; i++) {
    int x, y;
    cin >> x >> y;
    r[x] = c[y] = 1;
  }
  dp[0][0] = 1;
  for (int i = 1; i <= h; i++)
    for (int j = 0; j <= w; j++) {
      dp[i][j] = dp[i - 1][j];
      if (i > 1 && j > 0 && r[i] + r[i - 1] == 0)
        dp[i][j] = (dp[i][j] + dp[i - 2][j - 1]) % Mod;
    }
  for (int i = 0; i <= w; i++) rr[i] = dp[h][i] * Fact[i] % Mod;
  for (int i = 1; i <= w; i++)
    for (int j = 0; j <= h; j++) {
      dp[i][j] = dp[i - 1][j];
      if (i > 1 && j > 0 && c[i] + c[i - 1] == 0)
        dp[i][j] = (dp[i][j] + dp[i - 2][j - 1]) % Mod;
    }
  for (int i = 0; i < h; i++) cc[i] = dp[w][i] * Fact[i] % Mod;
  long long ans = 0;
  int hh = 0, ww = 0;
  for (int i = 1; i <= h; i++) hh += !r[i];
  for (int j = 1; j <= w; j++) ww += !c[j];
  for (int i = 0; i <= h; i++)
    for (int j = 0; j <= w; j++, ans %= Mod)
      ans +=
          cc[i] * rr[j] % Mod * C(hh - 2 * j, i) % Mod * C(ww - 2 * i, j) % Mod;
  cout << ans << '\n';
  return 0;
}
