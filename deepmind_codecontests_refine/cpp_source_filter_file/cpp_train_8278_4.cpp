#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio;
  int n, k, ck = 0;
  cin >> n >> k;
  int a[n], b[n], mn = INT_MAX;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  long long l = 0, r = 2000000000;
  long long mid, cnt = 0;
  while (l < r) {
    mid = (l + r) / 2, cnt = 0;
    for (int i = 0; i < n; i++) {
      if ((mid * a[i] - b[i]) > 0) cnt += (mid * a[i] - b[i]);
      if (cnt > k) break;
    }
    if (cnt <= k)
      l = mid + 1;
    else
      r = mid - 1;
  }
  cout << l << endl;
  return 0;
}
