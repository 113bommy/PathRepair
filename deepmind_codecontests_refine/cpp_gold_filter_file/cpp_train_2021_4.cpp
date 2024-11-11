#include <bits/stdc++.h>
using namespace std;
long long a[2005], dp[2005];
bool dinamika(int n, int k, long long d) {
  for (int i = n - 1; i >= 0; i--) {
    dp[i] = 1;
    for (int j = i + 1; j < n; j++)
      if ((abs(a[j] - a[i]) + (j - i) - 1) / (j - i) <= d)
        dp[i] = max(dp[i], dp[j] + 1);
    if (dp[i] >= k) return true;
  }
  return false;
}
int main() {
  long long n, k, l = -1, r = 2 * (1e9);
  cin >> n >> k;
  k = n - k;
  for (int i = 0; i < n; i++) cin >> a[i];
  while (r - l > 1) {
    int mid = (l + r) / 2;
    if (dinamika(n, k, mid))
      r = mid;
    else
      l = mid;
  }
  cout << r;
  return 0;
}
