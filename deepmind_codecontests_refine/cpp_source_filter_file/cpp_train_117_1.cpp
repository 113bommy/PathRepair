#include <bits/stdc++.h>
using namespace std;
long long dp[200005][10], dp2[6][2];
int main() {
  memset(dp, 0xcf, sizeof(dp));
  dp[0][0] = 0;
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    memset(dp2, 0xcf, sizeof(dp2));
    dp2[0][0] = 0;
    int k, c, d;
    scanf("%d", &k);
    vector<int> v[4];
    vector<pair<int, int> > v2;
    for (int j = 1; j <= k; j++) {
      scanf("%d%d", &c, &d);
      v[c].push_back(d);
    }
    for (int j = 1; j <= 3; j++) {
      sort(v[j].begin(), v[j].end());
      reverse(v[j].begin(), v[j].end());
      int s = (j == 1 ? 3 : 1);
      while (v[j].size() > s) v[j].pop_back();
    }
    for (int j = 1; j <= 3; j++)
      for (int k = 0; k < v[j].size(); k++) v2.push_back(make_pair(j, v[j][k]));
    do {
      int now = 3, cnt = 0;
      long long mx = 0, sum = 0;
      for (int j = 0; j < v2.size(); j++) {
        cnt++;
        if (now < v2[j].first) break;
        now -= v2[j].first;
        sum += v2[j].second;
        mx = max(mx, (long long)v2[j].second);
        dp2[cnt][0] = max(dp2[cnt][0], sum);
        dp2[cnt][1] = max(dp2[cnt][1], sum + mx);
      }
    } while (next_permutation(v2.begin(), v2.end()));
    for (int j = 0; j < 10; j++) {
      for (int k = 0; k <= 3; k++)
        dp[i][(j + k) % 10] = max(dp[i][(j + k) % 10],
                                  dp[i - 1][j] + dp2[k][j + k == 10 ? 1 : 0]);
    }
  }
  long long ans = 0;
  for (int j = 0; j < 10; j++) ans = max(ans, dp[n][j]);
  printf("%lld\n", ans);
  return 0;
}
