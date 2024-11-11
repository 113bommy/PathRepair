#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 1;
long long dp[MAXN][3];
long long a[MAXN];
int bin_srch(long long pt, int lo, int hi) {
  if (pt == 0) return 0;
  int idx = hi;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    if (a[mid] > pt) {
      hi = mid - 1;
      idx = min(idx, mid);
    } else
      lo = mid + 1;
  }
  return idx;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%lld", &a[i + 1]);
  long long prev = 0;
  for (int i = 1; i <= n; i++) {
    long long p1 = max(0LL, a[i] + 1 - 90);
    long long p2 = max(0LL, a[i] + 1 - 1440);
    int idx1 = bin_srch(p1, 0, i - 1) - 1;
    int idx2 = bin_srch(p2, 0, i - 1) - 1;
    dp[i][1] = 50 + min(dp[idx1][0], min(dp[idx1][1], dp[idx1][2]));
    dp[i][2] = 120 + min(dp[idx2][0], min(dp[idx2][1], dp[idx2][2]));
    dp[i][0] = 20 + min(dp[i - 1][0], min(dp[i - 1][1], dp[i - 1][2]));
    cout << min(dp[i][0], min(dp[i][1], dp[i][2])) - prev << '\n';
    prev = min(dp[i][0], min(dp[i][1], dp[i][2]));
  }
}
