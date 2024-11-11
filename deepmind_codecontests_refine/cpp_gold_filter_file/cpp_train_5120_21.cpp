#include <bits/stdc++.h>
using namespace std;
struct node {
  long long x, y;
};
vector<node> a, b;
bool cmp1(const node& lhs, const node& rhs) { return lhs.x < rhs.x; }
bool cmp2(const node& lhs, const node& rhs) {
  return lhs.x + lhs.y > rhs.x + rhs.y;
}
long long n, r;
const long long maxn = 6e4 + 10;
long long dp[maxn];
signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  cin >> n >> r;
  for (long long i = 1; i <= n; ++i) {
    long long x, y;
    cin >> x >> y;
    if (y <= 0)
      b.push_back(node{x, y});
    else
      a.push_back(node{x, y});
  }
  sort(a.begin(), a.end(), cmp1);
  sort(b.begin(), b.end(), cmp2);
  bool flag = true;
  long long ans = 0;
  for (long long i = 0; i < a.size(); ++i) {
    if (r < a[i].x) {
      continue;
    }
    ans++;
    r += a[i].y;
  }
  memset(dp, -1, sizeof(dp));
  dp[r] = ans;
  for (long long i = 0; i < b.size(); ++i) {
    for (long long j = 0; j <= r; ++j) {
      if (j - b[i].y >= b[i].x && dp[j - b[i].y] != -1)
        dp[j] = max(dp[j], dp[j - b[i].y] + 1);
      ans = max(ans, dp[j]);
    }
  }
  cout << ans << endl;
  return 0;
}
