#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  long long H, N;
  cin >> H >> N;
  long long ans = 0;
  for (long long lo = 1, hi = (1 << H), i = 0; lo < hi; i++) {
    long long mid = (lo + hi) / 2;
    long long dis = hi - mid;
    if (i % 2 == 0) {
      if (N <= mid)
        hi = mid, ans++;
      else
        ans += (dis << 1) - 1;
    } else {
      if (N <= mid)
        ans += (dis << 1) - 1;
      else
        lo = mid + 1, ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
