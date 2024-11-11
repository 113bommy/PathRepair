#include <bits/stdc++.h>
using namespace std;
void file() {}
int tc;
const int N = 1e5 + 5, M = 2e6 + 5, MOD = 998244353, OO = 1e9 + 7;
const long long INF = 1e18;
void solve(int tc) {
  int n, d;
  scanf("%d %d", &n, &d);
  std::vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &a[i].first, &a[i].second);
  }
  sort((a).begin(), (a).end());
  std::vector<long long> dp(n);
  dp[0] = a[0].second;
  long long ans = 0;
  for (int i = 1; i < n; i++) dp[i] = dp[i - 1] + a[i].second;
  for (int i = 0; i < n; i++) {
    auto j = upper_bound((a).begin(), (a).end(),
                         make_pair(a[i].first + d - 1, 1000000000)) -
             a.begin();
    ans = max(ans, i ? dp[j - 1] - dp[i - 1] : dp[j - 1]);
  }
  printf("%lld\n", ans);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  file();
  int tc = 1;
  for (int i = 1; i <= tc; i++) solve(i);
}
