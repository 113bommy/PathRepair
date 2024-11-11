#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > P;
int n, m, c0, d0, ans;
int dp[1009 * 2];
int main() {
  scanf("%d %d %d %d", &n, &m, &c0, &d0);
  for (int i = 0; i < m; i++) {
    int ai, bi, ci, di;
    scanf("%d %d %d %d", &ai, &bi, &ci, &di);
    for (int j = 0; j < (n / ci < ai / bi ? n / ci : ai / bi); j++)
      P.push_back(make_pair(ci, di));
  }
  for (int i = 0; i < n / c0; i++) P.push_back(make_pair(c0, d0));
  memset(dp, -1, sizeof dp);
  dp[0] = 0;
  for (__typeof((P).begin()) i = (P).begin(); i != (P).end(); i++) {
    int dou = i->first, pr = i->second;
    for (int i = n; i >= 0; i--)
      if (dp[i] != -1) {
        if (dp[i + dou] == -1)
          dp[i + dou] = dp[i] + pr;
        else
          dp[i + dou] = (dp[i + dou] > dp[i] + pr ? dp[i + dou] : dp[i] + pr);
        if (i + dou <= n) ans = (ans > dp[i + dou] ? ans : dp[i + dou]);
      }
  }
  printf("%d\n", ans);
}
