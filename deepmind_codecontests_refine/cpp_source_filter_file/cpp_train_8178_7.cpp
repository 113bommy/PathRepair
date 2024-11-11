#include <bits/stdc++.h>
using namespace std;
int n, a[100100], dp[100100], st, dr, mid;
int bs(int val, int idx) {
  st = 1;
  dr = idx - 1;
  if (a[dr] < val) return -1;
  if (a[1] >= val) return 0;
  while (st <= dr) {
    mid = st + dr >> 1;
    if (a[mid] >= val)
      dr = mid - 1;
    else
      st = mid + 1;
  }
  return st - 1;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  dp[1] = 20;
  for (int i = 2; i <= n; i++) {
    dp[i] = dp[i - 1] + 20;
    int idx = bs(a[i] - 90 + 1, i);
    if (idx != -1) dp[i] = min(dp[i], dp[idx] + 50);
    idx = bs(a[i] - 1440, i);
    if (idx != -1) dp[i] = min(dp[i], dp[idx] + 120);
  }
  for (int i = 1; i <= n; i++) cout << dp[i] - dp[i - 1] << '\n';
  return 0;
}
