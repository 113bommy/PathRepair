#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int minv = 0, maxv = 0;
  if (n > k) minv = 1;
  maxv = minv;
  if (k == 0) {
    cout << "0 0";
    return 0;
  }
  if (k == 1) {
    maxv = min(2, n - k);
    ;
    cout << minv << " " << maxv;
    return 0;
  }
  if (n >= k + 2) {
    maxv = 2;
    int x = 0, y = n;
    int ans = 0;
    while (x <= y) {
      int mid = x + (y - x) / 2;
      if (3 * mid + 4 <= n && 2 + mid <= k) {
        ans = mid;
        x = mid + 1;
      } else
        y = mid - 1;
    }
    if (ans == 0) {
      int p = 2 + min(2, n - 4);
      if (ans + 2 < k) p -= (k - 2 - ans);
      cout << "1 " << to_string(p);
      return 0;
    }
    maxv += 2 * ans;
    maxv += (n - 4 - 3 * ans);
    if (ans + 2 < k) maxv -= (k - ans - 2);
  }
  cout << minv << " " << maxv;
}
