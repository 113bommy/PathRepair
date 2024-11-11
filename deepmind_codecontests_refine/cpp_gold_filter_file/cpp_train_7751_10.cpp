#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int a[maxn];
int dp[maxn];
int leftt[maxn], rightt[maxn];
map<pair<int, int>, int> ted;
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  fill(dp, dp + maxn, 1e6);
  for (int i = 1; i <= n; ++i) {
    int t = lower_bound(dp, dp + maxn, a[i]) - dp;
    dp[t] = a[i];
    leftt[i] = t + 1;
  }
  reverse(a + 1, a + n + 1);
  for (int i = 1; i <= n; ++i) a[i] = -a[i];
  fill(dp, dp + maxn, 1e6);
  int mx = 0;
  for (int i = 1; i <= n; ++i) {
    int t = lower_bound(dp, dp + maxn, a[i]) - dp;
    dp[t] = a[i];
    mx = max(mx, t + 1);
    rightt[n - i + 1] = t + 1;
  }
  for (int i = 1; i <= n; ++i) ted[{leftt[i], rightt[i]}]++;
  for (int i = 1; i <= n; ++i)
    if (leftt[i] + rightt[i] < mx + 1)
      cout << "1";
    else if (ted[{leftt[i], rightt[i]}] == 1)
      cout << "3";
    else
      cout << "2";
  cout << "\n";
  return 0;
}
