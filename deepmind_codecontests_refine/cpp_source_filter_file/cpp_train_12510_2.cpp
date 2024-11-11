#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int lo = 0, hi = n - 1, mid, ans = -1;
  while (lo <= hi) {
    mid = lo + (hi - lo) / 2;
    long long sum = ((n - mid) * (n - mid + 1)) / 2;
    if (sum == k + mid) {
      ans = mid;
      break;
    }
    if (sum > k + mid)
      lo = mid + 1;
    else
      hi = mid - 1;
  }
  cout << ans << endl;
}
