#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, k, l = 2, r, mid, best = 1e18, val1, val2, val3, val4;
  cin >> n >> k;
  r = k;
  if (n == 1) {
    cout << 0;
    return 0;
  }
  while (l <= r) {
    mid = (l + r) / 2;
    val1 = r - mid;
    val2 = ((r) * (r + 1)) / 2;
    val3 = (((mid - 1) * mid) / 2);
    val4 = val2 - val3 - val1;
    if (val4 >= n) {
      best = val1 + 1;
      l = mid + 1;
    } else
      r = mid - 1;
  }
  if (best == 1e18) best = -1;
  cout << best << "\n";
  return 0;
}
