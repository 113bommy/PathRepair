#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, k, ans = 0;
  cin >> n >> k;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    ans += arr[i] / 10;
    arr[i] %= 10;
  }
  sort(arr, arr + n);
  for (int i = n - 1; i >= 0; i--) {
    if (k >= (10 - arr[i]) && ans < n * 10) {
      k -= (10 - arr[i]);
      ans++;
    } else
      break;
  }
  if (k < 0) k = 0;
  ans = min(ans + k / 10, n * 10);
  cout << ans;
  return 0;
}
