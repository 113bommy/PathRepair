#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
int n, m, k;
int a[N], dp[N];
int main() {
  long long T = 1, x, y, rt;
  while (T--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    for (int i = 1; i <= n; i += 2) {
      dp[(i + 1) / 2] = a[i];
    }
    int l = (n + 1) / 2;
    for (int i = 2; i <= n; i += 2) {
      dp[l + i / 2] = a[i];
    }
    for (int i = 1; i <= n; i++) {
      dp[n + i] = dp[i];
    }
    long long mx = 0, ans = 0;
    for (int i = 1; i <= l; i++) {
      ans += dp[i];
    }
    mx = ans;
    for (int i = l + 1; i <= 2 * n; i++) {
      ans += dp[i] - dp[i - l];
      mx = max(ans, mx);
    }
    cout << mx << endl;
  }
  return 0;
}
