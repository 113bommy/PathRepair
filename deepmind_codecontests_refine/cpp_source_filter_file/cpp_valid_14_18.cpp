#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll mod = 1000000007;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(20);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
      cin >> p[i];
      p[i]--;
    }
    vector<int> f(n + 1, -1);
    f[0] = 0;
    for (int i = 0; i < n; i++) {
      vector<int> dp(n + 1, -1);
      dp[0] = 0;
      for (int j = 0; j <= i; j++) {
        if (p[i] == i - j) {
          dp[j] = max(dp[j], f[j] + 1);
        } else {
          dp[j] = max(dp[j], f[j]);
        }
        dp[j + 1] = max(dp[j + 1], dp[j]);
      }
      swap(dp, f);
    }
    int ans = -1;
    for (int i = 0; i <= n; i++) {
      if (f[i] >= k) {
        ans = i;
        break;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
