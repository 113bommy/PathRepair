#include <bits/stdc++.h>
using namespace std;
const int DIM = 3009;
const int CNS = 1509;
const int MOD = 1000000007;
const int dx[8] = {-1, 1, 2, 2, 1, -1, -2, -2};
const int dy[8] = {2, 2, 1, -1, -2, -2, -1, 1};
int dp[DIM][DIM], cnt[DIM];
deque<pair<int, int>> que;
int main(void) {
  long long k;
  int m;
  cin >> k >> m;
  for (int i = 1; i <= m; ++i) {
    int x, y;
    cin >> x >> y;
    dp[x + CNS][y + CNS] = -1;
  }
  dp[CNS][CNS] = 1;
  que.push_back(make_pair(CNS, CNS));
  for (; que.size(); que.pop_front()) {
    pair<int, int> cp = que.front();
    ++cnt[dp[cp.first][cp.second] - 1];
    if (dp[cp.first][cp.second] - 1 == min(k, 500LL)) continue;
    for (int d = 0; d <= 7; ++d) {
      pair<int, int> np = make_pair(cp.first + dx[d], cp.second + dy[d]);
      if (dp[np.first][np.second] == 0) {
        dp[np.first][np.second] = dp[cp.first][cp.second] + 1;
        que.push_back(np);
      }
    }
  }
  int ans = 0;
  if (k <= 500) {
    for (int i = 0; i <= k; ++i) ans += cnt[i];
  } else {
    for (int i = 0; i <= 499; ++i) ans += cnt[i];
    k -= 499;
    long long v1 = k, v2 = k - 1;
    ((k & 1) ? v2 : v1) /= 2;
    ans = ((v1 % MOD) * (v2 % MOD) % MOD * (cnt[500] - cnt[499]) % MOD +
           k % MOD * cnt[500] % MOD + ans) %
          MOD;
  }
  cout << ans << endl;
  return 0;
}
