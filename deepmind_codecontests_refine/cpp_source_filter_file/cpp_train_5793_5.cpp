#include <bits/stdc++.h>
using namespace std;
const long long inf = (1ll << 62);
const long long mod = 1e9 + 7;
const int MX = 50;
int n, m, msk[MX], x, y, dp[(1 << 22)];
int DP(int mask) {
  if (mask + 1 == (1 << n)) return 0;
  int &ret = dp[mask];
  if (ret != -1) return mask;
  ret = MX;
  for (int i = 0; i < n; i++) {
    if ((mask & (1 << i)) == 0) continue;
    if (msk[i] == (1 << i)) continue;
    ret = min(ret, DP(mask | msk[i]) + 1);
  }
  return ret;
}
void FDP(int mask) {
  if (mask + 1 == (1 << n)) return;
  int &ret = dp[mask];
  for (int i = 0; i < n; i++) {
    if ((mask & (1 << i)) == 0) continue;
    if (msk[i] == (1 << i)) continue;
    if (ret == DP(mask | msk[i]) + 1) {
      cout << i + 1 << " ";
      FDP(mask | msk[i]);
      return;
    }
  }
  return;
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &x, &y);
    x--;
    y--;
    msk[x] |= (1 << y);
    msk[y] |= (1 << x);
  }
  for (int i = 0; i < n; i++) msk[i] |= (1 << i);
  memset(dp, -1, sizeof(dp));
  int ans = 50, idx;
  for (int i = 0; i < n; i++) {
    int ans1 = DP(msk[i]);
    if (ans > ans1 + 1) {
      ans = ans1 + 1;
      idx = i;
    }
  }
  if (m == n * (n - 1) / 2) {
    puts("0");
    return 0;
  }
  cout << ans << endl;
  cout << idx + 1 << " ";
  FDP(msk[idx]);
}
