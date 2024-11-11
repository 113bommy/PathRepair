#include <bits/stdc++.h>
using namespace std;
const int N = 301000;
const int MOD = 998244353;
const int M = 12;
const char c[6] = {'A', 'O', 'X', 'a', 'o', 'x'};
int n, m;
int a[N];
int cnt[N];
int f[1 << M][1 << M];
int dp[2][1 << M];
int w;
int num[N];
string s;
int main() {
  for (int i = 0; i < 6; i++) num[c[i]] = i;
  scanf("%d%d%d", &w, &n, &m);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (int i = 0; i < n; i++) cnt[a[i]]++;
  for (int mask2 = 0; mask2 < (1 << w); mask2++) {
    int cur = 0;
    for (int mask1 = 0; mask1 < (1 << w); mask1++) dp[cur][mask1] = 0;
    for (int mask1 = 0; mask1 < (1 << w); mask1++) dp[cur][mask1] = cnt[mask1];
    for (int i = 0; i < w; i++) {
      cur ^= 1;
      for (int mask1 = 0; mask1 < (1 << w); mask1++) dp[cur][mask1] = 0;
      for (int mask1 = 0; mask1 < (1 << w); mask1++) {
        if (mask2 & (1 << i))
          dp[cur][mask1] = dp[cur ^ 1][mask1];
        else
          dp[cur][mask1] = dp[cur ^ 1][mask1] + dp[cur ^ 1][mask1 ^ (1 << i)];
      }
    }
    for (int mask1 = 0; mask1 < (1 << w); mask1++) {
      f[mask1][mask2] = dp[cur][mask1];
    }
  }
  int fmask = (1 << w) - 1;
  for (int i = 1; i <= m; i++) {
    int msk[6] = {0, 0, 0, 0, 0, 0};
    cin >> s;
    reverse(s.begin(), s.end());
    for (int j = 0; j < w; j++) msk[num[s[j]]] |= (1 << j);
    long long ans = 0;
    for (int mask = 0; mask < (1 << w); mask++) {
      int mask1 = 0, mask2 = 0;
      if (msk[1] & mask) continue;
      if (msk[3] & (fmask ^ mask)) continue;
      mask2 |= msk[2];
      mask2 |= msk[5];
      mask1 |= (msk[2] & mask);
      mask1 |= (msk[5] & (msk[5] ^ mask));
      mask2 |= msk[1];
      mask2 |= msk[3];
      mask1 |= msk[3];
      mask2 |= (msk[0] & mask);
      mask2 |= (msk[4] & (fmask ^ mask));
      mask1 |= msk[4];
      ans += 1ll * cnt[mask] * f[mask1][mask2];
    }
    printf("%I64d\n", ans);
  }
  return 0;
}
