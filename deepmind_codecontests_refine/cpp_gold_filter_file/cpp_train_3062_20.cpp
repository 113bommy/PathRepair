#include <bits/stdc++.h>
using namespace std;
vector<int> v[100010];
int use[800 + 5], dp2[800 + 5], dp[800 + 5], up[800 + 5];
void cal(int first) {
  int i;
  for (i = 0; i < 800; i++) use[i] = 0;
  for (i = 0; i < v[first].size(); i++) use[v[first][i]] = 1;
  for (i = 0; i < 800; i++) dp2[i] = 2000000007;
  int cost = 0;
  for (i = 800 - 1; i >= 0; i--) {
    up[i + 1] = cost;
    int tmp = dp[max(i - 1, 0)];
    if (i && tmp < dp2[i]) dp2[i] = tmp;
    tmp += cost;
    if (i > 0) tmp += i * (i + 1) / 2 + 2;
    if (tmp < dp2[0]) dp2[0] = tmp;
    if (use[i]) cost += 3;
  }
  for (i = 0; i < 800; i++) dp[i] = dp2[i];
  for (i = 2; i < 800; i++) dp[i] = min(dp[i], dp[i - 1]);
  for (i = 1; i < 800; i++) dp[i] += up[i + 1], dp[i] = min(dp[i], dp[i - 1]);
}
int main() {
  int i, j, m, k, T, n;
  while (~scanf("%d%d", &n, &k)) {
    int ans = 0;
    for (i = 0; i < k; i++) {
      int r, c;
      scanf("%d%d", &r, &c);
      int first = c - 1;
      int second = n - r + 1;
      if (second < 800)
        v[first].push_back(second);
      else
        ans += 3;
    }
    for (i = n - 1; i >= 0; i--) cal(i);
    printf("%d\n", dp[0] + ans);
  }
  return 0;
}
