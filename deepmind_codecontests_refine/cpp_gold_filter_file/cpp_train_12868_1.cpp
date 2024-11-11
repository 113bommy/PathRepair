#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  int64_t n;
  cin >> n;
  int64_t arr[n];
  for (int64_t i = 0; i < n; i++) cin >> arr[i];
  int64_t dp1[n];
  int64_t dp2[n];
  int64_t u[n];
  int64_t w[n];
  for (int64_t i = 0; i < n; i++) {
    u[i] = 0;
    w[i] = 0;
  }
  dp1[0] = 0;
  dp2[n - 1] = 0;
  int64_t q[n];
  for (int64_t i = 0; i < n; i++) q[i] = arr[i];
  for (int64_t i = 1; i < n; i++) {
    dp1[i] = dp1[i - 1] + max((q[i - 1] + (int64_t)1) - q[i], (int64_t)0);
    u[i] = max((q[i - 1] + 1) - q[i], (int64_t)0);
    q[i] = max(q[i], q[i - 1] + (int64_t)1);
  }
  for (int64_t i = n - 2; i >= 0; i--) {
    dp2[i] = dp2[i + 1] + max((arr[i + 1] + (int64_t)1) - arr[i], (int64_t)0);
    w[i] = max((arr[i + 1] + (int64_t)1) - arr[i], (int64_t)0);
    arr[i] = max(arr[i], arr[i + 1] + (int64_t)1);
  }
  int64_t mini = 1e18;
  for (int64_t i = 0; i < n; i++) {
    mini = min(mini, dp1[i] + dp2[i] - min(u[i], w[i]));
  }
  cout << mini << endl;
  return 0;
}
