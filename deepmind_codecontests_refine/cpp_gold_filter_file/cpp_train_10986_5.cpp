#include <bits/stdc++.h>
using namespace std;
void solve() {
  int64_t n;
  cin >> n;
  int64_t arr[n];
  for (int64_t i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int64_t cnt = 1, mx_cnt = INT_MIN;
  for (int64_t i = 0; i < n; i++) {
    cnt = 1;
    if (i == 0) {
      int64_t j = i;
      while (j < n - 1) {
        if (arr[j + 1] <= arr[j]) {
          cnt++;
          j++;
        } else
          break;
      }
    } else if (i == n - 1) {
      int64_t j = i;
      while (j > 0) {
        if (arr[j] >= arr[j - 1]) {
          cnt++;
          j--;
        } else
          break;
      }
    } else {
      int64_t j = i;
      while (j < n - 1) {
        if (arr[j + 1] <= arr[j]) {
          cnt++;
          j++;
        } else
          break;
      }
      j = i;
      while (j > 0) {
        if (arr[j] >= arr[j - 1]) {
          cnt++;
          j--;
        } else
          break;
      }
    }
    mx_cnt = max(mx_cnt, cnt);
  }
  cout << mx_cnt << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int64_t test = 1;
  while (test--) {
    solve();
  }
}
