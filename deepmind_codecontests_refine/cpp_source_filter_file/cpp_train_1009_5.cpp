#include <bits/stdc++.h>
using namespace std;
int n, k;
int cnt[100005], h[15], memo[5005][505];
int DP(int rem, int group) {
  if (group == 0 || rem == 0) {
    return 0;
  } else if (memo[rem][group] != -1) {
    return memo[rem][group];
  } else {
    int ret = 0;
    for (int i = 1; i <= min(k, rem); i++) {
      ret = max(ret, DP(rem - i, group - 1) + h[i]);
    }
    return memo[rem][group] = ret;
  }
}
int main() {
  int ans = 0;
  map<int, int> mp;
  scanf("%d %d", &n, &k);
  for (int i = 0, in; i < n * k; i++) {
    scanf("%d", &in);
    cnt[in]++;
  }
  for (int i = 0, in; i < n; i++) {
    scanf("%d", &in);
    mp[in]++;
  }
  for (int i = 1; i <= k; i++) {
    scanf("%d", h + i);
  }
  for (auto it = mp.begin(); it != mp.end(); it++) {
    memset(memo, -1, sizeof(memo));
    ans += DP(min(cnt[it->first], it->first * k), it->second);
  }
  printf("%d", ans);
  return 0;
}
