#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  int ans = 0, temp;
  sort(arr, arr + n);
  for (int i = 0; i < n; i++) {
    if (arr[i] < 0) {
      if (arr[i] & 1)
        temp = (arr[i] - 1) / 2;
      else
        temp = arr[i] / 2;
      ans += (upper_bound(arr + i + 1, arr + n, temp) - arr);
      ans -= i + 1;
      ans += (upper_bound(arr + i + 1, arr + n, -1 * arr[i] * 2) -
              lower_bound(arr + i + 1, arr + n, -1 * temp));
    } else if (arr[i] > 0) {
      ans += (upper_bound(arr + i + 1, arr + n, 2 * arr[i]) - arr);
      ans -= i + 1;
    }
  }
  cout << ans;
  return 0;
}
