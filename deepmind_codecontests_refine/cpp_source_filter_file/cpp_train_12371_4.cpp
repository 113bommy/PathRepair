#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    a[x] ^= z;
    a[y] ^= z;
  }
  vector<int> cnt(16);
  for (int i = 0; i < n; i++) {
    ++cnt[a[i]];
  }
  int res = 0;
  int have = 0;
  for (int i = 1; i < 16; i++) {
    res += cnt[i] / 2;
    cnt[i] &= 1;
    have |= (cnt[i] << i);
  }
  vector<bool> ok(1 << 16);
  for (int mask = 0; mask < (1 << 16); mask++) {
    int here = 0;
    for (int i = 0; i < 16; i++) {
      if ((mask >> i) & 1) {
        here ^= i;
      }
    }
    ok[mask] = (here == 0);
  }
  vector<int> dp(1 << 16);
  for (int mask = 1; mask < (1 << 16); mask++) {
    if (mask & 1) continue;
    for (int smsk = mask; smsk > 0; smsk = (smsk - 1) & mask) {
      if (ok[smsk]) {
        dp[mask] = max(dp[mask], dp[mask ^ smsk] + 1);
      }
    }
  }
  cout << res + __builtin_popcount(have) - dp[have] << endl;
  return 0;
}
