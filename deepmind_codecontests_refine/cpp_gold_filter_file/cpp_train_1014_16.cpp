#include <bits/stdc++.h>
using namespace std;
int64_t mod = 1e9 + 7;
int64_t mod1 = 1e9 + 5;
int64_t power(int64_t a, int64_t b) {
  if (b == 0)
    return 1;
  else if (b % 2 == 0)
    return power(((((a) % mod) * ((a) % mod)) % mod), b / 2) % mod;
  else
    return (((a) % mod) *
            (power(((((a) % mod) * ((a) % mod)) % mod), b / 2) % mod)) %
           mod;
}
inline int64_t inverse(int64_t a, int64_t md) {
  a %= md;
  if (a < 0) a += md;
  int64_t b = md, u = 0, v = 1;
  while (a) {
    int64_t t = b / a;
    b -= t * a;
    swap(a, b);
    u -= t * v;
    swap(u, v);
  }
  assert(b == 1);
  if (u < 0) u += md;
  return u;
}
const int64_t ce = 1e9 + 7;
int64_t fast_mod(int64_t input) { return input < ce ? input : input % ce; }
int64_t fre[100001];
int64_t co[11];
int64_t n, k;
int64_t f[100001];
int64_t maxi;
int64_t dp[501][5001];
int64_t solve(int64_t i, int64_t rem) {
  if (rem == 0) return 0;
  if (i == maxi) return 0;
  int64_t &res = dp[i][rem];
  if (res != -1) return res;
  res = 0;
  for (int64_t j = 1; j <= min(rem, k); j++) {
    res = max(res, co[j] + solve(i + 1, rem - j));
  }
  return res;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> k;
  memset(fre, 0, sizeof(fre));
  for (int64_t i = 0; i < n * k; i++) {
    int64_t x;
    cin >> x;
    fre[x]++;
  }
  memset(f, 0, sizeof(f));
  for (int64_t i = 1; i <= n; i++) {
    int64_t s;
    cin >> s;
    f[s]++;
  }
  co[0] = 0;
  for (int64_t i = 1; i <= k; i++) {
    cin >> co[i];
  }
  memset(dp, -1, sizeof(dp));
  int64_t ans = 0;
  for (int64_t i = 1; i <= 100000; i++) {
    maxi = f[i];
    for (int64_t j = 0; j <= maxi; j++)
      for (int64_t k = 0; k <= fre[i]; k++) dp[j][k] = -1;
    ans += solve(0, fre[i]);
  }
  cout << ans << '\n';
}
