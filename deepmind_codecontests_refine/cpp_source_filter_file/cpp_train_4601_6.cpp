#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i];
  }
  struct fence {
    long long zero = 0, one = 0, two = 0;
    long long get() { return min({zero, one, two}); }
  };
  vector<fence> dp(n);
  dp[0].one = b[0];
  dp[0].two = b[0] << 1;
  for (int i = 1; i < n; ++i) {
    if (a[i] == a[i - 1]) {
      dp[i].zero = min(dp[i - 1].one, dp[i - 1].two);
      dp[i].one = min(dp[i - 1].zero, dp[i - 1].two) + b[i];
      dp[i].two = min(dp[i - 1].zero, dp[i - 1].one) + b[i] * 2;
    } else if (a[i] + 1 == a[i - 1]) {
      dp[i].zero = dp[i - 1].get();
      dp[i].one = min(dp[i - 1].one, dp[i - 1].two) + b[i];
      dp[i].two = min(dp[i - 1].zero, dp[i - 1].two) + b[i] * 2;
    } else if (a[i] + 2 == a[i - 1]) {
      dp[i].zero = dp[i].get();
      dp[i].one = dp[i - 1].get() + b[i];
      dp[i].two = min(dp[i - 1].two, dp[i - 1].one) + b[i] * 2;
    } else if (a[i] - 1 == a[i - 1]) {
      dp[i].zero = min(dp[i - 1].zero, dp[i - 1].two);
      dp[i].one = min(dp[i - 1].zero, dp[i - 1].one) + b[i];
      dp[i].two = dp[i - 1].get() + b[i] * 2;
    } else if (a[i] - 2 == a[i - 1]) {
      dp[i].zero = min(dp[i - 1].zero, dp[i - 1].one);
      dp[i].one = dp[i - 1].get() + b[i];
      dp[i].two = dp[i - 1].get() + b[i] * 2;
    } else {
      dp[i].zero = dp[i - 1].get();
      dp[i].one = dp[i - 1].get() + b[i];
      dp[i].two = dp[i - 1].get() + b[i] * 2;
    }
  }
  cout << dp[n - 1].get();
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int q;
  cin >> q;
  while (q--) {
    solve();
    cout << '\n';
  }
  return 0;
}
