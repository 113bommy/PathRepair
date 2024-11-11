#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
long long dp[N];
int main() {
  iostream::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<int> ids;
  ids.push_back(-N);
  for (int i = 0; i < n; i++)
    if (s[i] == '1') ids.push_back(i);
  ids.push_back(N);
  int l = 0, r = 1;
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') r++;
    while (i - ids[l] > k) l++;
    dp[i + 1] = (long long)1 << 60;
    if (l < r)
      dp[i + 1] = ids[l] + 1 + dp[max(ids[l] - k, 0)];
    else if (ids[r] - i <= k)
      dp[i + 1] = ids[r] + 1 + dp[max(ids[r] - k, 0)];
    dp[i + 1] = min(dp[i + 1], dp[i] + i + 1);
  }
  cout << dp[n] << endl;
}
