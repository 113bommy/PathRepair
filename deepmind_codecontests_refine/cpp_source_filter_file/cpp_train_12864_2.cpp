#include <bits/stdc++.h>
using namespace std;
int n, t[100050], prefix[100050], dp[100050];
int upperbound(int x) {
  int lo, hi, mid, ans;
  lo = 1;
  hi = n;
  ans = -1;
  while (lo <= hi) {
    mid = (lo + hi) / 2;
    if (t[mid] >= x) {
      ans = mid;
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }
  return ans;
}
int main() {
  int i, x, y, a, b, c;
  cin >> n;
  for (i = 1; i <= n; i++) cin >> t[i];
  prefix[0] = 0;
  for (i = 1; i <= n; i++) {
    x = upperbound(t[i] - 90 + 1);
    y = upperbound(t[i] - 1440 + 1);
    a = 20;
    b = max(50 - (prefix[i - 1] - prefix[x - 1]), 0);
    c = max(1440 - prefix[i - 1] - prefix[y - 1], 0);
    dp[i] = min(a, min(b, c));
    prefix[i] = prefix[i - 1] + dp[i];
  }
  for (i = 1; i <= n; i++) {
    cout << dp[i] << " ";
  }
  cout << endl;
  return 0;
}
