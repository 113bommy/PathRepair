#include <bits/stdc++.h>
using namespace std;
int n, y, m, ls[16], pref[16];
long long dp[1 << 16];
long long count() {
  fill(dp, dp + (1 << n), 0);
  dp[0] = 1;
  for (int mask = 0; mask < (1 << n); ++mask) {
    int cnt = 0, tmp = mask;
    while (tmp > 0) {
      if (tmp & 1 == 1) cnt++;
      tmp /= 2;
    }
    for (int i = 0; i < n; i++)
      if ((pref[i] == -1 || pref[i] == cnt - 1) && ((mask & (1 << i)) != 0) &&
          ((mask & ls[i]) == 0))
        dp[mask] += dp[mask - (1 << i)];
  }
  return dp[(1 << n) - 1];
}
int main() {
  cin >> n >> y >> m;
  y -= 2000;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    ls[u - 1] |= 1 << (v - 1);
  }
  fill(pref, pref + n, -1);
  for (int i = 0; i < n; i++) {
    for (;;) {
      pref[i]++;
      if (pref[i] == n) {
        cout << "The times have changed" << endl;
        return 0;
      }
      long long tmp = count();
      if (tmp < y)
        y -= tmp;
      else
        break;
    }
  }
  for (int i = 0; i < n; i++) cout << pref[i] + 1 << " ";
  cout << endl;
  return 0;
}
