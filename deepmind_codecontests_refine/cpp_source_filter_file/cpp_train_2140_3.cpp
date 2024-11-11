#include <bits/stdc++.h>
using namespace std;
const long long BIG = 1e7 + 9;
int a[BIG], b[BIG], n, m, ans = -1;
int left_BS(int x) {
  int mid, l = 0, r = m - 1, ans = 1e6;
  ;
  while (l <= r) {
    mid = (l + r) / 2;
    if (b[mid] <= x) {
      ans = abs(b[mid] - x);
      l = mid + 1;
    } else
      r = mid - 1;
  }
  return ans;
}
int right_BS(int x) {
  int mid, l = 0, r = m - 1, ans = 1e6;
  ;
  while (l <= r) {
    mid = (l + r) / 2;
    if (b[mid] >= x) {
      ans = abs(b[mid] - x);
      r = mid - 1;
    } else
      l = mid + 1;
  }
  return ans;
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) cin >> b[i];
  for (int i = 0; i < n; i++) {
    int x = min(left_BS(a[i]), right_BS(a[i]));
    ans = max(ans, x);
  }
  cout << ans;
  return 0;
}
