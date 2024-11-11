#include <bits/stdc++.h>
using namespace std;
void solve();
int main() {
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
void solve() {
  int n, k;
  scanf("%d %d", &n, &k);
  long long ans = -1;
  long long l = 0, r = n;
  long long val, mid;
  while (l <= r) {
    mid = l + (r - l) / 2;
    val = mid * (mid + 1) / 2 - (n - mid);
    if (val == k) {
      ans = n - mid;
      break;
    } else if (val < k) {
      l = mid + 1;
    } else {
      r = mid;
    }
  }
  printf("%lld\n", ans);
}
