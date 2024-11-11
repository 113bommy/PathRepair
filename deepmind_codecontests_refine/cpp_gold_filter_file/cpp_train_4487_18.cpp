#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  int n;
  cin >> n;
  n = 2 * n;
  long long arr[n], ans;
  for (int i = 0; i < n; i++) cin >> arr[i];
  sort(arr, arr + n);
  ans = (arr[n / 2 - 1] - arr[0]) * (arr[n - 1] - arr[n / 2]);
  long long max_col_diff = arr[n - 1] - arr[0], min_row_diff = INT_MAX;
  for (int i = 1; i < n / 2; i++)
    min_row_diff = min(min_row_diff, arr[n / 2 - 1 + i] - arr[i]);
  ans = min(ans, max_col_diff * min_row_diff);
  cout << ans;
  return 0;
}
