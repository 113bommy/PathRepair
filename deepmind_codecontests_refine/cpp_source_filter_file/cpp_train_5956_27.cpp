#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 5, mod = 998244353;
long long n, a[N], k, dp[N][N][2];
long long sol(int i, int dif, int bit) {
  if (i == n) return (dif > 0 && !bit);
  long long &ret = dp[i][dif][bit];
  if (ret != -1) return ret;
  int j = (i + 1) % n;
  if (a[i] == a[j])
    ret = (n * sol(i + 1, dif, bit)) % mod;
  else {
    int dif1 = dif - 1, bit1 = bit;
    if (dif1 < 0) dif1 = abs(dif1), bit1 = 1 - bit1;
    ret =
        (((n - 2) * sol(i + 1, dif, bit)) % mod + sol(i + 1, dif1, bit1)) % mod;
    ret += sol(i + 1, dif + 1, bit), ret %= mod;
  }
  return ret;
}
int main() {
  memset(dp, -1, sizeof dp);
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  cout << sol(0, 0, 0) << endl;
}
