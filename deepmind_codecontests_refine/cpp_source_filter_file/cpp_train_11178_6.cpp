#include <bits/stdc++.h>
int64_t M = 1e9 + 7;
using namespace std;
int main() {
  int t = 1;
  while (t--) {
    int64_t n, m;
    cin >> n >> m;
    vector<int> a(n), v(m + 1, 0);
    for (auto& x : a) {
      float f;
      cin >> x >> f;
    }
    vector<int> dp(n + 1, 1);
    vector<int> dp2(n + 1, 1);
    v[a[0]]++;
    int ans = 0;
    int ans2 = 0;
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if (a[i] >= a[j]) dp[i] = max(dp[i], dp[j] + 1);
        if (a[i] <= a[j]) dp2[i] = max(dp2[i], dp2[j] + 1);
      }
      ans = max(dp[i], ans);
    }
    cout << n - ans << endl;
  }
}
