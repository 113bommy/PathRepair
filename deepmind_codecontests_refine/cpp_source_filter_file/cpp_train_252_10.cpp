#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
const int MOD = 1e9 + 7;
int dp[maxn];
int Pow2[maxn] = {1};
int main() {
  for (int i = 1; i <= 1000000; i++) Pow2[i] = (Pow2[i - 1] << 1) % MOD;
  int N;
  while (cin >> N) {
    memset(dp, 0, sizeof dp);
    for (int i = 1; i <= N; i++) {
      int t;
      scanf("%d", &t);
      dp[t]++;
    }
    for (int k = 0; k < 20; k++) {
      for (int i = 0; i <= 15; i++) {
        if (i & (1 << k)) {
          int t = i & (~(1 << k));
          dp[t] += dp[i];
        }
      }
    }
    long long ans = 0;
    for (int i = 0; i <= 1000000; i++) {
      int cnt = __builtin_popcount(i);
      if (cnt & 1)
        ans -= Pow2[dp[i]] - 1;
      else
        ans += Pow2[dp[i]] - 1;
      ans %= MOD;
    }
    ans = (ans + MOD) % MOD;
    cout << ans << endl;
  }
}
