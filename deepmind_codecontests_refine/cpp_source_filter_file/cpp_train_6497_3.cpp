#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3000;
int a[MAXN], dp[MAXN], n, k;
bool good(int x) {
  for (int i = 0; i < MAXN; i++) dp[i] = 0;
  for (int i = 1; i < n; i++) {
    dp[i] = i;
    for (int j = 0; j < i; j++) {
      if ((long long)abs(a[i] - a[j]) <= (long long)(i - j) * x)
        dp[i] = min(dp[i], dp[j] + (i - j - 1));
    }
    if (dp[i] + n - i - 1 <= k) return true;
  }
  return false;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  long long l = 0, r = 2 * 1000 * 1000 * 1000 + 10;
  while (r >= l) {
    long long mid = (l + r) >> 1;
    if (good(mid))
      r = mid - 1;
    else
      l = mid + 1;
  }
  cout << l << endl;
  return 0;
}
