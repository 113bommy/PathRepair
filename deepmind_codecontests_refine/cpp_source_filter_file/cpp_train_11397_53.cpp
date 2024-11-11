#include <bits/stdc++.h>
using namespace std;
int n, k;
long long m;
long long dp[1500][200][2];
long long ten[2000], ten2[2000];
long long solve(int pos, int mod, bool flag) {
  if (mod == 0 && flag) {
    long long ans = (pos == n) ? 1 : (9 * ten2[n - pos - 1]);
    return ans % m;
  }
  if (pos == n) return 0;
  if (dp[pos][mod][flag] != -1) return dp[pos][mod][flag];
  long long ans = 0;
  for (int i = 0; i <= 9; i++) {
    int nxt = (mod + (i * ten[pos])) % k;
    ans += solve(pos + 1, nxt, i != 0);
    ans %= m;
  }
  return dp[pos][mod][flag] = ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  ten[0] = 1;
  ten2[0] = 1;
  while (cin >> n >> k >> m) {
    memset(dp, -1, sizeof dp);
    for (int i = 1; i <= 1000; i++) {
      ten[i] = (ten[i - 1] * 10) % k;
      ten2[i] = (ten2[i - 1] * 10);
    }
    cout << solve(0, 0, 0) << endl;
  }
  return 0;
}
