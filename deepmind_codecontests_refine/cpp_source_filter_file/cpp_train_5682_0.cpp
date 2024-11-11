#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll B = 50;
ll dp[2][B + 1][B + B + 1];
ll solve(ll sum, ll bits, ll dmax, ll emax) {
  ll lastbit = 1;
  while ((1LL << lastbit) <= sum) ++lastbit;
  if (sum > (1LL << (dmax + 1)) + (1LL << (emax + 1LL)) - 2LL) return 0LL;
  for (int b = 0; b <= bits; ++b) dp[0][0][b] = dp[1][0][b] = 0;
  dp[0][0][0] = 1;
  for (int b = 1; b < lastbit; ++b) {
    sum >>= 1;
    int s = 0, i = sum & 1, j = 1 ^ sum & 1;
    for (int bt = 0; bt <= bits; ++bt) {
      dp[0][b][bt] = dp[i][b - 1][bt];
      dp[1][b][bt] = 0;
      if (bt > 0 && b <= dmax) dp[j][b][bt] += dp[j][b - 1][bt - 1];
      if (bt > 0 && b <= emax) dp[j][b][bt] += dp[j][b - 1][bt - 1];
      if (bt > 1 && b <= dmax && b <= emax)
        dp[1][b][bt] += dp[i][b - 1][bt - 2];
      s += dp[0][b][bt] + dp[1][b][bt];
    }
    if (s == 0) return 0LL;
  }
  ll r = dp[0][lastbit - 1][bits];
  return r;
}
int main() {
  ll s, ans = 0;
  cin >> s;
  for (ll d = 1; d <= B; ++d)
    for (ll e = 1; e <= B; ++e) {
      ll G = ((1LL << d) + (1LL << e) - 3LL);
      ll x = s / G;
      if (x < 1) break;
      ll r = s - x * G;
      r -= ((1LL << (e - 1)) - 1LL);
      if (r < 0) continue;
      if (r > (1LL << d) + (1LL << e) - d - e - 2LL) continue;
      for (ll bits = r % 2; bits < max(2LL, d + e - 2LL); bits += 2)
        ans += solve(r + bits, bits, d - 2, e - 2);
    }
  cout << ans << endl;
  return 0;
}
