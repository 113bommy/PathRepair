#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 6;
int n, a[N], dp[N], loc[N];
vector<int> p, dv[N];
int main() {
  for (int i = 2; i < N; i++) {
    for (int j = 2; j * j <= i; j++)
      if (i % j == 0) {
        dv[i].push_back(j);
        if (j != i / j) dv[i].push_back(i / j);
      }
  }
  int ans = 0;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    dp[a[i]] = 1;
  }
  for (int i = 1; i <= n; i++) {
    for (auto j : dv[a[i]]) {
      dp[a[i]] = max(dp[a[i]], dp[j] + 1);
      ans = max(ans, dp[a[i]]);
    }
    for (auto j : dv[a[i]]) dp[j] = dp[a[i]];
  }
  cout << ans;
}
