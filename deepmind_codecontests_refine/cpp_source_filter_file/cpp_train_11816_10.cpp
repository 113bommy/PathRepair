#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
const int N = 400004;
int dp[N];
pair<int, int> b[N];
int fac[N], ifac[N], inv[N];
void prencr() {
  fac[0] = ifac[0] = inv[1] = 1;
  for (int i = 2; i < N; ++i)
    inv[i] = mod - 1LL * (mod / i) * inv[mod % i] % mod;
  for (int i = 1; i < N; ++i) {
    fac[i] = 1LL * i * fac[i - 1] % mod;
    ifac[i] = 1LL * inv[i] * ifac[i - 1] % mod;
  }
}
int C(int n, int r) {
  return (r >= 0 && n >= r) ? (1LL * fac[n] * ifac[n - r] % mod * ifac[r] % mod)
                            : 0;
}
int main() {
  prencr();
  int h, w, n;
  scanf("%d %d %d", &h, &w, &n);
  for (int i = 0; i < n; ++i) scanf("%d %d", &b[i].first, &b[i].second);
  b[n] = {h, w};
  sort(b, b + n + 1);
  for (int i = 0; i <= n; ++i) {
    int ur = b[i].first, uc = b[i].second;
    dp[i] = C(ur + uc - 2, ur - 1);
    for (int j = 0; j < i; ++j) {
      int vr = b[j].first, vc = b[j].second;
      dp[i] -= 1LL * dp[j] * C(ur - vr + uc - vc, uc - vc) % mod;
      if (dp[i] < mod) dp[j] += mod;
    }
  }
  printf("%d\n", dp[n]);
}
