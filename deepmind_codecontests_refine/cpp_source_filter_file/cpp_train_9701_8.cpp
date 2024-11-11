#include <bits/stdc++.h>
using namespace std;
multiset<long long> vals, mins;
long long dp[200005];
vector<long long> del[200005];
char s[200005];
int main() {
  int n, k;
  scanf("%d%d %s", &n, &k, s);
  dp[n] = 0;
  mins.insert(dp[n]);
  for (int i = n - 1; i >= 0; i--) {
    dp[i] = dp[i + 1] + i + 1;
    if (i + k + 2 <= n) mins.erase(mins.find(dp[i + k + 2]));
    for (auto v : del[i]) vals.erase(vals.find(v));
    if (!vals.empty()) dp[i] = min(dp[i], *vals.begin());
    if (s[i] == '1') {
      long long val = mins.empty() ? 0 : *mins.begin();
      val += 1ll * (i + 1);
      dp[i] = min(dp[i], val);
      vals.insert(val);
      if (i - k - 1 >= 0) del[i - k + 1].push_back(val);
    }
    mins.insert(dp[i]);
  }
  printf("%lld\n", dp[0]);
  return 0;
}
