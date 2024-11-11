#include <bits/stdc++.h>
using namespace std;
bool file = 0;
long long n, k;
long long a[2010];
bool check(long long x) {
  long long dp[2010];
  dp[1] = 0;
  for (int i = 2; i <= n; i++) {
    dp[i] = i - 1;
    for (int j = 1; j < i; j++) {
      if (abs(a[i] - a[j]) <= (i - j) * x)
        dp[i] = min(dp[i], dp[j] + i - j - 1);
    }
  }
  long long t = n - 1;
  for (int i = 1; i <= n; i++) t = min(t, dp[i] + n - i);
  return t <= k;
}
int main() {
  if (file) {
    freopen("inp.in", "r", stdin);
    freopen("inp.out", "w", stdout);
  }
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  long long l, r, mid;
  l = 0;
  r = 2000000000;
  while (r - l > 1) {
    mid = (l + r) / 2;
    if (check(mid))
      r = mid;
    else
      l = mid;
  }
  long long ans;
  if (check(l))
    ans = l;
  else
    ans = r;
  cout << ans << endl;
  return 0;
}
