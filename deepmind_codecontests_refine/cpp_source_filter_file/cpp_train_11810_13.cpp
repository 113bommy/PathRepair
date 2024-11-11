#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
int n, k, a[2005];
long long dp[2005][1 << 12];
int go(int msk, int nxt) {
  if (nxt > (msk)) return nxt;
  return msk + nxt;
}
long long solve(int idx, int msk) {
  if (idx == n) return msk >= k;
  long long &ret = dp[idx][msk];
  if (~ret) return ret;
  if (msk >= k)
    return a[idx] ? solve(idx + 1, msk) : 2 * solve(idx + 1, msk) % mod;
  ret = 0;
  if (a[idx] != 2) ret = (ret + solve(idx + 1, go(msk, 4))) % mod;
  if (a[idx] != 4) ret = (ret + solve(idx + 1, go(msk, 2))) % mod;
  return ret;
}
int main() {
  scanf("%d%d", &n, &k);
  k = 1 << k;
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  memset(dp, -1, sizeof dp);
  printf("%d\n", solve(0, 0));
  return 0;
}
