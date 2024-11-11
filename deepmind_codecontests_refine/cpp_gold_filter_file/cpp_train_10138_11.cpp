#include <bits/stdc++.h>
using namespace std;
const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};
long long dp[2][200500], arr[200500], n;
long long solve(bool flip, int idx) {
  if (idx < 0 || idx >= n) return 0;
  long long& ret = dp[flip][idx];
  if (~ret) return ret;
  ret = -(1ll << 60);
  return ret = arr[idx] +
               (flip ? solve(0, idx - arr[idx]) : solve(1, idx + arr[idx]));
}
int main() {
  memset(dp, -1, sizeof(dp));
  scanf("%I64d", &n);
  for (int i = 1; i < n; i++) scanf("%I64d", &arr[i]);
  long long ans;
  for (int i = 1; i < n; i++) {
    arr[0] = i;
    ans = i + solve(1, i);
    if (ans < 0)
      puts("-1");
    else
      cout << ans << endl;
  }
  return 0;
}
