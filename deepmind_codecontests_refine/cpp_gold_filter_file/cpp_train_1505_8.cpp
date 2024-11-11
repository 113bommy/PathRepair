#include <bits/stdc++.h>
using namespace std;
const int MXN = 1000100;
const int INF = (int)1e9;
const long long LINF = (long long)1e18;
const int mod = 1000000007;
int p[MXN];
int dp[MXN];
pair<pair<int, int>, int> mx[MXN];
int main() {
  int n;
  scanf("%d", &n);
  int sz = 1;
  for (int i = (0); i < (n); i++) {
    int t;
    scanf("%d", &t);
    p[sz++] = t - 1;
    dp[sz - 1] = 1;
    for (int q = sz - 1; q; q = p[q]) {
      int pp = p[q];
      if (mx[pp].first.first < dp[q] || mx[pp].first.second == q)
        mx[pp].first = make_pair(dp[q], q);
      else
        mx[pp].second = dp[q];
      if (pp) {
        if (dp[pp] < max(mx[pp].first.first, mx[pp].second + 1))
          dp[pp] = max(mx[pp].first.first, mx[pp].second + 1);
        else
          break;
      } else
        dp[pp] = mx[pp].first.first;
    }
    printf("%d ", dp[0]);
  }
}
