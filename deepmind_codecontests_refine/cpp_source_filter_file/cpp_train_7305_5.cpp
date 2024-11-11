#include <bits/stdc++.h>
using namespace std;
long long t, n, a, b;
string s;
long long dp[3][200005 + 10];
int arr[200005 + 10];
long long call(int pre, int idx) {
  if (idx == n) {
    if (pre == 2)
      return 2 * a + b;
    else
      return a + b;
  }
  if (dp[pre][idx] != -1) return dp[pre][idx];
  long long ret = 10000000000;
  if (arr[idx] == 2) {
    if (pre == 2) {
      ret = min(ret, call(2, idx + 1) + a + 2 * b);
    } else {
      ret = min(ret, call(2, idx + 1) + 2 * a + 2 * b);
    }
  } else {
    if (pre == 2) {
      ret = min(ret, call(1, idx + 1) + 2 * a + b);
      ret = min(ret, call(2, idx + 1) + a + 2 * b);
    } else {
      ret = min(ret, call(1, idx + 1) + a + b);
      ret = min(ret, call(2, idx + 1) + 2 * a + 2 * b);
    }
  }
  return dp[pre][idx] = ret;
}
int main() {
  cin >> t;
  while (t--) {
    cin >> n >> a >> b;
    cin >> s;
    memset(arr, 0, sizeof arr);
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') {
        arr[i] = 2;
        arr[i + 1] = 2;
      }
    }
    for (int i = 0; i <= n; i++) {
      if (!arr[i]) arr[i] = 1;
    }
    memset(dp, -1, sizeof dp);
    long long ans = call(1, 1) + b;
    cout << ans << endl;
  }
}
