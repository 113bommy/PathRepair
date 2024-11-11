#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const int MAXM = 200100;
int n, m;
pair<int, int> bus[MAXM];
map<int, int> mp;
int dp[MAXM];
int main() {
  cin >> n >> m;
  mp[0] = 1;
  for (int i = 0; i < m; i++) {
    cin >> bus[i].second >> bus[i].first;
    mp[bus[i].first] = 1;
    mp[bus[i].second] = 1;
  }
  int idx = 1;
  for (map<int, int>::iterator it = mp.begin(); it != mp.end(); it++)
    it->second = idx++;
  if (!mp.count(n)) {
    puts("0");
    return 0;
  }
  for (int i = 0; i < m; i++) {
    bus[i].first = mp[bus[i].first];
    bus[i].second = mp[bus[i].second];
  }
  sort(bus, bus + m);
  dp[1] = 1;
  int j = 0;
  for (int i = 2; i < idx; i++) {
    dp[i] = dp[i - 1];
    while (j < m && i == bus[j].first) {
      dp[i] = (dp[i] + dp[i - 1] - dp[bus[j].second - 1]) % MOD;
      if (dp[i] < 0) dp[i] += MOD;
      j++;
    }
  }
  int ans = (dp[idx - 1] - dp[idx - 2]) % MOD;
  if (ans < 0) ans += MOD;
  cout << ans << endl;
  return 0;
}
